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
   
   //Declarando las funciones.
   Lista* insertar_pedido(Lista* menu);
   void listar_pedidos(Lista* menu);
   Lista* excluir_pedidos(Lista* menu);
   void alterar_pedidos(Lista* menu);

