#include "Validacion.h"

string Validacion::soloLetrasyNumeros(string cadena)
{
	for (int i = 0; i < cadena.length(); i++) {
		if (!isalpha(cadena.at(i))&& cadena.at(i) != ' '&&!isdigit(cadena.at(i))) {
			cout << "Dato no valido, Reingrese" << endl;
			getline(cin, cadena);
			while ((getchar()) != '\n');
			i = -1;
		}
	}
	return cadena;
}

string Validacion::soloNumeros(string cadena)
{
	for (int i = 0; i < cadena.length(); i++) {
		if (!isdigit(cadena.at(i))) {
			cout << "Dato no valido, Reingrese" << endl;
			getline(cin, cadena);
			i = -1;
		}
	}
	return cadena;
}


int Validacion::valorN(int n)
{
	string aux;
	bool bandera = true;
	while (bandera)
	{
		if (n > 10 || n < 1) {
			cout << "Dato invalido, reingrese !"<<endl;
			cin >> aux;
			while ((getchar()) != '\n');
			aux = soloNumeros(aux);
			n = stoi(aux);
		}
		else
		{
			bandera = false;
		}
	}

	return n;

}
