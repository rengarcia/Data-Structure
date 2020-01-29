/***********************************************************************
 * Module:  Pila.cpp
 * Author:  Kevin Duy, Carlos Puco
 * Modified: sabado, 26 de noviembre de 2019 17:21:23
 * Purpose: Implementation of the class Pila
 ***********************************************************************/
#include "Pila.h"

Pila::Pila(Nodo *newRaiz) {
    this->raiz = newRaiz;
    siguiente = NULL;
}
