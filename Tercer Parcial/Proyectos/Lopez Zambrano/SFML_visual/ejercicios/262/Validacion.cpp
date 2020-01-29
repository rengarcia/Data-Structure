#include "Validacion.h"

string Validacion::soloNumeros(string cadena)
{
	for (int i = 0; i < cadena.length(); i++) {
		if (!isdigit(cadena.at(i))&&cadena.at(i)!='-' && cadena.at(i) != '.') {
			cout << "Dato no valido, Reingrese: " << endl;
			cin >> cadena;
			i = -1;
		}
	}
	return cadena;
}

float Validacion::mayorA1(float numero)
{
	string aux;
	
	while (numero < 1 && numero > -1) {
		cout << "Ingrese un numero mayor a 1 o menor a -1 porfavor: " << endl;
		cin >> aux;
		aux = soloNumeros(aux);
		numero = strtof((aux).c_str(), 0);
	}

	return numero;

}




