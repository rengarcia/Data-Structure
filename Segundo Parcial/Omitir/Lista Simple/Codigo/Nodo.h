/***********************************************************************
 * Module:  Nodo.h
 * Author:  K-vn-
 * Modified: miércoles, 13 de noviembre de 2019 10:41:23
 * Purpose: Declaration of the class Nodo
 ***********************************************************************/

#if !defined(__Persona2_Nodo_h)
#define __Persona2_Nodo_h
#include "Persona.h"

class Nodo
{
public:
   Persona getPersona(void);
   void setPersona(Persona newPersona);
   Nodo* getSiguiente(void);
   void setSiguiente(Nodo* newSiguiente);
   Nodo();
   ~Nodo();
	Nodo(Persona, Nodo*);
protected:
private:
   Persona persona;
   Nodo* siguiente;


};

#endif
