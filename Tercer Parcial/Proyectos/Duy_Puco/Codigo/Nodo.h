/***********************************************************************
 * Module:  Nodo.h
 * Author:  Carlos Puco, Kevin Duy
 * Modified: Sabado, 11 de enero de 2020 20:20:06
 * Purpose: Declaration of the class Nodo
 ***********************************************************************/

class Nodo { 
	private:
		char dato;
		Nodo *izquierda;
		Nodo *derecha;
	public:
		Nodo();
        Nodo(char);
    
    friend class Pila;
    friend class Arbol;
}; 
  
