/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS                   *
*                        ESPE                                     *
*TRABAJO EN GRUPO:                                                *
*          NOMBRES:ANTONI TOAPANTA                                *
*                   JONNY NARANJO                                 *
*MATERIA: ESTRUCTURA DE DATOS                                     *
*NRC:2967                                                         *
*Fecha de Creacion:09/12/2019                                     *
******************************************************************/

#include "Nodo.h"
#include <stdlib.h>
////////////////////////////////////////////////////////////////////////
// Name:       Nodo::getDatos()
// Purpose:    Implementation of Nodo::getDatos()
// Return:     Persona
////////////////////////////////////////////////////////////////////////

int Nodo::getDatos(void)
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

void Nodo::setDatos(int newDatos)
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

////////////////////////////////////////////////////////////////////////
// Name:       Nodo::setSiguiente(Nodo* newSiguiente)
// Purpose:    Implementation of Nodo::setSiguiente()
// Parameters:
// - newSiguiente
// Return:     void
////////////////////////////////////////////////////////////////////////
Nodo::Nodo()
{
    datos = NULL;
    siguiente = NULL;
    anterior = NULL;
}
////////////////////////////////////////////////////////////////////////
// Name:       Nodo::setSiguiente(Nodo* newSiguiente)
// Purpose:    Implementation of Nodo::setSiguiente()
// Parameters:
// - newSiguiente
// Return:     void
////////////////////////////////////////////////////////////////////////
void Nodo::setAnterior(Nodo* newAnterior)
{
   anterior = newAnterior;
}
////////////////////////////////////////////////////////////////////////
// Name:       Nodo::setSiguiente(Nodo* newSiguiente)
// Purpose:    Implementation of Nodo::setSiguiente()
// Parameters:
// - newSiguiente
// Return:     void
////////////////////////////////////////////////////////////////////////
Nodo * Nodo::getAnterior(void)
{
   return anterior;
}
