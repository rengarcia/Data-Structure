/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 2967                                                       *
******************************************************************/
#include <iostream>
#include <string>
#if !defined(__Class_Diagram_1_Persona_h)
#define __Class_Diagram_1_Persona_h
using namespace std;
class Persona
{
public:
   int getIdPersona(void);
   void setIdPersona(int newIdPersona);
   string getCedula(void);
   void setCedula(string newCedula);
   string getNombre(void);
   void setNombre(string newNombre);
   string getApellido(void);
   void setApellido(string newApellido);
   Persona();
   ~Persona();

protected:
private:
   int idPersona;
   string cedula;
   string nombre;
   string apellido;


};

#endif
