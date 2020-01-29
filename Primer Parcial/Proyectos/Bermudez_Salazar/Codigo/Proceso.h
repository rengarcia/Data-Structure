/***********************************************************************
 * Module:  Proceso.h
 * Author:  Alan
 * Modified: sábado, 02 de noviembre de 2019 11:21:27
 * Purpose: Declaration of the class Proceso
 ***********************************************************************/

#if !defined(__Indiana_Croft_Proceso_h)
#define __Indiana_Croft_Proceso_h

#include "Laberinto.h"

class Proceso
{
public:
   virtual void generarSolucion(int** laberinto,int fila_actual,int columnas_actual,int n,int direccion)=0;

protected:
private:

};




#endif
