%{
    /* bibliotecas, função de erro*/
    #include <stdio.h>
    #include <stdlib.h>
    #include <string>
    #include "arv.h"
    #include "semantico.h"

    int yylex(); 
    void yyerror(const char *s); 

    Programa* raiz_arv = nullptr; /* ponteiro para a raiz da arvore de sintaxe abstrata */
%}

%union {
    char* texto;
    No* no_arvore;
}

%token <texto> TYPEID OBJECTID INT_CONST STR_CONST
%token CLASS INHERITS IF THEN ELSE FI WHILE LOOP POOL LET IN CASE OF ESAC NEW ISVOID NOT TRUE_CONST FALSE_CONST ASSIGN LE DARROW

%right ASSIGN
%left NOT
%nonassoc LE '<' '='
%left '+' '-'
%left '*' '/'
%left ISVOID
%left '~'
%left '@'
%left '.'

%type <no_arvore> programa lista_classes classe features lista_features feature formals lista_formals formal expr exprs lista_exprs bloco_exprs lista_let lista_cases item_case

%%
/*Regras da Gramática */

programa: 
    lista_classes
    {
        raiz_arv = new Programa($1);
        $$ = raiz_arv;
    }
    ;

lista_classes:
    classe ';'
    {
        /* encontrou a primeira classe = cria uma nova lista vazia e adiciona ela */
        ListaClasses* l = new ListaClasses();
        l->adicionar($1);
        $$ = l;
    }
    | lista_classes classe ';'
    {
        /* ja tem uma lista $1 = só adiciona a nova classe $2 nela */
        ((ListaClasses*)$1)->adicionar($2);
        $$ = $1;
    }
    ;

classe:
    CLASS TYPEID '{' features '}'
    {
        /* $2 é o TYPEID (nome da classe) $4 são as features herda de object por padrao. */
        $$ = new Classe($2, "Object", $4);
    }
    | CLASS TYPEID INHERITS TYPEID '{' features '}'
    {
        /* $2 é o TYPEID (nome da classe) $4 é o TYPEID da classe pai $6 são as features */
        $$ = new Classe($2, $4, $6);
    }
    ;

features:
    /*vazia*/
    {
        /* se a classe for vazia = retorna uma lista vazia */
        $$ = new ListaFeatures();
    }
    | lista_features
    {
        $$ = $1;
    }
    ;

lista_features:
    feature ';'
    {
        /* encontrou a primeira feature = cria uma nova lista vazia e adiciona ela */
        ListaFeatures* l = new ListaFeatures();
        l->adicionar($1);
        $$ = l;
    }
    | lista_features feature ';'
    {
        /* ja tem uma lista $1 = só adiciona a nova feature $2 nela */
        ((ListaFeatures*)$1)->adicionar($2);
        $$ = $1;
    }
    ;

feature:
    OBJECTID ':' TYPEID
    {
        $$ = new Atributo($1, $3, NULL);
    }
    | OBJECTID ':' TYPEID ASSIGN expr
    {
        $$ = new Atributo($1, $3, $5);
    }
    | OBJECTID '(' formals ')' ':' TYPEID '{' expr '}'
    {
        /* $1 nome do metodo, $3 parametros, $6 é o tipo de retorno, $8 é o corpo do metodo */
        $$ = new Metodo($1, $3, $6, $8);
    }
    ;

formals:
    /*vazia*/
    {
        $$ = new ListaFormais();
    }
    | lista_formals
    {
        $$ = $1;
    }
    ;

lista_formals:
    formal
    {
        /* encontrou o primeiro formal = cria uma nova lista vazia e adiciona ele */
        ListaFormais* l = new ListaFormais();
        l->adicionar($1);
        $$ = l;
    }
    | lista_formals ',' formal
    {
        /* ja tem uma lista $1 = só adiciona o novo formal $3 nela */
        ((ListaFormais*)$1)->adicionar($3);
        $$ = $1;
    }
    ;

formal:
    OBJECTID ':' TYPEID
    {
        $$ = new Formal($1, $3);
    }
    ;

