.RECIPEPREFIX = ;
.PHONY: all clean parser parser.tab.h lex.yy.c

all: parser

parser: lex.yy.c parser.tab.c parser.tab.h
;   gcc -o $@ parser.tab.c lex.yy.c

parser.tab.c parser.tab.h: parser.y
;   bison -d parser.y

lex.yy.c: parser.tab.h
;   flex lexer.l

clean:
;   rm -f parser parser.tab.c parser.tab.h lex.yy.c
