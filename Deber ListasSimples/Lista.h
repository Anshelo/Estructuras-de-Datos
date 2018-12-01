#include <iostream>
#include <conio.h>

#include "Nodo.h"
using namespace std;
class Lista{
	private:
		Nodo *primero;
	public:
		Lista();
		void insertarNodoInicio();
		void insertarNodoFinal();
		void buscarLista();
		void ordenarLista();
		void eliminarNodo();
		void guardarArchivo();
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

void Lista::insertarNodoInicio(){
	
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
		char *mensaje3="Ingrese el Telefono de Casa (Ejm: 022369131): ";
		telefono=leerTelefono(mensaje3);
	}while(!validarTelefono(telefono));
	
	
	if(vacio()){
		//primero->setDato(dato);
		primero=new Nodo();
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
void Lista::insertarNodoFinal(){
	
	string nombre, apellido, telefono;
	long int cedula;
	Nodo *nuevo = new Nodo();
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
		char *mensaje3="Ingrese el Telefono de Casa (Ejm: 022369131): ";
		telefono=leerTelefono(mensaje3);
	}while(!validarTelefono(telefono));
	nuevo->setApellido(apellido);
	nuevo->setNombre(nombre);
	nuevo->setCI(cedula);
	nuevo->setTelefono(telefono);
	Nodo *aux = primero;
	Nodo *aux2;
	while(aux!=NULL){
		aux2 = aux;
		aux = aux->getSiguiente();
	}
	if(primero==aux){
		primero = nuevo;
	}else{
		aux2->setSiguiente(nuevo);
	}
	nuevo->setSiguiente(aux);
}
void Lista::buscarLista(){
	bool bandera = false;
	Nodo *aux=new Nodo();
	aux = primero;
	long cedu;
	cout<<"Ingrese la cedula a buscar"<<endl;
	cin>>cedu;
	while(aux!=NULL){
		if(aux->getCI()==cedu){
			bandera=true;
			cout<<"Cedula encontrada"<<endl;
			cout<<"Nombre: "<<aux->getNombre()<<endl;
			cout<<"Apellido: "<<aux->getApellido()<<endl;
			cout<<"Cedula: "<<aux->getCI()<<endl;
			cout<<"Telefono: "<<aux->getTelefono()<<endl;
		}
		aux=aux->getSiguiente();
	}
	if(bandera==false){
		cout<<"La cedula no existe"<<endl;	
	}
}
void Lista::eliminarNodo(){
	bool bandera = false;
	long cedu;
	cout<<"Ingrese la cedula a eliminar"<<endl;
	cin>>cedu;
	if(primero!=NULL){
		Nodo *aux_borrar;
		Nodo *anterior = NULL;
		aux_borrar = primero;
		
		while((aux_borrar !=NULL)&&(aux_borrar->getCI()!=cedu)){
			anterior = aux_borrar;
			aux_borrar = aux_borrar->getSiguiente();
		}
		if(aux_borrar == NULL){
			cout<<"El elemento ha sido encontrado y borrado";
		}else if(anterior ==NULL){
			primero = primero->getSiguiente();
			delete aux_borrar;
		}
		else{
			anterior->setSiguiente(aux_borrar);
		}
	}
	
}
void Lista::ordenarLista(){
	 Nodo *actual=new Nodo();; 
	 Nodo *sig=new Nodo();;
     string nom;
     string ape;
     long int ced;
     string telf;
     actual = primero;
     while(actual->getSiguiente()!= NULL)
     {
          sig = actual->getSiguiente();
          
          while(sig!=NULL)
          {
               if(actual->getApellido() > sig->getApellido())
               {
                    ape = sig->getApellido();
					nom = sig->getNombre();
					ced = sig->getCI();
					telf = sig->getTelefono();   
                    sig->setApellido(actual->getApellido());
                    sig->setNombre(actual->getNombre());
                    sig->setCI(actual->getCI());
                    sig->setTelefono(actual->getTelefono());
                    actual->setApellido(ape);
                    actual->setNombre(nom);
                    actual->setCI(ced);
                    actual->setTelefono(telf);
               }
               sig = sig->getSiguiente();                    
          }    
          actual = actual->getSiguiente();
          sig = actual->getSiguiente();
     }
}
void Lista::guardarArchivo(){
	ofstream archivo;
	archivo.open("Agenda.txt",ios::out);
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";
	}
	if(!vacio()){
		Nodo *aux=new Nodo();
		aux=primero;
		do{
			archivo<<"Nombre: "<<aux->getNombre()<<endl;
			archivo<<"Apellido: "<<aux->getApellido()<<endl;
			archivo<<"Cedula: "<<aux->getCI()<<endl;
			archivo<<"Telefono: "<<aux->getTelefono()<<endl;
			aux=aux->getSiguiente();
		}while(aux!=NULL);
	}
	archivo.close();
}
void Lista::mostrar(){
	system("cls");
	if(!vacio()){
		Nodo *aux=new Nodo();
		aux=primero;
		do{
			cout<<"Nombre: "<<aux->getNombre()<<endl;
			cout<<"Apellido: "<<aux->getApellido()<<endl;
			cout<<"Cedula: "<<aux->getCI()<<endl;
			cout<<"Telefono: "<<aux->getTelefono()<<endl;
			aux=aux->getSiguiente();
		}while(aux!=NULL);
	}
}




