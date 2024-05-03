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

%token ENDSTMT BEGINING BODY END TO MOVE ADD INPUT PRINT SEP
%%

// program: BEGINING DECLARATIONS BODY STATEMENTS END

program: statement | program statement

statement: assignment | addition | declaration | input

input: INPUT inputlist ENDSTMT
{
    printf("Input syntax is valid!\n");
}

inputlist: ID SEP inputlist | ID
{
    checkIsDeclared($1);
    // MAYBE: take values in here from stdin
}

declaration: CAPACITY ID ENDSTMT
{
    printf("Declaration syntax is valid!\n");
    declareVariable($2, $1);
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
    addINTtoID($2, $4);
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
