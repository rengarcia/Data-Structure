/***********************************************************************
 * Module:  OperacionesNodo.h
 * Author:  fleia
 * Modified: Saturday, November 30, 2019 1:33:41 PM
 * Purpose: Declaration of the class OperacionesNodo
 ***********************************************************************/

#if !defined(__proyecto_OperacionesNodo_h)
#define __proyecto_OperacionesNodo_h

#include "Nodo.h"
#include "Cubo.h"

class OperacionesNodo
{
public:
   void insertarCabeza(Nodo** referencia, Cubo cubo);
   void insertarCola(Nodo** referencia, Cubo cubo);
   void imprimir(Nodo* referencia);
   void imprimirTxt(Nodo* referencia);
   void verificacionHorizontal(Nodo* fila);
   void verificacionVertical(Nodo* fila);
   void insertarDatoPorPosicion(Nodo* fila,int posicionColumna,int posicionFila,int dato);
   void inicializarFila(Nodo** fila, int casillas);
   bool seguirEnJuego(Nodo* fila);
 
private:
	int asignarFila(int numero);
	
};

#endif