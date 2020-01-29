/***********************************************************************
 * Module:  Convinacion.h
 * Author:  Luis Carvajal, Elian Llorente
 * Modified: 12 de ener de 2020 1:04:26
 * Purpose: Declaration of the class Arbol.h
 ***********************************************************************/
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

class Arbol
{
private:
	int codigo;
	string palabra;

public:
	typedef Arbol *arbol;
	Arbol *izq;
	Arbol *der;
	void crearNodo(string, int, arbol&);
	void insertar(arbol&, int, string);
	void preOrden(arbol);
	void postOrden(arbol);
	void enOrden(arbol);
	string Buscar(arbol, int);
	int Buscar(arbol, string);
	string Traducir(arbol, arbol, string);
	Arbol();
	~Arbol();
};

/*ELIAN LLORENTE ES GAY*/