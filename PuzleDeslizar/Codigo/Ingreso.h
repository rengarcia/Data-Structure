#include <iostream>
#include <string>
#include "Validacion.h"

using namespace std;

class Ingreso {

public:
	string leer(string,int);
};

string Ingreso::leer(string mensage,int tipo) {
	Validacion validacion;
	string entrada;
	cout << mensage << endl;
	getline(cin,entrada);
	while (validacion.validar(entrada, tipo)) {
		cout << "Valor no valido reingrese" << endl;
		cin >> entrada;
	}
	return entrada;

}
