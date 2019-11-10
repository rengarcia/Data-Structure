/**
  * Universidad De las Fuerzas Armadas ESPE
  * Carrera: Ingeniería de Software
  * Materia: Estructura de Datos
  * Tema: Cubo Magico
  * NRC: 2969
*/
#include <iostream>
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
	cin >> entrada;
	while (validacion.validar(entrada, tipo)) {
		cout << "Valor no valido reingrese" << endl;
		cin >> entrada;
	}
	return entrada;

}
