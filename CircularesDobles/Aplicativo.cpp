/*
						"UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE"
										
				
						Tema: LISTAS CIRCULARES DOBLES
								AGENDA
	Integrantes: 	Danny Escobar
					Jean Pierre Cerón 
					Isaac Pilataxi
					Diego Villegas
					Anshelo Pullas
					David Ayala
					Roger Pilacuán
					Melissa Cedeño
	Fecha:	    04/12/2018
	Profesor:	Ing. Fernando Solis
	Carrera:	Ing. Sistemas e informatica
	Materia:	Estructura de datos
*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include "logo.h"
#include "Agenda.h"
//Prototipos de las funciones
int menu();	
void menu_seleccion();
//Fin prototipos

int main(){
	menu_seleccion();
	return 0;
}
//Funciones
void menu_seleccion(){	
	Dato *lista=NULL;
	int opcion;
	string nombreAux;
	string apellidoAux;
	int cedulaAux=0;
	int telefonoAux=0;
	do{
		opcion=0;
		opcion=menu();
		switch(opcion){
			case 1:{
				system("cls");
				printf("Ha escojido opcion insertar al final");
				printf("\nIngrese Nombre: ");
				cin>>nombreAux;
				printf("\nIngrese Apellido: ");
				cin>>apellidoAux;
				printf("\nIngrese Cedula: ");
				cin>>cedulaAux;
				printf("\nIngrese Telefono: ");
				cin>>telefonoAux;
				lista->ingresarDato(&lista,nombreAux,apellidoAux,cedulaAux,telefonoAux);
				lista->actualizarArchivoDato(lista);
				lista->ordenarAgenda(lista);
				lista->actualizarArchivoDato(lista);
				getch();
				break;
			}
			case 2:{
				system("cls");
				printf("Ha escojido opcion insertar al inicio\n");
				printf("\nIngrese Nombre: ");
				cin>>nombreAux;
				printf("\nIngrese Apellido: ");
				cin>>apellidoAux;
				printf("\nIngrese Cedula: ");
				cin>>cedulaAux;
				printf("\nIngrese Telefono: ");
				cin>>telefonoAux;
				lista->ingresarDato(&lista,nombreAux,apellidoAux,cedulaAux,telefonoAux);
				lista->ordenarAgenda(lista);
				lista->actualizarArchivoDato(lista);
				getch();
				break;
			}
			case 3:{
				system("cls");
				printf("Ha escojido opcion consultar\n");
				if(lista!=NULL){
					lista->buscarDato(lista);
				}else{
					printf("\nLa lista esta vacia...");
				}
				getch();
				break;
			}
			case 4:{
				system("cls");
				printf("Ha escojido opcion eliminar\n");
				if(lista!=NULL){
					lista->eliminarDato(&lista);
					lista->actualizarArchivoDato(lista);
				
				}else{
					printf("\nLa lista esta vacia...");	
				}
				getch();
				break;
			}
			case 5:{
				system("cls");
				printf("Ha escojido opcion imprimir\n");
				if(lista!=NULL){
					lista->imprimirDato(lista);

				}else{
					printf("La lista esta vacia...");
				}
				getch();
				break;
			}
			case 6:{
				system("cls");
				printf("Saliendo del sistema");
				getch();
				break;
			}
		}
		
	}while(opcion!=6);	
}
int menu()
{
	int nOpciones=6;
	int seleccion=1,tecla=0;
	bool repite=true;
	
	char caracter;
	do
	{
	    system("cls");
		logoEspe(); 
		SetColorA(0,0); 
    	Rectangle(12,0,55,22,"*"); 
		SetColorA(1,6);
		gotoxy(13,10);
		for(int i=0;i<53;i++){
			printf("#");
		}
		
		SetColorA(4,0);
		Say(27,11,"|*** MENU PRINCIPAL ***|");
		cambiarcolor(240);//Blanco
		if (seleccion==1)
        {   
		  cambiarcolor(263);
          gotoxy(16,13);
		  printf("Ingresar Final  ");
		  cambiarcolor(240);//Blanco
		  gotoxy(15,14);
		  printf("Ingresar Inicio ");
		  gotoxy(15,15);
		  printf("Consultar       ");
		  gotoxy(15,16);
		  printf("Eliminar        ");
		  gotoxy(15,17);
		  printf("Imprimir        ");
		  gotoxy(15,18);
		  printf("Salir           ");
        }
        if (seleccion==2)
        {
         cambiarcolor(240);
         gotoxy(15,13);
		 printf("Ingresar Final  ");
	     cambiarcolor(263);//Blanco
		 gotoxy(16,14);
		 printf("Ingresar Inicio ");
		 cambiarcolor(240);//Blanco
		 gotoxy(15,15);
		 printf("Consultar       ");
	     gotoxy(15,16);
   	     printf("Eliminar        ");
		 gotoxy(15,17);
		 printf("Imprimir        ");
		 gotoxy(15,18);
		 printf("Salir           ");
        }
        if (seleccion==3)
        {
         cambiarcolor(240);
         gotoxy(15,13);
		 printf("Ingresar Final  ");
		 gotoxy(15,14);
		 printf("Ingresar Inicio ");
		 gotoxy(16,15);
	     cambiarcolor(263);//Blanco
		 printf("Consultar       ");
		 cambiarcolor(240);//Blanco
		 gotoxy(15,16);
		 printf("Eliminar        ");
		 gotoxy(15,17);
		 printf("Imprimir        ");
		 gotoxy(15,18);
		 printf("Salir           ");
        }
        if (seleccion==4)
        {
         cambiarcolor(240);
         gotoxy(15,13);
		 printf("Ingresar Final  ");
		 gotoxy(15,14);
		 printf("Ingresar Inicio ");
		 gotoxy(15,15);
		 printf("Consultar       ");
		 cambiarcolor(263);//Blanco
		 gotoxy(16,16);
		 printf("Eliminar        ");
		 cambiarcolor(240);//Blanco
		 gotoxy(15,17);
		 printf("Imprimir        ");
	     gotoxy(15,18);
		 printf("Salir           ");
        }
        if (seleccion==5)
        {
         cambiarcolor(240);
         gotoxy(15,13);
		 printf("Ingresar Final  ");
		 gotoxy(15,14);
		 printf("Ingresar Inicio ");
	     gotoxy(15,15);
		 printf("Consultar       ");
		 gotoxy(15,16);
		 printf("Eliminar        ");
		 gotoxy(16,17);
		 cambiarcolor(263);//Blanco
		 printf("Imprimir        ");
		 cambiarcolor(240);//Blanco
		 gotoxy(15,18);
		 printf("Salir           ");
        }
        if (seleccion==6)
        {
         cambiarcolor(240);
         gotoxy(15,13);
		 printf("Ingresar Final  ");
		 gotoxy(15,14);
		 printf("Ingresar Inicio ");
		 gotoxy(15,15);
		 printf("Consultar       ");
		 gotoxy(15,16);
		 printf("Eliminar        ");
		 gotoxy(15,17);
		 printf("Imprimir        ");
		 cambiarcolor(263);//Blanco
		 gotoxy(16,18);
		 printf("Salir           ");
		 cambiarcolor(240);//Blanco
        }
		do
		{
			tecla=getch();
		}while((tecla!=72)&&(tecla!=80)&&(tecla!=13));
		switch(tecla)
		{
			case 72:{
				seleccion--;
				if(seleccion<1)
				{

					seleccion=nOpciones;
				}
				break;
				}
			case 80:{
				seleccion++;
				if(seleccion>nOpciones)
			 	{
					seleccion=1;
				}
				break;
				}
			case 13:{
				repite=false;
				break;
				}
		}
	}while(repite);
	return seleccion;
}


//Fin funciones
