/***********************************************************************
 * Module:  NodoChar.h
 * Author:  fleia
 * Modified: Sunday, December 8, 2019 11:28:08 PM
 * Purpose: Declaration of the class NodoChar
 ***********************************************************************/

#if !defined(__Diagram_NodoChar_h)
#define __Diagram_NodoChar_h

class NodoChar
{
public:
   char getDato(void);
   void setDato(char newDato);
   NodoChar* getSiguiente(void);
   void setSiguiente(NodoChar* newSiguiente);

protected:
private:
   char dato;
   NodoChar* siguiente;


};

#endif