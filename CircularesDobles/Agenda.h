
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <fstream>


using namespace std;

class Dato{
	private:
		string nombre;
		string apellido;
		int numeroCedula;
		int numeroTelefono;
	public:
		Dato *siguiente;
		Dato *anterior;
		//Constructor
		Dato();
		//Setter
		void setDatoNombre(string);
		void setDatoApellido(string);
		void setDatonumeroCedula(int);
		void setDatonumeroTelefono(int);
		//Getter
		string getDatoNombre();
		string getDatoApellido();
		int getDatoNumeroCedula();
		int getDAtoNumeroTelefono();
		//Metodos
		void ingresarDato(Dato **,string,string,int,int);
		void imprimirDato(Dato*);
		void buscarDato(Dato *);
		void eliminarDato(Dato**);
		void actualizarArchivoDato(Dato *);
		void ordenarAgenda(Dato*);
		
};

//Constructor
Dato::Dato(){
	
}
//Setter
void Dato::setDatoNombre(string _nombre){
	nombre=_nombre;
}
void Dato::setDatoApellido(string _apellido){
	apellido=_apellido;
}
void Dato::setDatonumeroCedula(int _numeroCedula){
	numeroCedula=_numeroCedula;
}
void Dato::setDatonumeroTelefono(int _numeroTelefono){
	numeroTelefono=_numeroTelefono;
}
//Getter
string Dato::getDatoNombre(){
	return nombre;
}
string Dato::getDatoApellido(){
	return apellido;
}
int Dato::getDatoNumeroCedula(){
	return numeroCedula;
}
int Dato::getDAtoNumeroTelefono(){
	return numeroTelefono;
}
//Metodos

void Dato::ingresarDato(Dato **cabeza,string _nombre,string _apellido, int _cedula,int _telefono){
		if (*cabeza == NULL)
    {
       Dato *nuevo = new Dato();
       nuevo->setDatoNombre(_nombre);
       nuevo->setDatoApellido(_apellido);
       nuevo->setDatonumeroCedula(_cedula);
       nuevo->setDatonumeroTelefono(_telefono);
        nuevo->siguiente=nuevo;
        nuevo->anterior=nuevo;
		*cabeza = nuevo;
    }
    Dato *ultimo = (*cabeza)->anterior;
    Dato *nuevo = new Dato();
    nuevo->setDatoNombre(_nombre);
    nuevo->setDatoApellido(_apellido);
    nuevo->setDatonumeroCedula(_cedula);
    nuevo->setDatonumeroTelefono(_telefono);
		nuevo->siguiente = *cabeza;
    (*cabeza)->anterior = nuevo;
    nuevo->anterior = ultimo;
    ultimo->siguiente = nuevo;	
}
void Dato::imprimirDato(Dato *lista){
	Dato *actual=lista->siguiente;
    while(actual!=lista){
    	cout<<"_______________________________________________________________________________"<<endl;
    	cout<<"Nombre: "<<actual->getDatoNombre()<<" Apellido: "<<actual->getDatoApellido()<<" Cedula: "<<actual->getDatoNumeroCedula()<<" Telefono: "<<actual->getDAtoNumeroTelefono()<<endl;
		cout<<"_______________________________________________________________________________"<<endl;
		actual=actual->siguiente;
	}
}
void Dato::buscarDato(Dato *lista){
	int control=0;
	Dato *actual=lista->siguiente;
	int cedulaBuscar=0;
	printf("\nIngrese numero de cedula a buscar: ");
	cin>>cedulaBuscar;
	
    while(actual!=lista){
    	if(cedulaBuscar==actual->getDatoNumeroCedula()){
    	cout<<"_______________________________________________________________________________"<<endl;
    	cout<<"Nombre: "<<actual->getDatoNombre()<<" Apellido: "<<actual->getDatoApellido()<<" Cedula: "<<actual->getDatoNumeroCedula()<<" Telefono: "<<actual->getDAtoNumeroTelefono()<<endl;
		cout<<"_______________________________________________________________________________"<<endl;
		actual=lista;
		}else{
			actual=actual->siguiente;
			control++;
		}
	}
		if(control>0){
  			printf("\nDato no encontrado...");
		  }
}

