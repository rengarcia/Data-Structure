/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 2967                                                       *
******************************************************************/
#include <string>
using namespace std;


class Parroquia
{
public:
   string getIdParroq(void);
   void setIdParroq(string newIdParroq);
   string getNombreParroq(void);
   void setNombreParroq(string newNombreParroq);
   Parroquia();
protected:
   string idParroq;
   string nombreParroq;


};

string Parroquia::getIdParroq(void)
{
   return idParroq;
}
void Parroquia::setIdParroq(string newIdParroq)
{
   idParroq = newIdParroq;
}

string Parroquia::getNombreParroq(void)
{
   return nombreParroq;
}
void Parroquia::setNombreParroq(string newNombreParroq)
{
   nombreParroq = newNombreParroq;
}

Parroquia::Parroquia()
{
}
