/***********************************************************************
 * Module:  Cubo.cpp
 * Author:  fleia
 * Modified: Saturday, November 30, 2019 1:35:25 PM
 * Purpose: Implementation of the class Cubo
 ***********************************************************************/

#include "Cubo.h"

////////////////////////////////////////////////////////////////////////
// Name:       Cubo::getPosicion()
// Purpose:    Implementation of Cubo::getPosicion()
// Return:     int
////////////////////////////////////////////////////////////////////////

int Cubo::getFila(void)
{
   return fila;
}

////////////////////////////////////////////////////////////////////////
// Name:       Cubo::setPosicion(int newPosicion)
// Purpose:    Implementation of Cubo::setPosicion()
// Parameters:
// - newPosicion
// Return:     void
////////////////////////////////////////////////////////////////////////

void Cubo::setFila(int newFila)
{
   fila = newFila;
}

int Cubo::getColumna(void)
{
	return columna;
}

void Cubo::setColumna(int newColumna)
{
	columna = newColumna;
}

////////////////////////////////////////////////////////////////////////
// Name:       Cubo::getValor()
// Purpose:    Implementation of Cubo::getValor()
// Return:     int
////////////////////////////////////////////////////////////////////////

int Cubo::getValor(void)
{
   return valor;
}

////////////////////////////////////////////////////////////////////////
// Name:       Cubo::setValor(int newValor)
// Purpose:    Implementation of Cubo::setValor()
// Parameters:
// - newValor
// Return:     void
////////////////////////////////////////////////////////////////////////

void Cubo::setValor(int newValor)
{
   valor = newValor;
}