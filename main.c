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

      printf(" | ");printf("\t\t\t     Menu Restaurante");printf("\t\t\t      |\n");
      printf("\t       %c----------%c\t\t\t\t       ",201,187);
      printf("\t\t\t               |   MENU   ");printf("|\t\t\t\t      \n");
      printf("   | <A>  Nuevo Menu               |\n");
      
      printf("   | <B>  Listar Menu                       |\n");      
      
      printf("   | <C>  Eliminar Menu            |\n");      
      
      printf("   | <D>  Modificar Menu            |\n"); 
      
      printf("   | <S>  Salir                         |\n");
      
      printf("\n\n\n\n");
      printf("\t\t\t      Realizado por: Sin fronteras");
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
              menu= inserir_restaurantes(menu);
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
              listar_restaurantes(menu);
         getch();
         system("cls");
         break;
         
         case 'C':   
         case 'c':   
              //Excluindo restaurantes da lista.
              system ("cls");
              printf(" %c----------------------------------------------------------------------------%c\n",201,187);
              printf(" | ");printf("\t\t\t        ELIMINAR MENU");printf("\t\t\t      |\n");
              printf(" %c----------------------------------------------------------------------------%c\n",200,188);
              menu= excluir_restaurantes(menu);
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
              alterar_restaurantes(menu);
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
