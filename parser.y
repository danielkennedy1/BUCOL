%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "src/bucol.h"

extern int yylex();
extern int yyparse();
extern void yyerror(char *s);

%}

%union {
    int size;
    char *str; // For ID
}

%token <str> ID INTLITERAL
%token <size> CAPACITY

%token ENDSTMT BEGINING BODY END TO MOVE ADD INPUT PRINT
%%

// program: BEGINING DECLARATIONS BODY STATEMENTS END

program: statement | program statement

statement: assignment | addition | declaration 

declaration: CAPACITY ID ENDSTMT
{
    printf("Declaration syntax is valid!\n");
    declareVariable($2, $1);
    printTable();
} 

assignment: MOVE ID TO ID ENDSTMT
{
    printf("Assignment syntax is valid!\n");
    moveIDtoID($2, $4);
}

assignment: MOVE INTLITERAL TO ID ENDSTMT
{
    printf("Assignment syntax is valid!\n");
    moveINTtoID($2, $4);
}

addition: ADD INTLITERAL TO ID ENDSTMT
{
    printf("Addition syntax is valid!\n");
}

addition: ADD ID TO ID ENDSTMT
{
    printf("Addition syntax is valid!\n");
    addIDtoID($2, $4);
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
