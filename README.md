Compilador COOL com geração de código em BRIL





Caso necessário execução
 - win_bison -d cool.y
 - flex cool.l
 - g++ -std=c++17 cool.tab.c lex.yy.c -o compilador
 - .\compilador.exe teste.cl
