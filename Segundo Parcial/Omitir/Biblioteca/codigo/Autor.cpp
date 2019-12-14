/***********************************************************************
 * Module:  Autor.cpp
 * Author:  NICKOLAS
 * Modified: sábado, 23 de noviembre de 2019 20:20:06
 * Purpose: Implementation of the class Autor
 ***********************************************************************/

#include "Autor.h"

////////////////////////////////////////////////////////////////////////
// Name:       Autor::getidAutor()
// Purpose:    Implementation of Autor::getidAutor()
// Return:     int
////////////////////////////////////////////////////////////////////////

int Autor::getidAutor(void)
{
   return idAutor;
}

////////////////////////////////////////////////////////////////////////
// Name:       Autor::setidAutor(int newIdAutor)
// Purpose:    Implementation of Autor::setidAutor()
// Parameters:
// - newIdAutor
// Return:     void
////////////////////////////////////////////////////////////////////////

void Autor::setidAutor(int newIdAutor)
{
   idAutor = newIdAutor;
}

////////////////////////////////////////////////////////////////////////
// Name:       Autor::getseudonimo()
// Purpose:    Implementation of Autor::getseudonimo()
// Return:     string
////////////////////////////////////////////////////////////////////////

string Autor::getseudonimo(void)
{
   return seudonimo;
}

////////////////////////////////////////////////////////////////////////
// Name:       Autor::setseudonimo(string newSeudonimo)
// Purpose:    Implementation of Autor::setseudonimo()
// Parameters:
// - newSeudonimo
// Return:     void
////////////////////////////////////////////////////////////////////////

void Autor::setseudonimo(string newSeudonimo)
{
   seudonimo = newSeudonimo;
}

////////////////////////////////////////////////////////////////////////
// Name:       Autor::Autor()
// Purpose:    Implementation of Autor::Autor()
// Return:     
////////////////////////////////////////////////////////////////////////

Autor::Autor()
{
}