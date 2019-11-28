/***********************************************************************
 * Module:  Biblioteca.cpp
 * Author:  NICKOLAS
 * Modified: sábado, 23 de noviembre de 2019 20:20:06
 * Purpose: Implementation of the class Biblioteca
 ***********************************************************************/

#include "Biblioteca.h"

////////////////////////////////////////////////////////////////////////
// Name:       Biblioteca::Reservarlibro()
// Purpose:    Implementation of Biblioteca::Reservarlibro()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Biblioteca::Reservarlibro(void)
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       Biblioteca::insertarInicio(Nodo*& Nodo, Libro libro)
// Purpose:    Implementation of Biblioteca::insertarInicio()
// Parameters:
// - Nodo
// - libro
// Return:     void
////////////////////////////////////////////////////////////////////////

void Biblioteca::insertarInicio(Nodo*& Nodo, Libro libro)
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       Biblioteca::borrarLibro(int idLibro)
// Purpose:    Implementation of Biblioteca::borrarLibro()
// Parameters:
// - idLibro
// Return:     void
////////////////////////////////////////////////////////////////////////

void Biblioteca::borrarLibro(int idLibro)
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       Biblioteca::buscarLibro(int idLibro)
// Purpose:    Implementation of Biblioteca::buscarLibro()
// Parameters:
// - idLibro
// Return:     void
////////////////////////////////////////////////////////////////////////

void Biblioteca::buscarLibro(int idLibro)
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       Biblioteca::imprimir()
// Purpose:    Implementation of Biblioteca::imprimir()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Biblioteca::imprimir(void)
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       Biblioteca::modificarLibro(int idLibro)
// Purpose:    Implementation of Biblioteca::modificarLibro()
// Parameters:
// - idLibro
// Return:     void
////////////////////////////////////////////////////////////////////////

void Biblioteca::modificarLibro(int idLibro)
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       Biblioteca::insertarEntre(Nodo*& Nodo, Libro libro)
// Purpose:    Implementation of Biblioteca::insertarEntre()
// Parameters:
// - Nodo
// - libro
// Return:     void
////////////////////////////////////////////////////////////////////////

void Biblioteca::insertarEntre(Nodo*& Nodo, Libro libro)
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       Biblioteca::insertarFinal(Nodo*& Nodo, Libro libro)
// Purpose:    Implementation of Biblioteca::insertarFinal()
// Parameters:
// - Nodo
// - libro
// Return:     void
////////////////////////////////////////////////////////////////////////

void Biblioteca::insertarFinal(Nodo*& nodo, Libro libro)
{
  Nodo *newNodo = new Nodo();
  newNodo->setlibro(libro);
  Nodo *aux=nodo;
  Nodo *aux2;
  while(aux!=NULL)
  {
      aux2=aux;
      aux=aux->getsiguiente();
  }
  if(aux==nodo)
   {
       nodo=newNodo;
       nodo->setsiguiente(NULL);
       nodo->setanterior(NULL);
   }
   else{
        aux2->setsiguiente(newNodo);
        newNodo->setanterior(aux2);
   }
   newNodo->setsiguiente(NULL);
}
