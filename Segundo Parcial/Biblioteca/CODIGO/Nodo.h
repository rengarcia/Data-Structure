/***********************************************************************
 * Module:  Nodo.h
 * Author:  ALEX
 * Modified: Saturday, December 14, 2019 8:55:50 PM
 * Purpose: Declaration of the class Nodo
 ***********************************************************************/

#if !defined(__BIBLIOTECA_LISTA_DOBLE2_Nodo_h)
#define __BIBLIOTECA_LISTA_DOBLE2_Nodo_h

#include "Libro.h"

class Nodo
{
public:
   Nodo();
   ~Nodo();
   Libro getLibro(void);
   void setLibro(Libro newLibro);
   Nodo* getAnterior(void);
   void setAnterior(Nodo* newAnterior);
   Nodo* getSiguiente(void);
   void setSiguiente(Nodo* newSiguiente);

protected:
private:
   Libro libro;
   Nodo* anterior;
   Nodo* siguiente;


};

#endif
