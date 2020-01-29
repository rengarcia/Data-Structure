#include "Operaciones.h"
#include "Validacion.h"
Validacion validacion;


void Operaciones::Palindromo(string cadena)
{
	int dim = cadena.length();
	char* temporal1 = (char*)cadena.c_str();
	char* temporal2 = new char[dim];

	int pivot = 0;
	for (int i = dim - 1; i >= 0; i--) {
		*(temporal2 + i) = *(temporal1 + pivot);
		pivot++;
	}

	bool flag = true;
	for (int i = 0; i < dim; i++) {
		if (*(temporal1 + i) != *(temporal2 + i)) {
			flag = false;
		}
	}

	if (flag == true) {
		cout << "Es un palindromo" << endl;

	}

	else {
		cout << "No es un palindromo" << endl;
	}
}

string Operaciones::convertir(string cadena)
{
	string resultado;
	resultado = removerAcentuacionyDieresis(cadena);
	resultado = validacion.soloLetras(resultado);
	resultado = removerEspacioySignos(resultado);
	resultado = aMinusculas(resultado);

	return resultado;
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

string Operaciones::removerEspacioySignos(string cadena)
{
	char* temp = (char*)cadena.c_str();
	int count = 0;

	for (int i = 0; *(temp + i); i++) {
		if (*(temp + i) != '.' && *(temp + i) != ',' && *(temp + i) != ' ' && *(temp + i) != ':' 
			&& *(temp + i) != ';' && cadena.at(i) != '¡' && cadena.at(i) != '!') {
			*(temp + count) = *(temp+i);
			count++;
		}

	}
	*(temp + count) = '\0';

	string resultado(temp);

	return resultado;
}

string Operaciones::removerAcentuacionyDieresis(string cadena)
{
	int dim = cadena.size();
	char* temp = (char*)cadena.c_str();

	for (int i = 0; i< dim; i++) {
	
		if (*(temp + i) == 'Á') {
			*(temp + i) = 'A';
		}

		if (*(temp + i) == 'É') {
			*(temp + i) = 'E';
		}

		if (*(temp + i) == 'Í') {
			*(temp + i) = 'I';
		}

		if (*(temp + i) == 'Ó') {
			*(temp + i) = 'O';
		}

		if (*(temp + i) == 'Ú') {
			*(temp + i) = 'U';
		}

		if (*(temp + i) == 'á') {
			*(temp + i) = 'a';
		}

		if (*(temp + i) == 'é') {
			*(temp + i) = 'e';
		}
		
		if (*(temp + i) == 'í') {
			*(temp + i) = 'i';
		}

		if (*(temp + i) == 'ó') {
			*(temp + i) = 'o';
		}

		if (*(temp + i) == 'ú') {
			*(temp + i) = 'u';
		}

		if (*(temp + i) == 'ü') {
			*(temp + i) = 'u';
		}
	}

	string resultado(temp);

	return resultado;
}

