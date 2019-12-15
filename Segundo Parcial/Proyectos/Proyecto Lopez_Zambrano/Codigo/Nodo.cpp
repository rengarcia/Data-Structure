/***********************************************************************
 * Module:  Nodo.cpp
 * Author:  fleia
 * Modified: Saturday, November 30, 2019 1:37:37 PM
 * Purpose: Implementation of the class Nodo
 ***********************************************************************/

#include "Nodo.h"

////////////////////////////////////////////////////////////////////////
// Name:       Nodo::getCubo()
// Purpose:    Implementation of Nodo::getCubo()
// Return:     Cubo
////////////////////////////////////////////////////////////////////////

Cubo Nodo::getCubo(void)
{
   return cubo;
}

////////////////////////////////////////////////////////////////////////
// Name:       Nodo::setCubo(Cubo newCubo)
// Purpose:    Implementation of Nodo::setCubo()
// Parameters:
// - newCubo
// Return:     void
////////////////////////////////////////////////////////////////////////

void Nodo::setCubo(Cubo newCubo)
{
   cubo = newCubo;
}

////////////////////////////////////////////////////////////////////////
// Name:       Nodo::getSiguiente()
// Purpose:    Implementation of Nodo::getSiguiente()
// Return:     Nodo*
////////////////////////////////////////////////////////////////////////

Nodo* Nodo::getSiguiente(void)
{
   return siguiente;
}

////////////////////////////////////////////////////////////////////////
// Name:       Nodo::setSiguiente(Nodo* newSiguiente)
// Purpose:    Implementation of Nodo::setSiguiente()
// Parameters:
// - newSiguiente
// Return:     void
////////////////////////////////////////////////////////////////////////

void Nodo::setSiguiente(Nodo* newSiguiente)
{
   siguiente = newSiguiente;
}

////////////////////////////////////////////////////////////////////////
// Name:       Nodo::getAnterior()
// Purpose:    Implementation of Nodo::getAnterior()
// Return:     Nodo*
////////////////////////////////////////////////////////////////////////

Nodo* Nodo::getAnterior(void)
{
   return anterior;
}

////////////////////////////////////////////////////////////////////////
// Name:       Nodo::setAnterior(Nodo* newAnterior)
// Purpose:    Implementation of Nodo::setAnterior()
// Parameters:
// - newAnterior
// Return:     void
////////////////////////////////////////////////////////////////////////

void Nodo::setAnterior(Nodo* newAnterior)
{
   anterior = newAnterior;
}