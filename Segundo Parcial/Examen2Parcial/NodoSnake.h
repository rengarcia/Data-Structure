#include <iostream>
#include <stdio.h>
#include <string>
/*
	Universidad de las Fuerzas Armdas
	Miembros: Kevin Zurita
	NRC:2967
	Fecha de creacion:17 de noviembre del 2019
	Fecha de modificacion:17 de noviembre de 2019
	Profesor: Ing. Fernando Solis
*/

using namespace std;

class NodoSnake{
	public:
		NodoSnake(int, NodoSnake*);
		int getNumero();
	private:
		int numero;
		NodoSnake *siguiente;
	
	friend class ListaEnlazada;
};

NodoSnake::NodoSnake(int num, NodoSnake *sig=NULL){
	numero=num;
	siguiente=sig;
}

int NodoSnake::getNumero(){
	return numero;
}

