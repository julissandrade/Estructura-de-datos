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
     printf("  Precio: ",135);
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
         //Alocando os espaços e guardando as informações do pedido.
         Lista* NuevoPedido=(Lista*) malloc (sizeof(Lista));       
         strcpy(NuevoPedido->Nombre, pedido.Nombre);
         strcpy(NuevoPedido->Precio, pedido.Precio);
         NuevoPedido->codigo= pedido.codigo;
         NuevoPedido->prox= primero;
         printf("  Cadastro realizado com sucesso.");
         printf("\n\n  Precione cualquier tecla para volver al menu principal..");
         return NuevoPedido;    
     }else{
         printf("  Cadastro inv%clido.",160);
         printf("\n\n  Precione cualquier tecla para volver al menu principal..");
         return primero;
     }
}

void listar_pedidos (Lista* primero){
     Lista* actual;
     
     //Imprimiendo pedidos de la lista con su respectiva informacion
     for(actual= primero ; actual!= NULL; actual= actual->prox){
        printf("\n  Nombre: ");
        printf("%s", actual->Nombre);
        printf("\n  Precio: ",135);
        printf("%s", actual->Precio);
        printf("\n  C%cdigo: ",162 );
        printf("%u", actual->codigo);
        printf("\n\n");
     }
     if(primero==NULL)
        printf("  Nenhum pedido cadastrado.");
     printf("\n\n  Precione cualquier tecla para volver al menu principal..");
}

Lista* excluir_pedidos(Lista *primero){
     
     Lista *anterior= NULL;//Ponteiro para saber o elemento anterior ao elemento actual da lista.
     Lista *actual= primero;//Ponteiro para percorrer a lista sem perder o primero elemento da lista.
     unsigned long int codigo=0;
     
     //Requisitando e lendo o código do pedido a ser excluído.
     printf("  C%cdigo do pedido a ser exclu%cdo: ", 162,161);
     fflush(stdin);
     scanf("%u",&codigo);
     
     //Procurando o pedido na lista.
     while(actual!= NULL && actual->codigo!=codigo){
        anterior= actual;
        actual= actual->prox;
     }
     
     //Mensagem caso o pedido não seja encontrado.
     if(actual==NULL){
        printf("\n  pedido n%co encontrado.", 198); 
        printf("\n\n  Precione cualquier tecla para volver al menu principal..");
        return primero;
     }
     
     //Excluindo o primero pedido da lista.   
     if(anterior==NULL){
        printf("\n  Conte%cdo exclu%cdo com sucesso.", 163,161); 
        primero= actual->prox;
     //Excluindo um pedido do meio da lista.
     }else{
        printf("\n  Conte%cdo exclu%cdo com sucesso.", 163,161);
        anterior->prox= actual->prox;
     }
     
     //Desalocando o espaço da memória.
     free(actual);
     printf("\n\n  Precione cualquier tecla para volver al menu principal..");
     return primero;     
}

//Função para alterar pedidos.
void alterar_pedidos(Lista* primero){     
     char Nombre_substituto[40], Precio_substituto[40];
     unsigned long int codigo;  
     Lista* actual=primero;
     
     //Requisitando e lendo o código do pedido a ser alterado.
     printf("  C%cdigo do pedido a ser alterado: ", 162);
     fflush(stdin);
     scanf("%u",&codigo);
     
     //Procurando o pedido na lista.
     while(actual!= NULL && actual->codigo!=codigo){
        actual= actual->prox;
     }
     
     //Alterando os dados do pedido.
     if(actual!=NULL){
        printf("\n  Novo Nombre: ");
        fflush (stdin); fgets(Nombre_substituto, 40, stdin); 
        strcpy(actual->Nombre,Nombre_substituto);
        printf("\n  Novo Precio: ",135);
        fflush (stdin); fgets(Precio_substituto, 40, stdin); printf ("\n");
        strcpy(actual->Precio,Precio_substituto);
        printf("  Dados alterados com sucesso.");
     }else{
        printf("\n  pedido n%co encontrado.",198);
     }
     printf("\n\n\n  Precione cualquier tecla para volver al menu principal..");
     }
