/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS                   *
*                        ESPE                                     *
*TRABAJO EN GRUPO:                                                *
*          NOMBRES:ANTONI TOAPANTA                                *
*                   JHONY NARANJO                                 *
*MATERIA: ESTRUCTURA DE DATOS                                     *
*NRC:2967                                                         *
*Fecha de Creacion:26/01/2020                                     *
******************************************************************/
#pragma once
#include "Arbol.h"

////////////////////////////////////////////////////////////////////////
// Name:       Arbol::getPalabra()
// Purpose:    Implementation of Arbol::getPalabra()
// Return:     Palabra
////////////////////////////////////////////////////////////////////////

Palabra Arbol::getPalabra(void)
{
   return palabra;
}

////////////////////////////////////////////////////////////////////////
// Name:       Arbol::setPalabra(Palabra newPalabra)
// Purpose:    Implementation of Arbol::setPalabra()
// Parameters:
// - newPalabra
// Return:     void
////////////////////////////////////////////////////////////////////////

void Arbol::setPalabra(Palabra newPalabra)
{
   palabra = newPalabra;
}

////////////////////////////////////////////////////////////////////////
// Name:       Arbol::getDer()
// Purpose:    Implementation of Arbol::getDer()
// Return:     Arbol*
////////////////////////////////////////////////////////////////////////

Arbol* Arbol::getDer(void)
{
   return der;
}

////////////////////////////////////////////////////////////////////////
// Name:       Arbol::setDer(Arbol* newDer)
// Purpose:    Implementation of Arbol::setDer()
// Parameters:
// - newDer
// Return:     void
////////////////////////////////////////////////////////////////////////

void Arbol::setDer(Arbol* newDer)
{
   der = newDer;
}

////////////////////////////////////////////////////////////////////////
// Name:       Arbol::getIzq()
// Purpose:    Implementation of Arbol::getIzq()
// Return:     Arbol*
////////////////////////////////////////////////////////////////////////

Arbol* Arbol::getIzq(void)
{
   return izq;
}

////////////////////////////////////////////////////////////////////////
// Name:       Arbol::setIzq(Arbol* newIzq)
// Purpose:    Implementation of Arbol::setIzq()
// Parameters:
// - newIzq
// Return:     void
////////////////////////////////////////////////////////////////////////

void Arbol::setIzq(Arbol* newIzq)
{
   izq = newIzq;
}

////////////////////////////////////////////////////////////////////////
// Name:       Arbol::Arbol()
// Purpose:    Implementation of Arbol::Arbol()
// Return:
////////////////////////////////////////////////////////////////////////

Arbol::Arbol()
{
}

////////////////////////////////////////////////////////////////////////
// Name:       Arbol::~Arbol()
// Purpose:    Implementation of Arbol::~Arbol()
// Return:
////////////////////////////////////////////////////////////////////////

Arbol::~Arbol()
{
   // TODO : implement
}
