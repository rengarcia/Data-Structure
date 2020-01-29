/***********************************************************************
 * Module:  Validacion.h
 * Author:  fleia
 * Modified: Monday, January 20, 2020 ‏‎10:14:25 AM
 * Purpose: Declaration of the class Validacion
 ***********************************************************************/

#if !defined(__Class_Diagram_1_Validacion_h)
#define __Class_Diagram_1_Validacion_h

#include <string>
#include <iostream>
using namespace std;

class Validacion
{
public:
	string soloNumeros(string cadena);
	string dentroDeLimites(string cadena);
};

#endif