/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 2967                                                       *
******************************************************************/
#ifndef INGRESO_H
#define INGRESO_H

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

class Ingreso {
public:
protected:
};

#endif
