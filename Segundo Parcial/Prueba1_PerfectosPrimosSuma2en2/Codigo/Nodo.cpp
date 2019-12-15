/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 2967                                                       *
******************************************************************/

#include "Nodo.h"

////////////////////////////////////////////////////////////////////////
// Name:       Nodo::getDatos()
// Purpose:    Implementation of Nodo::getDatos()
// Return:     Persona
////////////////////////////////////////////////////////////////////////

Persona Nodo::getDatos(void)
{
   return datos;
}

////////////////////////////////////////////////////////////////////////
// Name:       Nodo::setDatos(Persona newDatos)
// Purpose:    Implementation of Nodo::setDatos()
// Parameters:
// - newDatos
// Return:     void
////////////////////////////////////////////////////////////////////////

void Nodo::setDatos(Persona newDatos)
{
   datos = newDatos;
}

////////////////////////////////////////////////////////////////////////
// Name:       Nodo::getSiguiente()
// Purpose:    Implementation of Nodo::getSiguiente()
// Return:       Nodo *
////////////////////////////////////////////////////////////////////////

  Nodo * Nodo::getSiguiente(void)
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

Nodo::Nodo()
{
    siguiente = NULL;
}

Nodo::Nodo(Persona obj, Nodo *sig)
{
    datos = obj;
    siguiente = sig;
}
