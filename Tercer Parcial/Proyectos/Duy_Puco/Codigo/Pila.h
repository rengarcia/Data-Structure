/***********************************************************************
 * Module:  Pila.h
 * Author:  Carlos Puco, Kevin Duy
 * Modified: Sabado, 11 de enero de 2020 20:20:06
 * Purpose: Declaration of the class Pila
 ***********************************************************************/

#include "Nodo.cpp"

class Pila {    
	private:
		Nodo *raiz;
		Pila *siguiente;
    public:
        Pila(Nodo*);
        
    friend class Nodo;
    friend class Arbol;
};
