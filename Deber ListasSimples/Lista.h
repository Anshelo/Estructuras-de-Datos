#include <iostream>
#include <conio.h>

#include "Nodo.h"
using namespace std;
class Lista{
	private:
		Nodo *primero;
	public:
		Lista();
		void insertarNodo();
		bool vacio();
		string leerNombre(char *);
		string leerApellido(char *);
		long int leerCedula(char *);
		string leerTelefono(char *);
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
string Lista::leerNombre(char *mensaje){
	string nombre;
	cout<<mensaje<<endl;
	cin>>nombre;
	return nombre;
}

string Lista::leerApellido(char *mensaje1){
	string apellido;
	cout<<mensaje1<<endl;
	cin>>apellido;
	return apellido;
}
long int Lista::leerCedula(char *mensaje2){
	long int cedula;
	cout<<mensaje2<<endl;
	cin>>cedula;
	return cedula;
}
string Lista::leerTelefono(char *mensaje3){
	string telefono;
	cout<<mensaje3<<endl;
	cin>>telefono;
	return telefono;
}
bool validarCedula(long int civalidar)
{
    int A[I];
    int res,i,digver,sp,si,mul,st,v;
    long int coc;
    bool bandera = true;
/*Cedula de 10 digitos*/
    while((civalidar<1000000000)||(civalidar>9999999999))
    {
        printf("Cedula invalida, ingrese otro numero: ");
        scanf("%ld", &civalidar);
        bandera = false;
    }
/*Separar el digito verificador*/
    i=9;
    res=civalidar%10;
    A[i]=res;
    coc=civalidar/10;
    civalidar=coc;
/*Almacenar los valores en el arreglo*/
    do
    {
        i--;
        coc=civalidar/10;
        res=civalidar%10;
        A[i]=res;
        civalidar=coc;
    }
    while(coc!=0);
/*Suma de los valores pares e impares*/
    sp=si=0;
    for(i=0; i<I; i+=2)
    {
        mul=A[i]*2;
        if(mul>9)
            mul-=9;
        sp+=mul;
    }
    for(i=1; i<8; i+=2)
        si+=A[i];
/*Validacion final*/
    st=sp+si;

    v=10-(st%10);
    if(v==10)
        v=0;
    do
	{
		if(v==A[9])
    	{
    		printf("Cedula valida\n");
    		bandera = true;
    		break;
		}
        
    	else
    	{
    		printf("Cedula invalida");
    		bandera = false;
    		break;
		}
	}
	while(bandera==true);
    return bandera;
}
bool validarTelefono(string contacto)
{
	int longitud= contacto.length();
	char *telefono=new char();
	char *p;
	int cont=0;
	bool bandera=true;
	if(longitud==9)
	{
		telefono = (char *)contacto.c_str();
		p=telefono;
		if(*p!='0' && *(p+1)!='2'){
			bandera=false;
			return bandera;
		}
				p=telefono;
		if(*p=='0' && *(p+1)!='2'){
			bandera=false;
			
			return bandera;
		}
				p=telefono;
				
		if(*p!='0' && *(p+1)=='2'){
			bandera=false;
			return bandera;
		}
				p=telefono;
				
				
		while(p && cont<9){
			if(*p<'0' || *p>'9'){
			/*	cout<<"*";
				printf("%c>",*p);
			*/	bandera=false;
			}
			p++;
			cont++;
		}
	}else{
		bandera=false;
	}
	return bandera;
}

bool validarNomApl(string cadena)
{
	int longitud= cadena.length();
	char *auxcadena=new char();
	char *p;
	int cont=0;
	bool bandera=true;
	
	auxcadena = (char *)cadena.c_str();
	p=auxcadena;
	*p=tolower(*p);
	while(p && cont<longitud)
	{
		if(*p<'a' || *p>'z')
		{
			/*	cout<<"*";
			printf("%c>",*p);
			*/bandera=false;
		}
		p++;
		cont++;
	}
	return bandera;
}

void Lista::insertarNodo(){
	
	string nombre, apellido, telefono;
	long int cedula;
	do
	{
		char *mensaje="Ingrese el Nombre: ";
		nombre=leerNombre(mensaje);
		fflush(stdin);
		
	}while(!validarNomApl(nombre));
	
	do
	{
		char *mensaje1="Ingrese el Apellido: ";
		apellido=leerApellido(mensaje1);
		fflush(stdin);
	}while(!validarNomApl(apellido));

	do 
	{
		char *mensaje2="Ingrese la Cedula: ";
		cedula=leerCedula(mensaje2);
	}while(!validarCedula(cedula));

	do 
	{
		char *mensaje3="Ingrese el Telefono: ";
		telefono=leerTelefono(mensaje3);
	}while(!validarTelefono(telefono));
	
	
	if(vacio()){
		//primero->setDato(dato);
		Nodo *primero=new Nodo();
		primero->setNombre(nombre);
		primero->setApellido(apellido);
		primero->setCI(cedula);
		primero->setTelefono(telefono);
		primero->setSiguiente(NULL);
		
	}else{
		//aux->setDato(dato);
		Nodo *aux=new Nodo();
		aux->setNombre(nombre);
		aux->setApellido(apellido);
		aux->setCI(cedula);
		aux->setTelefono(telefono);
		aux->setSiguiente(primero);
		primero=aux;
	}
}
void Lista::mostrar(){
	system("cls");
	if(!vacio()){
		Nodo *aux=new Nodo();
		aux=primero;
		do{
			cout<<"->"<<aux->getNombre()<<endl;
			cout<<"->"<<aux->getApellido()<<endl;
			cout<<"->"<<aux->getCI()<<endl;
			cout<<"->"<<aux->getTelefono()<<endl;
			aux=aux->getSiguiente();
		}while(aux!=NULL);
	}
	fflush(stdin);
}




