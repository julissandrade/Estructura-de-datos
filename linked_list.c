#include "linked_list.h"
#include <stdlib.h>
#include <assert.h>
Lista* insertar_pedido (Lista *primero){ 
     Lista pedido;
     Lista *actual= primero;
     char identificador= 'F';
     
     //Info del pedido
     printf("  Nombre: ");
     fflush (stdin); fgets(pedido.Nombre, 40, stdin); printf ("\n");
     printf("  Precio: $  ",135);
     fflush (stdin); fgets(pedido.Precio, 40, stdin); printf ("\n");
     printf("  C%cdigo: ",162);
     scanf("%u",&pedido.codigo);printf ("\n");
     
     //Verificando si existe el pedido
     for(actual=primero; actual!=NULL; actual=actual->prox){
        if(actual->codigo==pedido.codigo){
            identificador= 'V'; 
            break;
        }    
     }

     if(identificador!='V' && (strlen(pedido.Nombre)!=1 && strlen(pedido.Precio)!=1)){
         //Guardando info del pedido.
         Lista* NuevoPedido=(Lista*) malloc (sizeof(Lista));       
         strcpy(NuevoPedido->Nombre, pedido.Nombre);
         strcpy(NuevoPedido->Precio, pedido.Precio);
         NuevoPedido->codigo= pedido.codigo;
         NuevoPedido->prox= primero;
         printf("  Pedido realizado con exito.");
         printf("\n\n  Presione cualquier tecla para volver al pedido principal..");
         return NuevoPedido;    
     }else{
         printf("  Pedido incorrecto.",160);
         printf("\n\n  Presione cualquier tecla para volver al pedido principal..");
         return primero;
     }
}

void listar_pedidos (Lista* primero){
     Lista* actual;
     
     //Imprimiendo pedidos de la lista con su respectiva informacion
     for(actual= primero ; actual!= NULL; actual= actual->prox){
        printf("\n  Nombre: ");
        printf("%s", actual->Nombre);
        printf("\n  Precio: $  ",135);
        printf("%s", actual->Precio);
        printf("\n  C%cdigo: ",162 );
        printf("%u", actual->codigo);
        printf("\n\n");
     }
     if(primero==NULL)
        printf("  Nenhum pedido cadastrado.");
     printf("\n\n  Presione cualquier tecla para volver al pedido principal..");
}

Lista* eliminar_pedido(Lista *primero){
     
     Lista *anterior= NULL;//puntero para saber el elemento anterior o actual de la lista
     Lista *actual= primero;//puntero para recorrer la lista o primer elemento de la lista
     unsigned long int codigo=0;
     
     //Consultando el pedido a ser eliminado
     printf("  C%cdigo de pedido a ser Eliminado: ", 162,161);
     fflush(stdin);
     scanf("%u",&codigo);
     
     //Buscar el pedido en la lista.
     while(actual!= NULL && actual->codigo!=codigo){
        anterior= actual;
        actual= actual->prox;
     }
     
     //Mensaje si el pedido no se encuentra.
     if(actual==NULL){
        printf("\n  pedido no encontrado.", 198); 
        printf("\n\n  Presione cualquier tecla para volver al pedido principal..");
        return primero;
     }
     
     //Excluyendo el primer pedido de la lista.   
     if(anterior==NULL){
        printf("\n  Pedido eliminado exitosamente.", 163,161); 
        primero= actual->prox;
     //Excluyendo un pedido de la lista.
     }else{
        printf("\n  Pedido eliminado exitosamente.", 163,161);
        anterior->prox= actual->prox;
     }
     
     //Liberando la memoroia
     free(actual);
     printf("\n\n  Presione cualquier tecla para volver al pedido principal..");
     return primero;     
}

//Modificar pedido
void alterar_pedidos(Lista* primero){     
     char Nombre_substituto[40], Precio_substituto[40];
     unsigned long int codigo;  
     Lista* actual=primero;
     
     //Pedido a modificar
     printf("  C%cdigo de pedido a ser modificado: ", 162);
     fflush(stdin);
     scanf("%u",&codigo);
     
     //Buscar el pedido en la lista.
     while(actual!= NULL && actual->codigo!=codigo){
        actual= actual->prox;
     }
     
     //Modificando el pedido.
     if(actual!=NULL){
        printf("\n  Nuevo Nombre: ");
        fflush (stdin); fgets(Nombre_substituto, 40, stdin); 
        strcpy(actual->Nombre,Nombre_substituto);
        printf("\n  Nuevo Precio: $  ",135);
        fflush (stdin); fgets(Precio_substituto, 40, stdin); printf ("\n");
        strcpy(actual->Precio,Precio_substituto);
        printf("  Pedido modificado con exito.");
     }else{
        printf("\n  pedido no encontrado.",198);
     }
     printf("\n\n\n  Presione cualquier tecla para volver al pedido principal..");
     }
