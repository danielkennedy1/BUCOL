%{
#include<stdio.h>
extern int yylex();
extern int yyparse();
extern void yyerror(char *s);
%}

%token ENDSTMT BEGINING BODY END CAPACITY ID TO MOVE ADD INPUT PRINT INTLITERAL
%%

declaration: CAPACITY ID ENDSTMT
{
    printf("Declaration is valid!\n");
} 

%%

extern FILE *yyin;

int main() {
    do {
        yyparse();
    } while (!feof(yyin));
    return 0;
}

void yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
}
