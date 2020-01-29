#include "Validacion.h"

string Validacion::soloLetras(string cadena)
{
	for (int i = 0; i < cadena.length(); i++) {
		if (!isalpha(cadena.at(i)) && cadena.at(i) != ' ') {
			cout << "Dato no valido, Reingrese" << endl;
			cin >> cadena;
			i = -1;
		}
	}
	return cadena;
}

string Validacion::unCaracter(string cadena)
{
	while (cadena.length() > 1) {
		cout << "Ingrese solo un caracter: " << endl;
		cin >> cadena;
		cadena = soloLetras(cadena);
	}

	return cadena;
}


