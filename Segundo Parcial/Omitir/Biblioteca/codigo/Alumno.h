/***********************************************************************
 * Module:  Alumno.h
 * Author:  NICKOLAS
 * Modified: sábado, 23 de noviembre de 2019 20:20:06
 * Purpose: Declaration of the class Alumno
 ***********************************************************************/

#if !defined(__UML_Class_Diagram_2_Alumno_h)
#define __UML_Class_Diagram_2_Alumno_h

#include <Persona.h>

class Alumno : public Persona
{
public:
   int getidAlumno(void);
   void setidAlumno(int newIdAlumno);
   Alumno();

protected:
private:
   int idAlumno;


};

#endif