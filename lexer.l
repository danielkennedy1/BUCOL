%option case-insensitive
%option debug

%{
#include "parser.tab.h" /* token definitions from the parser */
#include <ctype.h>
%}

%%
[ \t\n] ;

"." return(ENDSTMT);

"BEGINING" return(BEGINING);
"BODY" return(BODY);
"END" return(END);

X+ return(CAPACITY);

"TO" return(TO);
"MOVE" return(MOVE);
"ADD" return(ADD);
"INPUT" return(INPUT);
"PRINT" return(PRINT);

[A-Za-z][^ .]* return(ID);

[0-9]+ return(INTLITERAL);


. return(0);
%%

int yywrap() {
    return 1;
}
