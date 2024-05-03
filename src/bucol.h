#include <stdbool.h>

// Declare a variable with a given identifier and size
bool declareVariable(char* identifier, int size);

// Move the value of source_id to dest_id (dest_id = source_id)
bool moveIDtoID(char* source_id, char* dest_id);

// Assign the value of source_int to dest_id->value
bool moveINTtoID(char* int_literal, char* dest_id);

// Add the value of source_id to dest_id->value
bool addIDtoID(char* source_id, char* dest_id);

// Add the value of source_int to dest_id->value
bool addINTtoID(char* int_literal, char* dest_id);

// Check if id is declared
bool checkIsDeclared(char* id);
