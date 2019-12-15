/***********************************************************************
 * Module:  Nodo.h
 * Author:  fleia
 * Modified: Saturday, November 30, 2019 1:37:37 PM
 * Purpose: Declaration of the class Nodo
 ***********************************************************************/

#if !defined(__proyecto_Nodo_h)
#define __proyecto_Nodo_h

#include "Cubo.h"

class Nodo
{
public:
   Cubo getCubo(void);
   void setCubo(Cubo newCubo);
   Nodo* getSiguiente(void);
   void setSiguiente(Nodo* newSiguiente);
   Nodo* getAnterior(void);
   void setAnterior(Nodo* newAnterior);

private:
   Cubo cubo;
   Nodo* siguiente;
   Nodo* anterior;

};

#endif