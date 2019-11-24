/***********************************************************************
 * Module:  Persona.cpp
 * Author:  NICKOLAS
 * Modified: s�bado, 23 de noviembre de 2019 20:20:06
 * Purpose: Implementation of the class Persona
 ***********************************************************************/

#include "Persona.h"

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

////////////////////////////////////////////////////////////////////////
// Name:       Persona::gettelefono()
// Purpose:    Implementation of Persona::gettelefono()
// Return:     string
////////////////////////////////////////////////////////////////////////

string Persona::gettelefono(void)
{
   return telefono;
}

////////////////////////////////////////////////////////////////////////
// Name:       Persona::settelefono(string newTelefono)
// Purpose:    Implementation of Persona::settelefono()
// Parameters:
// - newTelefono
// Return:     void
////////////////////////////////////////////////////////////////////////

void Persona::settelefono(string newTelefono)
{
   telefono = newTelefono;
}

////////////////////////////////////////////////////////////////////////
// Name:       Persona::Persona()
// Purpose:    Implementation of Persona::Persona()
// Return:     
////////////////////////////////////////////////////////////////////////

Persona::Persona()
{
}