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

bool Operaciones::es_repeticion(string cadena)
{
	int contador = 0;
	int dim = cadena.size();
	char* cadena_char = (char*)cadena.c_str();
	int media = dim / 2;
	char* aux1 = new char[media];
	char* aux2 = new char[media];

	if (!es_impar(dim)) {
		for (int i = 0; i < dim; i++) {
			if (i < media) {
				*(aux1 + i) = *(cadena_char + i);
			}
			else {
				*(aux2 + contador) = *(cadena_char + i);
				contador++;
			}
		}
		
		if (es_igual(aux1, aux2, media)) {
			return true;
		}

	}

	return false;
}

bool Operaciones::es_igual(char* cadena1, char* cadena2, int dim)
{
	for (int i = 0; i < dim; i++) {

		if (*(cadena1 + i) != *(cadena2 + i)) {
			return false;
		}

	}

	return true;
}

bool Operaciones::es_impar(int numero)
{
	if (numero % 2 != 0) {
		return true;
	}
	return false;
}
