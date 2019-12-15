/***********************************************************************
 * Module:  OperacionesNodo.cpp
 * Author:  fleia
 * Modified: Saturday, November 30, 2019 1:33:41 PM
 * Purpose: Implementation of the class OperacionesNodo
 ***********************************************************************/

#include "OperacionesNodo.h"
#include "Cubo.h"
#include <iostream>
#include <fstream>

using namespace std;
fstream enter;
int valorClave = -1;
int n = 1;

////////////////////////////////////////////////////////////////////////
// Name:       OperacionesNodo::insertarCabeza(Nodo** referencia, Cubo cubo)
// Purpose:    Implementation of OperacionesNodo::insertarCabeza()
// Parameters:
// - referencia
// - cubo
// Return:     void
////////////////////////////////////////////////////////////////////////

void OperacionesNodo::insertarCabeza(Nodo** referencia, Cubo cubo)
{
	if (*referencia == NULL)
	{
		class Nodo* temporal = new Nodo;
		temporal->setCubo(cubo);
		temporal->setAnterior(temporal);
		temporal->setSiguiente(temporal);

		*referencia = temporal;
		return;
	}
	class Nodo* temporal = new Nodo;
	class Nodo* ultimo = (*referencia)->getAnterior();

	temporal->setCubo(cubo);

	temporal->setSiguiente(*referencia);

	temporal->setAnterior(ultimo);

	(*referencia)->setAnterior(temporal);
	ultimo->setSiguiente(temporal);

	*referencia = temporal;

}

////////////////////////////////////////////////////////////////////////
// Name:       OperacionesNodo::insertarCola(Nodo** referencia, Cubo cubo)
// Purpose:    Implementation of OperacionesNodo::insertarCola()
// Parameters:
// - referencia
// - cubo
// Return:     void
////////////////////////////////////////////////////////////////////////

void OperacionesNodo::insertarCola(Nodo** referencia, Cubo cubo)
{
	if (*referencia == NULL)
	{
		class Nodo* temporal = new Nodo;
		temporal->setCubo(cubo);
		temporal->setAnterior(temporal);
		temporal->setSiguiente(temporal);

		*referencia = temporal;
		return;
	}

	Nodo* ultimo = (*referencia)->getAnterior();

	class Nodo* temporal = new Nodo;
	temporal->setCubo(cubo);
	temporal->setSiguiente(*referencia);
	(*referencia)->setAnterior(temporal);
	temporal->setAnterior(ultimo);
	ultimo->setSiguiente(temporal);
}

////////////////////////////////////////////////////////////////////////
// Name:       OperacionesNodo::imprimir(Nodo* referencia)
// Purpose:    Implementation of OperacionesNodo::imprimir()
// Parameters:
// - referencia
// Return:     void
////////////////////////////////////////////////////////////////////////

void OperacionesNodo::imprimir(Nodo* referencia)
{
	class Nodo* temporal = referencia;
	Cubo cubo;
	int contador = 0;

	while (temporal->getSiguiente() != referencia)
	{
		cubo = temporal->getCubo();
		cout << cubo.getValor() << " ";
		contador++;
		if (contador > 9) {
			cout << endl;
			contador = 0;
		}

		temporal = temporal->getSiguiente();
	}

	cout << endl;
}

void OperacionesNodo::imprimirTxt(Nodo* referencia)
{
	class Nodo* temporal = referencia;
	Cubo cubo;
	int contador = 0;

	if (n == 1) {
		enter.open("Soluciones/solucion.txt", fstream::out);
		enter << "Tablero: " << endl << endl;
	}

	enter << "Intento Numero: " << n << endl;

	while (temporal->getSiguiente() != referencia)
	{
		cubo = temporal->getCubo();
		enter << cubo.getValor() << " ";
		contador++;
		if (contador > 9) {
			enter << endl;
			contador = 0;
	}

		temporal = temporal->getSiguiente();
	}

	n++;
	enter << endl;
}



////////////////////////////////////////////////////////////////////////
// Name:       OperacionesNodo::verificacionHorizontal(Nodo* fila)
// Purpose:    Implementation of OperacionesNodo::verificacionHorizontal()
// Parameters:
// - fila
// Return:     void
////////////////////////////////////////////////////////////////////////

void OperacionesNodo::verificacionHorizontal(Nodo* fila)
{
   class Nodo* tempInicial = fila;
   class Nodo* tempSiguiente = fila->getSiguiente();
   class Nodo* tempSiguientex2 = tempSiguiente->getSiguiente();

   Cubo cuboInicial;
   Cubo cuboSiguiente;
   Cubo cuboSiguientex2;

   int auxiliar;
   bool bandera;

   while (tempInicial->getSiguiente() != fila)
   {
	   bandera = false;
	   cuboInicial = tempInicial->getCubo();
	   cuboSiguiente = tempSiguiente->getCubo();
	   cuboSiguientex2 = tempSiguientex2->getCubo();
	   auxiliar = cuboInicial.getValor();

	   if (cuboInicial.getValor() == cuboSiguiente.getValor()&&cuboInicial.getValor()!=0) {
		   cuboInicial.setValor(valorClave);
		   cuboSiguiente.setValor(valorClave);
		   bandera = true;

		   tempInicial->setCubo(cuboInicial);
		   tempSiguiente->setCubo(cuboSiguiente);
	   }

	   if (auxiliar == cuboSiguientex2.getValor() && bandera&&auxiliar != 0) {
		   cuboSiguientex2.setValor(valorClave);

		   tempSiguientex2->setCubo(cuboSiguientex2);
	   }

	   tempInicial = tempInicial->getSiguiente();
	   tempSiguiente = tempSiguiente->getSiguiente();
	   tempSiguientex2 = tempSiguientex2->getSiguiente();
   }
}

