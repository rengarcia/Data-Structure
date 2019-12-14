/***********************************************************************
 * Module:  NodoPersona.h
 * Author:  fleia
 * Modified: Wednesday, November 13, 2019 10:28:40 AM
 * Purpose: Declaration of the class NodoPersona
 ***********************************************************************/

#if !defined(__DiagramaBase_NodoPersona_h)
#define __DiagramaBase_NodoPersona_h

#include "Persona.h"

class NodoPersona
{
public:
   NodoPersona* getSiguiente(void);
   void setSiguiente(NodoPersona* newSiguiente);
   Persona getPersona(void);
   void setPersona(Persona newPersona);

private:
   NodoPersona* siguiente;
   Persona persona;

};

#endif