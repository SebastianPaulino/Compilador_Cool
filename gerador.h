#ifndef GERADOR_H
#define GERADOR_H

#include "arv.h"
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

struct ValorBril {
    std::string var;
    std::string tipo; // "int", "bool" ou "ptr<int>"
};

class GeradorCodigo {
private:
    std::stringstream corpo_out;
    int temp_count = 0;
    int label_count = 0;
    std::string classe_atual;

    std::vector<std::map<std::string, ValorBril>> escopos;
    std::map<std::string, std::string> retorno_metodos;
    std::set<std::string> runtime_usado;

    std::string novo_temp() {
        return "t" + std::to_string(temp_count++);
    }

    std::string novo_label(const std::string& prefixo) {
        return "." + prefixo + "_" + std::to_string(label_count++);
    }

    void enterScope() {
        escopos.push_back(std::map<std::string, ValorBril>());
    }

    void exitScope() {
        if (!escopos.empty()) escopos.pop_back();
    }

    void addVar(const std::string& nome_cool, const std::string& nome_bril, const std::string& tipo_bril) {
        if (!escopos.empty()) {
            escopos.back()[nome_cool] = {nome_bril, tipo_bril};
        }
    }

    ValorBril lookupVar(const std::string& nome_cool) {
        for (auto it = escopos.rbegin(); it != escopos.rend(); ++it) {
            if (it->find(nome_cool) != it->end()) {
                return it->at(nome_cool);
            }
        }
        return {"", "int"};
    }

    std::string mapear_tipo(const std::string& tipo_cool) {
        if (tipo_cool == "Int") return "int";
        if (tipo_cool == "Bool") return "bool";
        return "ptr<int>";
    }

    std::string limpar_string(const std::string& bruto) {
        std::string s = bruto;
        if (s.size() >= 2 && s.front() == '"' && s.back() == '"') {
            s = s.substr(1, s.size() - 2);
        }
        std::string limpa;
        for (size_t i = 0; i < s.size(); ++i) {
            if (s[i] == '\\' && i + 1 < s.size()) {
                char prox = s[i + 1];
                if (prox == 'n') { limpa += '\n'; i++; }
                else if (prox == 't') { limpa += '\t'; i++; }
                else if (prox == '\\') { limpa += '\\'; i++; }
                else if (prox == '"') { limpa += '"'; i++; }
                else { limpa += s[i]; }
            } else {
                limpa += s[i];
            }
        }
        return limpa;
    }

    // Todas as funcoes sao void e terminam direto com '}' (sem 'ret;' vazio)
    void emitir_runtime(std::ostream& out) {
        if (runtime_usado.count("str_set")) {
            out << "@str_set(buf: ptr<int>, pos: int, val: int) {\n";
            out << "  ptr: ptr<int> = ptradd buf pos;\n";
            out << "  store ptr val;\n";
            out << "}\n\n";
        }

        if (runtime_usado.count("IO_out_int")) {
            out << "@IO_out_int(self: ptr<int>, val: int) {\n";
            out << "  print val;\n";
            out << "}\n\n";
        }

        if (runtime_usado.count("IO_out_string")) {
            out << "@IO_out_string(self: ptr<int>, str: ptr<int>) {\n";
            out << "  one: int = const 1;\n";
            out << "  len: int = load str;\n";
            out << "  idx_i: int = const 0;\n";
            out << ".loop_out:\n";
            out << "  cond: bool = lt idx_i len;\n";
            out << "  br cond .body_out .end_out;\n";
            out << ".body_out:\n";
            out << "  idx: int = add idx_i one;\n";
            out << "  ptr_p: ptr<int> = ptradd str idx;\n";
            out << "  ascii: int = load ptr_p;\n";
            out << "  print ascii;\n";
            out << "  idx_i: int = add idx_i one;\n";
            out << "  jmp .loop_out;\n";
            out << ".end_out:\n";
            out << "}\n\n";
        }
    }

