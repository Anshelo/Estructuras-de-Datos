#include<stdio.h>
#include <conio.h>
#include <windows.h>
void gotoxy(int x,int y){
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X = x;
      dwPos.Y= y;
      SetConsoleCursorPosition(hcon,dwPos);
 }
void cambiarcolor(int X)
{
    SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),X);
}
void Say(int x,int y,const char *txt)
{   
	gotoxy(x,y);printf("%s",txt);
}
void SetColorA(int color,int colorf)
{
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color | colorf | FOREGROUND_INTENSITY | BACKGROUND_INTENSITY );
}
void SetColorB(int color,int colorf)
{
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color | colorf | BACKGROUND_INTENSITY );
}
void ReplicateH(int x,int y,const char *c,int can)
{
	for(int i=0;i<can;i++)
	 {
		Say(x+i,y,c);	
	 }
}

void ReplicateV(int x,int y,const char *c,int can)
{
	for(int i=0;i<can;i++)
	 {
		Say(x,y+i,c);	
	 }
}


void Rectangle(int x,int y,int w,int h,const char *c)
{  
		ReplicateH(x,y,c,w);//fila 1
		ReplicateH(x,y+h,c,w);//fila 2
		ReplicateV(x,y,c,h);//col 1
		ReplicateV(x+w-1,y,c,h);//col 2
   
} 

void TextColor(int color)
{
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color); 
}

void logoEspe()
{
system("color f7");
int x=219,o=255,y=220; 
printf("\n"); 
printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o);//Blanco
cambiarcolor(2);
printf("%c%c%c%c%c%c",x,x,x,x,x,x);
cambiarcolor(240);
printf("%c%c%c",o,o,o);
cambiarcolor(2);
printf("%c%c%c%c%c%c",x,x,x,x,x,x);
cambiarcolor(240);
printf("%c%c%c",o,o,o);
cambiarcolor(2);
printf("%c%c%c%c%c%c",x,x,x,x,x,x);
cambiarcolor(240);
printf("%c%c%c",o,o,o);
cambiarcolor(2);
printf("%c%c%c%c%c%c",x,x,x,x,x,x);
//2 linea
printf("\n");
cambiarcolor(240);
printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o);//Blanco
cambiarcolor(2);
printf("%c%c",x,x);
cambiarcolor(240);
printf("%c%c%c%c%c%c%c",o,o,o,o,o,o,o);
cambiarcolor(2);
printf("%c%c",x,x);
cambiarcolor(240);
printf("%c%c%c%c%c%c%c",o,o,o,o,o,o,o);
cambiarcolor(2);
printf("%c%c",x,x);
cambiarcolor(240);
printf("%c%c",o,o);
cambiarcolor(2);
printf("%c%c",x,x);
cambiarcolor(240);
printf("%c%c%c",o,o,o);
cambiarcolor(2);
printf("%c%c",x,x);
//3 linea
printf("\n");
cambiarcolor(240);//Blanco
printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o);//Blanco
cambiarcolor(2);//verde
printf("%c%c%c%c",x,x,x,x);//verde
cambiarcolor(240);//Blanco
printf("%c%c%c%c%c",o,o,o,o,o);//Blanco
cambiarcolor(2);//verde
printf("%c%c%c%c%c%c",x,x,x,x,x,x);//verde
cambiarcolor(240);//Blanco
printf("%c%c%c",o,o,o);//Blanco
cambiarcolor(2);//verde
printf("%c%c",x,x);//verde
cambiarcolor(2);//verde
printf("%c%c%c%c",x,x,x,x);//verde
cambiarcolor(240);//Blanco
printf("%c%c%c",o,o,o);//Blanco
cambiarcolor(2);//verde
printf("%c%c%c%c",x,x,x,x);//verde
//4 linea
printf("\n");
cambiarcolor(240);//Blanco
printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o);//Blanco
cambiarcolor(2);//verde
printf("%c%c",x,x);//verde
cambiarcolor(240);//Blanco
printf("%c%c%c%c%c%c%c%c%c%c%c",o,o,o,o,o,o,o,o,o,o,o);//Blanco
cambiarcolor(2);//verde
printf("%c%c",x,x);//verde
cambiarcolor(240);//Blanco
printf("%c%c%c",o,o,o);//Blanco
cambiarcolor(2);//verde
printf("%c%c",x,x);//verde
cambiarcolor(240);//Blanco
printf("%c%c%c%c%c%c%c",o,o,o,o,o,o,o);//Blanco
cambiarcolor(2);//verde
printf("%c%c",x,x);//verde
//5linea
printf("\n");
cambiarcolor(240);//Blanco
printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o);//Blanco
cambiarcolor(2);//verde
printf("%c%c%c%c%c%c",x,x,x,x,x,x);//verde
cambiarcolor(240);//Blanco
printf("%c%c%c",o,o,o);//Blanco
cambiarcolor(2);//verde
printf("%c%c%c%c%c%c",x,x,x,x,x,x);//verde
cambiarcolor(240);//Blanco
printf("%c%c%c",o,o,o);//Blanco
cambiarcolor(2);//verde
printf("%c%c",x,x);//verde
cambiarcolor(240);//Blanco
printf("%c%c%c%c%c%c%c",o,o,o,o,o,o,o);//Blanco
cambiarcolor(2);//verde
printf("%c%c%c%c%c%c",x,x,x,x,x,x);//verde
printf("\n");
cambiarcolor(240);//Blanco
printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o);//Blanco
cambiarcolor(252);
printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",y,y,y,y,y,y,y,y,y,y,y,y,y,y,y,y,y,y,y,y,y,y,y,y,y,y,y,y,y,y,y,y,y);
printf("\n");
cambiarcolor(240);
printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o);//Blanco
printf("UNIVERSIDAD DE LAS FUERZAS ARMADAS");
printf("\n");
cambiarcolor(240);//Blanco
printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o);//Blanco
cambiarcolor(2);
printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",y,y,y,y,y,y,y,y,y,y,y,y,y,y,y,y,y,y,y,y,y,y,y,y,y,y,y,y,y,y,y,y,y);
printf("\n");
cambiarcolor(240);//Blanco
printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o,o);//Blanco
cambiarcolor(240);
printf("  INNOVACION PARA LA EXCELENCIA");
 
}
