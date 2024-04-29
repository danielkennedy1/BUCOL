%{
/* this demonstrates (very) simple recognition of a sentence */
#include "parser.tab.h" /* token definitions from the parser */
%}

%%
[\t ]+ /* ignore whitespace */ ;
"cat" |
"dog" |
"mouse" return(NOUN);
"ate" |
"hit" return(VERB);
"the" |
"a" return(ARTICLE);
[a-zA-Z]+ |
. return(0);
%%

int yywrap() {
    return 1;
}
