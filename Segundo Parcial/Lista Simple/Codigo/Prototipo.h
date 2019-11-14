/***********************************************************************
 * Module:  Prototipo.h
 * Author:  K-vn-
 * Modified: miércoles, 13 de noviembre de 2019 10:44:55
 * Purpose: Declaration of the class Prototipo
 ***********************************************************************/

#if !defined(__Persona2_Prototipo_h)
#define __Persona2_Prototipo_h
#include "Nodo.h"
#include <iostream>

using namespace std;

class Prototipo
{
public:
   bool vacio();
   Persona leerPersona();
   void insertarInicio(void);
   void insertarFinal(void);
   void imprimirNodo(void);

protected:
private:
	Nodo *siguiente;
};

#endif
