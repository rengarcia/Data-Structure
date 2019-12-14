/***********************************************************************
 * Module:  Pila.h
 * Author:  RODRIGO
 * Modified: domingo, 8 de diciembre de 2019 20:01:04
 * Purpose: Declaration of the class Pila
 ***********************************************************************/

#if !defined(__Nodo_Pila_h)
#define __Nodo_Pila_h
#include "Nodo.cpp"

class Pila
{
public:
   void mostrar(Nodo* pila,int n);
   void apilar(Nodo*& pila, char dato);
   char desapilar(Nodo*& pila);
protected:
private:

};

#endif
