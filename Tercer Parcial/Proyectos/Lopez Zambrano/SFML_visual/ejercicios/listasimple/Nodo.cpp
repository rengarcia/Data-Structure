/***********************************************************************
 * Author:  Zambrano Andres
 * Modified: miércoles, 13 de noviembre de 2019 10:41:23
 * Purpose: Implementation of the class Nodo
 ***********************************************************************/

#include "Nodo.h"
#include <iostream>
using namespace std;

 // Constructor por defecto
template<typename T>

Nodo<T>::Nodo()
{
    setDato(nullptr);
    setSiguiente(nullptr);
}

// Constructor por parámetro
template<typename T>
Nodo<T>::Nodo(T newDato)
{
    setDato(newDato);
    setSiguiente(nullptr);
}

// Eliminar todos los Nodos
template<typename T>
void Nodo<T>::borrarTodo()
{
    if (getSiguiente())
        getSiguiente()->borrarTodo();
    delete this;
}

// Imprimir un Nodo
template<typename T>
void Nodo<T>::imprimir()
{
    //cout << "Node-> " << "Dato: " << dato << " Direcion: " << this << " Siguiente: " << next << endl;
    cout << getDato() << "-> ";
}

template<typename T>
Nodo<T>::~Nodo() {}

