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

class Validacion
{
public:
	int validar(string val);
};

/*******************************************
*Valida el ingreso de solo numero enteros o decimales
*y si el numero tiene mas de un punto
*******************************************/
 
int Validacion::validar(string val) {
		int validez = 0;
		int punto = 0;
		int letras = 0;

		for (int i = 0; i < val.size(); i++)
		{
			if (!isdigit(val[i])) {
				letras++;
			}

			if (val[i] == '.') {
				punto++;
			}
		}

		if ((letras - punto) > 0 || punto > 1) {
			validez = 1;
		}

		return validez;
	}
