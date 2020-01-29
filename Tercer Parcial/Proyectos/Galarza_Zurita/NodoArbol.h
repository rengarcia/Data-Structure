/*	***** UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE ***** **
** Estructura de Datos									**
** Nombre: Jorge Galarza - Kevin Zurita					**
** NRC: 2742											**
** Fecha de realizacion: 01/12/2019						**
** Fecha de modificacion: 12/12/2019					**
** Ing. Fernando Solis									**
*/	
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

class NodoArbol{
	private:
		int id;
		string palabra;
		NodoArbol* izquierda;
		NodoArbol* derecha;
	public:
		NodoArbol(int, string);
		int getId();
		string getPalabra();
		NodoArbol* getIzquierda();
		NodoArbol* getDerecha();
		void setId(int);
		void setPalabra(string);
		void setIzquierda(NodoArbol*);
		void setDerecha(NodoArbol*);
		
		friend class ArbolBinario;
};

NodoArbol::NodoArbol(int code, string word){
	id=code;
	palabra=word;
	izquierda=NULL;
	derecha=NULL;
}

int NodoArbol::getId(){
	return id;
}

string NodoArbol::getPalabra(){
	return palabra;
}

NodoArbol* NodoArbol::getIzquierda(){
	return izquierda;
}

NodoArbol* NodoArbol::getDerecha(){
	return derecha;
}

void NodoArbol::setId(int code){
	id=code;
}

void NodoArbol::setPalabra(string word){
	palabra=word;
}

void NodoArbol::setIzquierda(NodoArbol* left){
	izquierda=left;
}

void NodoArbol::setDerecha(NodoArbol* right){
	derecha=right;
}
