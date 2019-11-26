#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include "Persona.h"
#include "Persona.cpp"
#include "listaNum.h"
using namespace std;

/***********************************************************************
 * Module:  ListaEnlazada.h
 * Author:  Kevin Zurita
 * Modified: Thursday, November 13, 2019 10:38:09 AM
 * Purpose: Declaration of the class ListaEnlazada
 ***********************************************************************/

#if !defined(__Listas2_ListaEnlazada_h)
#define __Listas2_ListaEnlazada_h

#include "Nodo.h"

typedef Nodo *pnodo;


class ListaEnlazada
{
public:
   void ingresarCola(string, string, string);
   void ingresarCabeza(string, string, string);
   void imprimirLista(void);
   void imprimirListaPrimos(void);
   bool listaVacia();
   int buscarElemento(string);
   void borrarCabeza();
   void borrarCola();
   void generarArchivo();
   int numeroElementos();
   string generarCorreo(string, string);
   ListaEnlazada();
protected:
private:
	int idPersona=0;
    pnodo primero;
};

ListaEnlazada::ListaEnlazada(){
	primero=NULL;
}

bool ListaEnlazada::listaVacia(){
	 return primero == NULL; 
}

int ListaEnlazada::numeroElementos(){
	int i=0;
	pnodo aux;
   	aux = primero;
   	while(aux) {
      	aux = aux->getsiguiente();
      	i++;
   	}
   	return i;
}

int ListaEnlazada::buscarElemento(string palabra){
	int indice=0;
	cout<<"El apellido "<<palabra<<" existe en las siguientes posiciones: ";
	pnodo aux;
   	aux = primero;
   	while(aux) {
   		string tempApellido=aux->getperson().getapellido();
   		if(tempApellido.compare(palabra)==0){
   			cout<<indice<<" ";
		   }
		   indice++;
      	aux = aux->getsiguiente();
   	}
   	cout << endl;
}

void ListaEnlazada::borrarCabeza(){
	pnodo aux;
    pnodo temp;
	aux=primero;
	if(numeroElementos()==1){
		delete primero;
		primero=NULL;
	}
   else if(!listaVacia()) {          
   		while(aux->getsiguiente()) {
   			temp=aux;
      		aux = aux->getsiguiente();
   		}
   		temp->setsiguiente(NULL);
   		delete aux;
   		
	}
}

void ListaEnlazada::borrarCola(){
	pnodo siguiente;
	if(numeroElementos()==1){
		delete primero;
		primero=NULL;
	}
   else if(!listaVacia()) {
      siguiente = primero->getsiguiente();
      delete primero;
      primero=siguiente;
	}
}

void ListaEnlazada::generarArchivo(){
	fstream enter;
	enter.open("ListaPersonas.txt", fstream::out);
	enter << "Lista de personas guardadas" << endl;
	pnodo aux;
	aux = primero;
	while (aux) {
		enter <<endl;
		enter <<"Id Persona: "<<aux->getperson().getidPersona()<<endl;
		enter <<"Cedula Persona: "<<aux->getperson().getcedula()<<endl;
		enter <<"Nombre Persona: "<<aux->getperson().getnombre()<<endl;
		enter <<"Apellido Persona: "<<aux->getperson().getapellido()<<endl;
		enter <<"Correo Persona: "<<aux->getperson().getCorreo()<<endl;
		aux = aux->getsiguiente();
	}
	enter.close();
}

void ListaEnlazada::imprimirListaPrimos(void)
{
	listaNum listN;
  	pnodo aux;
   	aux = primero;
   	while(aux) {
   		aux->getperson().imprimirDatosPrimos();
   		listN.llenarListaCedula(aux->getperson().getcedula());
   		cout<<"Numero de numeros perfectos: "<<listN.contarPerfectos()<<endl;
   		listN.~listaNum();
   		aux=aux->getsiguiente();
   	}
   	
   	cout << endl;
}

string ListaEnlazada::generarCorreo(string nombre, string apellido){
	string email, min;
	char* alocator;
	alocator=(char*)malloc(1*sizeof(char));
	int x=nombre.find(" ");
	if(x>1){
	sprintf(alocator,"%c%c",nombre.at(0),nombre.at(nombre.find(" ")+1));
	}
	else{
	sprintf(alocator,"%c",nombre.at(0));
	}
	email.append(alocator);
	if(apellido.find(" ")>0){
	email.append(apellido.substr(0,apellido.find(" ")).c_str());
	}
	else{
	email.append(apellido.c_str());
	}
	free(alocator);
	for(int i = 0; i<email.length();i++){
		int y=(int)email.at(i);
		char c=tolower(y);
		char* minus;
		minus=(char*)malloc(1*sizeof(char));
		sprintf(minus,"%c",c);
		min.append(minus);
		free(minus);
	}
	pnodo aux;
   	aux = primero;
   	char* numero=new char[10];
   	int number=0;
   	while(aux) {
   		if(min.compare(aux->getperson().getCorreo().substr(0,min.length()))==0)
   			number++;
   			
      	aux = aux->getsiguiente();
   	}
   	if(number!=0){
		sprintf(numero,"%d",number);
		min.append(numero);
	   }
	   free(numero);
	   min.append("@espe.edu.ec");
	   
	   return min;
}
#endif
