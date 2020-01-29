#include "Validacion.h"

string Validacion::soloNumeros(string cadena)
{
	for (int i = 0; i < cadena.length(); i++) {
		if (!isdigit(cadena.at(i))) {
			cout << "Dato no valido, Reingrese: " << endl;
			getline(cin, cadena);
			i = -1;
		}
	}
	return cadena;
}

int Validacion::nValida(int n)
{
	string temp;
	while (n > 12) {
		cout << "El valor de \"n\" debe ser menor a o igual 12: ";
		getline(cin, temp);
		temp = soloNumeros(temp);
		n = stoi(temp);
	}

	return n;
}

int Validacion::mValida(int n, int m)
{
	string temp;
	while (m > n) {
		cout << "El valor de \"m\" debe ser menor o igual a n: ";
		getline(cin,temp);
		temp = soloNumeros(temp);
		m = stoi(temp);
	}

	return m;
}

