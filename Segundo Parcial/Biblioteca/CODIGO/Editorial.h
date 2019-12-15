/***********************************************************************
 * Module:  Editorial.h
 * Author:  ALEX
 * Modified: Saturday, December 14, 2019 8:55:50 PM
 * Purpose: Declaration of the class Editorial
 ***********************************************************************/

#include<iostream>

#if !defined(__BIBLIOTECA_LISTA_DOBLE2_Editorial_h)
#define __BIBLIOTECA_LISTA_DOBLE2_Editorial_h

class Editorial
{
public:
   Editorial();
   ~Editorial();
   int getIdEditorial(void);
   void setIdEditorial(int newIdEditorial);
   std::string getNombreEditorial(void);
   void setNombreEditorial(std::string newNombreEditorial);
   std::string getContactoEditorial(void);
   void setContactoEditorial(std::string newContactoEditorial);

protected:
private:
   int idEditorial;
   std::string nombreEditorial;
   std::string contactoEditorial;


};

#endif
