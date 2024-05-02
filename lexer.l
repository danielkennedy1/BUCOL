%option case-insensitive
%option noyywrap
%{
#include "parser.tab.h" /* token definitions from the parser */
#include <ctype.h>

    //%option debug
%}

CHAR [A-Za-z1-9-]

%%
[ \r\t]* ;

"." return(ENDSTMT);

"BEGINING." return(BEGINING);
"BODY." return(BODY);
"END." return(END);

^X+ return(CAPACITY);

"TO" return(TO);
"MOVE" return(MOVE);
"ADD" return(ADD);
"INPUT" return(INPUT);
"PRINT" return(PRINT);

[A-WYZa-wyz]{CHAR}* |
[Xx]{CHAR}*[^Xx .]{CHAR}* return(ID);

[0-9]+ return(INTLITERAL);


. return(0);
%%
