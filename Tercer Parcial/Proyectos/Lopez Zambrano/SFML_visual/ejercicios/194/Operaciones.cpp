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

string Operaciones::Pasatiempo(string cadena)
{
	int dim = cadena.size();
	char* temp = (char*)cadena.c_str();

	for (int i = 0; i < dim; i++)
	{
		if (*(temp + i) == 'a' || *(temp + i) == 'e' || *(temp + i) == 'i' || *(temp + i) == 'o'|| *(temp + i) == 'u')
		{
			*(temp + i) = '.';
		}
	}

	string resultado(temp);

	return resultado;
}

