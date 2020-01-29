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

string Operaciones::Encriptar(string cadena,int valor)
{
	int dim = cadena.size();
	int aux;
	char* temp = (char*)cadena.c_str();

	for (int i = 0; i < dim; i++)
	{
		if (*(temp + i) > 47 && *(temp + i) < 58) {
			if (*(temp + i) + valor > 57) {
				aux = *(temp + i) + valor - 57;
				*(temp + i)  = 47 + aux;
			}
			else
			{
				*(temp + i) = *(temp + i) + valor;
			}
		}
			
		if (*(temp + i) > 96 && *(temp + i) < 123) {
			if (*(temp + i) + valor > 122) {
				aux = *(temp + i) + valor - 122;
				*(temp + i) = 96 + aux;
			}
			else {
				*(temp + i) = *(temp + i) + valor;
			}
		}

	}

	string resultado(temp);

	return resultado;
}

string Operaciones::Desencriptar(string cadena, int valor)
{
	int dim = cadena.size();
	int aux;
	char* temp = (char*)cadena.c_str();

	for (int i = 0; i < dim; i++)
	{
		if (*(temp + i) > 47 && *(temp + i) < 58) {
			if (*(temp + i) - valor < 48) {
				aux = 48 - (*(temp + i) - valor);
				*(temp + i) = 58 - aux;
			}
			else
			{
				*(temp + i) = *(temp + i) - valor;
			}
		}

		if (*(temp + i) > 96 && *(temp + i) < 123) {
			if (*(temp + i) - valor < 97) {
				aux = 97 - (*(temp + i) - valor);
				*(temp + i) = 123 - aux;
			}
			else {
				*(temp + i) = *(temp + i) - valor;
			}
		}

	}

	string resultado(temp);

	return resultado;
}






