#include <iostream>
#include <windows.h>
#include <conio.h> 
#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include<string>
using namespace std;

class Nodo{
	private:
		int dato;
		string nombre;
		string apellido;
		long int CI;
		string telefono;
		Nodo *siguiente;
	public: 
		Nodo(){}
		~Nodo(){}
		Nodo(int valor, string _nombre, string _apellido, long int _CI, string _telefono, Nodo *_siguiente){
			dato = valor;
			nombre=_nombre;
			apellido=_apellido;
			CI=_CI;
			telefono=_telefono;
			siguiente=siguiente;
		}
		Nodo *getSiguiente(){
			return siguiente;
		}
		void setSiguiente(Nodo *_siguiente){
			siguiente=_siguiente;
		}
		int getDato(){
			return dato;
		}
		void setDato(int valor){
			dato=valor;
		}
		string getNombre(){
			return nombre;
		}
		void setNombre (string _nombre){
			nombre=_nombre;
		}
		string getApellido(){
			return apellido;
		}
		void setApellido(string _apellido){
			apellido=_apellido;
		}
		long int getCI(){
			return CI;
		}
		void setCI(long int _CI){
			CI=_CI;
		}
		string getTelefono(){
			return telefono;
		}
		void setTelefono(string _telefono){
			telefono=_telefono;
		}
				
};
