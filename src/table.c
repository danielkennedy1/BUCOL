#include "table.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_SIZE 101
static Variable *variableTable[HASH_SIZE];

// Hash function: form hash value for string s
unsigned hash(char *s) {
  unsigned hashval;
  for (hashval = 0; *s != '\0'; s++)
    hashval = *s + 31 * hashval;
  return hashval % HASH_SIZE;
}

Variable *lookup(char *identifier) {
  Variable *np;
  for (np = variableTable[hash(identifier)]; np != NULL;
       np = np->next) // Traverse the linked list
    if (strcmp(identifier, np->identifier) == 0) {
      printf("Found: %s at hash %d\n", identifier, hash(identifier));
      return np; // Found

    }

  return NULL; // Not found
}

Variable *insert(char *identifier, int size) {
  unsigned hashval;
  Variable *np;

  if ((np = lookup(identifier)) == NULL) { // Not found
    np = (Variable *)malloc(sizeof(*np));

    if (np == NULL || (np->identifier = strdup(identifier)) == NULL)
      return NULL;

    hashval = hash(identifier);
    np->next = variableTable[hashval];
    variableTable[hashval] = np;
  }
  np->size = size;

  return np;
}

void printTable() {
  for (int i = 0; i < HASH_SIZE; i++) {
    Variable *np;
    for (np = variableTable[i]; np != NULL; np = np->next) {
      if (np == NULL) {
        continue;
      }
      printf("Variable: hash: %d, identifier: %s, size: %d, value: %d\n",
              i, np->identifier, np->size, np->value);
    }
  }
}

