#include "linked_list.h"
#include <stdio.h>

void imprimirLista(List *l) {
    int i;
    for (i = 0; i < listSize(l); i++)
        printf("%d ", listGet(l, i));
        printf("%d ", listGet(l, i));
    printf("\n");
}

int validarPosicion(List *l, int opcion, int posicion) {
    /* Agregar en posicion especificada */
    if ((opcion == 3) && (posicion < 0 || posicion > listSize(l))) {
        printf("Posicion %d no valida\n", posicion);
        return 0;
    /* Obtener o remover elemento de posicion especificada */
    } else if ((opcion == 5 || opcion == 7) && (posicion < 0 || posicion >= listSize(l))) {
        printf("Posicion %d no valida\n", posicion);
        return 0;
    } else {
        return 1;
    }
}


int main(int argc, char **argv) {
    List lst;
    int eleccion, valor, posicion;
    listInitialize(&lst);
    while (1) {
        printf("Menu de operaciones de listas\n");
        printf("\t1- Tamano de la lista\n");
        printf("\t2- Agregar al final\n");
        printf("\t3- Agregar en posicion especifica\n");
        printf("\t4- Comprobar si la lista esta vacia\n");
        printf("\t5- Obtener elemento en una posicion\n");
        printf("\t6- Verificar si la lista contiene un elemento\n");
        printf("\t7- Remover elemento en posicion\n");
        printf("\t8- Remover elemento con valor\n");
        printf("\t9- Limpiar la lista\n");
        printf("\t0- Salir\n");

        /* Obtiene entrada del usuario */
        printf("Su eleccion: ");
        scanf("%d", &eleccion);

        if (eleccion == 0) break;

        switch(eleccion) {
            case 1:
                printf("Tamano = %d\n", listSize(&lst));
                break;
            case 2:
            case 3:
                printf("Lista anterior: ");
                imprimirLista(&lst);
                printf("Valor: ");
                scanf("%d", &valor);
                if (eleccion == 2) listAppend(&lst, valor);
                else {
                    printf("Posicion: ");
                    scanf("%d", &posicion);
                    if(validarPosicion(&lst, 3, posicion)) listAdd(&lst, posicion, valor);
                }
                printf("Lista nueva: ");
                imprimirLista(&lst);
                break;
            case 4:
                printf("Lista%svacia\n", listIsEmpty(&lst) ? " " : " no ");
                break;
            case 5:
                printf("Posicion: ");
                scanf("%d", &posicion);
                if (validarPosicion(&lst, 5, posicion))
                    printf("Valor: %d\n", listGet(&lst, posicion));
                break;
            case 6:
                printf("Valor: ");
                scanf("%d", &valor);
                printf("El elemento %d%sesta en la lista\n", valor, listContains(&lst, valor) ? " " : " no ");
                break;
            case 7:
                printf("Lista anterior: ");
                imprimirLista(&lst);
                printf("Posicion: ");
                scanf("%d", &posicion);
                if (validarPosicion(&lst, 7, posicion)) listRemove(&lst, posicion);
                printf("Lista nueva   : ");
                imprimirLista(&lst);
                break;
            case 8:
                printf("Lista anterior: ");
                imprimirLista(&lst);
                printf("Valor: ");
                scanf("%d", &valor);
                listRemoveItem(&lst, valor);
                printf("Lista nueva: ");
                imprimirLista(&lst);
                break;
            case 9:
                printf("Lista anterior: ");
                imprimirLista(&lst);
                listClear(&lst);
                printf("Lista nueva: ");
                imprimirLista(&lst);
                break;
        }
        printf("\n");
 }
    return 0;
}