    ValorBril gerar_expressao(No* expr) {
        if (!expr) {
            std::string t = novo_temp();
            corpo_out << "  " << t << ": int = const 0;\n";
            return {t, "int"};
        }

        if (Int* i = dynamic_cast<Int*>(expr)) {
            std::string t = novo_temp();
            corpo_out << "  " << t << ": int = const " << i->valor << ";\n";
            return {t, "int"};
        }

        if (Bool* b = dynamic_cast<Bool*>(expr)) {
            std::string t = novo_temp();
            corpo_out << "  " << t << ": bool = const " << (b->valor ? "true" : "false") << ";\n";
            return {t, "bool"};
        }

        if (String* s = dynamic_cast<String*>(expr)) {
            std::string texto = limpar_string(s->valor);
            std::string t_len = novo_temp();
            std::string t_size = novo_temp();
            std::string t_ptr = novo_temp();

            corpo_out << "  " << t_len << ": int = const " << texto.size() << ";\n";
            corpo_out << "  " << t_size << ": int = const " << (texto.size() + 1) << ";\n";
            corpo_out << "  " << t_ptr << ": ptr<int> = alloc " << t_size << ";\n";
            corpo_out << "  store " << t_ptr << " " << t_len << ";\n";

            if (!texto.empty()) {
                runtime_usado.insert("str_set");
                std::string t_idx = novo_temp();
                std::string t_ch = novo_temp();
                for (size_t idx = 0; idx < texto.size(); ++idx) {
                    corpo_out << "  " << t_idx << ": int = const " << (idx + 1) << ";\n";
                    corpo_out << "  " << t_ch << ": int = const " << (int)(unsigned char)texto[idx] << ";\n";
                    corpo_out << "  call @str_set " << t_ptr << " " << t_idx << " " << t_ch << ";\n";
                }
            }
            return {t_ptr, "ptr<int>"};
        }

        if (ObjectID* id = dynamic_cast<ObjectID*>(expr)) {
            if (id->nome == "self") return {"self", "ptr<int>"};
            return lookupVar(id->nome);
        }

        if (Atribuicao* at = dynamic_cast<Atribuicao*>(expr)) {
            ValorBril val = gerar_expressao(at->expr);
            ValorBril dest = lookupVar(at->nome);
            corpo_out << "  " << dest.var << ": " << dest.tipo << " = id " << val.var << ";\n";
            return dest;
        }

        if (Let* l = dynamic_cast<Let*>(expr)) {
            ListaLet* lista = dynamic_cast<ListaLet*>(l->declaracoes);
            int escopos_abertos = 0;

            if (lista) {
                for (No* item_no : lista->elementos) {
                    LetItem* item = (LetItem*)item_no;
                    std::string tipo_bril = mapear_tipo(item->tipo);
                    std::string var_bril = item->nome + "_" + std::to_string(temp_count++);

                    if (item->expr_inicial) {
                        ValorBril init = gerar_expressao(item->expr_inicial);
                        corpo_out << "  " << var_bril << ": " << tipo_bril << " = id " << init.var << ";\n";
                    } else if (tipo_bril == "int") {
                        corpo_out << "  " << var_bril << ": int = const 0;\n";
                    } else if (tipo_bril == "bool") {
                        corpo_out << "  " << var_bril << ": bool = const false;\n";
                    } else {
                        std::string t_one = novo_temp();
                        corpo_out << "  " << t_one << ": int = const 1;\n";
                        corpo_out << "  " << var_bril << ": ptr<int> = alloc " << t_one << ";\n";
                    }

                    enterScope();
                    escopos_abertos++;
                    addVar(item->nome, var_bril, tipo_bril);
                }
            }

            ValorBril res = gerar_expressao(l->corpo);
            for (int i = 0; i < escopos_abertos; ++i) exitScope();
            return res;
        }

        if (Plus* p = dynamic_cast<Plus*>(expr)) {
            ValorBril e = gerar_expressao(p->esq);
            ValorBril d = gerar_expressao(p->dir);
            std::string t = novo_temp();
            corpo_out << "  " << t << ": int = add " << e.var << " " << d.var << ";\n";
            return {t, "int"};
        }
        if (Minus* m = dynamic_cast<Minus*>(expr)) {
            ValorBril e = gerar_expressao(m->esq);
            ValorBril d = gerar_expressao(m->dir);
            std::string t = novo_temp();
            corpo_out << "  " << t << ": int = sub " << e.var << " " << d.var << ";\n";
            return {t, "int"};
        }
        if (Mult* m = dynamic_cast<Mult*>(expr)) {
            ValorBril e = gerar_expressao(m->esq);
            ValorBril d = gerar_expressao(m->dir);
            std::string t = novo_temp();
            corpo_out << "  " << t << ": int = mul " << e.var << " " << d.var << ";\n";
            return {t, "int"};
        }
        if (Divide* d = dynamic_cast<Divide*>(expr)) {
            ValorBril e = gerar_expressao(d->esq);
            ValorBril dir = gerar_expressao(d->dir);
            std::string t = novo_temp();
            corpo_out << "  " << t << ": int = div " << e.var << " " << dir.var << ";\n";
            return {t, "int"};
        }

        if (MenorQue* mq = dynamic_cast<MenorQue*>(expr)) {
            ValorBril e = gerar_expressao(mq->esq);
            ValorBril d = gerar_expressao(mq->dir);
            std::string t = novo_temp();
            corpo_out << "  " << t << ": bool = lt " << e.var << " " << d.var << ";\n";
            return {t, "bool"};
        }
        if (MenorIgual* mi = dynamic_cast<MenorIgual*>(expr)) {
            ValorBril e = gerar_expressao(mi->esq);
            ValorBril d = gerar_expressao(mi->dir);
            std::string t = novo_temp();
            corpo_out << "  " << t << ": bool = le " << e.var << " " << d.var << ";\n";
            return {t, "bool"};
        }
        if (Igual* ig = dynamic_cast<Igual*>(expr)) {
            ValorBril e = gerar_expressao(ig->esq);
            ValorBril d = gerar_expressao(ig->dir);
            std::string t = novo_temp();
            corpo_out << "  " << t << ": bool = eq " << e.var << " " << d.var << ";\n";
            return {t, "bool"};
        }

        if (Negacao* neg = dynamic_cast<Negacao*>(expr)) {
            ValorBril v = gerar_expressao(neg->expr);
            std::string z = novo_temp();
            std::string t = novo_temp();
            corpo_out << "  " << z << ": int = const 0;\n";
            corpo_out << "  " << t << ": int = sub " << z << " " << v.var << ";\n";
            return {t, "int"};
        }
        if (Not* n = dynamic_cast<Not*>(expr)) {
            ValorBril v = gerar_expressao(n->expr);
            std::string t = novo_temp();
            corpo_out << "  " << t << ": bool = not " << v.var << ";\n";
            return {t, "bool"};
        }

        if (If* iff = dynamic_cast<If*>(expr)) {
            ValorBril cond = gerar_expressao(iff->condicao);
            std::string lbl_then = novo_label("then");
            std::string lbl_else = novo_label("else");
            std::string lbl_end = novo_label("endif");
            std::string res = novo_temp();

            corpo_out << "  br " << cond.var << " " << lbl_then << " " << lbl_else << ";\n";
            corpo_out << lbl_then << ":\n";
            ValorBril v_then = gerar_expressao(iff->entao);
            corpo_out << "  " << res << ": " << v_then.tipo << " = id " << v_then.var << ";\n";
            corpo_out << "  jmp " << lbl_end << ";\n";
            corpo_out << lbl_else << ":\n";
            ValorBril v_else = gerar_expressao(iff->senao);
            corpo_out << "  " << res << ": " << v_else.tipo << " = id " << v_else.var << ";\n";
            corpo_out << lbl_end << ":\n";
            return {res, v_then.tipo};
        }

        if (While* w = dynamic_cast<While*>(expr)) {
            std::string lbl_cond = novo_label("while_cond");
            std::string lbl_body = novo_label("while_body");
            std::string lbl_end = novo_label("while_end");

            corpo_out << lbl_cond << ":\n";
            ValorBril cond = gerar_expressao(w->condicao);
            corpo_out << "  br " << cond.var << " " << lbl_body << " " << lbl_end << ";\n";
            corpo_out << lbl_body << ":\n";
            gerar_expressao(w->corpo);
            corpo_out << "  jmp " << lbl_cond << ";\n";
            corpo_out << lbl_end << ":\n";

            std::string t_one = novo_temp();
            std::string t_void = novo_temp();
            corpo_out << "  " << t_one << ": int = const 1;\n";
            corpo_out << "  " << t_void << ": ptr<int> = alloc " << t_one << ";\n";
            return {t_void, "ptr<int>"};
        }

        if (Bloco* b = dynamic_cast<Bloco*>(expr)) {
            return gerar_expressao(b->bloco_exprs);
        }
        if (BlocoExprs* be = dynamic_cast<BlocoExprs*>(expr)) {
            ValorBril ultimo = {"", "int"};
            for (No* e : be->elementos) {
                ultimo = gerar_expressao(e);
            }
            return ultimo;
        }

        if (dynamic_cast<New*>(expr)) {
            std::string t_one = novo_temp();
            std::string t_obj = novo_temp();
            corpo_out << "  " << t_one << ": int = const 1;\n";
            corpo_out << "  " << t_obj << ": ptr<int> = alloc " << t_one << ";\n";
            return {t_obj, "ptr<int>"};
        }
        if (IsVoid* iv = dynamic_cast<IsVoid*>(expr)) {
            gerar_expressao(iv->expr);
            std::string t = novo_temp();
            corpo_out << "  " << t << ": bool = const false;\n";
            return {t, "bool"};
        }

        // Chamadas de Metodo (100% void calls - sem '=')
        if (Chamada* ch = dynamic_cast<Chamada*>(expr)) {
            if (ch->metodo == "in_string") {
                if (ch->expr_objeto) gerar_expressao(ch->expr_objeto);
                std::string t_zero = novo_temp();
                std::string t_one = novo_temp();
                std::string t_str = novo_temp();
                corpo_out << "  " << t_zero << ": int = const 0;\n";
                corpo_out << "  " << t_one << ": int = const 1;\n";
                corpo_out << "  " << t_str << ": ptr<int> = alloc " << t_one << ";\n";
                corpo_out << "  store " << t_str << " " << t_zero << ";\n";
                return {t_str, "ptr<int>"};
            }
            if (ch->metodo == "in_int") {
                if (ch->expr_objeto) gerar_expressao(ch->expr_objeto);
                std::string t_zero = novo_temp();
                corpo_out << "  " << t_zero << ": int = const 0;\n";
                return {t_zero, "int"};
            }

            ValorBril obj = {"self", "ptr<int>"};
            if (ch->expr_objeto) {
                obj = gerar_expressao(ch->expr_objeto);
            }

            std::vector<ValorBril> args;
            if (ListaExprs* le = dynamic_cast<ListaExprs*>(ch->exprs)) {
                for (No* e : le->elementos) {
                    args.push_back(gerar_expressao(e));
                }
            }

            if (ch->metodo == "length") {
                std::string t_len = novo_temp();
                corpo_out << "  " << t_len << ": int = load " << obj.var << ";\n";
                return {t_len, "int"};
            }

            // Concatenacao inline
            if (ch->metodo == "concat" && !args.empty()) {
                std::string t_one = novo_temp();
                std::string t_len1 = novo_temp();
                std::string t_len2 = novo_temp();
                std::string t_tot = novo_temp();
                std::string t_alloc = novo_temp();
                std::string t_res = novo_temp();

                corpo_out << "  " << t_one << ": int = const 1;\n";
                corpo_out << "  " << t_len1 << ": int = load " << obj.var << ";\n";
                corpo_out << "  " << t_len2 << ": int = load " << args[0].var << ";\n";
                corpo_out << "  " << t_tot << ": int = add " << t_len1 << " " << t_len2 << ";\n";
                corpo_out << "  " << t_alloc << ": int = add " << t_tot << " " << t_one << ";\n";
                corpo_out << "  " << t_res << ": ptr<int> = alloc " << t_alloc << ";\n";
                corpo_out << "  store " << t_res << " " << t_tot << ";\n";

                std::string t_i = novo_temp();
                std::string lbl_c1 = novo_label("cat_c1");
                std::string lbl_b1 = novo_label("cat_b1");
                std::string lbl_e1 = novo_label("cat_e1");
                std::string t_cond1 = novo_temp();
                std::string t_idx1 = novo_temp();
                std::string t_p1 = novo_temp();
                std::string t_ch1 = novo_temp();
                std::string t_pd1 = novo_temp();

                corpo_out << "  " << t_i << ": int = const 0;\n";
                corpo_out << lbl_c1 << ":\n";
                corpo_out << "  " << t_cond1 << ": bool = lt " << t_i << " " << t_len1 << ";\n";
                corpo_out << "  br " << t_cond1 << " " << lbl_b1 << " " << lbl_e1 << ";\n";
                corpo_out << lbl_b1 << ":\n";
                corpo_out << "  " << t_idx1 << ": int = add " << t_i << " " << t_one << ";\n";
                corpo_out << "  " << t_p1 << ": ptr<int> = ptradd " << obj.var << " " << t_idx1 << ";\n";
                corpo_out << "  " << t_ch1 << ": int = load " << t_p1 << ";\n";
                corpo_out << "  " << t_pd1 << ": ptr<int> = ptradd " << t_res << " " << t_idx1 << ";\n";
                corpo_out << "  store " << t_pd1 << " " << t_ch1 << ";\n";
                corpo_out << "  " << t_i << ": int = add " << t_i << " " << t_one << ";\n";
                corpo_out << "  jmp " << lbl_c1 << ";\n";
                corpo_out << lbl_e1 << ":\n";

                std::string t_j = novo_temp();
                std::string lbl_c2 = novo_label("cat_c2");
                std::string lbl_b2 = novo_label("cat_b2");
                std::string lbl_e2 = novo_label("cat_e2");
                std::string t_cond2 = novo_temp();
                std::string t_idx2 = novo_temp();
                std::string t_p2 = novo_temp();
                std::string t_ch2 = novo_temp();
                std::string t_off2 = novo_temp();
                std::string t_pd2 = novo_temp();

                corpo_out << "  " << t_j << ": int = const 0;\n";
                corpo_out << lbl_c2 << ":\n";
                corpo_out << "  " << t_cond2 << ": bool = lt " << t_j << " " << t_len2 << ";\n";
                corpo_out << "  br " << t_cond2 << " " << lbl_b2 << " " << lbl_e2 << ";\n";
                corpo_out << lbl_b2 << ":\n";
                corpo_out << "  " << t_idx2 << ": int = add " << t_j << " " << t_one << ";\n";
                corpo_out << "  " << t_p2 << ": ptr<int> = ptradd " << args[0].var << " " << t_idx2 << ";\n";
                corpo_out << "  " << t_ch2 << ": int = load " << t_p2 << ";\n";
                corpo_out << "  " << t_off2 << ": int = add " << t_len1 << " " << t_idx2 << ";\n";
                corpo_out << "  " << t_pd2 << ": ptr<int> = ptradd " << t_res << " " << t_off2 << ";\n";
                corpo_out << "  store " << t_pd2 << " " << t_ch2 << ";\n";
                corpo_out << "  " << t_j << ": int = add " << t_j << " " << t_one << ";\n";
                corpo_out << "  jmp " << lbl_c2 << ";\n";
                corpo_out << lbl_e2 << ":\n";

                return {t_res, "ptr<int>"};
            }

            if (ch->metodo == "out_string" || ch->metodo == "out_int") {
                std::string chave = "IO_" + ch->metodo;
                runtime_usado.insert(chave);
                corpo_out << "  call @" << chave << " " << obj.var;
                for (const auto& a : args) {
                    corpo_out << " " << a.var;
                }
                corpo_out << ";\n";
                return {obj.var, "ptr<int>"};
            }

            if (ch->metodo == "copy" || ch->metodo == "abort") {
                return {obj.var, "ptr<int>"};
            }

            std::string chave = classe_atual + "_" + ch->metodo;
            std::string tipo_ret = retorno_metodos.count(chave) ? retorno_metodos[chave] : "ptr<int>";
            std::string t_one = novo_temp();
            std::string t_slot = novo_temp();
            std::string t_res = novo_temp();

            corpo_out << "  " << t_one << ": int = const 1;\n";
            corpo_out << "  " << t_slot << ": ptr<" << tipo_ret << "> = alloc " << t_one << ";\n";
            corpo_out << "  call @" << chave << " " << obj.var << " " << t_slot;
            for (const auto& a : args) {
                corpo_out << " " << a.var;
            }
            corpo_out << ";\n";
            corpo_out << "  " << t_res << ": " << tipo_ret << " = load " << t_slot << ";\n";
            corpo_out << "  free " << t_slot << ";\n";
            return {t_res, tipo_ret};
        }

        std::string t = novo_temp();
        corpo_out << "  " << t << ": int = const 0;\n";
        return {t, "int"};
    }

public:
    void gerar(No* programa, const std::string& arquivo_saida = "saida.bril") {
        Programa* prog = (Programa*)programa;
        ListaClasses* lista = (ListaClasses*)prog->lista_classes;

        for (No* c_no : lista->elementos) {
            Classe* c = (Classe*)c_no;
            if (!c->features) continue;
            ListaFeatures* features = (ListaFeatures*)c->features;
            for (No* f_no : features->elementos) {
                if (Metodo* met = dynamic_cast<Metodo*>(f_no)) {
                    retorno_metodos[c->nome + "_" + met->nome] = mapear_tipo(met->tipo_retorno);
                }
            }
        }

        for (No* c_no : lista->elementos) {
            Classe* c = (Classe*)c_no;
            classe_atual = c->nome;
            if (!c->features) continue;

            ListaFeatures* features = (ListaFeatures*)c->features;
            for (No* f_no : features->elementos) {
                if (Metodo* met = dynamic_cast<Metodo*>(f_no)) {
                    bool eh_main = (c->nome == "Main" && met->nome == "main");
                    std::string tipo_ret = mapear_tipo(met->tipo_retorno);

                    corpo_out << "@" << c->nome << "_" << met->nome << "(self: ptr<int>";
                    if (!eh_main) {
                        corpo_out << ", ret_out: ptr<" << tipo_ret << ">";
                    }

                    enterScope();
                    if (ListaFormais* formals = dynamic_cast<ListaFormais*>(met->formals)) {
                        for (No* fm_no : formals->elementos) {
                            Formal* fm = (Formal*)fm_no;
                            std::string t_bril = mapear_tipo(fm->tipo);
                            std::string param_bril = "arg_" + fm->nome;
                            corpo_out << ", " << param_bril << ": " << t_bril;
                            addVar(fm->nome, param_bril, t_bril);
                        }
                    }
                    corpo_out << ") {\n";

                    ValorBril res = gerar_expressao(met->corpo);
                    if (!eh_main) {
                        corpo_out << "  store ret_out " << res.var << ";\n";
                    }
                    corpo_out << "}\n\n";
                    exitScope();
                }
            }
        }

        std::ofstream arquivo(arquivo_saida);
        emitir_runtime(arquivo);
        arquivo << corpo_out.str();

        arquivo << "@main {\n";
        arquivo << "  one: int = const 1;\n";
        arquivo << "  main_obj: ptr<int> = alloc one;\n";
        arquivo << "  call @Main_main main_obj;\n";
        arquivo << "  free main_obj;\n";
        arquivo << "}\n";
        arquivo.close();

        std::cout << "Codigo Bril gerado com sucesso em '" << arquivo_saida << "'!\n";
    }
};

#endif