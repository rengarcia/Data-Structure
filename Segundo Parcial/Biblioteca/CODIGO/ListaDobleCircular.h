/***********************************************************************
 * Module:  ListaDobleCircular.h
 * Author:  ALEX
 * Modified: Saturday, December 14, 2019 8:55:50 PM
 * Purpose: Declaration of the class ListaDobleCircular
 ***********************************************************************/

#if !defined(__BIBLIOTECA_LISTA_DOBLE2_ListaDobleCircular_h)
#define __BIBLIOTECA_LISTA_DOBLE2_ListaDobleCircular_h

#include "Nodo.h"
#include "Libro.h"

class ListaDobleCircular
{
public:
   bool vacia(void);
   void insertarInicio(Libro newLibro);
   void insertarFinal(Libro newLibro);
   void insertarPosicion(int newPosicion, Libro newLibro);
   int buscarPosicionLibroId(int idLibro);
   void modificarPorId(int idLibro, Libro libro);
   void eliminar(int id);
   void imprimir(void);
   void imprimirNodo(Nodo* nodo);
   int tamanioLista(void);
   void crearTxt(Nodo* nodo);

protected:
private:
   Nodo* primero;
   Nodo* ultimo;


};

#endif
