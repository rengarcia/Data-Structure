#include "Nodo.h"
#include "Prototipo.h"
#include <string>
#include <iostream>

using namespace std;

void Prototipo::insertar(Nodo** referencia, string palabra)
{
	Nodo* temporal = *referencia;

	bool bandera = buscarDato(temporal, palabra);

	if (!bandera) {
		insertarCola(referencia, palabra);
	}

}

void Prototipo::insertarCola(Nodo** referencia, string palabra)
{
	Nodo* nodoTemporal = new Nodo();
	Nodo* ultimo = *referencia;

	nodoTemporal->setPalabra (palabra);
	nodoTemporal->setSiguiente(NULL);

	if (*referencia == NULL)
	{
		*referencia = nodoTemporal;
		return;
	}

	while (ultimo->getSiguiente() != NULL)
		ultimo = ultimo->getSiguiente();

	ultimo->setSiguiente(nodoTemporal);
	return;
}


void Prototipo::eliminarDato(Nodo** referencia, string palabra)
{
	Nodo* temporal = *referencia;
	Nodo* prev = new Nodo();

	string palabraTemp = temporal->getPalabra();
	char* aux1 = (char*)palabra.c_str();
	char* aux2 = (char*)palabraTemp.c_str();

	bool bandera = buscarDato(temporal, palabra);

	if (bandera) {

		if (temporal != NULL && strcmp(aux1, aux2) == 0)
		{
			*referencia = temporal->getSiguiente();
			free(temporal);
			return;
		}
		else {
			while (temporal != NULL && strcmp(aux1, aux2) != 0)
			{
				prev = temporal;
				temporal = temporal->getSiguiente();
				palabraTemp = temporal->getPalabra();
				aux2 = (char*)palabraTemp.c_str();
			}
			prev->setSiguiente(temporal->getSiguiente());
		}

	}
	else {
		cout << "no existe ese dato" << endl;
	}
}


bool Prototipo::buscarDato(Nodo* referencia, string palabra) {

		Nodo* temporal = referencia; 
		string palabraTemp;
		char* aux1= (char*)palabra.c_str();
		char* aux2;

		while (temporal != NULL)
		{
			palabraTemp = temporal->getPalabra();
			aux2 = (char*)palabraTemp.c_str();

			if (strcmp(aux1, aux2) == 0) {
				return true;
			}		
			temporal = temporal->getSiguiente();
		}
		return false;
}

void Prototipo::imprimir(Nodo* referencia)
{	
	cout << endl<<"La lista es: [ ";
	while (referencia != NULL) {
		cout << referencia->getPalabra() << ", ";
		referencia = referencia->getSiguiente();
	}

	cout << "]";
}


