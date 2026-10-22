#ifndef ARV_H
#define ARV_H

#include <vector>
#include <iostream>
#include <string>


inline std::string safe_str(const std::string& s) {
    return s;
}

// nó base
class No {
public:
    std::string tipo_no; // tipo do no util para analise semantica
    virtual ~No() {}

    virtual void print(int indent = 0) const = 0;
};

//imprime com indentação da arvore
inline void printIndent(int indent) {
    for (int i = 0; i < indent; ++i) {
        std::cout << "  ";
    }
}

class ListaClasses : public No {
public:
    std::vector<No*> elementos;

    void adicionar(No* elemento) {
        if(elemento) elementos.push_back(elemento);
    }

    void print(int indent = 0) const override {
        printIndent(indent);
        std::cout << "[ListaClasses]\n";
        for (auto elem : elementos) {
            elem->print(indent + 1);
        }
    }
};

class ListaFeatures : public No {
public:
    std::vector<No*> elementos;

    void adicionar(No* elemento) {
        if(elemento) elementos.push_back(elemento);
    }

    void print(int indent = 0) const override {
        printIndent(indent);
        std::cout << "[ListaFeatures]\n";
        for (auto elem : elementos) {
            elem->print(indent + 1);
        }
    }
};

class ListaFormais : public No {
public:
    std::vector<No*> elementos;

    void adicionar(No* elemento) {
        if(elemento) elementos.push_back(elemento);
    }

    void print(int indent = 0) const override {
        printIndent(indent);
        std::cout << "[ListaFormais]\n";
        for (auto elem : elementos) {
            elem->print(indent + 1);
        }
    }
};

class ListaExprs : public No {
public:
    std::vector<No*> elementos;

    void adicionar(No* elemento) {
        if(elemento) elementos.push_back(elemento);
    }

    void print(int indent = 0) const override {
        printIndent(indent);
        std::cout << "[ListaExprs]\n";
        for (auto elem : elementos) {
            elem->print(indent + 1);
        }
    }
};

class BlocoExprs : public No {
public:
    std::vector<No*> elementos;

    void adicionar(No* elemento) {
        if (elemento) elementos.push_back(elemento);
    }

    void print(int indent = 0) const override {
        printIndent(indent);
        std::cout << "[BlocoExprs]\n";
        for (auto elem : elementos) {
            elem->print(indent + 1);
        }
    }
};

class ListaLet : public No {
public:
    std::vector<No*> elementos;

    void adicionar(No* elemento) {
        if(elemento) elementos.push_back(elemento);
    }

    void print(int indent = 0) const override {
        printIndent(indent);
        std::cout << "[ListaLet]\n";
        for (auto elem : elementos) {
            elem->print(indent + 1);
        }
    }
};

class ListaCase : public No {
public:
    std::vector<No*> elementos;

    void adicionar(No* elemento) {
        if(elemento) elementos.push_back(elemento);
    }

    void print(int indent = 0) const override {
        printIndent(indent);
        std::cout << "[ListaCase]\n";
        for (auto elem : elementos) {
            elem->print(indent + 1);
        }
    }
};

class Programa : public No {
public:
    No* lista_classes;

    Programa(No* classes) : lista_classes(classes) {}

    void print(int indent = 0) const override {
        printIndent(indent);
        std::cout << "Programa\n";
        if (lista_classes)  lista_classes->print(indent + 1);
    }
};

class Classe : public No {
public:
    std::string nome;
    std::string superclasse;
    No* features;

    Classe(std::string n, std::string s, No* f) 
        : nome(safe_str(n)), superclasse(safe_str(s.c_str())), features(f) {}

    void print(int indent = 0) const override {
        printIndent(indent);
        std::cout << "Classe: " << nome << "(Superclasse: " << superclasse << ")\n";
        if (features) features->print(indent + 1);
    }
};

class Formal : public No {
public:
    std::string nome;
    std::string tipo;

    Formal(std::string n, std::string t) : nome(safe_str(n)), tipo(safe_str(t)) {}

    void print(int indent = 0) const override {
        printIndent(indent);
        std::cout << "Formal: " << nome << " : " << tipo << "\n";
    }
};

class Atributo : public No {
public:
    std::string nome;
    std::string tipo;
    No* expr_inicial;

    Atributo(std::string n, std::string t, No* e = nullptr) 
        : nome(safe_str(n)), tipo(safe_str(t)), expr_inicial(e) {}

    void print(int indent = 0) const override {
        printIndent(indent);
        std::cout << "Atributo: " << nome << " : " << tipo << "\n";
        if (expr_inicial) expr_inicial->print(indent + 1);
    }
};

