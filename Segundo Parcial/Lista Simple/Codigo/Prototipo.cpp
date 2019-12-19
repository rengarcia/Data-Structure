/***********************************************************************
 * Module:  Prototipo.cpp
 * Author:  K-vn-
 * Modified: miércoles, 13 de noviembre de 2019 10:44:55
 * Purpose: Implementation of the class Prototipo
 ***********************************************************************/
 
//D.O.S

#include "Prototipo.h"
#include "Nodo.cpp"

using namespace std;

bool Prototipo::vacio(){
	if(siguiente == NULL)
		return true;
	else
		return false;
}

Persona Prototipo::leerPersona(){
	Persona _persona;
	_persona.ingresarDatos();
	return _persona;
}

////////////////////////////////////////////////////////////////////////
// Name:       Prototipo::insertarInicio()
// Purpose:    Implementation of Prototipo::insertarInicio()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Prototipo::insertarInicio(void)
{
   Persona _persona;
	_persona = leerPersona();
	if(vacio()){
		siguiente = new Nodo(_persona, NULL);
	}else{
		Nodo *aux = new Nodo();
		aux->setPersona(_persona);
		aux->setSiguiente(siguiente);
		siguiente = aux;
	}
}

////////////////////////////////////////////////////////////////////////
// Name:       Prototipo::insertarFinal()
// Purpose:    Implementation of Prototipo::insertarFinal()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Prototipo::insertarFinal(void)
{
   Persona _persona;
	_persona = leerPersona();
	if(vacio()){
		siguiente = new Nodo(_persona, NULL);
	}
	else{
		Nodo *aux1 = new Nodo();
		aux1=siguiente;
		Nodo *aux2=new Nodo();
		while((aux1)!=NULL){
			aux2=aux1;
			aux1=aux1->getSiguiente();
		}
		Nodo *aux3=new Nodo(_persona,NULL);
		aux2->setSiguiente(aux3);
		
	}
}

////////////////////////////////////////////////////////////////////////
// Name:       Prototipo::imprimirNodo()
// Purpose:    Implementation of Prototipo::imprimirNodo()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Prototipo::imprimirNodo(void)
{
	Nodo *aux = new Nodo();
	aux = siguiente;
	if(!vacio()){
		while(aux != NULL){
			aux->getPersona().imprimirPersona();
			cout << endl;
			aux = aux->getSiguiente();
		}
	} else {
		cout << "Lista vacia" << endl;
	}
}
