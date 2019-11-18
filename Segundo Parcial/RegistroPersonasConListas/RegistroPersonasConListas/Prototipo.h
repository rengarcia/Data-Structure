/***********************************************************************
 * Module:  Prototipo.h
 * Author:  fleia
 * Modified: Wednesday, November 13, 2019 10:51:12 AM
 * Purpose: Declaration of the class Prototipo
 ***********************************************************************/

#if !defined(__DiagramaBase_Prototipo_h)
#define __DiagramaBase_Prototipo_h

#include "NodoPersona.h"
#include "Persona.h"

class Prototipo
{
public:
   NodoPersona* insertarCabeza(NodoPersona* referencia, Persona persona);
   NodoPersona* insertarCola(NodoPersona* referencia, Persona persona);
   void imprimir(NodoPersona* referencia);

};

#endif