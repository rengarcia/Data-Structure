#include "Nodo.h"
#include <string>
#include <iostream>
#include "Prototipo.h"
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

void Prototipo::imprimir(Nodo* referencia)
{	
	cout << endl <<"La lista Impar es: [";
	while (referencia != NULL) {
		cout << " " << referencia->getNumero();
		referencia = referencia->getSiguiente();
	}
	cout << " ]";
}


