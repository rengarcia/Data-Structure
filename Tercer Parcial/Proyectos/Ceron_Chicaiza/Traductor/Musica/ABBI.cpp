/*******************************************************************
 *	Universidad de las Fuerzas Armadas ESPE
 *	Alex Chicaiza
 *	Maria Belen Ceron
 *	NRC: 2967
 *	Fecha creacion: 19/01/2020
 *	Fecha ultima modificacion:	26/01/2020
 *	Docente: Ing. Fernando Solis
******************************************************************/

/***********************************************************************
 * Module:  ABBI.cpp
 * Modified: Sunday, January 19, 2020 4:00:49 PM
 * Purpose: Implementation of the class ABBI
 ***********************************************************************/

#include "ABBI.h"
#include <string>
#include <iostream>

////////////////////////////////////////////////////////////////////////
// Name:       ABBI::ABBI(char* newIngles, char* newEspanol)
// Purpose:    Implementation of ABBI::ABBI()
// Parameters:
// - newIngles
// - newEspanol
// Return:     
////////////////////////////////////////////////////////////////////////

ABBI::ABBI(std::string newIngles, std::string newEspanol)
{
	this->ingles = newIngles;
	this->espanol = newEspanol;
	this->izquierda = NULL;
	this->derecha = NULL;
}

////////////////////////////////////////////////////////////////////////
// Name:       ABBI::~ABBI()
// Purpose:    Implementation of ABBI::~ABBI()
// Return:     
////////////////////////////////////////////////////////////////////////

ABBI::~ABBI()
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       ABBI::insertarNodo(char* ingles, char* espanol, ABBI*& arbol)
// Purpose:    Implementation of ABBI::insertarNodo()
// Parameters:
// - ingles
// - espanol
// - arbol
// Return:     void
////////////////////////////////////////////////////////////////////////

void ABBI::insertarNodo(std::string newIngles, std::string newEspanol, ABBI*& arbol)
{
	if (arbol == NULL) {
		ABBI* nuevo = new ABBI(newIngles,newEspanol);
		arbol = nuevo;
		//std::cout << "ingreso";
	}
	else {
		if (newIngles.substr(0,1) < arbol->ingles.substr(0,1)) {
			return insertarNodo(newIngles,newEspanol, arbol->izquierda);
		}
		else if (newIngles.substr(0, 1) >= arbol->ingles.substr(0, 1)) {
			return insertarNodo(newIngles, newEspanol,arbol->derecha);
		}
	}
}

////////////////////////////////////////////////////////////////////////
// Name:       ABBI::imprimirNodo()
// Purpose:    Implementation of ABBI::imprimirNodo()
// Return:     void
////////////////////////////////////////////////////////////////////////

void ABBI::imprimirNodo(void)
{
	if (this->ingles.compare(NULL)) {
		return;
	}
	else {
		std::cout << "Dato del nodo: " << this->ingles;
		return;
	}
}

////////////////////////////////////////////////////////////////////////
// Name:       ABBI::recorridoIn(ABBI* arbol)
// Purpose:    Implementation of ABBI::recorridoIn()
// Parameters:
// - arbol
// Return:     void
////////////////////////////////////////////////////////////////////////

void ABBI::recorridoIn(ABBI* arbol)
{
	if (arbol != NULL) {
		recorridoIn(arbol->izquierda);
		std::cout << arbol->ingles << " "<< arbol->espanol<<std::endl;
		recorridoIn(arbol->derecha);
	}
}

////////////////////////////////////////////////////////////////////////
// Name:       ABBI::recorridoPos(ABBI* arbol)
// Purpose:    Implementation of ABBI::recorridoPos()
// Parameters:
// - arbol
// Return:     void
////////////////////////////////////////////////////////////////////////

void ABBI::recorridoPos(ABBI* arbol)
{
	if (arbol != NULL) {
		recorridoPos(arbol->izquierda);
		recorridoPos(arbol->derecha);
		std::cout << arbol->ingles << " " << arbol->espanol << std::endl;
	}
}

////////////////////////////////////////////////////////////////////////
// Name:       ABBI::recorridoPre(ABBI* arbol)
// Purpose:    Implementation of ABBI::recorridoPre()
// Parameters:
// - arbol
// Return:     void
////////////////////////////////////////////////////////////////////////

void ABBI::recorridoPre(ABBI* arbol)
{
	if (arbol != NULL) {
		std::cout << arbol->ingles << " " << arbol->espanol << std::endl;
		recorridoPre(arbol->izquierda);
		recorridoPre(arbol->derecha);
	}
}

////////////////////////////////////////////////////////////////////////
// Name:       ABBI::buscar(ABBI* arbol)
// Purpose:    Implementation of ABBI::buscar()
// Parameters:
// - arbol
// Return:     void
////////////////////////////////////////////////////////////////////////

std::string ABBI::buscar(ABBI* arbol,std::string palabra)
{
	if (arbol == NULL) {
		return " ";
	}
	else if ( palabra.substr(0,1)< arbol->ingles.substr(0,1)) {
		if (palabra.compare(arbol->ingles) == 0) {
			std::cout << "\n\tTRADUCCION: " << arbol->espanol << std::endl;
			return arbol->espanol;
		}
		else {
			return buscar(arbol->izquierda, palabra);
		}
	}
	else if (palabra.substr(0,1) >= arbol->ingles.substr(0,1)) {
		if (palabra.compare(arbol->ingles) == 0) {
			std::cout << "\n\tTRADUCCION: " << arbol->espanol << std::endl;
			return arbol->espanol;
		}
		else {
			return buscar(arbol->derecha, palabra);
		}
	}

}

