/** 

        UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
	
CARRERA: INGENIERIA DE SOFTWARE
MATERIA: ESTRUCTURA DE DATOS
TEMA: METODOS DE ORDENAMIENTO: ORDENAMIENTO HEAR SORT
NRC: 2967

 */

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
