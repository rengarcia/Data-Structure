#include "Validacion.h"

string Validacion::soloLetras(string cadena)
{
	for (int i = 0; i < cadena.length(); i++) {
		if (!isalpha(cadena.at(i)) && cadena.at(i) != ' ' && cadena.at(i) != '.'  && cadena.at(i) != ','
			&& cadena.at(i) != ':' && cadena.at(i) != ';') {
			cout << "Dato no valido, Reingrese" << endl;
			getline(cin, cadena);
			i = -1;
		}
	}
	return cadena;
}

