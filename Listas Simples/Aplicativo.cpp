#include <iostream>
#include "Lista.h"
#include "Recursos.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	Lista *lista = new Lista();
	char op;
	menu1();
	do{
		lista->insertarInicio();
		cout<<"Ingrese 1 para continuar 0 para salir"<<endl;
		op=getch();
	}while(op!='0');
	lista->mostrar();
	return 0;
}
