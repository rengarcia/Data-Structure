/***********************************************************************
 * Module:  NodoPersona.cpp
 * Author:  fleia
 * Modified: Wednesday, November 13, 2019 10:28:40 AM
 * Purpose: Implementation of the class NodoPersona
 ***********************************************************************/

#include "NodoPersona.h"

////////////////////////////////////////////////////////////////////////
// Name:       NodoPersona::getSiguiente()
// Purpose:    Implementation of NodoPersona::getSiguiente()
// Return:     NodoPersona*
////////////////////////////////////////////////////////////////////////

NodoPersona* NodoPersona::getSiguiente(void)
{
   return siguiente;
}

////////////////////////////////////////////////////////////////////////
// Name:       NodoPersona::setSiguiente(NodoPersona* newSiguiente)
// Purpose:    Implementation of NodoPersona::setSiguiente()
// Parameters:
// - newSiguiente
// Return:     void
////////////////////////////////////////////////////////////////////////

void NodoPersona::setSiguiente(NodoPersona* newSiguiente)
{
   siguiente = newSiguiente;
}

////////////////////////////////////////////////////////////////////////
// Name:       NodoPersona::getPersona()
// Purpose:    Implementation of NodoPersona::getPersona()
// Return:     Persona
////////////////////////////////////////////////////////////////////////

Persona NodoPersona::getPersona(void)
{
   return persona;
}

////////////////////////////////////////////////////////////////////////
// Name:       NodoPersona::setPersona(Persona newPersona)
// Purpose:    Implementation of NodoPersona::setPersona()
// Parameters:
// - newPersona
// Return:     void
////////////////////////////////////////////////////////////////////////

void NodoPersona::setPersona(Persona newPersona)
{
   persona = newPersona;
}