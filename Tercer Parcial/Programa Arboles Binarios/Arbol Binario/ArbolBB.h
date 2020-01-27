/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
Autor: Zambrano Andrés
Fecha Creacion: 118/01/2020
Estructura de Datos
Ing. Fernando Solis
*/#pragma once
#include "Nodo.h"
class ArbolBB {
private:
	Nodo* raiz;
public:
	ArbolBB();
	Nodo* getRaiz();
	void setRaiz(Nodo*& newRaiz);
	Nodo* crearNodo(int dato);
	void insertarNodo(Nodo*& arbol, int dato);
	void mostrarArbol(Nodo* arbol, int contador);
	void inOrden(Nodo* nodo);
	void preOrden(Nodo* nodo);
	void postOrden(Nodo* nodo);
	int verNivel(int nivel, Nodo* aux,int dato);
	int altura(Nodo* arbol);
};
