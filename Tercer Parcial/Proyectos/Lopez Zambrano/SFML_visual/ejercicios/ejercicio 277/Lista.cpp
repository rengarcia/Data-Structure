/***********************************************************************
 * Module:  Lista.cpp
 * Author:  Zambrano Andres
 * Modified: miércoles, 13 de noviembre de 2019 10:44:55
 * Purpose: Implementation of the class Prototipo
 ***********************************************************************/

#include "Lista.h"


using namespace std;

Lista::Lista()
{
	primero = NULL;
}


int Lista::getPrimero() const
{
	return primero->getDato();
}

void Lista::ingresarDatoInicio(int newDato)
{
	Nodo* temp = new Nodo;
	temp->dato = newDato;
	temp->siguiente = primero;

	primero = temp;

}

void Lista::ingresarDatoFinal(int newDato)
{
	Nodo* temp = new Nodo;
	Nodo* aux = primero;
	temp->dato = newDato;
	temp->siguiente = NULL;

	if (aux == NULL)
	{
		primero = temp;
	}
	else
	{
		while (aux->siguiente != NULL)
		{
			aux = aux->siguiente;
		}
		aux->siguiente = temp;
	}


}


void Lista::borrarPrimerElemento()
{
	Nodo* aux = primero;

	if (aux == NULL)
	{
		cout << "No existen elementos para borrar" << endl;
	}
	else
	{
		Nodo* temp = primero->siguiente;
		delete primero;

		primero = temp;
	}

}

void Lista::borrarUltimoElemento()
{
	Nodo* aux = primero;
	Nodo* aux2 = new Nodo();

	if (aux == NULL)
	{
		cout << "No se puede borrar - NO EXISTEN DATOS" << endl;
	}
	else
	{
		while (aux->siguiente != NULL)
		{
			aux2 = aux;
			aux = aux->siguiente;
		}

		if (aux->siguiente == NULL) {
			delete aux;
			aux2 = aux2->siguiente = NULL;
		}


	}

}

int Lista::operacion()
{
	Nodo* actual = primero;
	Nodo* aux = actual->siguiente;
	int respuesta = 0;
	int operador;
	while (aux) {
		operador = aux->getDato() - actual->getDato();
		respuesta = respuesta + operador;
		actual = actual->siguiente;
		aux = aux->siguiente;
	}
	return respuesta;
}

void Lista::imprimir() const
{
	Nodo* temp = primero;

	while (temp != NULL)
	{
		cout << temp->getDato() << "-> ";
		temp = temp->siguiente;
	}
	cout << endl;

}

Lista::~Lista()
{
	while (primero != NULL) {
		borrarPrimerElemento();
	}
}