class Metodo : public No {
public:
    std::string nome;
    No* formals;
    std::string tipo_retorno;
    No* corpo;

    Metodo(std::string n, No* f, std::string t, No* c) 
        : nome(safe_str(n)), formals(f), tipo_retorno(safe_str(t)), corpo(c) {}

    void print(int indent = 0) const override {
        printIndent(indent);
        std::cout << "Metodo: " << nome << "() : " << tipo_retorno << "\n";
        if (formals) formals->print(indent + 1);
        if (corpo) corpo->print(indent + 1);
    }
};

class Atribuicao : public No {
public:
    std::string nome;
    No* expr;

    Atribuicao(std::string n, No* e) : nome(safe_str(n)), expr(e) {}

    void print(int indent = 0) const override {
        printIndent(indent);
        std::cout << "Atribuicao: " << nome << " <-\n";
        if (expr) expr->print(indent + 1);
    }
};

class Chamada : public No {
public:
    std::string objeto;
    std::string metodo;
    No* exprs;
    No* expr_objeto; // para chamadas do tipo obj.metodo()

    Chamada(No* obj_expr, std::string m, No* e)
        : expr_objeto(obj_expr), metodo(m), exprs(e) {}

    Chamada(std::string obj, std::string m, No* e)
        : objeto(obj), metodo(m), exprs(e), expr_objeto(nullptr) {}

    void print(int indent = 0) const override {
        printIndent(indent);
        std::cout << "Chamada de Metodo: " << metodo << "\n";
        if (expr_objeto) expr_objeto->print(indent + 1);
        if (exprs) exprs->print(indent + 1);
    }
};

class ChamadaEstatica : public No {
public:
    No* objeto;
    std::string tipo;
    std::string metodo;
    No* exprs;

    ChamadaEstatica(No* obj, std::string t, std::string m, No* e)
        : objeto(obj), tipo(t), metodo(m), exprs(e) {}
    
    void print(int indent = 0) const override {
        printIndent(indent);
        std::cout << "Chamada Estatica: " << tipo << "." << metodo << "\n";
        if (objeto) objeto->print(indent + 1);
        if (exprs) exprs->print(indent + 1);
    }
};

class If : public No {
public:
    No* condicao;
    No* entao;
    No* senao;

    If(No* c, No* t, No* s) : condicao(c), entao(t), senao(s) {}

    void print(int indent = 0) const override {
        printIndent(indent);
        std::cout << "If-Then-Else\n";
        if (condicao) condicao->print(indent + 1);
        if (entao) entao->print(indent + 1);
        if (senao) senao->print(indent + 1);
    }
};

class While : public No {
public:
    No* condicao;
    No* corpo;

    While(No* c, No* b) : condicao(c), corpo(b) {}

    void print(int indent = 0) const override {
        printIndent(indent);
        std::cout << "While-Loop\n";
        if (condicao) condicao->print(indent + 1);
        if (corpo) corpo->print(indent + 1);
    }
};

class Bloco : public No {
public:
    No* bloco_exprs;

    Bloco(No* b) : bloco_exprs(b) {}

    void print(int indent = 0) const override {
        printIndent(indent);
        std::cout << "Bloco de Codigo\n";
        if (bloco_exprs) bloco_exprs->print(indent + 1);
    }
};

class LetItem : public No {
public:
    std::string nome;
    std::string tipo;
    No* expr_inicial;

    LetItem(std::string n, std::string t, No* e = nullptr) 
        : nome(n), tipo(t), expr_inicial(e) {}

    void print(int indent = 0) const override {
        printIndent(indent);
        std::cout << "Declaracao Let: " << nome << " : " << tipo << "\n";
        if (expr_inicial) expr_inicial->print(indent + 1);
    }
};

class Let : public No {
public:
    No* declaracoes;
    No* corpo;

    Let(No* d, No* c) : declaracoes(d), corpo(c) {}

    void print(int indent = 0) const override {
        printIndent(indent);
        std::cout << "Let-In\n";
        if (declaracoes) declaracoes->print(indent + 1);
        if (corpo) corpo->print(indent + 1);
    }
};

class CaseItem : public No {
public:
    std::string nome;
    std::string tipo;
    No* expr;

    CaseItem(std::string n, std::string t, No* e) : nome(n), tipo(t), expr(e) {}

    void print(int indent = 0) const override {
        printIndent(indent);
        std::cout << "Ramo Case: " << nome << " : " << tipo << " =>\n";
        if (expr) expr->print(indent + 1);
    }
};

class Case : public No {
public:
    No* expr;
    No* ramos;

