/***********************************************************************
 * Module:  ImpProceso.h
 * Author:  Alan
 * Modified: sábado, 02 de noviembre de 2019 11:23:17
 * Purpose: Declaration of the class ImpProceso
 ***********************************************************************/

#if !defined(__Indiana_Croft_ImpProceso_h)
#define __Indiana_Croft_ImpProceso_h

#include "Proceso.h"
#include "Laberinto.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

class ImpProceso : public Proceso
{
public:
    void generarSolucion(int** laberinto,int fila_actual,int columnas_actual,int n,int direccion);
	bool validar(int** laberinto,int n);
protected:
private:

};




#endif
