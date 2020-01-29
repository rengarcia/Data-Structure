#include "Validacion.h"

string Validacion::soloNumeros(string cadena)
{
	for (int i = 0; i < cadena.length(); i++) {
		if (!isdigit(cadena.at(i)) && cadena.at(i) != ' ') {
			cout << "Dato no valido, no se permiten decimales o numeros negativos,Reingrese" << endl;
			cout << "Lista: ";
			getline(cin, cadena);
			i = -1;
		}
	}
	return cadena;
}

