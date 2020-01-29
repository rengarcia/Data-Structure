#include "Nodo.h"
#include "Prototipo.h"
#include <string>
#include <iostream>

using namespace std;

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


Nodo* Prototipo::buscarDato(Nodo* referencia, char letra) {

	Nodo* nodo = NULL;
	Nodo* temporal = referencia; 
	string palabraTemp;
	char* aux;

	while (temporal != NULL)
	{
		palabraTemp = temporal->getPalabra();
		aux = (char*)palabraTemp.c_str();

		if (letra == *(aux)) {
				insertarCola(&nodo, palabraTemp);
		}
		temporal = temporal->getSiguiente();
	}

	return nodo;
}

string Prototipo::aMinusculas(string cadena)
{
	int dim = cadena.size();
	char* temp = (char*)cadena.c_str();

	for (int i = 0; i < dim; i++)
	{
		if (*(temp + i) >= 65 && *(temp + i) <= 92)
		{
			*(temp + i) = *(temp + i) + 32;
		}
	}

	string resultado(temp);
	return resultado;
}

void Prototipo::imprimir(Nodo* referencia)
{	
	cout << endl<<"La lista es: [ ";
	while (referencia != NULL) {
		cout << referencia->getPalabra()<< " ";
		referencia = referencia->getSiguiente();
	}

	cout << "]"<<endl;
}


