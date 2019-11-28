/***********************************************************************
 * Module:  Biblioteca.h
 * Author:  NICKOLAS
 * Modified: sábado, 23 de noviembre de 2019 20:20:06
 * Purpose: Declaration of the class Biblioteca
 ***********************************************************************/

#if !defined(__UML_Class_Diagram_2_Biblioteca_h)
#define __UML_Class_Diagram_2_Biblioteca_h

#include <Libro.h>
#include <Nodo.h>

class Biblioteca
{
public:
   void Reservarlibro(void);
   void insertarInicio(Nodo*& Nodo, Libro libro);
   void borrarLibro(int idLibro);
   int buscarLibro(Nodo *&nodo, int idLibro)
   void imprimir(void);
   void modificarLibro(int idLibro);
   void insertarEntre(Nodo*& Nodo, Libro libro);
   void insertarFinal(Nodo*& Nodo, Libro libro);

protected:
private:
   Libro libro;


};

#endif
