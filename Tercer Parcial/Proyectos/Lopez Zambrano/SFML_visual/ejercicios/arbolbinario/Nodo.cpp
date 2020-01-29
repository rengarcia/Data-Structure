/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
Autor: Zambrano Andrés
Fecha Creacion: 118/01/2020
Estructura de Datos
Ing. Fernando Solis
*/
#include "Nodo.h"
Nodo::Nodo()
{
	this->dato = 0;
	this->derecha = nullptr;
	this->izquierda = nullptr;
}

Nodo::Nodo(int newDato)
{
	this->dato = newDato;
	this->derecha = nullptr;
	this->izquierda = nullptr;
}

int Nodo::getDato()
{
	return dato;
}

void Nodo::setDato(int newDato)
{
	this->dato = newDato;
}

Nodo*& Nodo::getDerecha()
{
	return derecha;
}

void Nodo::setDerecha(Nodo* newNodoDerecha)
{
	this->derecha = newNodoDerecha;
}

Nodo*& Nodo::getIzquierda()
{
	return izquierda;
}

void Nodo::setIzquierda(Nodo* newNodoIzquierda)
{
	this->izquierda = newNodoIzquierda;
}