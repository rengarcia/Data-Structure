/***********************************************************************
 * Module:  Autor.cpp
 * Author:  ALEX
 * Modified: Saturday, December 14, 2019 8:55:50 PM
 * Purpose: Implementation of the class Autor
 ***********************************************************************/

#include "Autor.h"

////////////////////////////////////////////////////////////////////////
// Name:       Autor::Autor()
// Purpose:    Implementation of Autor::Autor()
// Return:     
////////////////////////////////////////////////////////////////////////

Autor::Autor()
{
}

////////////////////////////////////////////////////////////////////////
// Name:       Autor::~Autor()
// Purpose:    Implementation of Autor::~Autor()
// Return:     
////////////////////////////////////////////////////////////////////////

Autor::~Autor()
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       Autor::getPersona()
// Purpose:    Implementation of Autor::getPersona()
// Return:     Persona
////////////////////////////////////////////////////////////////////////

Persona Autor::getPersona(void)
{
   return persona;
}

////////////////////////////////////////////////////////////////////////
// Name:       Autor::setPersona(Persona newPersona)
// Purpose:    Implementation of Autor::setPersona()
// Parameters:
// - newPersona
// Return:     void
////////////////////////////////////////////////////////////////////////

void Autor::setPersona(Persona newPersona)
{
   persona = newPersona;
}

////////////////////////////////////////////////////////////////////////
// Name:       Autor::getNumPublicacion()
// Purpose:    Implementation of Autor::getNumPublicacion()
// Return:     int
////////////////////////////////////////////////////////////////////////

int Autor::getNumPublicacion(void)
{
   return numPublicacion;
}

////////////////////////////////////////////////////////////////////////
// Name:       Autor::setNumPublicacion(int newNumPublicacion)
// Purpose:    Implementation of Autor::setNumPublicacion()
// Parameters:
// - newNumPublicacion
// Return:     void
////////////////////////////////////////////////////////////////////////

void Autor::setNumPublicacion(int newNumPublicacion)
{
   numPublicacion = newNumPublicacion;
}