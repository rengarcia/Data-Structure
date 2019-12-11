/***********************************************************************
 * Module:  Nodo.h
 * Author:  G403
 * Modified: jueves, 14 de noviembre de 2019 9:59:20
 * Purpose: Declaration of the class Nodo
 ***********************************************************************/

#if !defined(__EjercicioClase_Nodo_h)
#define __EjercicioClase_Nodo_h

class Persona;

#include <Persona.h>

class Nodo
{
public:
   Persona* persona;

protected:
private:
   Persona Persona_;
   Nodo* siguiente;


};

#endif