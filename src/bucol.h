//declareVariable function
void declareVariable(char* identifier, int size);

// Move the value of source_id to dest_id (dest_id = source_id)
void moveIDtoID(char* source_id, char* dest_id);

// Assigns the value of source_int to dest_id->value
void moveINTtoID(char* int_literal, char* dest_id);

// Adds the value of source_id to dest_id->value
void addIDtoID(char* source_id, char* dest_id);

// Adds the value of source_int to dest_id->value
void addINTtoID(char* int_literal, char* dest_id);

// checks if id is declared
void checkIsDeclared(char* id);
