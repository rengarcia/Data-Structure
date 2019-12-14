/***********************************************************************
 * Module:  Pila.cpp
 * Author:  RODRIGO
 * Modified: domingo, 8 de diciembre de 2019 20:01:04
 * Purpose: Implementation of the class Pila
 ***********************************************************************/

#include "Pila.h"
#include <iostream>
using namespace std;

////////////////////////////////////////////////////////////////////////
// Name:       Pila::mostrar(Nodo* pila)
// Purpose:    Implementation of Pila::mostrar()
// Parameters:
// - pila
// Return:     void
////////////////////////////////////////////////////////////////////////

void Pila::mostrar(Nodo* pila, int n) {
    Nodo *actual = new Nodo();
    actual = pila;
    int p = 0;
    while (p != n) {
        cout << actual->getDato() << endl;
        actual = actual->getSiguiente();
        p++;
    }
}

void Pila::apilar(Nodo*& pila, char dato) {
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->setDato(dato);
    Nodo *aux;
    aux = pila;
    pila = nuevo_nodo;
    nuevo_nodo->setSiguiente(aux);
}

char Pila::desapilar(Nodo*& pila) {

}
