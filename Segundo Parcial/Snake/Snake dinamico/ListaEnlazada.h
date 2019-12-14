#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include "NodoSnake.h"
/*
	Universidad de las Fuerzas Armdas
	Miembros: Kevin Zurita
	NRC:2967
	Fecha de creacion:11 de noviembre del 2019
	Fecha de modificacion:12 de noviembre de 2019
	Profesor: Ing. Fernando Solis
*/

typedef NodoSnake *pnodo;

class ListaEnlazada{
	public:
		ListaEnlazada();
		void insertar(int);
		void insertarPrimero(int);
		bool listaVacia();
		char* crearLinea();
		
	private:
		pnodo primero;
};

ListaEnlazada::ListaEnlazada(){
	primero=NULL;
}


void ListaEnlazada::insertar(int num){
	pnodo anterior;
   if(listaVacia()) {                
      primero = new NodoSnake(num,primero);
   } else {
      anterior = primero;
	  primero = new NodoSnake(num,primero);
      primero->siguiente =anterior;
	}
}

bool ListaEnlazada::listaVacia(){
	 return primero == NULL; 
}

char* ListaEnlazada::crearLinea(){
	string serpiente;
	char* temp;
	pnodo aux;
   	aux = primero;
   	while(aux) {
   		temp=(char*)malloc(1*sizeof(int));
   		sprintf(temp,"%d",aux->getNumero());
   		serpiente.append(temp);
      	aux = aux->siguiente;
      	free(temp);
   	}
   	temp=(char*)malloc(serpiente.length()*sizeof(int));
   	sprintf(temp,"%s",serpiente.c_str());
   	return temp;
}

void ListaEnlazada::insertarPrimero(int num){
	pnodo aux;
	aux=primero;
   if(listaVacia()) {                
      primero = new NodoSnake(num,primero);
   } else {
   		while(aux->siguiente) {
      	aux = aux->siguiente;
   		}
   		aux->siguiente=new NodoSnake(num,aux->siguiente);	
	}
}
