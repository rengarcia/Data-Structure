/***********************************************************************
 * Module:  Persona.h
 * Author:  ALEX
 * Modified: Saturday, December 14, 2019 8:55:32 PM
 * Purpose: Declaration of the class Persona
 ***********************************************************************/
#include<iostream>

#if !defined(__BIBLIOTECA_LISTA_DOBLE_Persona_h)
#define __BIBLIOTECA_LISTA_DOBLE_Persona_h

class Persona
{
public:
   Persona();
   ~Persona();
   std::string getId(void);
   void setId(std::string newId);
   std::string getNombre(void);
   void setNombre(std::string newNombre);
   std::string getApellido(void);
   void setApellido(std::string newApellido);
   std::string getCorreo(void);
   void setCorreo(std::string newCorreo);

protected:
private:
   std::string id;
   std::string nombre;
   std::string apellido;
   std::string correo;


};

#endif
