#include "bucol.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_SIZE 101
#define MAX_INT_SIZE 12

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

    } // if the name matches

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

void declareVariable(char *identifier, int size) {
  if (lookup(identifier) != NULL) {
    printf("Error: variable %s already declared\n", identifier);
    return;
  }
  if (size > MAX_INT_SIZE) {
    printf("Error: variable %s size %d exceeds maximum size %d\n", identifier,
           size, MAX_INT_SIZE);
    return;
  }
  Variable *np = insert(identifier, size);
  if (np == NULL) {
    printf("Error: cannot insert variable %s\n", identifier);
  }
}

void moveIDtoID(char *source_id, char *dest_id) {
  Variable *source = lookup(source_id);
  Variable *dest = lookup(dest_id);

  // Declaration guards
  if (source == NULL) {
    printf("Error: variable %s not declared\n", source_id);
    return;
  }
  if (dest == NULL) {
    printf("Error: variable %s not declared\n", dest_id);
    return;
  }

  // Size check
  if (source->size > dest->size) {
    printf("Error: cannot move from %s (size %d) to %s (size %d)\n", source_id,
           source->size, dest_id, dest->size);
    return;
  }

  // Move
  printf("Moving value %d from %s to %s\n", source->value, source->identifier,
         dest->identifier);
  dest->value = source->value;
}

void moveINTtoID(char *int_literal, char *dest_id) {
    Variable *dest = lookup(dest_id);
    
    // Declaration guards
    if (dest == NULL) {
        printf("Error: variable %s not declared\n", dest_id);
        return;
    }
    
    // size check
    int int_literal_size = strlen(int_literal);
    if (int_literal_size > dest->size) {
        printf("Error: cannot move %s (size %d) to %s (size %d)\n", int_literal, int_literal_size, dest_id, dest->size);
        return;
    }
    
    // Assign 
    printf("Assigning value %s to %s\n", int_literal, dest_id);
    dest->value = atoi(int_literal);
}

void addIDtoID(char *source_id, char *dest_id) {
    Variable *source = lookup(source_id);
    Variable *dest = lookup(dest_id);
    
    // Declaration guards
    if (source == NULL) {
        printf("Error: variable %s not declared\n", source_id);
        return;
    }
    if (dest == NULL) {
        printf("Error: variable %s not declared\n", dest_id);
        return;
    }

    // Size check
    int new_value = source->value + dest->value;
    char new_value_str[MAX_INT_SIZE];
    
    sprintf(new_value_str, "%d", new_value);

    if (strlen(new_value_str) > dest->size) {
        printf("Error: cannot assign %s (size %d) to %s (size %d)\n", new_value_str, (int) strlen(new_value_str), dest_id, dest->size);
        return;
    }
    
    // Add
    printf("Adding value %d from %s to %s, new value: %d\n", source->value, source->identifier, dest->identifier, new_value);
    dest->value = new_value;
}