    Case(No* e, No* r) : expr(e), ramos(r) {}

    void print(int indent = 0) const override {
        printIndent(indent);
        std::cout << "Case-Of\n";
        if (expr) expr->print(indent + 1);
        if (ramos) ramos->print(indent + 1);
    }
};

class New : public No {
public:
    std::string tipo;

    New(std::string t) : tipo(t) {}

    void print(int indent = 0) const override {
        printIndent(indent);
        std::cout << "New: " << tipo << "\n";
    }
};

class IsVoid : public No {
public:
    No* expr;

    IsVoid(No* e) : expr(e) {}

    void print(int indent = 0) const override {
        printIndent(indent);
        std::cout << "IsVoid\n";
        if (expr) expr->print(indent + 1);
    }
};

class Plus : public No {
public:
    No* esq;
    No* dir;

    Plus(No* e, No* d) : esq(e), dir(d) {}

    void print(int indent = 0) const override {
        printIndent(indent);
        std::cout << "Plus\n";
        if (esq) esq->print(indent + 1);
        if (dir) dir->print(indent + 1);
    }
};

class Minus : public No {
public:
    No* esq;
    No* dir;

    Minus(No* e, No* d) : esq(e), dir(d) {}

    void print(int indent = 0) const override {
        printIndent(indent);
        std::cout << "Minus\n";
        if (esq) esq->print(indent + 1);
        if (dir) dir->print(indent + 1);
    }
};

class Mult : public No {
public:
    No* esq;
    No* dir;

    Mult(No* e, No* d) : esq(e), dir(d) {}

    void print(int indent = 0) const override {
        printIndent(indent);
        std::cout << "Multiplicacao\n";
        if (esq) esq->print(indent + 1);
        if (dir) dir->print(indent + 1);
    }
};

class Divide : public No {
public:
    No* esq;
    No* dir;

    Divide(No* e, No* d) : esq(e), dir(d) {}

    void print(int indent = 0) const override {
        printIndent(indent);
        std::cout << "Divide\n";
        if (esq) esq->print(indent + 1);
        if (dir) dir->print(indent + 1);
    }
};

class MenorQue : public No {
public:
    No* esq;
    No* dir;

    MenorQue(No* e, No* d) : esq(e), dir(d) {}

    void print(int indent = 0) const override {
        printIndent(indent);
        std::cout << "MenorQue\n";
        if (esq) esq->print(indent + 1);
        if (dir) dir->print(indent + 1);
    }
};

class MenorIgual : public No {
public:
    No* esq;
    No* dir;

    MenorIgual(No* e, No* d) : esq(e), dir(d) {}

    void print(int indent = 0) const override {
        printIndent(indent);
        std::cout << "MenorIgual\n";
        if (esq) esq->print(indent + 1);
        if (dir) dir->print(indent + 1);
    }
};

class Igual : public No {
public:
    No* esq;
    No* dir;

    Igual(No* e, No* d) : esq(e), dir(d) {}

    void print(int indent = 0) const override {
        printIndent(indent);
        std::cout << "Igual\n";
        if (esq) esq->print(indent + 1);
        if (dir) dir->print(indent + 1);
    }
};

class Negacao : public No {
public: 
    No* expr;

    Negacao(No* e) : expr(e) {}

    void print(int indent = 0) const override {
        printIndent(indent);
        std::cout << "Negacao\n";
        if (expr) expr->print(indent + 1);
    }
};

class Not : public No {
public:
    No* expr;

    Not(No* e) : expr(e) {}

    void print(int indent = 0) const override {
        printIndent(indent);
        std::cout << "Negacao Logica\n";
        if (expr) expr->print(indent + 1);
    }
};

class ObjectID : public No {
public:
    std::string nome;

    ObjectID(std::string n) : nome(safe_str(n)) {}

    void print(int indent = 0) const override {
        printIndent(indent);
        std::cout << "Identificador: " << nome << "\n";
    }
};

class Int : public No {
public:
    std::string valor;

    Int(int v) : valor(std::to_string(v)) {}

    void print(int indent = 0) const override {
        printIndent(indent);
        std::cout << "Inteiro: " << valor << "\n";
    }
};

class String : public No {
public:
    std::string valor;

    String(std::string v) : valor(safe_str(v)) {}

    void print(int indent = 0) const override {
        printIndent(indent);
        std::cout << "String: " << valor << "\n";
    }
};

class Bool : public No {
public:
    bool valor;

    Bool(bool v) : valor(v) {}

    void print(int indent = 0) const override {
        printIndent(indent);
        std::cout << "Booleano: " << (valor ? "true" : "false") << "\n";
    }
};

#endif