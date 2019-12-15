/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 2967                                                       *
******************************************************************/

#include "Persona.h"

////////////////////////////////////////////////////////////////////////
// Name:       Persona::getIdPersona()
// Purpose:    Implementation of Persona::getIdPersona()
// Return:     int
////////////////////////////////////////////////////////////////////////

int Persona::getIdPersona(void)
{
   return idPersona;
}

////////////////////////////////////////////////////////////////////////
// Name:       Persona::setIdPersona(int newIdPersona)
// Purpose:    Implementation of Persona::setIdPersona()
// Parameters:
// - newIdPersona
// Return:     void
////////////////////////////////////////////////////////////////////////

void Persona::setIdPersona(int newIdPersona)
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
// Name:       Persona::getNombre()
// Purpose:    Implementation of Persona::getNombre()
// Return:     string
////////////////////////////////////////////////////////////////////////

string Persona::getNombre(void)
{
   return nombre;
}

////////////////////////////////////////////////////////////////////////
// Name:       Persona::setNombre(string newNombre)
// Purpose:    Implementation of Persona::setNombre()
// Parameters:
// - newNombre
// Return:     void
////////////////////////////////////////////////////////////////////////

void Persona::setNombre(string newNombre)
{
   nombre = newNombre;
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
// Name:       Persona::Persona()
// Purpose:    Implementation of Persona::Persona()
// Return:
////////////////////////////////////////////////////////////////////////

Persona::Persona()
{
}

////////////////////////////////////////////////////////////////////////
// Name:       Persona::~Persona()
// Purpose:    Implementation of Persona::~Persona()
// Return:
////////////////////////////////////////////////////////////////////////

Persona::~Persona()
{
   // TODO : implement
}
