/***********************************************************************
 * Module:  ListaEnlazada.cpp
 * Author:  Kevin Zurita
 * Modified: Thursday, November 13, 2019 10:38:09 AM
 * Purpose: Implementation of the class ListaEnlazada
 ***********************************************************************/

#include "ListaEnlazada.h"
#include "Nodo.cpp"
////////////////////////////////////////////////////////////////////////
// Name:       ListaEnlazada::ingresarCola()
// Purpose:    Implementation of ListaEnlazada::ingresarCola()
// Return:     void
////////////////////////////////////////////////////////////////////////

void ListaEnlazada::ingresarCola(string c, string n, string a)
{
	listaNum listN;
	listN.llenarListaCedula(c);
	string correo=generarCorreo(n,a);
	
   pnodo anterior;
   if(listaVacia()) {                
      primero = new Nodo(Persona(idPersona,c,n,a,listN.cantidadPrimos(),correo),primero);
      listN.~listaNum();
      idPersona++;
   } else {
      anterior = primero;
	  primero = new Nodo(Persona(idPersona,c,n,a,listN.cantidadPrimos(),correo),primero);
	  listN.~listaNum();
      primero->setsiguiente(anterior);
      idPersona++;
	}
}

////////////////////////////////////////////////////////////////////////
// Name:       ListaEnlazada::ingresarCabeza()
// Purpose:    Implementation of ListaEnlazada::ingresarCabeza()
// Return:     void
////////////////////////////////////////////////////////////////////////

void ListaEnlazada::ingresarCabeza(string c, string n, string a)
{
	listaNum listN;
	listN.llenarListaCedula(c);
	string correo=generarCorreo(n,a);
   pnodo aux;
   pnodo temp;
	aux=primero;
   if(listaVacia()) {                
      primero = new Nodo(Persona(idPersona,c,n,a,listN.cantidadPrimos(),correo),primero);
      listN.~listaNum();
      idPersona++;
   } else {
   		while(aux->getsiguiente()) {
      	aux = aux->getsiguiente();
   		}
   		temp = new Nodo(Persona(idPersona,c,n,a,listN.cantidadPrimos(),correo),aux->getsiguiente());
   		listN.~listaNum();
   		aux->setsiguiente(temp);	
   		idPersona++;
	}
}

////////////////////////////////////////////////////////////////////////
// Name:       ListaEnlazada::imprimirLista()
// Purpose:    Implementation of ListaEnlazada::imprimirLista()
// Return:     void
////////////////////////////////////////////////////////////////////////

void ListaEnlazada::imprimirLista(void)
{
  pnodo aux;
   	aux = primero;
   	while(aux) {
   		aux->getperson().imprimirDatos();
      	aux = aux->getsiguiente();
   	}
   	cout << endl;
}
