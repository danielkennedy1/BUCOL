/* Limited sentence recognizer */
%{
#include<stdio.h>
extern int yylex();
extern int yyparse();
extern void yyerror(char *s);
%}

%token NOUN VERB ARTICLE

%%

sentence: ARTICLE NOUN VERB ARTICLE NOUN
{
    printf("Is a valid Sentence!\n");
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
