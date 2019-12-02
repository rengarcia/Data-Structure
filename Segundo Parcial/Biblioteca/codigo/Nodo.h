/***********************************************************************
 * Module:  Nodo.h
 * Author:  NICKOLAS
 * Modified: sábado, 23 de noviembre de 2019 20:20:06
 * Purpose: Declaration of the class Nodo
 ***********************************************************************/

#if !defined(__UML_Class_Diagram_2_Nodo_h)
#define __UML_Class_Diagram_2_Nodo_h

#include <Libro.h>

class Nodo
{
public:
   Libro getlibro(void);
   void setlibro(Libro newLibro);
   Nodo* getSiguiente(void);
   void setsiguiente(Nodo* newSiguiente);
   Nodo* getAnterior(void);
   void setanterior(Nodo* newAnterior);
   Nodo();

protected:
private:
   Libro libro;
   Nodo* siguiente;
   Nodo* anterior;


};

#endif