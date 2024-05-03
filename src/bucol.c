#include "bucol.h"
#include "table.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_INT_SIZE 12

bool declareVariable(char *identifier, int size) {
  if (lookup(identifier) != NULL) {
    printf("Error: variable %s already declared\n", identifier);
    return false;
  }
  if (size > MAX_INT_SIZE) {
    printf("Error: variable %s size %d exceeds maximum size %d\n", identifier,
           size, MAX_INT_SIZE);
    return false;
  }
  Variable *np = insert(identifier, size);
  if (np == NULL) {
    printf("Error: cannot insert variable %s\n", identifier);
    return false;
  }
  return true;
}

bool moveIDtoID(char *source_id, char *dest_id) {
  Variable *source = lookup(source_id);
  Variable *dest = lookup(dest_id);

  // Declaration guards
  if (source == NULL) {
    printf("Error: variable %s not declared\n", source_id);
    return false;
  }
  if (dest == NULL) {
    printf("Error: variable %s not declared\n", dest_id);
    return false;
  }

  // Size check
  if (source->size > dest->size) {
    printf("Error: cannot move from %s (size %d) to %s (size %d)\n", source_id,
           source->size, dest_id, dest->size);
    return false;
  }

  // Move
  dest->value = source->value;
  return true;
}

bool moveINTtoID(char *int_literal, char *dest_id) {
    Variable *dest = lookup(dest_id);
    
    // Declaration guards
    if (dest == NULL) {
        printf("Error: variable %s not declared\n", dest_id);
        return false;
    }
    
    // size check
    int int_literal_size = strlen(int_literal);
    if (int_literal_size > dest->size) {
        printf("Error: cannot move %s (size %d) to %s (size %d)\n", int_literal, int_literal_size, dest_id, dest->size);
        return false;
    }
    
    // Assign 
    dest->value = atoi(int_literal);
    return true;
}

bool addIDtoID(char *source_id, char *dest_id) {
    Variable *source = lookup(source_id);
    Variable *dest = lookup(dest_id);
    
    // Declaration guards
    if (source == NULL) {
        printf("Error: variable %s not declared\n", source_id);
        return false;
    }
    if (dest == NULL) {
        printf("Error: variable %s not declared\n", dest_id);
        return false;
    }

    // Size check
    int new_value = source->value + dest->value;
    char new_value_str[MAX_INT_SIZE];
    
    sprintf(new_value_str, "%d", new_value);

    if (strlen(new_value_str) > dest->size) {
        printf("Error: cannot assign %s (size %d) to %s (size %d)\n", new_value_str, (int) strlen(new_value_str), dest_id, dest->size);
        return false;
    }
    
    // Add
    dest->value = new_value;
    return true;
}

bool addINTtoID(char *int_literal, char *dest_id) {
    Variable *dest = lookup(dest_id);
    
    // Declaration guard
    if (dest == NULL) {
        printf("Error: variable %s not declared\n", dest_id);
        return false;
    }

    // size check
    int int_literal_size = strlen(int_literal);
    if (int_literal_size > dest->size) {
        printf("Error: cannot add %s (size %d) to %s (size %d)\n", int_literal, int_literal_size, dest_id, dest->size);
        return false;
    }

    int new_value = atoi(int_literal) + dest->value;
    char new_value_str[MAX_INT_SIZE];
    
    sprintf(new_value_str, "%d", new_value);

    if (strlen(new_value_str) > dest->size) {
        printf("Error: cannot assign new value %s (size %d) to %s (size %d)\n", new_value_str, (int) strlen(new_value_str), dest_id, dest->size);
        return false;
    }
    
    // Add
    dest->value = new_value;
    return true;
}

bool checkIsDeclared(char *id) {
    if (lookup(id) == NULL) {
        printf("Error: variable %s not declared\n", id);
        return false;
    }
    return true;
}
