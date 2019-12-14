#include <iostream>
#include <stdio.h>
#include <string>
/*
	Universidad de las Fuerzas Armdas
	Miembros: Kevin Zurita
	NRC:2967
	Fecha de creacion:19 de noviembre del 2019
	Fecha de modificacion:19 de noviembre de 2019
	Profesor: Ing. Fernando Solis
*/

using namespace std;

class NodoNum{
public:
	NodoNum(int d, NodoNum* sig = NULL) {
		dato = d;
		siguiente = sig;
	}

private:
	int dato;
	NodoNum* siguiente;

friend class listaNum;
};
