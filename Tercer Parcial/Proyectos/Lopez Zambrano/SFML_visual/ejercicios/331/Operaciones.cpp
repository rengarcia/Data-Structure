#include "Nodo.h"
#include "Prototipo.h"
#include "Validacion.h"
#include "Operaciones.h"
#include <sstream>

Prototipo prototipo;

string Operaciones::convertir(string cadena)
{
	Validacion validacion;
	cadena = validacion.soloNumeros(cadena);
	
	string resultado;
	resultado = removerDobleEspacio(cadena);

	return resultado;
}

Nodo* Operaciones::Insetar(string cadena)
{
	Nodo* nodo = NULL;
	int aux;

	char* temp = (char*)cadena.c_str();

	char* token = strtok(temp, " ");

	while (token != NULL)
	{
		aux = stoi(token);
		prototipo.insertarCola(&nodo, aux);
		token = strtok(NULL, " ");
	}

	return nodo;
	
}

string Operaciones::removerDobleEspacio(string cadena)
{
	stringstream ss(cadena);
	string word;
	string resultado = "";

	while (ss >> word)
	{
		resultado = resultado + word + " ";
	}
	return resultado;
}

Nodo* Operaciones::eliminarDuplicados(Nodo* lista)
{
	Nodo* listaSinDuplicados = NULL;
	Nodo* temporal = lista;
	int numero;

	while (temporal != NULL)
	{
		numero = temporal->getNumero();

		if (!esComun(temporal->getSiguiente(), numero)) {
			prototipo.insertarCola(&listaSinDuplicados, numero);
		}

		temporal = temporal->getSiguiente();
	}
	
	return listaSinDuplicados;

}

Nodo* Operaciones::union_(Nodo* lista1, Nodo* lista2)
{
	Nodo* listaUnion = NULL;
	Nodo* temporal = lista1;
	int numero;

	while (temporal != NULL)
	{
		numero = temporal->getNumero();
		if (!esComun(lista2, numero)) {
			prototipo.insertarCola(&listaUnion, numero);
		}
		temporal = temporal->getSiguiente();
	}

	temporal = lista2;
	while (temporal != NULL) {
		numero = temporal->getNumero();
		prototipo.insertarCola(&listaUnion, numero);
		temporal = temporal->getSiguiente();
	}

	return listaUnion;
}

bool Operaciones::esComun(Nodo* lista, int numero)
{
	Nodo* temporal = lista;
	int aux;

	while (temporal != NULL)
	{
		aux = temporal->getNumero();
		if (numero==aux) {
			return true;
		}
		temporal = temporal->getSiguiente();
	}
	return false;
}





