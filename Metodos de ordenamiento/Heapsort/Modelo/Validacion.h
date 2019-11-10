/** 

        UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
	
CARRERA: INGENIERIA DE SOFTWARE
MATERIA: ESTRUCTURA DE DATOS
TEMA: METODOS DE ORDENAMIENTO: ORDENAMIENTO HEAR SORT
NRC: 2967

 */

#include <iostream>
using namespace std;

class Validacion
{
public:
	int validar(string val);
};

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
