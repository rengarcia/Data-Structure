/***********************************************************************
 * Module:  NodoDouble.h
 * Author:  fleia
 * Modified: Sunday, December 8, 2019 11:44:13 PM
 * Purpose: Declaration of the class NodoDouble
 ***********************************************************************/

#if !defined(__Diagram_NodoDouble_h)
#define __Diagram_NodoDouble_h

class NodoDouble
{
public:
   double getDato(void);
   void setDato(double newDato);
   NodoDouble* getSiguiente(void);
   void setSiguiente(NodoDouble* newSiguiente);

protected:
private:
   double dato;
   NodoDouble* siguiente;


};

#endif