#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

/***********************************************************************
 * Module:  Nodo.h
 * Author:  Kevin Zurita
 * Modified: Thursday, November 13, 2019 10:38:09 AM
 * Purpose: Declaration of the class Nodo
 ***********************************************************************/

#if !defined(__Listas2_Nodo_h)
#define __Listas2_Nodo_h
#include "Persona.h"

class Nodo
{
public:
   Persona getperson(void);
   void setperson(Persona newPerson);
   Nodo* getsiguiente(void);
   void setsiguiente(Nodo*);
   Nodo(Persona, Nodo*);

protected:
private:
   Persona person;
   Nodo* siguiente;
};

Nodo::Nodo(Persona p, Nodo *sig=NULL){
	person=p;
	siguiente=sig;
}

#endif
