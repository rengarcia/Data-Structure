/***********************************************************************
 * Module:  Nodo.cpp
 * Author:  Kevin Zurita
 * Modified: Thursday, November 13, 2019 10:38:09 AM
 * Purpose: Implementation of the class Nodo
 ***********************************************************************/

#include "Nodo.h"

////////////////////////////////////////////////////////////////////////
// Name:       Nodo::getperson()
// Purpose:    Implementation of Nodo::getperson()
// Return:     Persona
////////////////////////////////////////////////////////////////////////

Persona Nodo::getperson(void)
{
   return person;
}

////////////////////////////////////////////////////////////////////////
// Name:       Nodo::setperson(Persona newPerson)
// Purpose:    Implementation of Nodo::setperson()
// Parameters:
// - newPerson
// Return:     void
////////////////////////////////////////////////////////////////////////

void Nodo::setperson(Persona newPerson)
{
   person = newPerson;
}

////////////////////////////////////////////////////////////////////////
// Name:       Nodo::getsiguiente()
// Purpose:    Implementation of Nodo::getsiguiente()
// Return:     Nodo
////////////////////////////////////////////////////////////////////////

Nodo* Nodo::getsiguiente(void)
{
   return siguiente;
}

////////////////////////////////////////////////////////////////////////
// Name:       Nodo::setsiguiente(Nodo newsiguiente)
// Purpose:    Implementation of Nodo::setsiguiente()
// Parameters:
// - newsiguiente
// Return:     void
////////////////////////////////////////////////////////////////////////

void Nodo::setsiguiente(Nodo* newSiguiente)
{
   siguiente = newSiguiente;
}
