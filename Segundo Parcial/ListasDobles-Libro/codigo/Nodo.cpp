/***********************************************************************
 * Module:  Nodo.cpp
 * Author:  NICKOLAS
 * Modified: s�bado, 23 de noviembre de 2019 20:20:06
 * Purpose: Implementation of the class Nodo
 ***********************************************************************/

#include "Nodo.h"

////////////////////////////////////////////////////////////////////////
// Name:       Nodo::getlibro()
// Purpose:    Implementation of Nodo::getlibro()
// Return:     Libro
////////////////////////////////////////////////////////////////////////

Libro Nodo::getlibro(void)
{
   return libro;
}

////////////////////////////////////////////////////////////////////////
// Name:       Nodo::setlibro(Libro newLibro)
// Purpose:    Implementation of Nodo::setlibro()
// Parameters:
// - newLibro
// Return:     void
////////////////////////////////////////////////////////////////////////

void Nodo::setlibro(Libro newLibro)
{
   libro = newLibro;
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
// Name:       Nodo::setsiguiente(Nodo* newSiguiente)
// Purpose:    Implementation of Nodo::setsiguiente()
// Parameters:
// - newSiguiente
// Return:     void
////////////////////////////////////////////////////////////////////////

void Nodo::setsiguiente(Nodo* newSiguiente)
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
// Name:       Nodo::setanterior(Nodo* newAnterior)
// Purpose:    Implementation of Nodo::setanterior()
// Parameters:
// - newAnterior
// Return:     void
////////////////////////////////////////////////////////////////////////

void Nodo::setanterior(Nodo* newAnterior)
{
   anterior = newAnterior;
}

////////////////////////////////////////////////////////////////////////
// Name:       Nodo::Nodo()
// Purpose:    Implementation of Nodo::Nodo()
// Return:     
////////////////////////////////////////////////////////////////////////

Nodo::Nodo()
{
}