#include <iostream>
#include <string>
#include <fstream>
#include <bits/stdc++.h>
#include <stdlib.h> 
#include "NodoNum.h"

/*
	Universidad de las Fuerzas Armdas
	Miembros: Kevin Zurita
	NRC:2967
	Fecha de creacion:19 de noviembre del 2019
	Fecha de modificacion:19 de noviembre de 2019
	Profesor: Ing. Fernando Solis
*/

using namespace std;

typedef NodoNum* nodoPrimo;

class listaNum{
	public:
	listaNum() {
		primero = NULL;
	}
	~listaNum();
	void Insertar(int d);
	void Mostrar();
	void GenerarArchivo();
	void borrarCabeza();
	void borrarCola();
	void llenarListaCedula(string);
	int contarPerfectos();
	int cantidadPrimos();
	void llenarCedulaDoble(string);
	
private:
	nodoPrimo primero;
};

listaNum::~listaNum(){
	nodoPrimo aux;
   
   while(primero) {
      aux = primero;
      primero = primero->siguiente;
      delete aux;
   }
   primero=NULL;
}

void listaNum::Insertar(int d) {
	nodoPrimo anterior;

	if (primero == NULL) {
		primero = new NodoNum(d, primero);
	}
	else {
		
      anterior = primero;
	  primero = new NodoNum(d, primero);
      primero->siguiente=anterior;
	}
}

void listaNum::Mostrar() {
	nodoPrimo aux;
	aux = primero;
	while (aux) {
		cout <<aux->dato<< " ";
		aux = aux->siguiente;
	}
}

void listaNum::llenarListaCedula(string cedula){	
	for(int i=0; i<cedula.length(); i++){
	char* numero;
	numero=(char*)malloc(1*sizeof(char));
		sprintf(numero,"%c",cedula.at(i));
		int num=atoi(numero);
		Insertar(num);
		free(numero);
	}
}

void listaNum::llenarCedulaDoble(string cedula){	
	for(int i=0; i<=cedula.length()-1; i+=2){
		char* numero;
		numero=(char*)malloc(2*sizeof(char));
		sprintf(numero,"%c%c",cedula.at(i),cedula.at(i+1));
		int num=strtof(numero,0);
		Insertar(num);
		free(numero);
	}
}

int listaNum::cantidadPrimos(){
	nodoPrimo aux = primero;
	int cPrimos=0;
	while (aux) {
		int temp = aux->dato;
		if(temp==2||temp==3||temp==5||temp==7){
			cPrimos++;
		}
		aux = aux->siguiente;
	}
	
	return cPrimos;
}

int listaNum::contarPerfectos( )
{
	int contador = 0;
	int suma;
	int temporal;

	while (primero != NULL) {
		suma = 0;
		temporal = primero->dato;
		for (int i = 1; i < temporal - 1; i++) {
			if (temporal % i == 0) 
				suma += i;
			}
		if (suma == temporal&&temporal!=0) {
				contador++;
		}
		primero = primero->siguiente;

	}
	return contador;
}
