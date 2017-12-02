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
   Lista* insertar_pedido(Lista* pedido);
   void listar_pedidos(Lista* pedido);
   Lista* eliminar_pedido(Lista* pedido);
   void alterar_pedidos(Lista* pedido);

