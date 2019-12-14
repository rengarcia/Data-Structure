/***********************************************************************
 * Module:  Persona.cpp
 * Author:  K-vn-
 * Modified: miércoles, 13 de noviembre de 2019 10:41:23
 * Purpose: Implementation of the class Persona
 ***********************************************************************/

#include "Persona.h"
#include "ingreso.h"

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
// Name:       Persona::getCedula()
// Purpose:    Implementation of Persona::getCedula()
// Return:     string
////////////////////////////////////////////////////////////////////////

int Persona::getCedula(void)
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

void Persona::setCedula(int newCedula)
{
   cedula = newCedula;
}

////////////////////////////////////////////////////////////////////////
// Name:       Persona::Persona()
// Purpose:    Implementation of Persona::Persona()
// Return:     
////////////////////////////////////////////////////////////////////////

Persona::Persona()
{
    idPersona = 0;
    nombre = "";
	apellido = "";
	cedula = 0;
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

void Persona::ingresarDatos() {
	Ingreso leer;
	Persona persona;
	cout << "Ingrese el nombre: ";
	nombre = leer.ingresarLetra();
	cout << "Ingrese el apellido: ";
	apellido = leer.ingresarLetra();
	cedula = leer.validarCedula();
	cout << "Ingrese su ID: ";
	idPersona = leer.ingresarEntero();
}

void Persona::imprimirPersona() {
	cout << "Nombre: " << nombre << endl;
	cout << "Apellido: " << apellido << endl;
	cout << "Cedula: " << cedula << endl;
	cout << "ID: " << idPersona << endl;
}
