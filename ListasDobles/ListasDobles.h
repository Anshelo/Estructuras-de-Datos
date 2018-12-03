#include <iostream>
#include <conio.h>
#include "Nodo.h"
using namespace std;
class ListasDobles{
	private:
		Nodo *primero;
	public:
		ListasDobles();
		void insertarNodoInicio();
		void insertarNodoEntre();
		void insertarNodoFin();
		void buscarNodo();
		void ordenarNodo();
		void eliminarNodo();
		void guardarArchivo();
		bool vacio();
		string leerNombre(char *);
		string leerApellido(char *);
		long int leerCedula(char *);
		string leerTelefono(char *);
		void mostrar();
};

ListasDobles::ListasDobles()
{
	primero=NULL;
}
bool ListasDobles::vacio()
{
	if(primero==NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}
string ListasDobles::leerNombre(char *mensaje)
{
	string nombre;
	cout<<mensaje;
	cin>>nombre;
	return nombre;
}
string ListasDobles::leerApellido(char *mensaje1)
{
	string apellido;
	cout<<mensaje1;
	cin>>apellido;
	return apellido;
}
long int ListasDobles::leerCedula(char *mensaje2)
{
	long int cedula;
	cout<<mensaje2;
	cin>>cedula;
	return cedula;
}
string ListasDobles::leerTelefono(char *mensaje3)
{
	string telefono;
	cout<<mensaje3;
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

void ListasDobles::insertarNodoInicio()
{
	string nombre, apellido, telefono;
	long int cedula;
	Nodo *nuevo=new Nodo();
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
	
	nuevo->setNombre(nombre);
	nuevo->setApellido(apellido);
	nuevo->setCI(cedula);
	nuevo->setTelefono(telefono);
	
		
	if(vacio())
	{
		nuevo->setAnterior(NULL);
		nuevo->setSiguiente(NULL);
		primero=nuevo;
		cout<<"SE HA INGRESADO EL DATO CORRECTAMENTE";
	}
	else
	{
		nuevo->setSiguiente(primero);
		nuevo->setAnterior(primero->getAnterior());
		primero->setAnterior(nuevo);
		primero = nuevo;
		cout<<"SE HA INGRESADO EL DATO CORRECTAMENTE";
	}
}

void ListasDobles::insertarNodoFin()
{
	string nombre, apellido, telefono;
	long int cedula;
	Nodo *nuevo = new Nodo();
    Nodo *aux= new Nodo();
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
	
	nuevo->setNombre(nombre);
	nuevo->setApellido(apellido);
	nuevo->setCI(cedula);
	nuevo->setTelefono(telefono);
	
	if(!vacio())
	{
		while(aux->getSiguiente()!=NULL)
		{
			aux=aux->getSiguiente();			
		}
		nuevo->setSiguiente(aux->getSiguiente());
		aux->setSiguiente(nuevo);
		nuevo->setAnterior(aux);
	}
	else
	{
        printf("Debe ingresar el primer Dato!\n\n");
    }
	
}
void ListasDobles::buscarNodo()
{
	Nodo *aux = new Nodo();
	aux=primero;
	bool encontrado = false;
	long int cedula;
	if(!vacio())
	{
		do
		{
			char *mensaje2="Ingrese la Cedula: ";
			cedula=leerCedula(mensaje2);
			
		}while(!validarCedula(cedula));
		fflush(stdin);
		
		while((aux!=NULL) && encontrado!=true)
		{
			if(aux->getCI()==cedula)
			{
				cout<<aux->getNombre()<<"           "<<aux->getApellido()<<"            "<<"(593)"+aux->getTelefono()<<endl;        
	      		encontrado=true;
			}
			aux=aux->getSiguiente();	
			if(encontrado == false)
			{
				cout<<"\n\nNO SE ENCONTRARON LOS DATOS!!!";
			}
		}	
	}
	
	else
	{
		cout<<"\n\nLA LISTA SE ENCUENTRA VACIA!!!";
	}
}

void ListasDobles::guardarArchivo()
{
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

void ListasDobles::eliminarNodo()
{
	Nodo *aux=new Nodo();
    Nodo *ante=new Nodo();
    long int cedulaeliminar;
    aux=primero;
    ante=NULL;
    int valor,control=0;

    if(!vacio())
	{     
		mostrar();
       	do
		{
			char *mensaje2="Ingrese la Cedula: ";
			cedulaeliminar=leerCedula(mensaje2);
			
		}while(!validarCedula(cedulaeliminar));
		fflush(stdin);
		
        while(aux!=NULL)
        {
            if(aux->getCI() == cedulaeliminar)
            {
                if(ante==NULL)
                {
                    primero=primero->getSiguiente();
                    printf("\nDato eliminado");
                    control=1;
                    return;
                }
                if(aux->getSiguiente()==NULL)
                {
                    aux->setAnterior(NULL);
                    aux->setSiguiente(NULL);
                    printf("\nDato eliminado");
                    control=1;
                    return;
                }
                ante->setSiguiente(aux->getSiguiente());
                aux->setSiguiente(ante);
                aux->setAnterior(ante);
                printf("\nDato eliminado");
                control=1;
            }
            ante=aux;
            aux=aux->getSiguiente();
        }
        if(control==0)
        {
             printf("\nNo se encontro el dato");
        }
    }
    else
    {
        printf("Debe ingresar el primer elemento!\n\n");
    }
}

void ListasDobles::ordenarNodo(){
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
void ListasDobles::mostrar()
{
	system("cls"); 
	if(!vacio()){
		Nodo *aux=new Nodo();
		aux=primero;
		do{
			cout<<"Nombre: "<<aux->getNombre()<<endl;
			cout<<"Apellido: "<<aux->getApellido()<<endl;
			cout<<"Cedula: "<<aux->getCI()<<endl;
			cout<<"Telefono: "<<aux->getTelefono()<<endl;
			cout<<"\n";
			aux=aux->getSiguiente();
		}while(aux!=NULL);
	}
 }


