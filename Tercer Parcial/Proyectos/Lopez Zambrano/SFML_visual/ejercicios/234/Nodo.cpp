#include "Nodo.h"
Nodo* Nodo::getSiguiente(void)
{
	return siguiente;
}

void Nodo::setSiguiente(Nodo* newSiguiente)
{
	siguiente = newSiguiente;
}

int Nodo::getNumero(void)
{
	return numero;
}

void Nodo::setNumero(int newNumero)
{
	numero = newNumero;
}
