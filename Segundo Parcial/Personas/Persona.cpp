/***********************************************************************
 * Module:  Persona.cpp
 * Author:  Kevin Zurita
 * Modified: Thursday, November 13, 2019 10:38:09 AM
 * Purpose: Implementation of the class Persona
 ***********************************************************************/
#include <string>
#include "Persona.h"

////////////////////////////////////////////////////////////////////////
// Name:       Persona::getidPersona()
// Purpose:    Implementation of Persona::getidPersona()
// Return:     int
////////////////////////////////////////////////////////////////////////

int Persona::getidPersona(void)
{
   return idPersona;
}

////////////////////////////////////////////////////////////////////////
// Name:       Persona::setidPersona(int newIdPersona)
// Purpose:    Implementation of Persona::setidPersona()
// Parameters:
// - newIdPersona
// Return:     void
////////////////////////////////////////////////////////////////////////

void Persona::setidPersona(int newIdPersona)
{
   idPersona = newIdPersona;
}

////////////////////////////////////////////////////////////////////////
// Name:       Persona::getcedula()
// Purpose:    Implementation of Persona::getcedula()
// Return:     string
////////////////////////////////////////////////////////////////////////

string Persona::getcedula(void)
{
   return cedula;
}

////////////////////////////////////////////////////////////////////////
// Name:       Persona::setcedula(string newCedula)
// Purpose:    Implementation of Persona::setcedula()
// Parameters:
// - newCedula
// Return:     void
////////////////////////////////////////////////////////////////////////

void Persona::setcedula(string newCedula)
{
   cedula = newCedula;
}

////////////////////////////////////////////////////////////////////////
// Name:       Persona::getnombre()
// Purpose:    Implementation of Persona::getnombre()
// Return:     string
////////////////////////////////////////////////////////////////////////

string Persona::getnombre(void)
{
   return nombre;
}

////////////////////////////////////////////////////////////////////////
// Name:       Persona::setnombre(string newNombre)
// Purpose:    Implementation of Persona::setnombre()
// Parameters:
// - newNombre
// Return:     void
////////////////////////////////////////////////////////////////////////

void Persona::setnombre(string newNombre)
{
   nombre = newNombre;
}

////////////////////////////////////////////////////////////////////////
// Name:       Persona::getapellido()
// Purpose:    Implementation of Persona::getapellido()
// Return:     string
////////////////////////////////////////////////////////////////////////

string Persona::getapellido(void)
{
   return apellido;
}

////////////////////////////////////////////////////////////////////////
// Name:       Persona::setapellido(string newApellido)
// Purpose:    Implementation of Persona::setapellido()
// Parameters:
// - newApellido
// Return:     void
////////////////////////////////////////////////////////////////////////

void Persona::setapellido(string newApellido)
{
   apellido = newApellido;
}
