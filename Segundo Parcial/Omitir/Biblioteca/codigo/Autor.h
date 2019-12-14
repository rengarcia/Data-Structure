/***********************************************************************
 * Module:  Autor.h
 * Author:  NICKOLAS
 * Modified: sábado, 23 de noviembre de 2019 20:20:06
 * Purpose: Declaration of the class Autor
 ***********************************************************************/

#if !defined(__UML_Class_Diagram_2_Autor_h)
#define __UML_Class_Diagram_2_Autor_h

#include <Persona.h>

class Autor : public Persona
{
public:
   int getidAutor(void);
   void setidAutor(int newIdAutor);
   string getseudonimo(void);
   void setseudonimo(string newSeudonimo);
   Autor();

protected:
private:
   int idAutor;
   string seudonimo;


};

#endif