/***********************************************************************
 * Module:  Nodo.h
 * Author:  RODRIGO
 * Modified: domingo, 8 de diciembre de 2019 20:01:36
 * Purpose: Declaration of the class Nodo
 ***********************************************************************/

#if !defined(__Nodo_Nodo_h)
#define __Nodo_Nodo_h

class Nodo {
public:
    char getDato(void);
    void setDato(char newDato);
    Nodo* getSiguiente(void);
    void setSiguiente(Nodo* newSiguiente);
    Nodo();
    ~Nodo();

protected:
private:
    char dato;
    Nodo* siguiente;


};

#endif
