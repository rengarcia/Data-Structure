#include <iostream>
#include <stdio.h>
/*
	Universidad de las Fuerzas Armdas
	Miembros: Kevin Zurita
	NRC:2967
	Fecha de creacion:11 de diciembre del 2019
	Fecha de modificacion:11 de diciembre de 2019
	Profesor: Ing. Fernando Solis
*/
using namespace std;

class NodoComida{
    private:
        int valorTetris;
        int filas;
        int columna;
        NodoComida* sig;
    public:
        NodoComida(int,int,int);
        int getValorTetris();
        void setValorTetris(int);
        int getColumnas();
        void setColumnas(int);
        int getFilas();
        void setFilas(int);
        NodoComida* getSiguiente();
        void setSiguiente(NodoComida*);
		NodoComida* getAnterior();
        void setAnterior(NodoComida*);
        void imprimir();
    friend class ListaComida;
};

NodoComida::NodoComida(int value, int row, int column){
	valorTetris=value;
	filas=row;
	columna=column;
	sig=NULL;
}

int NodoComida::getValorTetris(){
	return valorTetris;
}

void NodoComida::setValorTetris(int value){
	valorTetris=value;
}

int NodoComida::getFilas(){
	return filas;
}

void NodoComida::setFilas(int row){
	filas=row;
}

int NodoComida::getColumnas(){
	return columna;
}

void NodoComida::setColumnas(int column){
	columna=column;
}

NodoComida* NodoComida::getSiguiente(){
	return sig;
}

void NodoComida::setSiguiente(NodoComida* after){
	sig=after;
}
