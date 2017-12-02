#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef int E;                         /* Lista de enteros */

typedef struct node {
    E item;
    E codigo;
    
    
    struct node *next;
} Node;                                 /* Un nodo */

typedef struct {
    Node *head;
    int count;
    
} List;                                 /* Una lista */

void listInitialize(List *l);           /* Inicializar la lista */
int listIsEmpty(List *l);               /* Esta la lista vacia? */
int listSize(List *l);                  /* Tamano de la lista */
E listGet(List *l, int idx);            /* Valor del elemento en el indice idx */
void listAppend(List *l, E item);       /* Agregar elemento al final */
void listAdd(List *l, int idx, E item); /* Agregar elemento en indice idx */
int listContains(List *l, E item);      /* Esta item en la lista? */
E listRemove(List *l, int idx);         /* Remover el elemento en el indice idx */
void listRemoveItem(List *l, E item);   /* Remover la primera ocurrencia de item de la lista */
void listClear(List *l);                /* Elimina todos los elementos de una lista */

#endif /* LINKED_LIST_H */


