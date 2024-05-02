.RECIPEPREFIX = ;
.PHONY: all clean parser parser.tab.h lex.yy.c

SRCS = helpers.c

all: parser

parser: lex.yy.c parser.tab.c parser.tab.h
;   gcc -o $@ parser.tab.c lex.yy.c $(SRCS)

parser.tab.c parser.tab.h: parser.y helpers.h
;   bison -d parser.y

lex.yy.c: parser.tab.h helpers.h lexer.l
;   flex lexer.l

clean:
;   rm -f parser parser.tab.c parser.tab.h lex.yy.c
