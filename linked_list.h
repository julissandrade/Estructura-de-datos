#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

typedef struct lista{
     char Nombre[40];
     char Precio[40];
     unsigned long int codigo;
     struct lista* prox;   
   }Lista;
   
   //Declaração de funções.
   Lista* inserir_restaurantes(Lista* menu);
   void listar_restaurantes(Lista* menu);
   Lista* excluir_restaurantes(Lista* menu);
   void alterar_restaurantes(Lista* menu);

