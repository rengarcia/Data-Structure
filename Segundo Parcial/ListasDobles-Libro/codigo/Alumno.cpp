/***********************************************************************
 * Module:  Alumno.cpp
 * Author:  NICKOLAS
 * Modified: sábado, 23 de noviembre de 2019 20:20:06
 * Purpose: Implementation of the class Alumno
 ***********************************************************************/

#include "Alumno.h"

////////////////////////////////////////////////////////////////////////
// Name:       Alumno::getidAlumno()
// Purpose:    Implementation of Alumno::getidAlumno()
// Return:     int
////////////////////////////////////////////////////////////////////////

int Alumno::getidAlumno(void)
{
   return idAlumno;
}

////////////////////////////////////////////////////////////////////////
// Name:       Alumno::setidAlumno(int newIdAlumno)
// Purpose:    Implementation of Alumno::setidAlumno()
// Parameters:
// - newIdAlumno
// Return:     void
////////////////////////////////////////////////////////////////////////

void Alumno::setidAlumno(int newIdAlumno)
{
   idAlumno = newIdAlumno;
}

////////////////////////////////////////////////////////////////////////
// Name:       Alumno::Alumno()
// Purpose:    Implementation of Alumno::Alumno()
// Return:     
////////////////////////////////////////////////////////////////////////

Alumno::Alumno()
{
}