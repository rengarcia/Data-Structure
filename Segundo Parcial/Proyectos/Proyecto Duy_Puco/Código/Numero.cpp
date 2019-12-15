/***********************************************************************
 * Module:  Numero.cpp
 * Author:  Carlos Puco, Kevin Duy
 * Modified: sábado, 26 de noviembre de 2019 20:20:06
 * Purpose: Implementation of the class Biblioteca
 ***********************************************************************/

#include "Numero.h"
#include "Nodo.cpp"
#include <time.h>
#include <iostream>

using namespace std;

////////////////////////////////////////////////////////////////////////
// Name:       Numero::insertarInicio(Nodo*& Nodo, Libro libro)
// Purpose:    Implementation of Numero::insertarInicio()
// Parameters:
// - Nodo
// - libro
// Return:     void
////////////////////////////////////////////////////////////////////////

void Numero::insertarInicio(int newNumero)
{
    Nodo *auxiliar = new Nodo();
    auxiliar->numero = newNumero;
    if(siguienteNumero == NULL) {
        auxiliar->siguiente = auxiliar;
        auxiliar->anterior = auxiliar;
        siguienteNumero = auxiliar;
    }
    else {
        anteriorNumero = siguienteNumero->anterior;
        auxiliar->siguiente = siguienteNumero;
        auxiliar->anterior = anteriorNumero;
        siguienteNumero->anterior = auxiliar;
        anteriorNumero->siguiente = auxiliar;
        siguienteNumero = auxiliar;
    }
}

////////////////////////////////////////////////////////////////////////
// Name:       Numero::borrarLibro(int idLibro)
// Purpose:    Implementation of Numero::borrarLibro()
// Parameters:
// - idLibro
// Return:     void
////////////////////////////////////////////////////////////////////////

void Numero::borrar(int posicion,int number)
{
   if (posicion <= tamanio()) {
        if (posicion == 1) {
            if (tamanio() == 1) {
                delete siguienteNumero;
                siguienteNumero = NULL;
            }else {
                Nodo *bor = siguienteNumero;
                anteriorNumero = siguienteNumero->anterior;
                siguienteNumero = siguienteNumero->siguiente;
                anteriorNumero->siguiente = siguienteNumero;
                siguienteNumero->anterior = anteriorNumero;
                delete bor;
            }
        }
        Nodo *auxiliar = siguienteNumero;
		if(auxiliar->numero == number) {
            for (int f = 1; f <= posicion-1; f++) {
            	auxiliar = auxiliar->siguiente;
			}
            Nodo *bor = auxiliar;
            anteriorNumero = auxiliar->anterior;
            auxiliar = auxiliar->siguiente;
            anteriorNumero->siguiente = auxiliar;
            auxiliar->anterior = anteriorNumero;
            delete bor;
        }
    }
}

////////////////////////////////////////////////////////////////////////
// Name:       Numero::buscarLibro(int idLibro)
// Purpose:    Implementation of Numero::buscarLibro()
// Parameters:
// - idLibro
// Return:     void
////////////////////////////////////////////////////////////////////////

int Numero::buscar(int numeroLista)
{
	int contador = 1;
	Nodo *auxiliar;
	auxiliar = siguienteNumero;
	while(auxiliar != anteriorNumero) {
		if(auxiliar->numero == numeroLista) {
			cout << "Se encontro en la posicion: " << contador << endl;
			return contador;
		}
		contador++;
		auxiliar = auxiliar->siguiente;
	}		
	return -1;
}

////////////////////////////////////////////////////////////////////////
// Name:       Numero::imprimir()
// Purpose:    Implementation of Numero::imprimir()
// Return:     void
////////////////////////////////////////////////////////////////////////
void Numero::imprimir(void)
{
	if (!vacio()) {
        Nodo *auxiliar = siguienteNumero;
        do {
            cout << auxiliar->numero << " ";
            auxiliar = auxiliar->siguiente;
        } while (auxiliar != siguienteNumero);
    }
}

////////////////////////////////////////////////////////////////////////
// Name:       Numero::modificarLibro(int idLibro)
// Purpose:    Implementation of Numero::modificarLibro()
// Parameters:
// - idLibro
// Return:     void
////////////////////////////////////////////////////////////////////////

void Numero::modificar(int idLibro, int newNumero)
{	
	Nodo *auxiliar = new Nodo;
	auxiliar = siguienteNumero;
	bool encontrado = false;
	if(siguienteNumero != anteriorNumero) {
		while(auxiliar != anteriorNumero && encontrado != true) {
			if(auxiliar->numero == newNumero) {
				auxiliar->numero = newNumero;
				encontrado = true;
			}
			auxiliar = auxiliar->siguiente;
		}
	}
}

////////////////////////////////////////////////////////////////////////
// Name:       Numero::insertarEntre(Nodo*& Nodo, Libro libro)
// Purpose:    Implementation of Numero::insertarEntre()
// Parameters:
// - Nodo
// - libro
// Return:     void
////////////////////////////////////////////////////////////////////////

void Numero::insertarEntre(int posicion, int newNumero)
{
   Nodo *auxiliar = new Nodo;
   auxiliar->numero = newNumero;
   auxiliar->siguiente = auxiliar;
   auxiliar->anterior= auxiliar;
   if(vacio()) {
   		siguienteNumero = auxiliar;
   		anteriorNumero = auxiliar;
   }else {
   		if(posicion == 1) {
   			insertarInicio(newNumero);	
		}else if(posicion == (tamanio()+1)){
			insertarFinal(newNumero);
		}else if(posicion > 1 && posicion < (tamanio()+1)) {
			Nodo *temporal;
			temporal = siguienteNumero;
			for(int i=1; i<posicion; i++) {
				temporal = temporal->siguiente;
			}
			temporal->anterior->siguiente = auxiliar;
			auxiliar->siguiente = temporal;
			auxiliar->anterior = temporal->anterior;
			temporal->anterior = auxiliar;
		}
		else {
			cout << "Error, posicion invalida" << endl;
		}
   }
}

////////////////////////////////////////////////////////////////////////
// Name:       Numero::insertarFinal(Nodo*& Nodo, Libro libro)
// Purpose:    Implementation of Numero::insertarFinal()
// Parameters:
// - Nodo
// - libro
// Return:     void
////////////////////////////////////////////////////////////////////////

void Numero::insertarFinal(int newNumero)
{
    Nodo *auxiliar = new Nodo();
    auxiliar->numero = newNumero;
    if (siguienteNumero == NULL) {
        auxiliar->siguiente = auxiliar;
        auxiliar->anterior = auxiliar;
        siguienteNumero = auxiliar;
    }
    else {
        anteriorNumero = siguienteNumero->anterior;
        auxiliar->siguiente = siguienteNumero;
        auxiliar->anterior = anteriorNumero;
        siguienteNumero->anterior = auxiliar;
        anteriorNumero->siguiente = auxiliar;
    }
}

bool Numero::vacio() {
	if (siguienteNumero == NULL)
        return true;
    else
        return false;
}

int Numero::tamanio() {
    if (!vacio()) {
        Nodo *auxiliar = siguienteNumero;
        do {
            contador++;
            auxiliar = auxiliar->siguiente;
        } while (auxiliar != siguienteNumero);
    }
    return contador;
}
