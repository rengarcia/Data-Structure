#include "Operaciones.h"

double Operaciones::diferencial(double numero, double mitad)
{
	if (numero > (mitad * mitad * mitad))
		return (numero - (mitad * mitad * mitad));
	else
		return ((mitad * mitad * mitad) - numero);
}

double Operaciones::raiz_cubica(double numero)
{
	// Establecer inicio y fin para la busqueda binaria 
	double inicio = 0;
	double fin = numero;

	// Precision para el calculo
	double e = 0.00000001;

	while (true)
	{
		double mitad = (inicio + fin) / 2;
		double error = diferencial(numero, mitad);

		// Si el error es menor a e, entonces mitad 
		// es la respuesta
		if (error <= e)
			return mitad;

		// Si mitad*mitad*mitad es mayor que el numero, 
		// entonces fin sera igual a mitad
		if ((mitad * mitad * mitad) > numero)
			fin = mitad;

		// Si mitad*mitad*mitad es manero que el numero 
		// entonces inicio sera igual a mitad
		else
			inicio = mitad;
	}
}

string Operaciones::eliminarSigno(string cadena)
{
	char* temp = (char*)cadena.c_str();
	int count = 0;

	for (int i = 0; *(temp + i); i++) {
		if (*(temp + i) != '-') {
			*(temp + count) = *(temp + i);
			count++;
		}

	}
	*(temp + count) = '\0';

	string resultado(temp);

	return resultado;
}