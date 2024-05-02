%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "helpers.h"

extern int yylex();
extern int yyparse();
extern void yyerror(char *s);

%}

%union {
    int size;
    char *str; // For ID
}

%token <str> ID
%token <size> CAPACITY

%token ENDSTMT BEGINING BODY END TO MOVE ADD INPUT PRINT INTLITERAL
%%

// program: BEGINING DECLARATIONS BODY STATEMENTS END

program: statement | program statement

statement: assignment | addition | declaration 

declaration: CAPACITY ID ENDSTMT
{
    printf("Declaration syntax is valid!\n");
    insert($2, $1);
    printTable();
} 

// TODO: Add size checking for assignment, so store the size of the ID in the symbol table

assignment: MOVE ID TO ID ENDSTMT
{
    printf("Assignment syntax is valid!\n");
}

assignment: MOVE INTLITERAL TO ID ENDSTMT
{
    printf("Assignment syntax is valid!\n");
}

addition: ADD INTLITERAL TO ID ENDSTMT
{
    printf("Addition syntax is valid!\n");
}

addition: ADD ID TO ID ENDSTMT
{
    printf("Addition syntax is valid!\n");
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
