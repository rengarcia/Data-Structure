/***********************************************************************
 * Module:  NodoInt.h
 * Author:  fleia
 * Modified: Sunday, December 8, 2019 11:37:36 PM
 * Purpose: Declaration of the class NodoInt
 ***********************************************************************/

#if !defined(__Diagram_NodoInt_h)
#define __Diagram_NodoInt_h

class NodoInt
{
public:
   int getDato(void);
   void setDato(int newDato);
   NodoInt* getSiguiente(void);
   void setSiguiente(NodoInt* newSiguiente);

protected:
private:
   int dato;
   NodoInt* siguiente;


};

#endif