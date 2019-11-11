/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 2967                                                       *
******************************************************************/
#include <string>
#include "Canton.h"
using namespace std;
class Canton;

class Provincia : public Canton
{
public:
   string getIdProvincia(void);
   void setIdProvincia(string newIdProvincia);
   string getNombreProvincia(void);
   void setNombreProvincia(string newNombreProvincia);
   Provincia();
protected:
   string idProvincia;
   string nombreProvincia;
};

string Provincia::getIdProvincia(void)
{
   return idProvincia;
}

void Provincia::setIdProvincia(string newIdProvincia)
{
   idProvincia = newIdProvincia;
}

string Provincia::getNombreProvincia(void)
{
   return nombreProvincia;
}
void Provincia::setNombreProvincia(string newNombreProvincia)
{
   nombreProvincia = newNombreProvincia;
}

Provincia::Provincia()
{
}

