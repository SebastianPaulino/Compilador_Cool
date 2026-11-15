#ifndef SEMANT_H
#define SEMANT_H

#include "arv.h"
#include <iostream>
#include <map>
#include <vector>
#include <string>

//criação da classe TabSimb para gerenciar a tabela de símbolos

class TabSimb {
private:
    // Um vetor de mapas simulando a pilha de escopo controlando o metodo
    // chave: nome do metodo, valor : tipo int string obj etc
    std::vector<std::map<std::string, std::string>> scopes;

public:
    TabSimb() {}

    void enterScope() {
        // Adiciona um novo escopo à pilha
        scopes.push_back(std::map<std::string, std::string>());
    }

    void exitScope() {
        // Remove o escopo mais recente da pilha
        if (!scopes.empty()) {
            scopes.pop_back();
        }
    }

    bool addId(const std::string& name, const std::string& type) {
        if (scopes.empty()) {
            return false; // Não há escopo para adicionar
        }
        if (scopes.back().find(name) != scopes.back().end()) {
            return false; // Identificador já existe no escopo atual
        }
        scopes.back()[name] = type;
        return true;
    }

    //encontrou variavel, quer saber o tipo
    std::string lookup(const std::string& name) {
        // Procura o identificador do escopo mais interno para o mais externo
        for (auto it = scopes.rbegin(); it != scopes.rend(); ++it) {
            if (it->find(name) != it->end()) {
                return it->at(name);
            }
        }
        return ""; // Identificador não encontrado
    }

};

//análise semântica
class analisadorSemantico {
    public:
        std::map<std::string, std::string> heranca; // mapa de classe para superclasse
        std::map<std::string, std::string> retornoMetodos; // guarda: nome_do_metodo -> tipo_de_retorno
        std::map<std::string, std::vector<std::string>> paramsMetodos; // guarda: nome_do_metodo -> lista de tipos dos parametros

        TabSimb tabelaSimbolos; // tabela de símbolos
        bool erroSemantico = false; // flag para indicar se tem erro semantico

        void registra_erro(const std::string& msg) {
            std::cerr << "Erro Semantico: " << msg << std::endl;
            erroSemantico = true;
        }

