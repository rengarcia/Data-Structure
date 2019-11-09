/***********************************************************************
 * Module:  Ordenamiento.h
 * Author:  User
 * Modified: sábado, 9 de noviembre de 2019 17:05:03
 * Purpose: Declaration of the class Ordenamiento
 ***********************************************************************/


#ifndef ORDENAMIENTO_H
#define ORDENAMIENTO_H

#include <iostream>
#include <stdlib.h>
#include "Ingreso.h"

using namespace std;

class Ordenamiento
{
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
