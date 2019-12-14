/***********************************************************************
 * Module:  Nodo.cpp
 * Author:  K-vn-
 * Modified: miércoles, 13 de noviembre de 2019 10:41:23
 * Purpose: Implementation of the class Nodo
 ***********************************************************************/

#include "Nodo.h"
#include "Persona.cpp"

////////////////////////////////////////////////////////////////////////
// Name:       Nodo::getPersona()
// Purpose:    Implementation of Nodo::getPersona()
// Return:     Persona
////////////////////////////////////////////////////////////////////////

Persona Nodo::getPersona(void)
{
   return persona;
}

////////////////////////////////////////////////////////////////////////
// Name:       Nodo::setPersona(Persona newPersona)
// Purpose:    Implementation of Nodo::setPersona()
// Parameters:
// - newPersona
// Return:     void
////////////////////////////////////////////////////////////////////////

void Nodo::setPersona(Persona newPersona)
{
   persona = newPersona;
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
// Name:       Nodo::Nodo()
// Purpose:    Implementation of Nodo::Nodo()
// Return:     
////////////////////////////////////////////////////////////////////////

Nodo::Nodo()
{
}

////////////////////////////////////////////////////////////////////////
// Name:       Nodo::~Nodo()
// Purpose:    Implementation of Nodo::~Nodo()
// Return:     
////////////////////////////////////////////////////////////////////////

Nodo::~Nodo()
{
   // TODO : implement
}

Nodo::Nodo(Persona _persona, Nodo *_sig) {
	persona = _persona;
	siguiente = _sig;
}
