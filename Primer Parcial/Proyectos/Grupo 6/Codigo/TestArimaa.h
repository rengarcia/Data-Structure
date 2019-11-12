/***********************************************************************
 * Module:  TestArimaa.h
 * Author:  Kevin Duy, Carlos Puco
 * Modified: sabado, 26 de octubre de 2019 17:21:23
 * Purpose: Declaration of the class TestArimaa
 ***********************************************************************/

#include <iostream>
#include <assert.h>
#include "ingreso.h"

using namespace std;

class TestArimaa {
	public:
		void comprobarPositivos() {
			Ingreso leer;
			int valorEsperado, valorReal;
			cout << "Ingrese un numero positivo: ";
			valorEsperado = leer.ingresarEntero();
			cout << "Ingrese el mismo numero positivo: ";
			valorReal = leer.ingresarEntero();
			assert(valorEsperado == valorReal);
		}
		
		void comprobarNegativos() {
			Ingreso leer;
			int valorEsperado, valorReal;
			cout << "Ingrese un numero negativo: ";
			valorEsperado = leer.ingresarEntero();
			cout << "Ingrese el mismo numero negativo: ";
			valorReal = leer.ingresarEntero();
			assert(valorEsperado == valorReal);
		}
};
