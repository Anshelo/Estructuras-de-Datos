#include <iostream>
#include<stdlib.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct NODO {
	int dato;
	struct NODO *sig;
};
NODO *primero = NULL;
NODO *ultimo = NULL;
void insertarNodo();
void imprimirLista();
int main(int argc, char** argv) {
	insertarNodo();
	insertarNodo();
	insertarNodo();
	insertarNodo();
	insertarNodo();
	imprimirLista();
	return 0;
}
void insertarNodo(){
	NODO *nuevo = (NODO *)malloc(sizeof (NODO));
	printf("\nIngrese el dato que contendra el nuevo nodo: ");
	scanf("%d",&nuevo->dato);
	if(primero == NULL){
		primero = nuevo;
		primero->sig = NULL;
		ultimo = nuevo;
	}else{
		ultimo->sig = nuevo;
		nuevo->sig = NULL;
		ultimo = nuevo;
	}
	printf("\nNodo insertado con exito\n\n");
}
void imprimirLista (){
	NODO *actual=(NODO *)malloc(sizeof(NODO));
	actual = primero;
	if(primero!=NULL){
		while(actual!=NULL){
			printf("\n %d",&actual->dato);
			actual=actual->sig;
		}
	}else{
		printf("\nLa lista se encuentra vacia\n\n");
	}
}
