#include "linked_list.h"
#include <stdio.h>

main() 
{ 
   //Declaracion de Variables
   Lista *pedido= NULL;
   char opcion;
     
   //Repetir Programa.
   while(opcion!='s')   
   {  
     //pedido de opciones 

	  printf("\t\t\t     SISTEMA DE PEDIDOS");printf("\t\t\t      \n\n");

      printf("\t\t\t    (A)  Nuevo pedido               \n");
      
      printf("\t\t\t    (B)  Listar pedido                       \n");      
      
      printf("\t\t\t    (C)  Eliminar pedido            \n");      
      
      printf("\t\t\t    (D)  Modificar pedido            \n"); 
      
      printf("\t\t\t    (S)  Salir                         \n");
      
      printf("\n\n");
      printf("\t\t      Digite una opcion del pedido: ");
      //Leyendo Opcion del pedido   
      fflush(stdin);
      opcion= getch(); 
      
      //pedido de opciones
      switch(opcion)
      {
         case 'A':   
         case 'a':   
              //Insertar pedido.
              fflush(stdin);
              system("cls");
              printf(" %c----------------------------------------------------------------------------%c\n",201,187);
              printf(" | ");printf("\t\t\t          NUEVO PEDIDO     ");printf("\t\t\t      |\n");
              printf(" %c----------------------------------------------------------------------------%c\n",200,188);
              pedido= insertar_pedido(pedido);
         getch();
         system("cls"); 
         break;
         
         case 'B':   
         case 'b':       
              //Listar pedido.
              system ("cls");
              printf(" %c----------------------------------------------------------------------------%c\n",201,187);
              printf(" | ");printf("\t\t\t          LISTAR PEDIDO     ");printf("\t\t\t      |\n");
              printf(" %c----------------------------------------------------------------------------%c\n",200,188);
              listar_pedidos(pedido);
         getch();
         system("cls");
         break;
         
         case 'C':   
         case 'c':   
              //Excluindo pedidos da lista.
              system ("cls");
              printf(" %c----------------------------------------------------------------------------%c\n",201,187);
              printf(" | ");printf("\t\t\t        ELIMINAR PEDIDO");printf("\t\t\t      |\n");
              printf(" %c----------------------------------------------------------------------------%c\n",200,188);
              pedido= eliminar_pedido(pedido);
         getch();
         system("cls");
         break;

         case 'D':   
         case 'd':   
              //Modificar pedido. 
              system ("cls");
              printf(" %c----------------------------------------------------------------------------%c\n",201,187);
              printf(" | ");printf("\t\t\t        MODIFICAR PEDIDO");printf("\t\t\t      |\n");
              printf(" %c----------------------------------------------------------------------------%c\n",200,188);
              alterar_pedidos(pedido);
         getch();
         system("cls");
         break;
         
         case 'S':   
         case 's':       
              //Salir Programa.
              opcion='s';
         break;
         
         default:     
              //Digitar Opcion Diferente del pedido.
              system("cls");        
         break; 
      } 
   }  
}

