/***********************************************************************
 * Module:  Nodo.h
 * Author:  Carlos Puco, Kevin Duy
 * Modified: sábado, 26 de noviembre de 2019 20:20:06
 * Purpose: Declaration of the class Nodo
 ***********************************************************************/

#if !defined(__UML_Class_Diagram_2_Nodo_h)
#define __UML_Class_Diagram_2_Nodo_h

class Nodo
{
public:
   Nodo* getSiguiente(void);
   void setsiguiente(Nodo* newSiguiente);
   Nodo* getAnterior(void);
   void setanterior(Nodo* newAnterior);
   Nodo();

protected:
private:
   Nodo *siguiente;
   Nodo *anterior;
   int numero;

friend class Numero;
};

#endif
