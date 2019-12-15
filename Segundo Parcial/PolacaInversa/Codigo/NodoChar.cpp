/***********************************************************************
 * Module:  NodoChar.cpp
 * Author:  fleia
 * Modified: Sunday, December 8, 2019 11:28:08 PM
 * Purpose: Implementation of the class NodoChar
 ***********************************************************************/

#include "NodoChar.h"

////////////////////////////////////////////////////////////////////////
// Name:       NodoChar::getDato()
// Purpose:    Implementation of NodoChar::getDato()
// Return:     char
////////////////////////////////////////////////////////////////////////

char NodoChar::getDato(void)
{
   return dato;
}

////////////////////////////////////////////////////////////////////////
// Name:       NodoChar::setDato(char newDato)
// Purpose:    Implementation of NodoChar::setDato()
// Parameters:
// - newDato
// Return:     void
////////////////////////////////////////////////////////////////////////

void NodoChar::setDato(char newDato)
{
   dato = newDato;
}

////////////////////////////////////////////////////////////////////////
// Name:       NodoChar::getSiguiente()
// Purpose:    Implementation of NodoChar::getSiguiente()
// Return:     NodoChar*
////////////////////////////////////////////////////////////////////////

NodoChar* NodoChar::getSiguiente(void)
{
   return siguiente;
}

////////////////////////////////////////////////////////////////////////
// Name:       NodoChar::setSiguiente(NodoChar* newSiguiente)
// Purpose:    Implementation of NodoChar::setSiguiente()
// Parameters:
// - newSiguiente
// Return:     void
////////////////////////////////////////////////////////////////////////

void NodoChar::setSiguiente(NodoChar* newSiguiente)
{
   siguiente = newSiguiente;
}