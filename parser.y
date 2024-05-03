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

%token <str> ID INTLITERAL STRINGLITERAL
%token <size> CAPACITY

%token ENDSTMT BEGINING BODY END TO MOVE ADD INPUT PRINT SEP
%%

program: begining declarations body statements end {
    printf("Program syntax is valid!\n");
} 

declarations: declaration | declarations declaration {
    // This means there has to be at least one declaration
}

begining: BEGINING ENDSTMT

body: BODY ENDSTMT

end: END ENDSTMT

statements: statement | statements statement {
    // This means there has to be at least one statement
}

statement: assignment | addition | declaration | input | print 

declaration: CAPACITY ID ENDSTMT
{
    printf("Declaration of variable %s with capacity %d\n", $2, $1);
    declareVariable($2, $1);
} 

assignment: MOVE ID TO ID ENDSTMT
{
    moveIDtoID($2, $4);
}

assignment: MOVE INTLITERAL TO ID ENDSTMT
{
    moveINTtoID($2, $4);
}

addition: ADD INTLITERAL TO ID ENDSTMT
{
    addINTtoID($2, $4);
}

addition: ADD ID TO ID ENDSTMT
{
    addIDtoID($2, $4);
}

input: INPUT inputlist ENDSTMT

inputlist: var SEP inputlist | var 

print: PRINT printlist ENDSTMT

printlist: var | STRINGLITERAL | var SEP printlist | STRINGLITERAL SEP printlist

var: ID {
   checkIsDeclared($1);
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
