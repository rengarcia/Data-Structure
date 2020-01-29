#include "Validacion.h"

string Validacion::soloNumeros(string cadena)
{
	for (int i = 0; i < cadena.length(); i++) {
		if (!isdigit(cadena.at(i)) || cadena.length() > 4) {
			cout << "Dato no valido, Reingrese: " << endl;
			cin >> cadena;
			i = -1;
		}
	}
	return cadena;
}

string Validacion::dentroDeLimites(string cadena)
{
	int temp;

	for (int i = 0; i < cadena.length(); i++) {
		temp = cadena.at(i) - 48;

		if (temp < 0 || temp >7) {
			cout << "Tu movimiento esta fuera de los limites, Reingrese: " << endl;
			cin >> cadena;
			cadena = soloNumeros(cadena);
			i = -1;
		}

	}

	return cadena;
}



