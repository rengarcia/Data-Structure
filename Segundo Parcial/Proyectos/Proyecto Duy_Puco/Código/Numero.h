/***********************************************************************
 * Module:  Numero.h
 * Author:  Carlos Puco, Kevin Duy
 * Modified: sábado, 26 de noviembre de 2019 20:20:06
 * Purpose: Declaration of the class Biblioteca
 ***********************************************************************/

#if !defined(__UML_Class_Diagram_2_Biblioteca_h)
#define __UML_Class_Diagram_2_Biblioteca_h

#include "Nodo.h"

int contador = 0;

class Numero
{
public:
   bool vacio();
   int tamanio();
   void insertarInicio(int);
   void borrar(int,int);
   int buscar(int);
   void imprimir(void);
   void modificar(int,int);
   void insertarEntre(int,int);
   void insertarFinal(int);

protected:
private:
   Nodo *siguienteNumero;
   Nodo *anteriorNumero;

friend class Nodo;
};

#endif
