/***********************************************************************
 * Module:  Persona.h
 * Author:  fleia
 * Modified: Wednesday, November 13, 2019 10:49:37 AM
 * Purpose: Declaration of the class Persona
 ***********************************************************************/
#include <string>
using namespace std;

#if !defined(__DiagramaBase_Persona_h)
#define __DiagramaBase_Persona_h

class Persona
{
public:
   string getIdPersona(void);
   void setIdPersona(string newIdPersona);
   string getCedula(void);
   void setCedula(string newCedula);
   string getApellido(void);
   void setApellido(string newApellido);
   string getNombre(void);
   void setNombre(string newSiguiente);

private:
   string idPersona;
   string cedula;
   string apellido;
   string nombre;


};

#endif