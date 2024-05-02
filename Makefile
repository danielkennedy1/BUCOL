.RECIPEPREFIX = ;
.PHONY: all clean parser parser.tab.h lex.yy.c

SRCS = src/*.c

all: parser

parser: lex.yy.c parser.tab.c parser.tab.h
;   gcc -o $@ parser.tab.c lex.yy.c $(SRCS)

parser.tab.c parser.tab.h: parser.y src/bucol.h
;   bison -d parser.y

lex.yy.c: parser.tab.h src/bucol.h lexer.l
;   flex lexer.l

clean:
;   rm -f parser parser.tab.c parser.tab.h lex.yy.c
