/********************************************
 UNIVERSIDAD DE LAS FUERZAAS ARMADAS ESPE
*********************************************
    ESTRUCTURA DE DATOS PROYECTO PRIMER PARCIAL
                 INTEGRANTES:
                - DANIEL AVILA
                - DIEGO ZURITA
FECHA: 
*********************************************/

#include <iostream>
using namespace std;

class Ingreso {
public:

	string ingresar(string msg);
};
/*************************************
*Ingreso de valores
*************************************/
string Ingreso::ingresar(string msg) {
	string valor;
	cout << msg << endl;
	cin >> valor;
	return valor;
}
