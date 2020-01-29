#include "Nodo.h"
#include "Prototipo.h"
#include "Validacion.h"
#include "Operaciones.h"
#include <sstream>

string Operaciones::convertir(string cadena)
{
	Validacion validacion;
	cadena = validacion.soloLetras(cadena);

	string resultado;
	resultado = removerSignos(cadena);
	resultado = removerDobleEspacio(resultado);
	resultado = aMinusculas(resultado);

	return resultado;
}

void Operaciones::separarInsetarPalabras(string cadena)
{
	Nodo* nodo = NULL;
	Prototipo prototipo;

	char* temp = (char*)cadena.c_str();

	char* token = strtok(temp, " ");

	while (token != NULL)
	{
		prototipo.insertar(&nodo, token);
		token = strtok(NULL, " ");
	}

	prototipo.imprimir(nodo);
	
}

string Operaciones::aMinusculas(string cadena)
{
	int dim = cadena.size();
	char* temp= (char*)cadena.c_str();

	for (int i = 0; i < dim; i++)
	{
		if (*(temp+i) >= 65 && *(temp + i) <= 92)
		{
			*(temp + i) = *(temp + i) + 32;
		}
	}

	string resultado (temp);

	return resultado;
}

string Operaciones::removerSignos(string cadena)
{
	char* temp = (char*)cadena.c_str();
	int count = 0;

	for (int i = 0; *(temp + i); i++) {
		if (*(temp + i) != '.' && *(temp + i) != ',' && *(temp + i) != ':'
			&& *(temp + i) != ';') {
			*(temp + count) = *(temp+i);
			count++;
		}
	}
	*(temp + count) = '\0';

	string resultado(temp);

	return resultado;
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





