#include <stdio.h>
#include <iostream>
#include <string>
#include "ListaEnlazada.h"
using namespace std;

int main(){
	ListaEnlazada listaE;
	listaE.insertar(0);
	listaE.insertar(1);
	listaE.insertar(2);
	listaE.insertar(3);
	listaE.insertar(4);
	listaE.insertar(5);
	listaE.insertar(6);
	listaE.insertar(7);
	listaE.insertar(8);
	listaE.insertar(9);
	
	cout<<listaE.crearLinea()<<endl;
	return 0;
}
