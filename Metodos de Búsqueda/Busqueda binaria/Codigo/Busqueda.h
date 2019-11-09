/***********************************************************************
 * Module:  Busqueda.h
 * Author:  Jorge Galarza
 * Modified: sabado, 9 de noviembre de 2019 10:41:46
 * Purpose: Declaration of the class Busqueda
 ***********************************************************************/

#ifndef BUSQUEDA_H
#define BUSQUEDA_H


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Ingreso.h"
using namespace std;
class Busqueda
{
	public:
		int* ordenamientoBurbuja(int, int*);
		int busquedaBinaria(int,int,int, int*);
		int* inicializarVector(int);
		int* ingresoDatos(int,int*);
};

#endif
