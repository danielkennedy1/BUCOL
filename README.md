# ISE CS4455
### Compiler Theory Project
### Daniel Kennedy: 22340017

## Overview

This project is an implementation of the BUCOL programming language. 
BUCOL is a powerful, high-level programming language that is way better than C or even HTML.

## Build Instructions
go to the root directory of the project and run the following command:
```bash
make
```
(First time having a go at make, turns out the idea for it came from trouble Steve Johnson 
(guy who made Yacc) had with not compiling his code after fixing a bug.)

or, if you don't have GNU make installed (??) (insert Stallman rant here):
```bash
bison -d parser.y
flex lexer.l
gcc -o parser parser.tab.c lex.yy.c src/*.c src/*.h
```

## Usage
throw this in them there terminal:
```
./parser
```
and if you want to shove a file in there:
```
./parser < filename
```
(I have to do this differently because of ms PowerShell, but you can do it like this on Linux or Mac.
I'm not sure about Windows Command Prompt. I won't test it because I don't want to. I'm not your babysitter.)

## Features
You can do every important computer operation in BUCOL, such as:
 - declaring variables (as long as they're numbers and are 12 or less digits) 
    - you've to do this at the top of the file if you know what's good for you
 - assigning values to variables (again, they would want to be numbers)
 - adding numbers together
 - getting user input (as long as it's a number)
 - printing things to the screen (as long as they're numbers)
 - ending the program (if you're a quitter) 

## Project Structure
(irrelevant and intermediate files omitted for brevity)
```
root
│   lexer.l - The lexer file that defines the tokens
│   Makefile - The file that make uses to build the project
│   parser.exe - Final executable
│   parser.y - The parser file that defines the grammar and actions
│   README.md - You are here
│
├───programs/
│       invalid.bucol - Ill-formed BUCOL program (usage of undeclared variable)
│       valid.bucol - Well-formed BUCOL program
│
└───src/
        bucol.c - Implementation of the BUCOL language (utilizes the symbol table)
        bucol.h - Header file for built-in BUCOL functionality

        table.c - Implementation of the symbol table
        table.h - Header file for the symbol table
```
