#include "Nodo.h"
#include "NodoPar.h"
#include "Pares.h"
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

void Prototipo::imprimir(NodoPar* referencia)
{
	Pares par;
	int numero1;
	int numero2;
	
	cout << endl << "La lista es: [";
	while (referencia != NULL) {
		par = referencia->getPar();
		numero1 = par.getNumero1();
		numero2 = par.getNumero2();
		cout << " [" << numero1 << "," << numero2 << "]";
		referencia = referencia->getSiguiente();
	}
	cout << " ]";
}

void Prototipo::insertarColaPar(NodoPar** referencia, Pares par)
{
	NodoPar* nodoTemporal = new NodoPar();
	NodoPar* ultimo = *referencia;
	
	nodoTemporal->setPar(par);
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


