/***********************************************************************
 * Module:  Pais.h
 * Author:  ALEX
 * Modified: Saturday, December 14, 2019 8:55:50 PM
 * Purpose: Declaration of the class Pais
 ***********************************************************************/

#include<iostream>

#if !defined(__BIBLIOTECA_LISTA_DOBLE2_Pais_h)
#define __BIBLIOTECA_LISTA_DOBLE2_Pais_h

class Pais
{
public:
   Pais();
   ~Pais();
   int getIdPais(void);
   void setIdPais(int newIdPais);
   std::string getNombrePais(void);
   void setNombrePais(std::string newNombrePais);
   std::string getNacionalidad(void);
   void setNacionalidad(std::string newNacionalidad);

protected:
private:
   int idPais;
   std::string nombrePais;
   std::string nacionalidad;


};

#endif
