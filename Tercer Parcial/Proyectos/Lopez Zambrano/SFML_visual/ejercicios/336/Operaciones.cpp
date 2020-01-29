#include "Nodo.h"
#include "NodoPar.h"
#include "Prototipo.h"
#include "Validacion.h"
#include "Operaciones.h"
#include <sstream>

Prototipo prototipo;
NodoPar* nodoPar = NULL;

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

NodoPar* Operaciones::recorrerCadenas(Nodo* lista1, Nodo* lista2)
{
	int numero;
	Nodo* temporal = lista1;

	while (temporal != NULL)
	{
		numero = temporal->getNumero();
		InsertarPar(numero, lista2);
		temporal = temporal->getSiguiente();
	}

	return nodoPar;
}

void Operaciones::InsertarPar(int numero1, Nodo* lista)
{
	Pares par; 
	int numero2;
	Nodo* temporal = lista;
	par.setNumero1(numero1);

	while (temporal != NULL)
	{
		numero2 = temporal->getNumero();
		par.setNumero2(numero2);
		prototipo.insertarColaPar(&nodoPar, par);
		temporal = temporal->getSiguiente();
	}
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