        // Funçao para verificar o tipo de uma expressão (retorna o tipo)
        std::string verificar_expressao(No* expr) {
            if (!expr) return "Object"; // Se a expressão for nula, retorna Object como tipo padrão

            // tipo primitivos
            if(dynamic_cast<Int*>(expr)) return "Int";
            if(dynamic_cast<String*>(expr)) return "String";
            if(dynamic_cast<Bool*>(expr)) return "Bool";

            //variavel / id - procura no escopo
            if(ObjectID* id = dynamic_cast<ObjectID*>(expr)) {
                std::string tipo = tabelaSimbolos.lookup(id->nome);
                if(tipo.empty()) {
                    registra_erro("Identificador '" + id->nome + "' nao definido.");
                    return "Object"; // Retorna Object como tipo padrão em caso de erro
                }
                return tipo;
            }

            if(Let* l = dynamic_cast<Let*>(expr)) {
                ListaLet* lista = dynamic_cast<ListaLet*>(l->declaracoes);
                int escopos = 0;

                if(lista){
                    for (No* item_no : lista->elementos){
                        LetItem* item = (LetItem*)item_no;

                        //verifica se o tipo existe
                        if (heranca.find(item->tipo) == heranca.end()) {
                            registra_erro("Tipo '" + item->tipo + "' nao definido para a variavel '" + item->nome + "'.");
                        }
                        //se tiver valor inicial verifica o tipo
                        if (item->expr_inicial) {
                            std::string tipo_inicial = verificar_expressao(item->expr_inicial);
                            if (tipo_inicial != item->tipo) {
                                registra_erro("Tipo do valor inicial da variavel '" + item->nome + "' nao corresponde ao tipo declarado.");
                            }
                        }
                        //adiciona a variavel na tabela de simbolos
                        tabelaSimbolos.enterScope();
                        escopos++;
                        tabelaSimbolos.addId(item->nome, item->tipo);
                    }
                    //verifica o corpo 'in'
                    std::string tipo_corpo = verificar_expressao(l->corpo);

                    //sai dos escopos
                    for (int i = 0; i < escopos; i++) {
                        tabelaSimbolos.exitScope();
                    }

                    return tipo_corpo; // Retorna o tipo do corpo do let
                }
            }

            //atribuição (<-)
            if(Atribuicao* at = dynamic_cast<Atribuicao*>(expr)){
                std::string tipo_variavel = tabelaSimbolos.lookup(at->nome);
                if(tipo_variavel.empty()) {
                    registra_erro("Identificador '" + at->nome + "' nao definido para atribuicao.");
                    return "Object"; // Retorna Object como tipo padrão em caso de erro
                }
                std::string tipo_expr = verificar_expressao(at->expr);
                if(tipo_variavel != tipo_expr) {
                    registra_erro("Tipo da expressao atribuida a '" + at->nome + "' nao corresponde ao tipo da variavel.");
                }
                return tipo_expr; // Retorna o tipo da expressão atribuída
            }

            //soma
            if (Plus* p = dynamic_cast<Plus*>(expr)) {
                std::string t1 = verificar_expressao(p->esq);
                std::string t2 = verificar_expressao(p->dir);
                if (t1 != "Int" || t2 != "Int") {
                    registra_erro("Operador '+' aplicado a tipos nao inteiros: " + t1 + " e " + t2);
                }
                return "Int";
            }

            //subtração
            if (Minus* m = dynamic_cast<Minus*>(expr)) {
                std::string t1 = verificar_expressao(m->esq);
                std::string t2 = verificar_expressao(m->dir);
                if (t1 != "Int" || t2 != "Int") {
                    registra_erro("Operador '-' aplicado a tipos nao inteiros: " + t1 + " e " + t2);
                }
                return "Int";
            }

            //multiplicação
            if (Mult* m = dynamic_cast<Mult*>(expr)) {
                std::string t1 = verificar_expressao(m->esq);
                std::string t2 = verificar_expressao(m->dir);
                if (t1 != "Int" || t2 != "Int") {
                    registra_erro("Operador '*' aplicado a tipos nao inteiros: " + t1 + " e " + t2);
                }
                return "Int";
            }

            //Divisão
            if (Divide* d = dynamic_cast<Divide*>(expr)) {
                std::string t1 = verificar_expressao(d->esq);
                std::string t2 = verificar_expressao(d->dir);
                if (t1 != "Int" || t2 != "Int") {
                    registra_erro("Operador '/' aplicado a tipos nao inteiros: " + t1 + " e " + t2);
                }
                return "Int";
            }

            //Menor que
            if (MenorQue* m = dynamic_cast<MenorQue*>(expr)) {
                std::string t1 = verificar_expressao(m->esq);
                std::string t2 = verificar_expressao(m->dir);
                if (t1 != "Int" || t2 != "Int") {
                    registra_erro("Operador '<' aplicado a tipos nao inteiros: " + t1 + " e " + t2);
                }
                return "Bool";
            }

            //menor ou igual
            if (MenorIgual* m = dynamic_cast<MenorIgual*>(expr)) {
                std::string t1 = verificar_expressao(m->esq);
                std::string t2 = verificar_expressao(m->dir);
                if (t1 != "Int" || t2 != "Int") {
                    registra_erro("Operador '<=' aplicado a tipos nao inteiros: " + t1 + " e " + t2);
                }
                return "Bool";
            }
            
            //igualdade
            if (Igual* i = dynamic_cast<Igual*>(expr)) {
                std::string t1 = verificar_expressao(i->esq);
                std::string t2 = verificar_expressao(i->dir);
                if (t1 != t2) {
                    registra_erro("Operador '=' aplicado a tipos diferentes: " + t1 + " e " + t2);
                }
                return "Bool";
            }
            
            //negacao
            if (Negacao* n = dynamic_cast<Negacao*>(expr)) {
                std::string t = verificar_expressao(n->expr);
                if (t != "Bool") {
                    registra_erro("Operador 'not' aplicado a tipo nao booleano: " + t);
                }
                return "Bool";
            }

            //not
            if (Not* n = dynamic_cast<Not*>(expr)) {
                std::string t = verificar_expressao(n->expr);
                if (t != "Bool") {
                    registra_erro("Operador 'not' aplicado a tipo nao booleano: " + t);
                }
                return "Bool";
            }

            if (Bloco* b = dynamic_cast<Bloco*>(expr)) {
                return verificar_expressao(b->bloco_exprs);
            }
            
            if(BlocoExprs* be = dynamic_cast<BlocoExprs*>(expr)) {
                std::string tipo_final = "Object"; // Tipo padrão
                for (No* e : be->elementos) {
                    tipo_final = verificar_expressao(e);
                }
                return tipo_final; // Retorna o tipo da última expressão
            }

            if (Chamada* ch = dynamic_cast<Chamada*>(expr)) {
                if(ch->expr_objeto){
                    verificar_expressao(ch->expr_objeto);
                }

                // Verifica se o método está definido
                if(retornoMetodos.find(ch->metodo) == retornoMetodos.end()) {
                    registra_erro("Metodo '" + ch->metodo + "' nao definido.");
                    return "Object"; // Retorna Object como tipo padrão em caso de erro
                }

                // Verifica os tipos dos argumentos passados
                std::vector<std::string> args_passados;
                if (ListaExprs* le = dynamic_cast<ListaExprs*>(ch->exprs)) {
                    for (No* e : le->elementos) {
                        args_passados.push_back(verificar_expressao(e));
                    }
                }

                // Verifica se o número de argumentos e os tipos correspondem ao esperado
                std::vector<std::string> tipos_esperados = paramsMetodos[ch->metodo];
                if(args_passados.size() != tipos_esperados.size()) {
                    registra_erro("Numero de argumentos para o metodo '" + ch->metodo + "' nao corresponde ao esperado.");
                } else {
                    for (size_t i = 0; i < args_passados.size(); ++i) {
                        if (args_passados[i] != tipos_esperados[i]) {
                            registra_erro("Tipo do argumento " + std::to_string(i+1) + " para o metodo '" + ch->metodo + "' nao corresponde ao esperado.");
                        }
                    }
                }

                return retornoMetodos[ch->metodo]; // Retorna o tipo de retorno do método
            }
            return "Object"; // Retorna Object como tipo padrão se a expressão não for reconhecida
        }
        
