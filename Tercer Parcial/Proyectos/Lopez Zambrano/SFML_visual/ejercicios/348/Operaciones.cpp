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

Nodo* Operaciones::Insertar(string cadena)
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

Nodo* Operaciones::Duplicar(Nodo* lista)
{
	Nodo* listaDuplicada = NULL;
	Nodo* temporal = lista;
	int numero;

	while (temporal != NULL)
	{
		numero = temporal->getNumero();
		prototipo.insertarCola(&listaDuplicada, numero*2);
		temporal = temporal->getSiguiente();
	}

	return listaDuplicada;
}







