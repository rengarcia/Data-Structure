/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 2967                                                       *
******************************************************************/

#ifndef BUSQUEDA_H
#define BUSQUEDA_H


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Ingreso.h"
using namespace std;

class Busqueda {
public:
    int* ordenamientoBurbuja(int, int*);
    int busquedaBinaria(int, int, int, int*);
    int* inicializarVector(int);
    int* ingresoDatos(int, int*);
};

#endif
