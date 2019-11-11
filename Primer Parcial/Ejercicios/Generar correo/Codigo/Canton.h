/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 2967                                                       *
******************************************************************/
#include <string>
#include "Parroquia.h"
using namespace std;


class Canton: public Parroquia
{
public:
   string getIdCanton(void);
   void setIdCanton(string newIdCanton);
   string getNombreCanton(void);
   void setNombreCanton(string newNombreCanton);
   Canton();
protected:
   string idCanton;
   string nombreCanton;
};

string Canton::getIdCanton(void)
{
   return idCanton;
}

void Canton::setIdCanton(string newIdCanton)
{
   idCanton = newIdCanton;
}

string Canton::getNombreCanton(void)
{
   return nombreCanton;
}

void Canton::setNombreCanton(string newNombreCanton)
{
	nombreCanton=newNombreCanton;
}

Canton::Canton()
{
}


