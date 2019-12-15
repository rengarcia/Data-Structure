#include "ManejoNodo.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;


void ManejoNodo::insertar(int dato, bool posicion) {
	Nodo* nuevo = new Nodo();
	nuevo->setNumero(dato);
	longitud++;
	if (primero == NULL) {
		primero = nuevo;
		ultimo = nuevo;
		primero->setSiguiente(primero);
		primero->setAnterior(ultimo);
	}
	else if(posicion){
		ultimo->setSiguiente(nuevo);
		nuevo->setAnterior(ultimo);
		nuevo->setSiguiente(primero);
		ultimo = nuevo;
		primero->setAnterior(ultimo);
	}
	else {
		nuevo->setSiguiente(primero);
		nuevo->setAnterior(ultimo);
		primero->setAnterior(nuevo);
		primero = nuevo;
		ultimo->setSiguiente(primero);
	}
}

void ManejoNodo::insertarEnMedio(int posicion, int dato){
	Nodo* nuevoNodo = new Nodo();
	Nodo* actual = primero;
	nuevoNodo->setNumero(dato);
	for (int i = 1; i <= posicion; i++) {
		actual = actual->getSiguiente();
		if (i+1 == posicion) {
			actual->getSiguiente()->setAnterior(nuevoNodo);
			nuevoNodo->setSiguiente(actual->getSiguiente());
			actual->setSiguiente(nuevoNodo);
			nuevoNodo->setAnterior(actual);
		}

	}
}

void ManejoNodo::imprimir() {
	fstream enter;
	enter.open("Lista.txt", fstream::out);
	enter << "Lista Numeros Tetris" << endl;

	Nodo* actual = new Nodo();
	actual = primero;
	if (primero != NULL) {
		do {
			enter << actual->getNumero() << " ";
			cout << actual->getNumero();
			actual = actual->getSiguiente();
		} while (actual != primero);
	}	
}

bool ManejoNodo::borrar()
{
	Nodo* actual = primero->getSiguiente();
	bool continuar = true;
	bool toReturn = false;
	while (continuar) {
		
		if (primero->getNumero() == ultimo->getNumero()) {
			if (longitud==2) {
				primero = NULL;
				ultimo = NULL;
				continuar = false;
				longitud = longitud - 2;
			}else{
			primero = primero->getSiguiente();
			ultimo = ultimo->getAnterior();
			primero->setAnterior(ultimo);
			ultimo->setSiguiente(primero);
			longitud = longitud	- 2;
			}
			toReturn = true;
		}
		else if (primero->getNumero() == primero->getSiguiente()->getNumero()) {
			primero = primero->getSiguiente()->getSiguiente();
			primero->setAnterior(ultimo);
			ultimo->setSiguiente(primero);
			longitud = longitud - 2;
			toReturn = true;;
		}
		else if (ultimo->getNumero() == ultimo->getAnterior()->getNumero()) {
			ultimo = ultimo->getAnterior()->getAnterior();
			ultimo->setSiguiente(primero);
			primero->setAnterior(ultimo);
			longitud = longitud - 2;	
			toReturn = true;
		}
		//Implementar el borrar en medio de la lista
		else if (actual->getSiguiente()->getNumero() == actual->getNumero() && actual->getSiguiente() != ultimo) {
			actual->getAnterior()->setSiguiente(actual->getSiguiente()->getSiguiente());
			actual->getSiguiente()->getSiguiente()->setAnterior(actual->getAnterior());
			longitud = longitud - 2;
			toReturn = true;
		}
		else if(actual->getSiguiente() == ultimo){
			primero = actual->getSiguiente()->getSiguiente();
			ultimo = actual->getSiguiente();
			continuar = false;			
		}		
		actual = actual->getSiguiente();		
	}

	return toReturn;
	
}

int ManejoNodo::getLongitud()
{
	return longitud;
}
