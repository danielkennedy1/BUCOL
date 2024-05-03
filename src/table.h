// Variable struct, is a linked list in case of hash collision
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

//printTable debug function
void printTable();
