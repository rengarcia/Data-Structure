/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
Autor: Zambrano Andrés
Fecha Creacion: 118/01/2020
Estructura de Datos
Ing. Fernando Solis
*/
#include "ArbolBB.h"
#include <iostream>
using namespace std;

ArbolBB::ArbolBB()
{
	raiz = NULL;
}

Nodo* ArbolBB::getRaiz()
{
	return raiz;
}

void ArbolBB::setRaiz(Nodo*& newRaiz)
{
	this->raiz = newRaiz;
}

Nodo* ArbolBB::crearNodo(int dato)
{
	Nodo* nuevoNodo = new Nodo();
	nuevoNodo->setDato(dato);
	nuevoNodo->setIzquierda(NULL);
	nuevoNodo->setDerecha(NULL);
	return nuevoNodo;
}

//INSERTAR
void ArbolBB::insertarNodo(Nodo*& arbol, int dato)
{
	//SIE EL ARBOL ESTA VACIO
	if (arbol == NULL)
	{
		Nodo* newNodo = crearNodo(dato);
		arbol = newNodo;
	}
	else//SI EL ARBOL TIENE ELEMENTOS
	{
		int valorRaiz = arbol->getDato();
		if (dato < valorRaiz) {
			insertarNodo(arbol->getIzquierda(), dato);
		}
		else {
			insertarNodo(arbol->getDerecha(), dato);
		}
	}
}

//MOSTRAR
void ArbolBB::mostrarArbol(Nodo* arbol, int contador)
{
	if (arbol == NULL)
	{
		return;
	}
	else {
		mostrarArbol(arbol->getDerecha(), contador + 1);
		for (int i = 0; i < contador; i++) {
			cout << "     ";
		}
		cout << arbol->getDato() << endl;
		mostrarArbol(arbol->getIzquierda(), contador + 1);
	}
}

//INORDEN
void ArbolBB::inOrden(Nodo* arbol)
{
	if (arbol != NULL) {
		inOrden(arbol->getIzquierda());
		cout << arbol->getDato() << "\t";
		inOrden(arbol->getDerecha());
	}
}

//PREORDEN
void ArbolBB::preOrden(Nodo* arbol)
{
	if (arbol != NULL) {
		cout << arbol->getDato() << "\t";
		preOrden(arbol->getIzquierda());
		preOrden(arbol->getDerecha());
	}
}

//POSTORDEN
void ArbolBB::postOrden(Nodo* arbol)
{
	if (arbol != NULL) {
		postOrden(arbol->getIzquierda());
		postOrden(arbol->getDerecha());
		cout << arbol->getDato() << "\t";
	}
}

int ArbolBB::verNivel(int nivel,Nodo* aux, int dato)
{
	if (aux == NULL)
		return 0;

	if (aux->getDato() == dato)
		return nivel;

	int nivelInferior = verNivel(nivel + 1,aux->getIzquierda(), dato);
	if (nivelInferior != 0)
		return nivelInferior;

	nivelInferior = verNivel(nivel + 1,aux->getDerecha(),dato);
	return nivelInferior;
}

int ArbolBB::altura(Nodo* arbol)
{
	int izquierda = 0;
	int derecha = 0;
	if (arbol != NULL) {
		izquierda++;
		derecha++;
		if (arbol->getIzquierda() != NULL) {
			izquierda = izquierda + altura(arbol->getIzquierda());
		}
		if (arbol->getDerecha() != NULL) {
			derecha = derecha + altura(arbol->getDerecha());
		}
	}
	if (izquierda >= derecha)
		return izquierda;
	else
		return derecha;
}