#pragma once
#include <iostream>
using namespace std;
class Nodo
{
private:
	int dato;
	Nodo* siguiente;

	friend class Lista;
public:
	int getDato() {
		return dato;
	}
};

class Lista
{
private:
	Nodo* primero;
public:
	Lista();
	int getPrimero() const;
	void ingresarDatoInicio(int newDato);
	void ingresarDatoFinal(int NewDato);
	void borrarPrimerElemento();
	void borrarUltimoElemento();
	int operacion();
	~Lista();
	void imprimir() const;
};