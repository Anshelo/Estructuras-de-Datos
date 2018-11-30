#include <windows.h>    // Win32Api Header File 
#define _CRT_SECURE_NO_DEPRECATE
#include <string>
#include<fstream>
#include <locale.h>
#define KEY_ESC 27
#include <iostream>
#include <windows.h>
#include <conio.h> 
#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include<string>
#include <time.h>
#include <ctype.h>
#define ARRIBA 72
#define ABAJO 80
#define ENTER 13
#define TAM 10
#define MAIL "@espe.edu.ec"
#define I 10
#define F 59
#include "Lista.h"
using namespace std;

void menuPrincipal();
void ingresarOrdenes();
void insertarDatoInicioLista(string nombre, string apellido, long int cedula, string telefono, string marca, string modelo, string placa, string detalle, int valor);
void insertarDatoFin(string nombre, string apellido, long int cedula, string telefono, string marca, string modelo, string placa, string detalle, int valor);
void insertarDatosEntreAntes(string nombre, string apellido, long int cedula, string telefono, string marca, string modelo, string placa, string detalle, int valor);
void imprimirLista();
void eliminarDato();
void buscarDato();
void modificarDato();
void gotoxy(int x,int y);
bool validarNomApl(string cadena);
bool validarCedula(string ci);
bool validarTelefono(string contacto);

void gotoxy(int x,int y)
{
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X = x;
      dwPos.Y= y;
      SetConsoleCursorPosition(hcon,dwPos);
}

Lista *lista = new Lista();
void ingresarOrdenes()
{
	
	int contingresos = 0;
	bool repite = true;
   	string nombre="", apellido="",telefono="";
	long int cedula;
	int num,c;
	system("cls");
	string menu[] = { 	"1.-INGRESAR UN CLIENTE AL INICIO",
						"2.-INGRESAR UN CLIENTE AL FINAL",
						"3.-SALIR" };
	int cursor = 0;
	char tecla;
	for (;;)
	{
		system("cls");
		//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 160);//DA COLOR AL TEXTO LISTAS SIMPLES
		cout << "                          LISTAS SIMPLES" << endl;
		for (int i = 0; i < 3; i++) 
		{
			if (cursor == i)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 160);
				cout << menu[i] << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
				cout << menu[i] << endl;
			}
		}
		for (;;)//TECLAS
		{
			tecla = _getch();
			if (tecla == 80) 
			{
				cursor++;
				if (cursor == 3)
				{
					cursor = 0;
				}
				break;
			}
			if (tecla == 72) 
			{
				cursor--;
				if (cursor == -1)
				{
					cursor = 2;
				}
				break;
			}
			
			if (tecla == 13) 
			{
	
					switch (cursor)
					{
						case 0:
							system("cls");
							cout<<"\t\t\tINGRESO DE DATOS DEL CLIENTE\n ";
							lista->insertarNodo();
							fflush(stdin);
							cout<<"\n";
							system("pause");
							break;
							
						case 1:
							system("cls");
							/*if(lista->vacio())
							{
								cout<<"\nDEBE INGRESAR lA PRIMER ORDEN!!\n";
								system("pause");
							}*/
							//else
							//{
							cout<<"\t\t\tINGRESO DE DATOS DEL CLIENTE\n ";
							do
							{
								cout<<"\t\tIngrese el nombre: ";
								cin>>nombre;
								fflush(stdin);
							}
							while(!validarNomApl(nombre));
							fflush(stdin);
								
							do
							{
								cout<<"\t\tIngrese el apellido: ";
								cin>>apellido;
								fflush(stdin);
							}
							while(!validarNomApl(apellido));
							fflush(stdin);
							
							do
							{
								cout<<"\t\tIngrese la cedula: ";
								cin>>cedula;
								fflush(stdin);
							}
							while(!validarCedula(cedula));
							fflush(stdin);
							
							do
							{
								cout<<"\t\tIngrese el telefono: ";
								cin>>telefono;
								fflush(stdin);
							}
							while(!validarTelefono(telefono));
							fflush(stdin);
							system("cls");
							contingresos++;
							fflush(stdin);
							cout<<"\n";
							system("pause");
							break;

						
						case 2:
							system("cls");
							menuPrincipal();
            				system("pause");
            				break;
					}
					break;			
			}
		}
	}
}


void menuPrincipal ()
{
	int tecla1;		
	system("color f0");
	int num,c;
	system("cls");
	string menu[] = {	"1.-INGRESAR NUEVA CLIENTE",
						"2.-BUSCAR CLIENTE",
						"3.-ELIMINAR CLIENTE",
						"4.-IMPRIMIR CLIENTE",
						"5.-SALIR" };
	int cursor = 0;
	char tecla;
	for (;;)
	{
		/*tecla1 = getch();
		if(tecla1 == 59)
		{
			system("Ayuda.chm");	
		}*/
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);//DA COLOR AL TEXTO LISTAS SIMPLES
		cout << "                          LISTAS SIMPLES" << endl;
		for (int i = 0; i < 5; i++) 
		{
			if (cursor == i)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 160);
				cout << menu[i] << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
				cout << menu[i] << endl;
			}
		}
		for (;;)//TECLAS
		{
			tecla = _getch();
		
			if (tecla == 80) 
			{
				cursor++;
				if (cursor == 5)
				{
					cursor = 0;
				}
				break;
			}
			if (tecla == 72) 
			{
				cursor--;
				if (cursor == -1)
				{
					cursor = 4;
				}
				break;
			}
			
			if (tecla == 13) 
			{
				switch (cursor)
				{
				case 0:
					system ("cls");
					ingresarOrdenes();
					cout<<"\n";
					system("pause");
					system("cls");
					break;
					
				case 1:
					system("cls");
					//buscarDato();
					cout<<"\n";
					system("pause");
					system("cls");
					break;
					
				case 2:
					system("cls");
					//eliminarDato();
					cout<<"\n";
					system("pause");
					system("cls");
					break;
					
				case 3:
					system("cls");
					lista->mostrar();
					cout<<"\n";
					system("pause");
					system("cls");
					break;
					
				case 4:
					system("cls");
					cout << endl << "    Gracias por usar nuestro programa......!" << endl;
					system("pause");
					exit(1);
					break;
				}
				break;
			}
		}
	}
}


