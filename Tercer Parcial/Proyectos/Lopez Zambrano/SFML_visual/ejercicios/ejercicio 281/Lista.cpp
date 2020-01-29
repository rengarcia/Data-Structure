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

double Lista::operacion()
{
	Nodo* actual = primero;
	int divisor = 0;
	double respuesta = 0;
	double operador = 0;
	while (actual) {
		divisor++;
		operador += actual->getDato();
		actual = actual->siguiente;
	}
	if (divisor == 0)
		return 0;
	else
		return operador / divisor;
}

double Lista::producto()
{
	Nodo* actual = primero;
	double multiplicador = 1;
	while (actual) {
		multiplicador *= actual->getDato();
		actual = actual->siguiente;
	}
	return multiplicador;
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

void Lista::ordenar()
{
	int temp_data;
	Nodo* aux_node = primero;
	Nodo* temp = aux_node;

	while (aux_node) {
		temp = aux_node;

		while (temp->siguiente) {
			temp = temp->siguiente;

			if (aux_node->getDato() > temp->getDato()) {
				temp_data = aux_node->getDato();
				aux_node->dato = temp->getDato();
				temp->dato = temp_data;
			}
		}

		aux_node = aux_node->siguiente;
	}
}
