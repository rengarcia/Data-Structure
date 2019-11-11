/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 2967                                                       *
******************************************************************/
#include <string>
#include "Provincia.h"
#include "FechaNacimiento.h"
using namespace std;

class Persona: public Provincia, public FechaNacimiento
{
public:
   string getCedula(void);
   void setCedula(string newCedula);
   string getNombre(void);
   void setNombre(string newNombre);
   string getApellido(void);
   void setApellido(string newApellido);
   string getNacionalidad(void);
   void setNacionalidad(string newNacionalidad);
   string getGenero(void);
   void setGenero(string newGenero);
   string getEstCivil(void);
   void setEstCivil(string newEstCivil);
   string getTelf(void);
   void setTelf(string newTelf);
   Persona();

private:
   string cedula;
   string nombre;
   string apellido;
   string nacionalidad;
   string genero;
   string estCivil;
   string telf;
};

string Persona::getCedula(void)
{
   return cedula;
}

void Persona::setCedula(string newCedula)
{
   cedula = newCedula;
}

string Persona::getNombre(void)
{
   return nombre;
}

void Persona::setNombre(string newNombre)
{
   nombre = newNombre;
}

string Persona::getApellido(void)
{
   return apellido;
}

void Persona::setApellido(string newApellido)
{
   apellido = newApellido;
}

string Persona::getNacionalidad(void)
{
   return nacionalidad;
}

void Persona::setNacionalidad(string newNacionalidad)
{
   nacionalidad = newNacionalidad;
}

string Persona::getGenero(void)
{
   return genero;
}

void Persona::setGenero(string newGenero)
{
   genero = newGenero;
}

string Persona::getEstCivil(void)
{
   return estCivil;
}

void Persona::setEstCivil(string newEstCivil)
{
   estCivil = newEstCivil;
}

string Persona::getTelf(void)
{
   return telf;
}

void Persona::setTelf(string newTelf)
{
   telf = newTelf;
}

Persona::Persona()
{
}
