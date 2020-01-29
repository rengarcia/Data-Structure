#include "Validacion.h"

string Validacion::soloNumeros(string cadena)
{
	for (int i = 0; i < cadena.length(); i++) {
		if (!isdigit(cadena.at(i)) && cadena.at(i)!='.'&& cadena.at(i)!= '-' || cadena.length() >6) {
			cout << "Dato no valido, Reingrese:" << endl;
			cin >> cadena;
			i = -1;
		}
	}
	return cadena;
}
