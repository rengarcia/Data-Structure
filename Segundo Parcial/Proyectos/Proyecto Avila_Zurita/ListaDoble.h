#pragma once
#include "NodoDoble.h"
#include <iostream>
#include <math.h>
#include <fstream>
#include "Position.h"
class ListaDoble
{
private:
	NodoDoble* head;
	NodoDoble* tail;
public:
	//Constructor
	ListaDoble();
	//Destructor
	~ListaDoble();
	//Funciones
	bool insertarDato(int dato);
	void listaDobleTetris(int tamaño);
	void imprimirLista();
	void insertarEnLista(Position* pos, int num,int limVer,int limHor);
	bool perdio(int elementos);
	bool gano(int elementos);
};

