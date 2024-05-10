# ISE CS4455
### Compiler Theory Project
### Daniel Kennedy: 22340017

## Overview

This project is an implementation of the BUCOL programming language. 

## Build Instructions
Go to the root directory of the project and run the following command:
```bash
make
```

Or, if you don't have GNU make installed:

```bash
bison -d parser.y
flex lexer.l
gcc -o parser parser.tab.c lex.yy.c src/*
```

## Usage
The above will create an executable called `parser`. You can run it by typing:
```
./parser
```

And then typing your BUCOL code into the terminal. 

You can also run it with a file as input like so:

```
./parser < filename
```
(Note that this step can be different depending on your OS and shell)

## Features
 - Variable declaration (Integers only, 12 or less digits): `XXX myNumber.`
    - Checks for previous declaration, and invalid names (xx, or .a;, etc.)

 - Variable assignmment: `MOVE 5 TO myNumber.`
    - Checks for declaration, and size validity (if a is size 2 [`XX a.`], then MOVE 1234 TO a. is invalid)
    - Equally, if b is size 3 [`XXX b.`], then `MOVE b TO a.` is invalid

 - Literal to variable addition and variable to variable addition: `ADD 5 TO myNumber.` `ADD myNumber TO myNumber.`
    - Checks for declaration, and size validity same as MOVE done on the addition result before assignment

 - User input statements: `INPUT myNumber1; myNumber2.`
    - Checks for declaration, arbitrary size of list > 1

 - Print statements: `PRINT myNumber1; myNumber2; "String literals also";.`
    - Checks for declaration, arbitrary size of list > 1 same as INPUT

Note: The parser classifies programs that fail any of the above static checks as invalid, so the program may still be syntactically correct, but in this case the parser will return that it is "not well-formed."

## Project Structure
(irrelevant and intermediate files omitted for brevity)
```
root
│   lexer.l - The lexer file that defines the tokens
│   Makefile - The file that make uses to build the project
│   parser.y - The parser file that defines the grammar and actions
│   README.md - You are here
│
├───programs/
│       invalid.bucol - Ill-formed BUCOL program (usage of undeclared variable)
│       valid.bucol - Well-formed BUCOL program
│
└───src/
        bucol.c - Implementation of the BUCOL language for parser actions (utilizes the symbol table)
        bucol.h - Header file for built-in BUCOL functionality

        table.c - Implementation of the symbol table
        table.h - Header file for the symbol table
```
