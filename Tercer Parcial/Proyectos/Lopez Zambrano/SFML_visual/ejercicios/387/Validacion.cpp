#include "Validacion.h"

string Validacion::soloNumeros(string cadena)
{
	for (int i = 0; i < cadena.length(); i++) {
		if (!isdigit(cadena.at(i))||cadena.length()>1) {
			cout << "Dato no valido, Reingrese: " << endl;
			cin >> cadena;
			i = -1;
		}
	}
	return cadena;
}

int Validacion::dentroRango(string cadena)
{
	int aux;

	for (int i = 0; i < cadena.length(); i++) {
		
		int aux = cadena.at(i) - '0';

		if (aux > 4 || aux <-1) {
			cout << "Dato fuera de rango, Reingrese: " << endl;
			cin >> cadena;
			cadena = soloNumeros(cadena);
			i = -1;
		}
	}
	
	int resultado = stoi(cadena);

	return resultado;
}

