#include "linked_list.h"
#include <stdio.h>

main() 
{ 
   //Declaracion de Variables
   Lista *menu= NULL;
   char opcion;
     
   //Repetir Programa.
   while(opcion!='s')   
   {  
     //Menu de opciones 

	  printf("\t\t\t     Menu pedido");printf("\t\t\t      \n");

      printf("\t\t\t    (A)  Nuevo Menu               \n");
      
      printf("\t\t\t    (B)  Listar Menu                       \n");      
      
      printf("\t\t\t    (C)  Eliminar Menu            \n");      
      
      printf("\t\t\t    (D)  Modificar Menu            \n"); 
      
      printf("\t\t\t    (S)  Salir                         \n");
      
      printf("\n\n");
      printf("\t\t      Digite una opcion del Menu: ");
      //Leyendo Opcion del Menu   
      fflush(stdin);
      opcion= getch(); 
      
      //Menu de opciones
      switch(opcion)
      {
         case 'A':   
         case 'a':   
              //Insertar Menu.
              fflush(stdin);
              system("cls");
              printf(" %c----------------------------------------------------------------------------%c\n",201,187);
              printf(" | ");printf("\t\t\t          NUEVO MENU     ");printf("\t\t\t      |\n");
              printf(" %c----------------------------------------------------------------------------%c\n",200,188);
              menu= insertar_pedido(menu);
         getch();
         system("cls"); 
         break;
         
         case 'B':   
         case 'b':       
              //Listar menu.
              system ("cls");
              printf(" %c----------------------------------------------------------------------------%c\n",201,187);
              printf(" | ");printf("\t\t\t     LISTAR MENU");printf("\t\t\t      |\n");
              printf(" %c----------------------------------------------------------------------------%c\n",200,188);
              listar_pedidos(menu);
         getch();
         system("cls");
         break;
         
         case 'C':   
         case 'c':   
              //Excluindo pedidos da lista.
              system ("cls");
              printf(" %c----------------------------------------------------------------------------%c\n",201,187);
              printf(" | ");printf("\t\t\t        ELIMINAR MENU");printf("\t\t\t      |\n");
              printf(" %c----------------------------------------------------------------------------%c\n",200,188);
              menu= excluir_pedidos(menu);
         getch();
         system("cls");
         break;

         case 'D':   
         case 'd':   
              //Modificar Menu. 
              system ("cls");
              printf(" %c----------------------------------------------------------------------------%c\n",201,187);
              printf(" | ");printf("\t\t\t       MODIFICAR MENU");printf("\t\t\t      |\n");
              printf(" %c----------------------------------------------------------------------------%c\n",200,188);
              alterar_pedidos(menu);
         getch();
         system("cls");
         break;
         
         case 'S':   
         case 's':       
              //Salir Programa.
              opcion='s';
         break;
         
         default:     
              //Digitar Opcion Diferente del menu.
              system("cls");        
         break; 
      } 
   }  
}

