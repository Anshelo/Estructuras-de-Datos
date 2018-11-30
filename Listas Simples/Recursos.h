#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include <time.h>
#include<iostream>
#include <windows.h>
#include <dos.h>
#define negro 0
#define azul 1
#define verde 2
#define cyan 3
#define rojo 4
#define magenta 5
#define marron 6
#define grisclaro 7
#define grisoscuro 8
#define azulclaro 9
#define verdeclaro 10
#define cyanclaro 11
#define rojoclaro 12
#define magentaclaro 13
#define amarillo 14
#define blanco 15
#define MAX 200
#define f 3
#define c 3
void menu1();
using namespace std;
void gotoxy(int x,int y){
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X = x;
      dwPos.Y= y;
      SetConsoleCursorPosition(hcon,dwPos);
 }
 void t(int n){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), n);
}

 //..........................
 void menu1()
 {
    // marpe();
     int tecla, op=1,i;
     int x;
     x=5;
     do{

  t(15);gotoxy(x,5);printf("MCD");
  t(15);gotoxy(x,6);printf("Invertir Numero");
  t(15);gotoxy(x,7);printf("Potencia");
  t(15);gotoxy(x,8);printf("Binario");
  t(15);gotoxy(x,9);printf("Suma Numeros Naturales");
  t(15);gotoxy(x,10);printf("Salir  ");

  switch(op)
  {
     case 1:
      t(14);gotoxy(x,5);printf("MCD");break;
     case 2:
      t(14);gotoxy(x,6);printf("Invertir Numero");break;
     case 3:
      t(14);gotoxy(x,7);printf("Potencia");break;
     case 4:
      t(14);gotoxy(x,8);printf("Binario");break;
      case 5:
      t(14);gotoxy(x,9);printf("Suma Numeros Naturales");break;
      case 6:
      t(14);gotoxy(x,10);printf("Salir");break;
  }


   do{
      tecla=getch();
      }while(tecla!=72 && tecla!=80 && tecla!=13);


      if(tecla==72)
      {

       if(op>1)
       {
       op--;
       }
       }
       if(tecla==80)
      {

       if(op<6)
       {
       op++;
       }
       }

       }while(tecla!=13);

       switch(op)
  {
  case 1:{
  	

	break;
  } 
  case 2:{
  	

	break;
  }
  case 3:{
  	int b,e;
	Potencia pten(0,0);
	do{
	gotoxy(25,5);printf("Ingrese la base\n");
    gotoxy(25,6);scanf("%d",&b);
    }while(b<0);
    pten.setBase(b);
    do{
    gotoxy(25,7);printf("Ingrese el exponente\n");
    gotoxy(25,8);scanf("%d",&e);
    }while(e<0);
    pten.setExp(e);
    gotoxy(25,9);printf("El resultado es: %d\n",pten.potencia(b,e));
	gotoxy(25,10);system("pause");
	system("cls");
	menu();
	break;
  }
  case 4:{
  	int ndec;
	Binario bin(0);
	do{
	gotoxy(25,5);printf("Ingrese el numero(decimal)\n");
    gotoxy(25,6);scanf("%d",&ndec);
    }while(ndec<0);
    bin.setNum(ndec);
    gotoxy(25,9);printf("El numero en binario es:\n");
    gotoxy(25,10);bin.binario(ndec);
	gotoxy(25,11);system("pause");
	system("cls");
	menu();
	break;
  } 
	case 5:{
  	int natu;
	Natural nat(0);
	do{
	gotoxy(28,5);printf("Ingrese cuantos el numero de terminos\n");
    gotoxy(28,6);scanf("%d",&natu);
    }while(natu<0);
    nat.setNum(natu);
    gotoxy(28,9);printf("La suma de los numeros naturales es: %d\n",nat.sumaNatural(natu));
	gotoxy(28,10);system("pause");
	system("cls");
	menu();
	break;
  } 
  case 6:
      {
       system("cls");
       t(15);
       menu();
      }

     getch();
	 break;
  }
 }

 
