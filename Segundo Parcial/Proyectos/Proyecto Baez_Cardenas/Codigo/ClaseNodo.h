#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<iomanip>
using namespace std;
class Nodo
{
public:
	int dato;
	Nodo *sig;
public:
	Nodo(){};
	Nodo(Nodo *x,int a);
	bool empty(Nodo *x);
	Nodo *Insertar(Nodo **x,int a);
	void Imprimir(Nodo *x);
};
Nodo::Nodo(Nodo *x,int a)
{
	sig=x;
	dato=a;
}
bool Nodo::empty(Nodo *x){
	return x==NULL;
}
Nodo *Nodo::Insertar(Nodo **x,int a)
{
	Nodo *nuevo=new Nodo();
	nuevo->dato=a;
	if(*x == NULL) 
		*x = nuevo;
	else{
		nuevo->sig = (*x)->sig;
	}
	(*x)->sig = nuevo;// cerramos la lista circular
	return nuevo;
}

void Nodo::Imprimir(Nodo *x)
{
	Nodo *nuevo=new Nodo();
	nuevo = x;
	do {
		printf("%d -> ", nuevo->dato);
		nuevo = nuevo->sig;
	} while(nuevo != x);
	printf("\n");
}

