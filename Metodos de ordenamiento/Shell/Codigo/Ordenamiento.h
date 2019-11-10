/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 2967                                                       *
******************************************************************/
#ifndef ORDENAMIENTO_H
#define ORDENAMIENTO_H

#include <iostream>
#include <stdlib.h>
#include "Ingreso.h"

using namespace std;

class Ordenamiento {
public:
    void ingresarDatos(int dim, int* arreglo);
    void imprimir(int* arreglo, int dim);
    void ordenarShell(int* arreglo, int dim);
    int* inicializarVector(int dim);
    Ordenamiento();
    ~Ordenamiento();

protected:
private:

};

#endif
