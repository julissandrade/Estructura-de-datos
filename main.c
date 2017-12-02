#include <stdio.h>
#include <stdlib.h>
#include "Struct.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void listar(){
	Node *i=primero;
	while(i!=NULL){
		switch(i->codComida){
			case 1:{
				printf("%d -- Orden de pollo. cant= %d",i->item,i->cantidad);		
				break;
			}
			case 2:{
				printf("%d -- Orden de carne. cant= %d",i->item,i->cantidad);		
				break;
			}
			case 3:{
				printf("%d -- Orden de sopa. cant= %d",i->item,i->cantidad);		
				break;
			}
		}
		printf("\n");
		i=i->next;
	}
}
void agregar(Node *l) {
	Node *temp;
	l->next=NULL;
	if(primero==NULL){
		primero=l;
		ultimo=l;
	}else{
		ultimo->next=l;
		temp=ultimo;
		ultimo=l;
		ultimo->ant=temp;
	}
}

void prioridad(int position,Node *pedido){
	Node *i=primero;
	Node *des;
	Node *ant;
	int item;
	while(i!=NULL){
		if(i->item==position){
			if(i->next!=NULL){
				des=i->next;
				ant=i->ant;
				ant->next=pedido;
				i->ant=pedido;
				pedido->next=i;
				pedido->ant=ant;
				//item=pedido->item;
				//i->next=pedido;
				//pedido->next=des;
				//pedido->item=des->item;
				//temp->item=item;
			}else{
				agregar(pedido);
			}
		}
		i=i->next;
	}
}
void main() {
	int op=10,cont=1,comida,cantidad,position;
	while (op!=0) {
		system("cls");
        printf("Menu de operaciones de listas\n");
        printf("\t1- Ingresar Pedido\n");
        printf("\t2- Ingresar Pedido Prioritario\n");
        printf("\t3- Historial de pedido\n");
        printf("\t4- Cancelar Pedido\n");
        printf("\t0- Salir\n");
        scanf("%d",&op);
        Node *pedido=malloc(sizeof(Node));
        switch(op){
        	case 1:{
        		system("cls");
        		printf("1) pollo 2)carne 3)sopa \n\n");
        		scanf("%d",&comida);
        		printf("Cantidad: \n\n");
        		scanf("%d",&cantidad);
        		switch(comida){
        			case 1:{
        				if(cantidad!=0){
        					pedido->codComida=1;
							pedido->item=cont;
							pedido->cantidad=cantidad;
							cont++;
							agregar(pedido);
						}
						break;
					}
					case 2:{
						pedido->codComida=2;
						pedido->item=cont;
						pedido->cantidad=cantidad;
						cont++;
						agregar(pedido);
						break;
					}
					case 3:{
						pedido->codComida=3;
						pedido->item=cont;
						pedido->cantidad=cantidad;
						cont++;
						agregar(pedido);
						break;
					}
				}
				
				break;
			}
			case 2:{
				system("cls");
				listar();
        		printf("\nPosicion:\n");
        		scanf("%d",&position);
        		
        		printf("1) pollo 2)carne 3)sopa \n\n");
        		scanf("%d",&comida);
        		printf("Cantidad: \n\n");
        		scanf("%d",&cantidad);
        		
        		switch(comida){
        			case 1:{
        				if(cantidad!=0){
        					pedido->codComida=1;
							pedido->item=cont;
							pedido->cantidad=cantidad;
							cont++;
						}
						break;
					}
					case 2:{
						pedido->codComida=2;
						pedido->item=cont;
						pedido->cantidad=cantidad;
						cont++;
						break;
					}
					case 3:{
						printf("3");
						pedido->codComida=3;
						pedido->item=cont;
						pedido->cantidad=cantidad;
						cont++;
						break;
					}
				}
        		
				prioridad(position,pedido);
				break;
			}
			case 3:{
				listar();
				system("pause");
				break;
			}
		}
		
		
}
}

