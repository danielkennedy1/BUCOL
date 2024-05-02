// Variable struct, is a linked list
typedef struct Variable {
    char* identifier;
    int size;
    int value;
    struct Variable* next;
} Variable;

//lookup function
Variable* lookup(char* identifier);

//insert function
Variable* insert(char* identifier, int size);

//printTable function
void printTable();

//declareVariable function
void declareVariable(char* identifier, int size);

// Move the value of source_id to dest_id (dest_id = source_id)
void moveIDtoID(char* source_id, char* dest_id);

// Assigns the value of source_int to dest_id->value
void moveINTtoID(char* int_literal, char* dest_id);

// Adds the value of source_id to dest_id->value
void addIDtoID(char* source_id, char* dest_id);
