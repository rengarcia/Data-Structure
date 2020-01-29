#include "Operaciones.h"

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

bool Operaciones::esAlfabetica(string cadena)
{
	int dim = cadena.size();
	char* temp = (char*)cadena.c_str();

	for (int i = 0; i < dim-1; i++)
	{
		if ( *(temp + i) > *(temp + i + 1) )
		{
			return false;
		}
	}

	return true;
}
