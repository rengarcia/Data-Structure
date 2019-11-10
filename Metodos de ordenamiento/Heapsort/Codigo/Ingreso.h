/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 2967                                                       *
******************************************************************/
#include <iostream>
using namespace std;

class Ingreso {
public:

	string ingresar(string msg);
};

string Ingreso::ingresar(string msg) {
	string valor;
	cout << msg << endl;
	cin >> valor;
	return valor;
}
