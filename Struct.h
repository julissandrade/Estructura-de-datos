                         /* Lista de enteros */

typedef struct{
    int item;
    int codComida;
    int cantidad;
    
    struct Node *next;
    struct Node *ant;
} Node;                                 /* Un nodo */

Node *primero=NULL;
Node *ultimo=NULL;

void agregar(Node *pedido);
void listar();
void limpiar();
void prioridad(int position,Node *pedido);

