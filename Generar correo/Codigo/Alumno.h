/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 2967                                                       *
******************************************************************/
#include <string>
using namespace std;
#include "Persona.h"

class Alumno : public Persona
{
public:
   string getIdAlumno(void);
   void setIdAlumno(string newIdAlumno);
   string getEmail(void);
   void setEmail(string newEmail);
   Alumno();
private:
   string idAlumno;
   string email;
};

string Alumno::getIdAlumno(void)
{
   return idAlumno;
}

void Alumno::setIdAlumno(string newIdAlumno)
{
   idAlumno = newIdAlumno;
}

string Alumno::getEmail(void)
{
   return email;
}

void Alumno::setEmail(string newEmail)
{
   email = newEmail;
}

Alumno::Alumno()
{
}
