/***********************************************************************
 * Module:  Persona.h
 * Author:  NICKOLAS
 * Modified: sábado, 23 de noviembre de 2019 20:20:06
 * Purpose: Declaration of the class Persona
 ***********************************************************************/

#if !defined(__UML_Class_Diagram_2_Persona_h)
#define __UML_Class_Diagram_2_Persona_h

class Persona
{
public:
   string getcedula(void);
   void setcedula(string newCedula);
   string getnombre(void);
   void setnombre(string newNombre);
   string getapellido(void);
   void setapellido(string newApellido);
   string gettelefono(void);
   void settelefono(string newTelefono);
   Persona();

protected:
private:
   string cedula;
   string nombre;
   string apellido;
   string telefono;


};

#endif