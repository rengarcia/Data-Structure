/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 2967                                                       *
******************************************************************/
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
