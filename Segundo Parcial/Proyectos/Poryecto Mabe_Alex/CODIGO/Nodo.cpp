/**************************************************************
 *	Universidad de las Fuerzas Armadas ESPE
 *	Maria Belen Ceron, Alex Chicaiza
 *	NRC: 2967
 *	Fecha creacion: 08/11/2019
 *	Fecha ultima modificacion:	12/12/2019
 *	Docente: Ing. Fernando Solis
***************************************************************/


#include "Nodo.h"

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

////////////////////////////////////////////////////////////////////////
// Name:       Nodo::getNumero()
// Purpose:    Implementation of Nodo::getNumero()
// Return:     int
////////////////////////////////////////////////////////////////////////

int Nodo::getNumero(void)
{
   return numero;
}

////////////////////////////////////////////////////////////////////////
// Name:       Nodo::setNumero(int newNumero)
// Purpose:    Implementation of Nodo::setNumero()
// Parameters:
// - newNumero
// Return:     void
////////////////////////////////////////////////////////////////////////

void Nodo::setNumero(int newNumero)
{
   numero = newNumero;
}

////////////////////////////////////////////////////////////////////////
// Name:       Nodo::getAnteriorDireccion()
// Purpose:    Implementation of Nodo::getAnteriorDireccion()
// Return:     Nodo*
////////////////////////////////////////////////////////////////////////

Nodo* Nodo::getAnteriorDireccion(void)
{
   return anteriorDireccion;
}

////////////////////////////////////////////////////////////////////////
// Name:       Nodo::setAnteriorDireccion(Nodo* newAnteriorDireccion)
// Purpose:    Implementation of Nodo::setAnteriorDireccion()
// Parameters:
// - newAnteriorDireccion
// Return:     void
////////////////////////////////////////////////////////////////////////

void Nodo::setAnteriorDireccion(Nodo* newAnteriorDireccion)
{
   anteriorDireccion = newAnteriorDireccion;
}

////////////////////////////////////////////////////////////////////////
// Name:       Nodo::getSiguienteDireccion()
// Purpose:    Implementation of Nodo::getSiguienteDireccion()
// Return:     Nodo*
////////////////////////////////////////////////////////////////////////

Nodo* Nodo::getSiguienteDireccion(void)
{
   return siguienteDireccion;
}

////////////////////////////////////////////////////////////////////////
// Name:       Nodo::setSiguienteDireccion(Nodo* newSiguienteDireccion)
// Purpose:    Implementation of Nodo::setSiguienteDireccion()
// Parameters:
// - newSiguienteDireccion
// Return:     void
////////////////////////////////////////////////////////////////////////

void Nodo::setSiguienteDireccion(Nodo* newSiguienteDireccion)
{
   siguienteDireccion = newSiguienteDireccion;
}
