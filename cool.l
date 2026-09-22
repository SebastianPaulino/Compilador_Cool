%{
    #include <stdio.h>
    #include "cool.tab.h"
%}

%option noyywrap
%option yylineno

%x COMENTARIO_BLOCO

%%
[ \t\r\n]+ { /*nao faz nada so tira tab espaço quebra de linha*/ }
"--".* { /*tira comentarios*/ }
"(*" { BEGIN(COMENTARIO_BLOCO); }
<COMENTARIO_BLOCO>"*)" { BEGIN(INITIAL); }
<COMENTARIO_BLOCO>.|\n {/*ignora qualquer comentario ou quebra de linha dentro*/}


"class"  { return CLASS;}
"inherits"  { return INHERITS;}
"if"  { return IF;}
"then"  { return THEN;}
"else"  { return ELSE;} 
"fi"  { return FI;}
"while"  { return WHILE;}
"loop"  { return LOOP;}
"pool"  { return POOL;}
"let"  { return LET;}
"in"  { return IN;}
"case"  { return CASE;}
"of"  { return OF;}
"esac"  { return ESAC;}
"new"  { return NEW;}
"isvoid"  { return ISVOID;}
"not"  { return NOT;}
"true"  { return TRUE_CONST;}
"false"  { return FALSE_CONST;}

[A-Z][a-zA-Z0-9_]*  { return TYPEID;} //TypeID = nome de classe/tipo inicia maiuscula sequencia de letras digitos ou _
[a-z][a-zA-Z0-9_]*  { return OBJECTID;} //ObjectID = nome variavel/metodo inicia minuscula resto igual

[0-9]+  { return INT_CONST;} 
\"([^"\\\n]|\\.)*\"  { return STR_CONST;}

"<-"  { return ASSIGN;}
"<="  { return LE;}
"=>"  { return DARROW;}
"+"  { return '+';}
"-"  { return '-';}
"*"  { return '*';}
"/"  { return '/';}
"~"  { return '~';}
"<"  { return '<';}
"="  { return '=';}
"."  { return '.';}
":"  { return ':';}
";"  { return ';';}
","  { return ',';}
"{"  { return '{';}
"}"  { return '}';}
"("  { return '(';}
")"  { return ')';}
"@"  { return '@';}

.  { printf("Erro lexico na linha %d: caractere invalido '%s'\n", yylineno,yytext);}

%%