/***********************************************************************
 * Module:  NodoInt.cpp
 * Author:  fleia
 * Modified: Sunday, December 8, 2019 11:37:36 PM
 * Purpose: Implementation of the class NodoInt
 ***********************************************************************/

#include "NodoInt.h"

////////////////////////////////////////////////////////////////////////
// Name:       NodoInt::getDato()
// Purpose:    Implementation of NodoInt::getDato()
// Return:     int
////////////////////////////////////////////////////////////////////////

int NodoInt::getDato(void)
{
   return dato;
}

////////////////////////////////////////////////////////////////////////
// Name:       NodoInt::setDato(int newDato)
// Purpose:    Implementation of NodoInt::setDato()
// Parameters:
// - newDato
// Return:     void
////////////////////////////////////////////////////////////////////////

void NodoInt::setDato(int newDato)
{
   dato = newDato;
}

////////////////////////////////////////////////////////////////////////
// Name:       NodoInt::getSiguiente()
// Purpose:    Implementation of NodoInt::getSiguiente()
// Return:     NodoInt*
////////////////////////////////////////////////////////////////////////

NodoInt* NodoInt::getSiguiente(void)
{
   return siguiente;
}

////////////////////////////////////////////////////////////////////////
// Name:       NodoInt::setSiguiente(NodoInt* newSiguiente)
// Purpose:    Implementation of NodoInt::setSiguiente()
// Parameters:
// - newSiguiente
// Return:     void
////////////////////////////////////////////////////////////////////////

void NodoInt::setSiguiente(NodoInt* newSiguiente)
{
   siguiente = newSiguiente;
}