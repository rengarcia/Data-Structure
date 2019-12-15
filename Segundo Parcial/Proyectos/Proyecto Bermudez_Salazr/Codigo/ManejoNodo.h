#pragma once
#include "Nodo.h"
#include <iostream>
using namespace std;

class ManejoNodo
{
public:
	void insertar(int dato, bool posicion);
	void insertarEnMedio(int posicion, int dato);
	void imprimir();
	bool borrar();
	int getLongitud();
private:
	Nodo* primero = NULL;
	Nodo* ultimo = NULL;
	int longitud = 0;
};

