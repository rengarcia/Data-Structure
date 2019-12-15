/***********************************************************************
 * Module:  Nodo.cpp
 * Author:  Alan
 * Modified: lunes, 18 de noviembre de 2019 23:20:19
 * Purpose: Implementation of the class Nodo
 ***********************************************************************/

#include "Nodo.h"

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

Nodo* Nodo::getAnterior(void)
{
    return anterior;
}

void Nodo::setAnterior(Nodo* newAnterior)
{
    anterior = newAnterior;
}

void Nodo::setNumero(int newNumero)
{
    numero = newNumero;
}

int Nodo::getNumero(void)
{
    return numero;
}
