#include <iostream>
#include <conio.h>
#include "Nodo.h"
using namespace std;
class Lista{
	private:
		Nodo *primero;
	public:
		Lista();
		void insertarInicio();
		bool vacio();
		int leerDato(char *);
		void mostrar();
};
Lista::Lista(){
	primero=NULL;
}
bool Lista::vacio(){
	if(primero==NULL){
		return true;
	}else{
		return false;
	}
}
int Lista::leerDato(char *mensaje){
	int valor;
	cout<<mensaje<<endl;
	cin>>valor;
	return valor;
}
void Lista::insertarInicio(){
	int dato;
	char *mensaje="Ingrese el valor entero en el nodo";
	dato=leerDato(mensaje);
	if(vacio()){
		primero=new Nodo();
		primero->setDato(dato);
		primero->setSiguiente(NULL);
		
	}else{
		Nodo *aux=new Nodo();
		aux->setDato(dato);
		aux->setSiguiente(primero);
		primero=aux;
	}
}
void Lista::mostrar(){
	if(!vacio()){
		Nodo *aux=new Nodo();
		aux=primero;
		do{
			cout<<"->"<<aux->getDato();
			aux=aux->getSiguiente();
		}while(aux!=NULL);
	}
}
