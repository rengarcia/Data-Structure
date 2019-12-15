#include "OperacionesNodo.h"
#include <iostream>
using namespace std;

void OperacionesNodo::imprimir_char(NodoChar* referencia)
{
	NodoChar* auxiliar = referencia;
	cout << "Pila: ";

	while (auxiliar != NULL)
	{
		cout << auxiliar->getDato() << " ";
		auxiliar = auxiliar->getSiguiente();
	}
}

void OperacionesNodo::destruirPila_char(NodoChar* referencia)
{
	NodoChar* aux = referencia;

	while (referencia != NULL)
	{
		referencia = aux->getSiguiente();
		delete(aux);
	}
}

void OperacionesNodo::pop_char(NodoChar*& referencia)
{
	NodoChar* aux = new NodoChar();

	aux = referencia;

	referencia = aux->getSiguiente();
	delete(aux);

}

char OperacionesNodo::top_char(NodoChar*& referencia)
{

	NodoChar* aux = new NodoChar();

	aux = referencia;
	char tope = aux->getDato();

	return tope;

}

void OperacionesNodo::push_char(NodoChar*& referencia, char dato)
{
	NodoChar* aux = new NodoChar();

	aux->setDato(dato);

	aux->setSiguiente(referencia);
	referencia = aux;
}

void OperacionesNodo::imprimir_int(NodoInt* referencia)
{
	NodoInt* auxiliar = referencia;
	cout << "Pila: ";

	while (auxiliar != NULL)
	{
		cout << auxiliar->getDato() << " ";
		auxiliar = auxiliar->getSiguiente();
	}
}

void OperacionesNodo::destruirPila_int(NodoInt* referencia)
{
	NodoInt* aux = referencia;

	while (referencia != NULL)
	{
		referencia = aux->getSiguiente();
		delete(aux);
	}
}

void OperacionesNodo::pop_int(NodoInt*& referencia)
{
	NodoInt* aux = new NodoInt();

	aux = referencia;

	referencia = aux->getSiguiente();
	delete(aux);

}

int OperacionesNodo::top_int(NodoInt*& referencia)
{

	NodoInt* aux = new NodoInt();
	aux = referencia;
	int tope = aux->getDato();
	cout << tope;

	return tope;

}

void OperacionesNodo::push_int(NodoInt*& referencia, int dato)
{
	NodoInt* aux = new NodoInt();

	aux->setDato(dato);

	aux->setSiguiente(referencia);
	referencia = aux;
}

void OperacionesNodo::imprimir_double(NodoDouble* referencia)
{
	NodoDouble* auxiliar = referencia;
	cout << "Pila: ";

	while (auxiliar != NULL)
	{
		cout << auxiliar->getDato() << " ";
		auxiliar = auxiliar->getSiguiente();
	}
}

void OperacionesNodo::destruirPila_double(NodoDouble* referencia)
{
	NodoDouble* aux = referencia;

	while (referencia != NULL)
	{
		referencia = aux->getSiguiente();
		delete(aux);
	}
}

void OperacionesNodo::pop_double(NodoDouble*& referencia)
{
	NodoDouble* aux = new NodoDouble();

	aux = referencia;

	referencia = aux->getSiguiente();
	delete(aux);

}

double OperacionesNodo::top_double(NodoDouble*& referencia)
{

	NodoDouble* aux = new NodoDouble();

	aux = referencia;
	double tope = aux->getDato();

	return tope;

}

void OperacionesNodo::push_double(NodoDouble*& referencia, double dato)
{
	NodoDouble* aux = new NodoDouble();

	aux->setDato(dato);

	aux->setSiguiente(referencia);
	referencia = aux;
}

string  OperacionesNodo::invertirCadena(string cadena) {
	
	int dim = cadena.length();
	char* temporal1 = (char*)cadena.c_str();
	char* temporal2 = new char[dim];

	int pivot = 0;
	for (int i = dim - 1; i >= 0; i--) {
		*(temporal2 + i) = *(temporal1 + pivot);
		pivot++;
	}

	string cadenaInvertida(temporal2, dim);

	return cadenaInvertida;
}