        void construir_grafo_classes(No* programa){
            heranca["Object"] = ""; // Object não tem superclasse
            heranca["IO"] = "Object"; // IO herda de Object
            heranca["Int"] = "Object"; // Int herda de Object
            heranca["String"] = "Object"; // String herda de Object
            heranca["Bool"] = "Object"; // Bool herda de Object

            retornoMetodos["out_string"] = "IO"; // out_string retorna IO
            paramsMetodos["out_string"] = {"String"}; // out_string exige String

            retornoMetodos["out_int"] = "IO"; // out_int retorna IO
            paramsMetodos["out_int"] = {"Int"}; // out_int exige Int
            
            retornoMetodos["in_string"] = "String"; // in_string retorna String
            paramsMetodos["in_string"] = {}; // in_string não exige parâmetros

            retornoMetodos["in_int"] = "Int"; // in_int retorna Int
            paramsMetodos["in_int"] = {}; // in_int não exige parâmetros

            retornoMetodos["concat"] = "String"; // concat retorna String
            paramsMetodos["concat"] = {"String"}; // concat exige String

            retornoMetodos["length"] = "Int"; // length retorna Int
            paramsMetodos["length"] = {}; // length não exige parâmetros
        
            Programa* prog = (Programa*)programa;

            ListaClasses* lista = (ListaClasses*)prog->lista_classes;
            for (No* c_no : lista->elementos) {
                Classe* c = (Classe*)c_no;
                
                // Verifica se a classe é uma das classes base
                if (c->nome == "Object" || c->nome == "IO" || c->nome == "Int" || c->nome == "String" || c->nome == "Bool") {
                    registra_erro("Classe " + c->nome + " é uma classe base e nao pode ser redefinida.");
                } 
                // Verifica se a superclasse é uma das classes base
                if (c->superclasse == "Int" || c->superclasse == "String" || c->superclasse == "Bool") {
                    registra_erro("Classe " + c->nome + " nao pode herdar de " + c->superclasse + ".");
                }

                heranca[c->nome] = c->superclasse;
            }

            //2 verificação, valida se as superclasses existem e se não há ciclo de herança
            for (No* c_no : lista->elementos) {

                Classe* c = (Classe*)c_no;

                if (!c->superclasse.empty() && heranca.find(c->superclasse) == heranca.end()) {
                    registra_erro("Superclasse '" + c->superclasse + "' da classe '" + c->nome + "' nao foi definida.");
                }

                // Verifica ciclo de heranca
                std::string atual = c->superclasse;
                size_t passos = 0;
                while (!atual.empty() && passos <= heranca.size()) {
                    if (atual == c->nome) {
                        registra_erro("Ciclo de heranca detectado envolvendo a classe '" + c->nome + "'.");
                        break;
                    }
                    if (heranca.find(atual) == heranca.end()){
                        break;
                    }
                    atual = heranca[atual];
                    passos++;
                }
            }

            if (heranca.find("Main") == heranca.end()) {
                registra_erro("Classe Main nao definida.");
            }
        }
        void verificar_classes(No* programa) {
            Programa* prog = (Programa*)programa;
            ListaClasses* lista = (ListaClasses*)prog->lista_classes;

            for (No* c_no : lista->elementos) {
                Classe* c = (Classe*)c_no;
                if(!c->features) continue; // Se não houver features, continue para a próxima classe

                ListaFeatures* features = (ListaFeatures*)c->features;

                tabelaSimbolos.enterScope(); // Entra em um novo escopo para a classe
                for (No* f_no : features->elementos) {
                    Atributo* atr = dynamic_cast<Atributo*>(f_no);
                    if (atr) {
                        // Verifica se o tipo do atributo está definido na herança
                        if (heranca.find(atr->tipo) == heranca.end()) {
                            registra_erro("Tipo " + atr->tipo + " do atributo " + atr->nome + " na classe " + c->nome + " nao definido.");
                        }
                        // ja esta definido na classe? se sim, erro
                        if (!tabelaSimbolos.addId(atr->nome, atr->tipo)) {
                            registra_erro("Atributo " + atr->nome + " ja definido na classe " + c->nome + ".");
                        }
                        // verifica se a expressao inicial do atributo e valida
                        if (atr->expr_inicial){
                            verificar_expressao(atr->expr_inicial);
                        }
                    }
                    Metodo* met = dynamic_cast<Metodo*>(f_no);
                    if (met) {
                        retornoMetodos[met->nome] = met->tipo_retorno;
                        std::vector<std::string> tipos_parametros;

                        // Armazena o tipo de retorno do método
                        if(met->formals){
                            ListaFormais* formals = (ListaFormais*)met->formals;
                            for (No* f : formals->elementos) {
                                tipos_parametros.push_back(((Formal*)f)->tipo);
                            }
                        }
                        paramsMetodos[met->nome] = tipos_parametros;

                        // Verifica se o tipo de retorno do método está definido na herança
                        if (heranca.find(met->tipo_retorno) == heranca.end()) {
                            registra_erro("Tipo de retorno " + met->tipo_retorno + " do metodo " + met->nome + " na classe " + c->nome + " nao definido.");
                        }
                        tabelaSimbolos.enterScope(); // Entra em um novo escopo para o método

                        if(met->formals){
                            ListaFormais* formals = (ListaFormais*)met->formals;
                            for (No* f_no : formals->elementos) {
                                Formal* formal = (Formal*)f_no;
                                if(!tabelaSimbolos.addId(formal->nome, formal->tipo)) {
                                    registra_erro("Parametro " + formal->nome + " ja definido no metodo " + met->nome + " na classe " + c->nome + ".");
                                }
                            }

                        }
                        if(met->corpo){
                            verificar_expressao(met->corpo);
                        }

                        tabelaSimbolos.exitScope(); // Sai do escopo do método
                    }
                }
                tabelaSimbolos.exitScope(); // Sai do escopo da classe 
            }
        }
};

#endif