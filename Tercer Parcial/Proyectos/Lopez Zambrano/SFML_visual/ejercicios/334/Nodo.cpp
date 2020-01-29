#include "Nodo.h"
Nodo* Nodo::getSiguiente(void)
{
	return siguiente;
}

void Nodo::setSiguiente(Nodo* newSiguiente)
{
	siguiente = newSiguiente;
}

string Nodo::getPalabra(void)
{
	return palabra;
}

void Nodo::setPalabra(string newPalabra)
{
	palabra = newPalabra;
}
