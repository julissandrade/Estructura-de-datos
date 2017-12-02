#include "linked_list.h"
#include <stdlib.h>
#include <assert.h>

/* Inicializar la lista */
void listInitialize(List *l) {
    l->head = 0;                            /* Hacer head un puntero nulo */
    l->count = 0;
	                           /* Numero de elementos: 0 */
}

/* Esta la lista vacia? */
int listIsEmpty(List *l) {
    return l->count == 0;
} 

/* Tamano de la lista */
int listSize(List *l) {
    return l->count;
}

/* Devuelve un puntero al nodo con indice idx */
static Node* getNode(List *l, int idx) {
    assert(idx >= 0 && idx < l->count);     /* Indice valido */
    Node *ptr = l->head;                    /* Inicia recorrido desde head */
    int i;
    for (i = 0; i < idx; i++)
        ptr = ptr->next;
    return ptr;
}

/* Crear un nuevo nodo */
static Node* createNode(E item) {
    Node *newNode = malloc(sizeof(Node));
    newNode->item = item;
    newNode->codigo = 8080;
	newNode->next = 0;
    return newNode;
}

/* Valor del elemento en el indice idx */
E listGet(List *l, int idx) {
    Node *tmp = getNode(l, idx);
    printf("%d", tmp->codigo);
    return tmp->item; 
}

/* Agregar elemento al final */
void listAppend(List *l, E item) {
	
    listAdd(l, l->count, item);
}

/* Agregar elemento en posicion idx */
void listAdd(List *l, int idx, E item) {
    assert(idx >= 0 && idx <= l->count);    /* Indice valido */

    /* Crear el nuevo nodo */
    Node *newNode = createNode(item);

    /* Caso especial: agregar al principio */
    if (idx == 0) {
        newNode->next = l->head;
        l->head = newNode;
    /* Insertar en un indice especifico */
    } else {
        /* Encontrar nodo anterior al indice */
        Node *prev = getNode(l, idx - 1);
        newNode->next = prev->next;
        prev->next = newNode;
    }

    (l->count)++;                           /* Actualiza numero de nodos */
}

/* Esta item en la lista? */
int listContains(List *l, E item) {
    Node *current;                          /* Nodo actual */ 
    
    /* Recorrer la lista desde el primer nodo */
    for (current = l->head; current != 0; current = current->next)
        if (current->item  == item) return 1;

    return 0;
}

/* Remover el elemento en el indice idx */
E listRemove(List *l, int idx) {
    assert(!listIsEmpty(l));                /* Lista no vacia */
    assert(idx >= 0 && idx < l->count);     /* Posicion valida */
    E val;                                  /* Valor del nodo a borrar */
    Node *prev, *curr;                      /* Nodos anterior, actual */

    /* Caso especial: eliminar el primer elemento */
    if (idx == 0) {
        curr = l->head;
        l->head = curr->next;
    /* Eliminar nodo en un indice especifico */
    } else {
        prev = getNode(l, idx - 1);         /* Encontrar nodo anterior */
        curr = prev->next;                  /* Nodo actual */
        prev->next = curr->next;            /* prev apunta al nodo que sigue a curr */
    }

    val = curr->item;                       /* Copia valor a una variable */
    free(curr);                             /* Elimina el nodo */
    (l->count)--;                           /* Actualiza numero de elementos */
    return val;                             /* Devuelve el valor */
}

/* Remover la primera ocurrencia de item de la lista */
void listRemoveItem(List *l, E item) {
	/* Su codigo aqui */
} 

/* Elimina todos los elementos de una lista */
void listClear(List *l) {
	/* Su codigo aqui */
}

