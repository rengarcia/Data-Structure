/***********************************************************************
 * Module:  Prototipo.cpp
 * Author:  fleia
 * Modified: Wednesday, November 13, 2019 10:51:12 AM
 * Purpose: Implementation of the class Prototipo
 ***********************************************************************/

#include "Prototipo.h"
#include <string>
#include <iostream>
using namespace std;

////////////////////////////////////////////////////////////////////////
// Name:       Prototipo::pushHead(NodoPersona* HeadRef, Persona persona)
// Purpose:    Implementation of Prototipo::pushHead()
// Parameters:
// - HeadRef
// - persona
// Return:     NodoPersona*
////////////////////////////////////////////////////////////////////////

NodoPersona* Prototipo::insertarCabeza(NodoPersona* referencia, Persona persona)
{
	NodoPersona* nodoTemporal = new NodoPersona();

	nodoTemporal->setPersona(persona);
	nodoTemporal->setSiguiente(referencia);

	return nodoTemporal;
}

////////////////////////////////////////////////////////////////////////
// Name:       Prototipo::pushTail(NodoPersona* HeadRef, Persona persona)
// Purpose:    Implementation of Prototipo::pushTail()
// Parameters:
// - HeadRef
// - persona
// Return:     void
////////////////////////////////////////////////////////////////////////

NodoPersona* Prototipo::insertarCola(NodoPersona* referencia, Persona persona)
{
	NodoPersona* nodoTemporal = new NodoPersona();

	nodoTemporal->setPersona(persona);
	nodoTemporal->setSiguiente(NULL);

	if (referencia == NULL) {
		nodoTemporal->setSiguiente(referencia);
		return nodoTemporal;
	}
	else {

		while (referencia->getSiguiente() != NULL)
			referencia = referencia->getSiguiente();

		referencia->setSiguiente(nodoTemporal);
	}
}

////////////////////////////////////////////////////////////////////////
// Name:       Prototipo::imprimir(NodoPersona* HeadRef)
// Purpose:    Implementation of Prototipo::imprimir()
// Parameters:
// - HeadRef
// Return:     void
////////////////////////////////////////////////////////////////////////

void Prototipo::imprimir(NodoPersona* referencia)
{	
	int contador=1;
	while (referencia != NULL) {
		Persona temporal;

		temporal = referencia->getPersona();
		cout << endl;
		cout <<"|**********************|"<<endl;
		cout <<"Datos de persona N-"<<contador<<": " << endl;
		cout <<"Nombre: " <<temporal.getNombre() << endl;
		cout <<"Apellido: " <<temporal.getApellido() << endl;
		cout <<"Cedula: " <<temporal.getCedula() << endl;
		cout <<"Id: " <<temporal.getIdPersona() << endl;
		cout <<"|**********************|"<< endl;
		cout << endl;
		referencia = referencia->getSiguiente();
		contador++;
	}
}