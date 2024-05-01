%option case-insensitive
%option debug

%{
#include "parser.tab.h" /* token definitions from the parser */
#include <ctype.h>
%}

%%
[ \r\n\t]* ;

"." return(ENDSTMT);

"BEGINING" return(BEGINING);
"BODY" return(BODY);
"END" return(END);

^X+ return(CAPACITY);

"TO" return(TO);
"MOVE" return(MOVE);
"ADD" return(ADD);
"INPUT" return(INPUT);
"PRINT" return(PRINT);

[A-WYZa-wyz][A-Za-z1-9-]* |
[Xx][A-Za-z1-9-]*[^Xx .][A-Za-z1-9-]* return(ID);

[0-9]+ return(INTLITERAL);


. return(0);
%%

int yywrap() {
    return 1;
}
