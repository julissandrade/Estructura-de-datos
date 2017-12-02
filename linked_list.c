#include "linked_list.h"
#include <stdlib.h>
#include <assert.h>
Lista* inserir_restaurantes (Lista *primeiro){ 
     Lista restaurante;
     Lista *atual= primeiro;
     char identificador= 'F';
     
     //Lendo as informações do restaurante.
     printf("  Nombre: ");
     fflush (stdin); fgets(restaurante.Nombre, 40, stdin); printf ("\n");
     printf("  Precio: ",135);
     fflush (stdin); fgets(restaurante.Precio, 40, stdin); printf ("\n");
     printf("  C%cdigo: ",162);
     scanf("%u",&restaurante.codigo);printf ("\n");
     
     //Verificando se o cadastro já existe.
     for(atual=primeiro; atual!=NULL; atual=atual->prox){
        if(atual->codigo==restaurante.codigo){
            identificador= 'V'; 
            break;
        }    
     }

     if(identificador!='V' && (strlen(restaurante.Nombre)!=1 && strlen(restaurante.Precio)!=1)){
         //Alocando os espaços e guardando as informações do restaurante.
         Lista* NovoRestaurante=(Lista*) malloc (sizeof(Lista));       
         strcpy(NovoRestaurante->Nombre, restaurante.Nombre);
         strcpy(NovoRestaurante->Precio, restaurante.Precio);
         NovoRestaurante->codigo= restaurante.codigo;
         NovoRestaurante->prox= primeiro;
         printf("  Cadastro realizado com sucesso.");
         printf("\n\n  Precione cualquier tecla para volver al menu principal..");
         return NovoRestaurante;    
     }else{
         printf("  Cadastro inv%clido.",160);
         printf("\n\n  Precione cualquier tecla para volver al menu principal..");
         return primeiro;
     }
}

void listar_restaurantes (Lista* primeiro){
     Lista* atual;//Ponteiro para percorrer a lista sem perder a referência do primeiro elemento da lista.
     
     //Imprimindo os restaurantes da lista, e suas repectivas informações.
     for(atual= primeiro ; atual!= NULL; atual= atual->prox){
        printf("\n  Nombre: ");
        printf("%s", atual->Nombre);
        printf("\n  Precio: ",135);
        printf("%s", atual->Precio);
        printf("\n  C%cdigo: ",162 );
        printf("%u", atual->codigo);
        printf("\n\n");
     }
     if(primeiro==NULL)
        printf("  Nenhum restaurante cadastrado.");
     printf("\n\n  Precione cualquier tecla para volver al menu principal..");
}

Lista* excluir_restaurantes(Lista *primeiro){
     
     Lista *anterior= NULL;//Ponteiro para saber o elemento anterior ao elemento atual da lista.
     Lista *atual= primeiro;//Ponteiro para percorrer a lista sem perder o primeiro elemento da lista.
     unsigned long int codigo=0;
     
     //Requisitando e lendo o código do restaurante a ser excluído.
     printf("  C%cdigo do restaurante a ser exclu%cdo: ", 162,161);
     fflush(stdin);
     scanf("%u",&codigo);
     
     //Procurando o restaurante na lista.
     while(atual!= NULL && atual->codigo!=codigo){
        anterior= atual;
        atual= atual->prox;
     }
     
     //Mensagem caso o restaurante não seja encontrado.
     if(atual==NULL){
        printf("\n  Restaurante n%co encontrado.", 198); 
        printf("\n\n  Precione cualquier tecla para volver al menu principal..");
        return primeiro;
     }
     
     //Excluindo o primeiro restaurante da lista.   
     if(anterior==NULL){
        printf("\n  Conte%cdo exclu%cdo com sucesso.", 163,161); 
        primeiro= atual->prox;
     //Excluindo um restaurante do meio da lista.
     }else{
        printf("\n  Conte%cdo exclu%cdo com sucesso.", 163,161);
        anterior->prox= atual->prox;
     }
     
     //Desalocando o espaço da memória.
     free(atual);
     printf("\n\n  Precione cualquier tecla para volver al menu principal..");
     return primeiro;     
}

//Função para alterar restaurantes.
void alterar_restaurantes(Lista* primeiro){     
     char Nombre_substituto[40], Precio_substituto[40];
     unsigned long int codigo;  
     Lista* atual=primeiro;
     
     //Requisitando e lendo o código do restaurante a ser alterado.
     printf("  C%cdigo do restaurante a ser alterado: ", 162);
     fflush(stdin);
     scanf("%u",&codigo);
     
     //Procurando o restaurante na lista.
     while(atual!= NULL && atual->codigo!=codigo){
        atual= atual->prox;
     }
     
     //Alterando os dados do restaurante.
     if(atual!=NULL){
        printf("\n  Novo Nombre: ");
        fflush (stdin); fgets(Nombre_substituto, 40, stdin); 
        strcpy(atual->Nombre,Nombre_substituto);
        printf("\n  Novo Precio: ",135);
        fflush (stdin); fgets(Precio_substituto, 40, stdin); printf ("\n");
        strcpy(atual->Precio,Precio_substituto);
        printf("  Dados alterados com sucesso.");
     }else{
        printf("\n  Restaurante n%co encontrado.",198);
     }
     printf("\n\n\n  Precione cualquier tecla para volver al menu principal..");
     }
