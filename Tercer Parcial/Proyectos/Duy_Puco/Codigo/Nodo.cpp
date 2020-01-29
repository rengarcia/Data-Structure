/***********************************************************************
 * Module:  Nodo.cpp
 * Author:  Kevin Duy, Carlos Puco
 * Modified: sabado, 26 de noviembre de 2019 17:21:23
 * Purpose: Implementation of the class Nodo
 ***********************************************************************/
#include "Nodo.h"
#include "stdlib.h"

Nodo::Nodo() {
	
}

Nodo::Nodo(char newDato) {
    this->dato = newDato;
    this->izquierda = NULL;
	this->derecha = NULL;
}

