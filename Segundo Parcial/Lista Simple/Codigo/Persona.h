/***********************************************************************
 * Module:  Persona.h
 * Author:  K-vn-
 * Modified: miércoles, 13 de noviembre de 2019 10:41:23
 * Purpose: Declaration of the class Persona
 ***********************************************************************/

#if !defined(__Persona2_Persona_h)
#define __Persona2_Persona_h
#include <string>

using namespace std;

class Persona
{
public:
   int getIdPersona(void);
   void setIdPersona(int newIdPersona);
   string getNombre(void);
   void setNombre(string newNombre);
   string getApellido(void);
   void setApellido(string newApellido);
   int getCedula(void);
   void setCedula(int newCedula);
   void ingresarDatos();
   void imprimirPersona();
   Persona();
   ~Persona();

protected:
private:
   int idPersona;
   int cedula;
   string nombre;
   string apellido;


};

#endif
