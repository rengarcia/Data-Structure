/***********************************************************************
 * Module:  Autor.h
 * Author:  ALEX
 * Modified: Saturday, December 14, 2019 8:55:50 PM
 * Purpose: Declaration of the class Autor
 ***********************************************************************/

#if !defined(__BIBLIOTECA_LISTA_DOBLE2_Autor_h)
#define __BIBLIOTECA_LISTA_DOBLE2_Autor_h

#include "Persona.h"

class Autor
{
public:
   Autor();
   ~Autor();
   Persona getPersona(void);
   void setPersona(Persona newPersona);
   int getNumPublicacion(void);
   void setNumPublicacion(int newNumPublicacion);

protected:
private:
   Persona persona;
   int numPublicacion;


};

#endif
