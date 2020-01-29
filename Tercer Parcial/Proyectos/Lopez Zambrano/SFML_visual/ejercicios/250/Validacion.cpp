#include "Validacion.h"

string Validacion::dimValida(string cadena)
{
	for (int i = 0; i < cadena.length(); i++) {
		if (!isdigit(cadena.at(i))||cadena.length()>1) {
			cout << "Dato no valido, el valor minimo es 1 y el maximo 10:" << endl;
			cin >> cadena;
			i = -1;
		}
	}
	return cadena;
}

string Validacion::soloNumeros(string cadena)
{
	for (int i = 0; i < cadena.length(); i++) {
		if (!isdigit(cadena.at(i))&& cadena.at(i)!='-') {
			cout << "Dato no valido, reingrese:" << endl;
			cin >> cadena;
			i = -1;
		}
	}
	return cadena;
}