////////////////////////////////////////////////////////////////////////
// Name:       OperacionesNodo::verificacionVertical(Nodo* fila, Nodo* primeraFila)
// Purpose:    Implementation of OperacionesNodo::verificacionVertical()
// Parameters:
// - fila
// - primeraFila
// Return:     void
////////////////////////////////////////////////////////////////////////

void OperacionesNodo::verificacionVertical(Nodo* fila)
{
	class Nodo* base = fila;
	class Nodo* pivot = fila;

	int i = 0;
	while (i < 10) {
		pivot = pivot->getSiguiente();
		i++;
	}

	Cubo cuboBase;
	Cubo cuboPivot;

	while (base->getSiguiente() != fila)
	{
		cuboBase = base->getCubo();
		cuboPivot = pivot->getCubo();

		if (cuboBase.getValor() == cuboPivot.getValor() && cuboBase.getValor() != 0 && cuboPivot.getValor() != 0) {
			cuboBase.setValor(valorClave);
			cuboPivot.setValor(valorClave);
			base->setCubo(cuboBase);
			pivot->setCubo(cuboPivot);
		}
		base = base->getSiguiente();
		pivot = pivot->getSiguiente();
	}

	cuboBase = base->getCubo();
	cuboPivot = pivot->getCubo();
	//este if sirve para verifcar solo la ultima posicion de la fila
	if (cuboBase.getValor() == cuboPivot.getValor() && cuboBase.getValor() != 0 && cuboPivot.getValor() != 0) {
		cuboBase.setValor(valorClave);
		cuboPivot.setValor(valorClave);
		base->setCubo(cuboBase);
		pivot->setCubo(cuboPivot);
	}
}

////////////////////////////////////////////////////////////////////////
// Name:       OperacionesNodo::insertarDatoPorPosicion(Nodo* fila)
// Purpose:    Implementation of OperacionesNodo::insertarDatoPorPosicion()
// Parameters:
// - fila
// Return:     void
////////////////////////////////////////////////////////////////////////

void OperacionesNodo::insertarDatoPorPosicion(Nodo* fila, int posicionfila,int posicionColumna,int dato)
{
	class Nodo* temporal = fila;
	Cubo cubo;
	
	while (temporal->getSiguiente() != temporal)
	{
		cubo = temporal->getCubo();
		if (cubo.getColumna() == posicionColumna&&cubo.getFila() == posicionfila) {
			cubo.setValor(dato);
			temporal->setCubo(cubo);
			break;
		}
		temporal = temporal->getSiguiente();
	}
	
}

void OperacionesNodo::inicializarFila(Nodo** lista, int casillas)
{
	int posicionColumna = 0;
	int posicionFila=0;
	int i = 0;
	Cubo cubo;

	while (i<=casillas) {
		cubo.setColumna(posicionColumna+1);
		
		posicionFila = asignarFila(i);
		cubo.setFila(posicionFila);
		
		cubo.setValor(0);
		
		insertarCola(lista, cubo);
		posicionColumna++;
		i++;
		
		if (posicionColumna > 9) {
			posicionColumna = 0;
		}
	}

}

bool OperacionesNodo::seguirEnJuego(Nodo* fila)
{
	class Nodo* temp;
	class Nodo* filaTemp=fila;
 
	Cubo cuboAuxiliar;
	int valor;
	int auxiliar = 180;

	int i = 0;
	while (i < auxiliar) {
		filaTemp = filaTemp->getSiguiente();
		i++;
	}

	while (filaTemp->getSiguiente()!=fila) {
		cuboAuxiliar = filaTemp->getCubo();
		valor = cuboAuxiliar.getValor();
		if (valor != 0) {
			return false;
		}
		filaTemp = filaTemp->getSiguiente();
	}

	return true;
}

int OperacionesNodo::asignarFila(int numero) {

	if (numero < 10) {
		return 1;
	}

	else if (numero < 20) {
		return 2;
	}
	
	else if (numero < 30) {
		return 3;
	}

	else if (numero < 40) {
		return 4;
	}
	
	else if (numero < 50) {
		return 5;
	}

	else if (numero < 60) {
		return 6;
	}

	else if (numero < 70) {
		return 7;
	}

	else if (numero < 80) {
		return 8;
	}

	else if (numero < 90) {
		return 9;
	}

	else if (numero < 100) {
		return 10;
	}

	else if (numero < 110) {
		return 11;
	}
	
	else if (numero < 120) {
		return 12;
	}

	else if (numero < 130) {
		return 13;
	}

	else if (numero < 140) {
		return 14;
	}

	else if (numero < 150) {
		return 15;
	}

	else if (numero < 160) {
		return 16;
	}

	else if (numero < 170) {
		return 17;
	}

	else if (numero < 180) {
		return 18;
	}

	else if (numero < 190) {
		return 19;
	}

	else {
		return 20;
	}

}


