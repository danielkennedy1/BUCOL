// Variable struct, is a linked list
typedef struct Variable {
    char* identifier;
    int size;
    struct Variable* next;
} Variable;

//lookup function
Variable* lookup(char* identifier);

//insert function
Variable* insert(char* identifier, int size);

//printTable function
void printTable();
