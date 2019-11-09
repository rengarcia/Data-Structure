#ifndef INGRESO_H
#define INGRESO_H

/**
  * Universidad De las Fuerzas Armadas ESPE
  * Carrera: Ingeniería de Software
  * Materia: Estructura de Datos
  * NRC: 2969
  * @file ingreso.h
  * @version 1.0.0
  * @date 23/09/2019
  * @author Kevin Duy
  * @title Division
  * @brief Validacion del ingreso de datos
*/


#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
class Ingreso {
	public:
		int ingresarEntero();
		double ingresarDouble();
		string ingresarLetra();
		float ingresarFloat();
		bool validar(string);
		bool validarEntero(string);
		bool validarLetra(string);
};



#endif
#ifndef INGRESO_H
#define INGRESO_H

class Ingreso
{
	public:
	protected:
};

#endif
