%option case-insensitive
%option noyywrap
%{
#include "parser.tab.h" /* token definitions from the parser */
#include <ctype.h>
#include <string.h>
%}

CHAR [A-Za-z1-9-]

%%
[ \r\t\n]* ;

"." return(ENDSTMT);
";" return(SEP);

"BEGINING" return(BEGINING);
"BODY" return(BODY);
"END" return(END);

^X+ { yylval.size = strlen(yytext); return(CAPACITY); }

"TO" return(TO);
"MOVE" return(MOVE);
"ADD" return(ADD);
"INPUT" return(INPUT);
"PRINT" return(PRINT);

[A-WYZa-wyz]{CHAR}* |
[Xx]{CHAR}*[^Xx .";]{CHAR}* { yylval.str = strdup(yytext); return(ID); }

[0-9]+ { yylval.str = strdup(yytext); return(INTLITERAL); }
\"[^";.]*\" { yylval.str = strdup(yytext); return(STRINGLITERAL); }

. return(0);
%%
