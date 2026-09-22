%{
    /* bibliotecas, função de erro*/
    #include <stdio.h>
    
    int yylex(); 
    void yyerror(const char *s); 
%}

%token CLASS INHERITS IF THEN ELSE FI WHILE LOOP POOL LET IN CASE OF ESAC NEW ISVOID NOT TRUE_CONST FALSE_CONST TYPEID OBJECTID INT_CONST STR_CONST ASSIGN LE DARROW

%%
/*Regras da Gramática */

programa: 
    lista_classes 
    ;

lista_classes:
    classe ';'
    | lista_classes classe ';'
    ;

classe:
    CLASS TYPEID '{' features '}'
    | CLASS TYPEID INHERITS TYPEID '{' features '}'
    ;

features:
    /*vazia*/
    | lista_features
    ;

lista_features:
    feature ';'
    | lista_features feature ';'
    ;

feature:
    OBJECTID ':' TYPEID
    | OBJECTID ':' TYPEID ASSIGN expr
    | OBJECTID '(' formals ')' ':' TYPEID '{' expr '}'
    ;

formals:
    /*vazia*/
    | lista_formals
    ;

lista_formals:
    formal
    | lista_formals ',' formal
    ;

formal:
    OBJECTID ':' TYPEID
    ;

expr:
    OBJECTID ASSIGN expr
    | expr '.' OBJECTID '(' exprs ')'
    | expr '@' TYPEID '.' OBJECTID '(' exprs ')'
    | OBJECTID '(' exprs ')'
    | IF expr THEN expr ELSE expr FI
    | WHILE expr LOOP expr POOL
    | '{' bloco_exprs '}'
    | LET lista_let IN expr
    | CASE expr OF lista_cases ESAC
    | NEW TYPEID
    | ISVOID expr
    | expr '+' expr
    | expr '-' expr
    | expr '*' expr
    | expr '/' expr
    | '~' expr
    | expr '<' expr
    | expr LE expr // LE = '<='
    | expr '=' expr
    | NOT expr
    | '(' expr ')'
    | OBJECTID
    | INT_CONST
    | STR_CONST
    | TRUE_CONST
    | FALSE_CONST
    ;

exprs:
    /*vazia*/
    | lista_exprs
    ;

lista_exprs:
    expr
    | lista_exprs ',' expr
    ;

bloco_exprs:
    expr ';'
    | bloco_exprs expr ';'
    ;

lista_let: /*permite varias inicializações */
    OBJECTID ':' TYPEID
    | OBJECTID ':' TYPEID ASSIGN expr
    | lista_let ',' OBJECTID ':' TYPEID
    | lista_let ',' OBJECTID ':' TYPEID ASSIGN expr
    ;

lista_cases:
    item_case
    | lista_cases item_case
    ;

item_case:
    OBJECTID ':' TYPEID DARROW expr ';'
    ;

%%

void yyerror(const char *s) {
    extern int yylineno;
    printf("Erro Sintatico na linha %d: %s\n", yylineno, s);
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

    if(yyparse() == 0) {
        printf("Analise sintatica concluida\n");
    }
    return 0;
}