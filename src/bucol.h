#include <stdbool.h>
//declareVariable function
bool declareVariable(char* identifier, int size);

// Move the value of source_id to dest_id (dest_id = source_id)
bool moveIDtoID(char* source_id, char* dest_id);

// Assigns the value of source_int to dest_id->value
bool moveINTtoID(char* int_literal, char* dest_id);

// Adds the value of source_id to dest_id->value
bool addIDtoID(char* source_id, char* dest_id);

// Adds the value of source_int to dest_id->value
bool addINTtoID(char* int_literal, char* dest_id);

// checks if id is declared
bool checkIsDeclared(char* id);
