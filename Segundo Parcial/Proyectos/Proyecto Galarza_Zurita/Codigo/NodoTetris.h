#include <iostream>
#include <stdio.h>

using namespace std;

class NodoTetris{
    private:
        int valorTetris;
        int filas;
        int columna;
        NodoTetris* sig;
        NodoTetris* ant;
    public:
        NodoTetris(int,int,int);
        int getValorTetris();
        void setValorTetris(int);
        int getColumnas();
        void setColumnas(int);
        int getFilas();
        void setFilas(int);
        NodoTetris* getSiguiente();
        void setSiguiente(NodoTetris*);
		NodoTetris* getAnterior();
        void setAnterior(NodoTetris*);
        void imprimir();
        
    friend class ListaCD;
};

NodoTetris::NodoTetris(int value, int row, int column){
	valorTetris=value;
	filas=row;
	columna=column;
	sig=NULL;
	ant=NULL;
}

int NodoTetris::getValorTetris(){
	return valorTetris;
}

void NodoTetris::setValorTetris(int value){
	valorTetris=value;
}

int NodoTetris::getFilas(){
	return filas;
}

void NodoTetris::setFilas(int row){
	filas=row;
}

int NodoTetris::getColumnas(){
	return columna;
}

void NodoTetris::setColumnas(int column){
	columna=column;
}

NodoTetris* NodoTetris::getAnterior(){
	return ant;
}

void NodoTetris::setAnterior(NodoTetris* before){
	ant=before;
}

NodoTetris* NodoTetris::getSiguiente(){
	return sig;
}

void NodoTetris::setSiguiente(NodoTetris* after){
	sig=after;
}
void NodoTetris::imprimir(){
	cout<<valorTetris;
	cout<<" "<<filas;
	cout<<" "<<columna<<endl;
}
