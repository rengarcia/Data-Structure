/***********************************************************************
 * Module:  NodoDouble.cpp
 * Author:  fleia
 * Modified: Sunday, December 8, 2019 11:44:13 PM
 * Purpose: Implementation of the class NodoDouble
 ***********************************************************************/

#include "NodoDouble.h"

////////////////////////////////////////////////////////////////////////
// Name:       NodoDouble::getDato()
// Purpose:    Implementation of NodoDouble::getDato()
// Return:     double
////////////////////////////////////////////////////////////////////////

double NodoDouble::getDato(void)
{
   return dato;
}

////////////////////////////////////////////////////////////////////////
// Name:       NodoDouble::setDato(double newDato)
// Purpose:    Implementation of NodoDouble::setDato()
// Parameters:
// - newDato
// Return:     void
////////////////////////////////////////////////////////////////////////

void NodoDouble::setDato(double newDato)
{
   dato = newDato;
}

////////////////////////////////////////////////////////////////////////
// Name:       NodoDouble::getSiguiente()
// Purpose:    Implementation of NodoDouble::getSiguiente()
// Return:     NodoDouble*
////////////////////////////////////////////////////////////////////////

NodoDouble* NodoDouble::getSiguiente(void)
{
   return siguiente;
}

////////////////////////////////////////////////////////////////////////
// Name:       NodoDouble::setSiguiente(NodoDouble* newSiguiente)
// Purpose:    Implementation of NodoDouble::setSiguiente()
// Parameters:
// - newSiguiente
// Return:     void
////////////////////////////////////////////////////////////////////////

void NodoDouble::setSiguiente(NodoDouble* newSiguiente)
{
   siguiente = newSiguiente;
}