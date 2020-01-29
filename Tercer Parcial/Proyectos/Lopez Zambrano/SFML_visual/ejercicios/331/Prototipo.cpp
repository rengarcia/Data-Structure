#include "Nodo.h"
#include "Prototipo.h"
#include <string>
#include <iostream>

using namespace std;

void Prototipo::insertarCola(Nodo** referencia, int numero)
{
	Nodo* nodoTemporal = new Nodo();
	Nodo* ultimo = *referencia;

	nodoTemporal->setNumero (numero);
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


void Prototipo::eliminarDato(Nodo** referencia, int numero)
{
	Nodo* temporal = *referencia;
	Nodo* prev = new Nodo();

	int numeroTemp = temporal->getNumero();

	bool bandera = buscarDato(temporal, numero);

	if (bandera) {

		if (temporal != NULL && numero==numeroTemp)
		{
			*referencia = temporal->getSiguiente();
			free(temporal);
			return;
		}
		else {
			while (temporal != NULL && numero != numeroTemp)
			{
				prev = temporal;
				temporal = temporal->getSiguiente();
				numeroTemp = temporal->getNumero();
			}
			prev->setSiguiente(temporal->getSiguiente());
		}

	}
	else {
		cout << "no existe ese dato" << endl;
	}
}


bool Prototipo::buscarDato(Nodo* referencia, int numero) {

		Nodo* temporal = referencia; 
		int numeroTemp;

		while (temporal != NULL)
		{
			numeroTemp = temporal->getNumero();
	
			if (numero==numeroTemp) {
				return true;
			}		
			temporal = temporal->getSiguiente();
		}
		return false;
}

void Prototipo::imprimir(Nodo* referencia)
{	
	cout << endl <<"La lista Union es: [";
	while (referencia != NULL) {
		cout << " " << referencia->getNumero();
		referencia = referencia->getSiguiente();
	}
	cout << " ]";
}


