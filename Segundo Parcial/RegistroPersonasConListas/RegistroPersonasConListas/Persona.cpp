/***********************************************************************
 * Module:  Persona.cpp
 * Author:  fleia
 * Modified: Wednesday, November 13, 2019 10:49:37 AM
 * Purpose: Implementation of the class Persona
 ***********************************************************************/

#include "Persona.h"
#include <string>

using namespace std;
////////////////////////////////////////////////////////////////////////
// Name:       Persona::getIdPersona()
// Purpose:    Implementation of Persona::getIdPersona()
// Return:     string
////////////////////////////////////////////////////////////////////////

string Persona::getIdPersona(void)
{
   return idPersona;
}

////////////////////////////////////////////////////////////////////////
// Name:       Persona::setIdPersona(string newIdPersona)
// Purpose:    Implementation of Persona::setIdPersona()
// Parameters:
// - newIdPersona
// Return:     void
////////////////////////////////////////////////////////////////////////

void Persona::setIdPersona(string newIdPersona)
{
   idPersona = newIdPersona;
}

////////////////////////////////////////////////////////////////////////
// Name:       Persona::getCedula()
// Purpose:    Implementation of Persona::getCedula()
// Return:     string
////////////////////////////////////////////////////////////////////////

string Persona::getCedula(void)
{
   return cedula;
}

////////////////////////////////////////////////////////////////////////
// Name:       Persona::setCedula(string newCedula)
// Purpose:    Implementation of Persona::setCedula()
// Parameters:
// - newCedula
// Return:     void
////////////////////////////////////////////////////////////////////////

void Persona::setCedula(string newCedula)
{
   cedula = newCedula;
}

////////////////////////////////////////////////////////////////////////
// Name:       Persona::getApellido()
// Purpose:    Implementation of Persona::getApellido()
// Return:     string
////////////////////////////////////////////////////////////////////////

string Persona::getApellido(void)
{
   return apellido;
}

////////////////////////////////////////////////////////////////////////
// Name:       Persona::setApellido(string newApellido)
// Purpose:    Implementation of Persona::setApellido()
// Parameters:
// - newApellido
// Return:     void
////////////////////////////////////////////////////////////////////////

void Persona::setApellido(string newApellido)
{
   apellido = newApellido;
}

////////////////////////////////////////////////////////////////////////
// Name:       Persona::getSiguiente()
// Purpose:    Implementation of Persona::getSiguiente()
// Return:     string
////////////////////////////////////////////////////////////////////////

string Persona::getNombre(void)
{
   return nombre;
}

////////////////////////////////////////////////////////////////////////
// Name:       Persona::setSiguiente(string newSiguiente)
// Purpose:    Implementation of Persona::setSiguiente()
// Parameters:
// - newSiguiente
// Return:     void
////////////////////////////////////////////////////////////////////////

void Persona::setNombre(string newSiguiente)
{
   nombre = newSiguiente;
}