expr:
    OBJECTID ASSIGN expr
    {    $$ = new Atribuicao($1, $3);  }

    | expr '.' OBJECTID '(' exprs ')'
    /* $1(objeto), $3(nome do metodo), $5(argumentos) */
    {    $$ = new Chamada($1, $3, $5);  }

    | expr '@' TYPEID '.' OBJECTID '(' exprs ')'
    /* $1(objeto), $3(tipo do metodo), $5(nome do metodo), $7(argumentos) */
    {    $$ = new ChamadaEstatica($1, $3, $5, $7);  }

    | OBJECTID '(' exprs ')'
    /* chamada de metodo na propria classe */
    {    $$ = new Chamada("self", $1, $3);  }

    | IF expr THEN expr ELSE expr FI
    {    $$ = new If($2, $4, $6);  }

    | WHILE expr LOOP expr POOL
    {    $$ = new While($2, $4);  }

    | '{' bloco_exprs '}'
    {    $$ = new Bloco($2);  }

    | LET lista_let IN expr
    {    $$ = new Let($2, $4);  }

    | CASE expr OF lista_cases ESAC
    {    $$ = new Case($2, $4);  }

    | NEW TYPEID
    {    $$ = new New($2);  }

    | ISVOID expr
    {    $$ = new IsVoid($2);  }

    | expr '+' expr
    {    $$ = new Plus($1, $3);  }

    | expr '-' expr
    {    $$ = new Minus($1, $3);  }

    | expr '*' expr
    {    $$ = new Mult($1, $3);  }

    | expr '/' expr
    {    $$ = new Divide($1, $3);  }

    | '~' expr
    {    $$ = new Negacao($2);  }

    | expr '<' expr
    {    $$ = new MenorQue($1, $3);  }

    | expr LE expr // LE = '<='
    {    $$ = new MenorIgual($1, $3);  }

    | expr '=' expr
    {    $$ = new Igual($1, $3);  }

    | NOT expr
    {    $$ = new Not($2);  }

    | '(' expr ')'
    {    $$ = $2;  }

    | OBJECTID
    {    $$ = new ObjectID($1);  }

    | INT_CONST
    {    $$ = new Int(atoi($1));  }

    | STR_CONST
    {    $$ = new String($1);  }

    | TRUE_CONST
    {    $$ = new Bool(true);  }

    | FALSE_CONST
    {    $$ = new Bool(false);  }
    ;

exprs:
    /*vazia*/
    {
        $$ = new ListaExprs();
    }
    | lista_exprs
    {
        $$ = $1;
    }
    ;

lista_exprs:
    expr
    {
        /* encontrou a primeira expressao = cria uma nova lista vazia e adiciona ela */
        ListaExprs* l = new ListaExprs();
        l->adicionar($1);
        $$ = l;
    }
    | lista_exprs ',' expr
    {
        /* ja tem uma lista $1 = só adiciona a nova expressao $3 nela */
        ((ListaExprs*)$1)->adicionar($3);
        $$ = $1;
    }
    ;

bloco_exprs:
    expr ';'
    {
        /* encontrou a primeira expressao = cria uma nova lista vazia e adiciona ela */
        BlocoExprs* l = new BlocoExprs();
        l->adicionar($1);
        $$ = l;
    }
    | bloco_exprs expr ';'
    {
        /* ja tem uma lista $1 = só adiciona a nova expressao $2 nela */
        ((BlocoExprs*)$1)->adicionar($2);
        $$ = $1;
    }
    ;

lista_let: /*permite varias inicializações */
    OBJECTID ':' TYPEID
    {
        ListaLet* l = new ListaLet();
        l->adicionar(new LetItem($1, $3, NULL));
        $$ = l;
    }

    | OBJECTID ':' TYPEID ASSIGN expr
    {
        ListaLet* l = new ListaLet();
        l->adicionar(new LetItem($1, $3, $5));
        $$ = l;
    }

    | lista_let ',' OBJECTID ':' TYPEID
    {
        ((ListaLet*)$1)->adicionar(new LetItem($3, $5, NULL));
        $$ = $1;
    }

    | lista_let ',' OBJECTID ':' TYPEID ASSIGN expr
    {
        ((ListaLet*)$1)->adicionar(new LetItem($3, $5, $7));
        $$ = $1;
    }
    ;

lista_cases:
    item_case
    {
        /* encontrou o primeiro case = cria uma nova lista vazia e adiciona ele */
        ListaCase* l = new ListaCase();
        l->adicionar($1);
        $$ = l;
    }
    | lista_cases item_case
    {
        /* ja tem uma lista $1 = só adiciona o novo case $2 nela */
        ((ListaCase*)$1)->adicionar($2);
        $$ = $1;
    }
    ;

item_case:
    OBJECTID ':' TYPEID DARROW expr ';'
    {
        /* $1 = id, $3 = tipo, $5 = corpo do case */
        $$ = new CaseItem($1, $3, $5);
    }
    ;

%%

void yyerror(const char *s) {
    extern int yylineno;
    printf("Erro sintatico na linha %d: %s\n", yylineno, s);
}

int main(int argc, char **argv) {
    extern FILE *yyin;
    
    if (argc > 1) {
        FILE *arquivo = fopen(argv[1], "r");
        if (!arquivo) {
            printf("Erro ao abrir o arquivo\n");
            return 1;
        }
        yyin = arquivo;
    }

    printf("Iniciando analise sintatica...\n");

    if(yyparse() == 0) {
        printf("Analise sintatica concluida com sucesso!\n\n");
        printf("=== ARVORE SINTATICA ABSTRATA (AST) ===\n");
        if (raiz_arv){        
            raiz_arv->print(0);  // Imprime a árvore de sintaxe abstrata

            printf("\n=== ANALISE SEMANTICA ===\n");
            analisadorSemantico semantico;
            semantico.construir_grafo_classes(raiz_arv);
            semantico.verificar_classes(raiz_arv);

            if(semantico.erroSemantico) {
                printf("Erros semanticos encontrados.\n");
            } else {
                printf("Analise semantica concluida com sucesso!\n");
            }
        } else {
            printf("A arvore de sintaxe abstrata esta vazia.\n");
        }
    } else {
        printf("Erro na analise sintatica.\n");
    }

    return 0;
}