void Dato::eliminarDato(Dato **cabeza){
	int cedulaEliminar=0;
	printf("\nIngrese numero de cedula a eliminar: ");
	cin>>cedulaEliminar;
	
	 if (*cabeza == NULL)
        return;
    Dato *aux = *cabeza, *aux2 = NULL;
    while (aux->getDatoNumeroCedula()!= cedulaEliminar)
    {
        if (aux->siguiente == *cabeza)
        {
            printf("\nNO SE ENCUENTRA CEDULA %d", cedulaEliminar);
            getch();
            return;
        }
        aux2 = aux;
        aux = aux->siguiente;
    }
    if (aux->siguiente == *cabeza && aux2 == NULL)
    {
        (*cabeza) = NULL;
        delete(aux);
        printf("\nCedula borrada exitosamente %d", cedulaEliminar);
        getch();
        return;
    }
    if (aux == *cabeza) //cabeza
    {
        aux2 = (*cabeza)->anterior;
        *cabeza = (*cabeza)->siguiente;
        aux2->siguiente = *cabeza;
        (*cabeza) ->anterior= aux2;
        delete(aux);
         printf("\nCedula borrada exitosamente %d", cedulaEliminar);
        getch();
    }
    else if (aux->siguiente == *cabeza)//cola
    {
        aux2->siguiente = *cabeza;
        (*cabeza)->anterior = aux2;
        delete(aux);
          printf("\nCedula borrada exitosamente %d", cedulaEliminar);
          
            getch();
    }
    else
    {
        Dato *temp = aux ->siguiente; //medio
        aux2->siguiente= temp;
        temp->anterior = aux2;
        delete(aux);
        printf("\nCedula borrada exitosamente %d", cedulaEliminar);
        getch();
    }
}

void Dato::actualizarArchivoDato(Dato *lista)
{
	Dato *actual;
	FILE *pfp;
	actual=lista->siguiente;
	char *archivoCita ="Agenda.txt";
	pfp=fopen(archivoCita,"w");
	while(actual!=lista){
			fprintf(pfp,"%s %s %d %d \n", actual->nombre.c_str(), actual->apellido.c_str(), actual->numeroCedula, actual->numeroTelefono);
			actual=actual->siguiente;
	}
	fclose(pfp);
}

void Dato::ordenarAgenda(Dato *lista){
	Dato *actual, *siguiente;
     string nom;
     string ape;
     int ced;
     int num;
     actual = lista->siguiente;
     
     while(actual->siguiente != lista)
     {
          siguiente = actual->siguiente;
          
          while(siguiente!=lista)
          {
          	if((actual->apellido.compare(siguiente->apellido))!=0){
          		int letra=-1;
          		do{
          			letra++;
          		if(actual->apellido[letra] > siguiente->apellido[letra])
               		{
                    nom = siguiente->nombre;
                    ape = siguiente->apellido;
                    ced = siguiente->numeroCedula;
                    num = siguiente->numeroTelefono;
                    siguiente->nombre = actual->nombre;
                    siguiente->apellido= actual->apellido;
                    siguiente->numeroCedula=actual->numeroCedula;
                    siguiente->numeroTelefono=actual->numeroTelefono;
					actual->nombre=nom;   
					actual->apellido=ape;
					actual->numeroCedula=ced;
					actual->numeroTelefono=num;
               		}	
				  }while(actual->apellido[letra]==siguiente->apellido[letra]);
          	
			  }
			  else{
			  	
			  	int letra=-1;
          		do{
          			letra++;
          		if(actual->nombre[letra] > siguiente->nombre[letra])
               		{
                    nom = siguiente->nombre;
                    ape = siguiente->apellido;
                    ced = siguiente->numeroCedula;
                    num = siguiente->numeroTelefono;
                    siguiente->nombre = actual->nombre;
                    siguiente->apellido= actual->apellido;
                    siguiente->numeroCedula=actual->numeroCedula;
                    siguiente->numeroTelefono=actual->numeroTelefono;
					actual->nombre=nom;   
					actual->apellido=ape;
					actual->numeroCedula=ced;
					actual->numeroTelefono=num;
               		}	
				  }while(actual->nombre[letra]==siguiente->nombre[letra]);
			  	
			  }
               
               siguiente = siguiente->siguiente;                    
          }    
          actual = actual->siguiente;
          siguiente = actual->siguiente;
           
     }
}

  



