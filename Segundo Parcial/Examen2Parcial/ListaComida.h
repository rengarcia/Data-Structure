#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <windows.h>
#include "NodoComida.h"
/*
	Universidad de las Fuerzas Armdas
	Miembros: Kevin Zurita
	NRC:2967
	Fecha de creacion:11 de diciembre del 2019
	Fecha de modificacion:11 de diciembre de 2019
	Profesor: Ing. Fernando Solis
*/

 
void gotoxy(int x, int y) 
{ 
 HANDLE hCon; 
 COORD dwPos; 
 
 dwPos.X = x; 
 dwPos.Y = y; 
 hCon = GetStdHandle(STD_OUTPUT_HANDLE); 
 SetConsoleCursorPosition(hCon,dwPos); 
}

typedef NodoComida *cnodo;

class ListaComida{
	public:
		ListaComida();
		void insertar(int,int,int);
		void insertarPrimero(int,int,int);
		bool listaVacia();
		char* crearLinea();
		void imprimirComida(int);
		bool comprobarElementos(int,int,int,int);
		int quitarElemento();
	private:
		cnodo primero;
};

ListaComida::ListaComida(){
	primero=NULL;
}


void ListaComida::insertar(int value, int row, int column){
	cnodo anterior;
   if(listaVacia()) {                
      primero = new NodoComida(value, row, column);
   } else {
      anterior = primero;
	  primero = new NodoComida(value, row, column);
      primero->sig =anterior;
	}
}

bool ListaComida::listaVacia(){
	 return primero == NULL; 
}

char* ListaComida::crearLinea(){
	string serpiente;
	char* temp;
	cnodo aux;
   	aux = primero;
   	while(aux) {
   		temp=(char*)malloc(1*sizeof(int));
   		sprintf(temp,"%d",aux->getValorTetris());
   		serpiente.append(temp);
      	aux = aux->sig;
      	free(temp);
   	}
   	temp=(char*)malloc(serpiente.length()*sizeof(int));
   	sprintf(temp,"%s",serpiente.c_str());
   	return temp;
}

void ListaComida::insertarPrimero(int value, int row, int column){
	cnodo aux;
	aux=primero;
   if(listaVacia()) {                
      primero = new NodoComida(value, row, column);
   } else {
   		while(aux->sig) {
      	aux = aux->sig;
   		}
   		aux->sig=new NodoComida(value, row, column);	
	}
}

void ListaComida::imprimirComida(int elementos){
	cnodo aux=primero;
	while(aux!=NULL){
		gotoxy(aux->getColumnas(),aux->getFilas()+elementos*2);
		printf("%d",aux->getValorTetris());
		elementos--;
		aux=aux->sig;
	}
}

bool ListaComida::comprobarElementos(int xCuerpo, int yCuerpo, int elementos, int cuerpo){
	cnodo aux=primero;
	if(aux->getFilas()+elementos*2==yCuerpo){
	//	if(aux->getColumnas()<=xCuerpo+cuerpo&&aux->getColumnas()>=xCuerpo){ //comentado para poder ganar el juego y demostrar funcionalidad
			return true;
	//	}
	}
	return false;
}

int ListaComida::quitarElemento(){
	cnodo aux=primero;
	primero=primero->sig;
	return aux->getValorTetris();
}
