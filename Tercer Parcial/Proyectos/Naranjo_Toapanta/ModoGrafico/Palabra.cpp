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
#include "Palabra.h"


////////////////////////////////////////////////////////////////////////
// Name:       Palabra::getEspanol()
// Purpose:    Implementation of Palabra::getEspanol()
// Return:     string
////////////////////////////////////////////////////////////////////////

string Palabra::getEspanol(void)
{
   return this->espanol;
}

////////////////////////////////////////////////////////////////////////
// Name:       Palabra::setEspanol(string newEspanol)
// Purpose:    Implementation of Palabra::setEspanol()
// Parameters:
// - newEspanol
// Return:     void
////////////////////////////////////////////////////////////////////////

void Palabra::setEspanol(string newEspanol)
{
   this->espanol = newEspanol;
}

////////////////////////////////////////////////////////////////////////
// Name:       Palabra::getIngles()
// Purpose:    Implementation of Palabra::getIngles()
// Return:     string
////////////////////////////////////////////////////////////////////////

string Palabra::getIngles(void)
{
   return this->ingles;
}

////////////////////////////////////////////////////////////////////////
// Name:       Palabra::setIngles(string newIngles)
// Purpose:    Implementation of Palabra::setIngles()
// Parameters:
// - newIngles
// Return:     void
////////////////////////////////////////////////////////////////////////

void Palabra::setIngles(string newIngles)
{
   this->ingles = newIngles;
}

////////////////////////////////////////////////////////////////////////
// Name:       Palabra::getClave()
// Purpose:    Implementation of Palabra::getClave()
// Return:     int
////////////////////////////////////////////////////////////////////////

int Palabra::getClave(void)
{
   return this->clave;
}

////////////////////////////////////////////////////////////////////////
// Name:       Palabra::setClave(int newClave)
// Purpose:    Implementation of Palabra::setClave()
// Parameters:
// - newClave
// Return:     void
////////////////////////////////////////////////////////////////////////

void Palabra::setClave(int newClave)
{
   this->clave = newClave;
}

void Palabra::setClaveE(int newClave)
{
   this->claveE = newClave;
}
////////////////////////////////////////////////////////////////////////
// Name:       Palabra::Palabra()
// Purpose:    Implementation of Palabra::Palabra()
// Return:
////////////////////////////////////////////////////////////////////////
int Palabra::getClaveE(void)
{
   return this->claveE;
}

////////////////////////////////////////////////////////////////////////
// Name:       Palabra::setClave(int newClave)
// Purpose:    Implementation of Palabra::setClave()
// Parameters:
// - newClave
// Return:     void
////////////////////////////////////////////////////////////////////////

Palabra::Palabra()
{
}

////////////////////////////////////////////////////////////////////////
// Name:       Palabra::~Palabra()
// Purpose:    Implementation of Palabra::~Palabra()
// Return:
////////////////////////////////////////////////////////////////////////

Palabra::~Palabra()
{
   // TODO : implement
}
