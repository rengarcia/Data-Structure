/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 2967                                                       *
******************************************************************/

#include <sstream>
#include "ListaSimpleCedula.h"
#include "NodoCedula.h"
#pragma once

////////////////////////////////////////////////////////////////////////
// Name:       ListaSimpleCedula::ingresoInicio(Persona obj)
// Purpose:    Implementation of ListaSimpleCedula::ingresoInicio()
// Parameters:
// - obj
// Return:     void
////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////
// Name:       ListaSimpleCedula::ingresoFinal(Persona obj)
// Purpose:    Implementation of ListaSimpleCedula::ingresoFinal()
// Parameters:
// - obj
// Return:     void
////////////////////////////////////////////////////////////////////////


void ListaSimpleCedula::ingresoInicio(int obj){
    prPrimero = new NodoCedula(obj,prPrimero);
}

void ListaSimpleCedula::ingresoFinal(int obj){
    NodoCedula *p = prPrimero;
    NodoCedula *nuevo;

    if(p == NULL){
        ingresoInicio(obj);
    }else{
        while(p->getSiguiente() != NULL){
            p = p->getSiguiente();
        }
        nuevo = new NodoCedula(obj, NULL);
        p->setSiguiente(nuevo);
    }
}
////////////////////////////////////////////////////////////////////////
// Name:       ListaSimpleCedula::imprimirDatos()
// Purpose:    Implementation of ListaSimpleCedula::imprimirDatos()
// Return:     void
////////////////////////////////////////////////////////////////////////



char* ListaSimpleCedula::transformar(int valor){
    stringstream a;
    a<<valor;
    return (char*)a.str().c_str();
}

int ListaSimpleCedula::sumarNodo(char* cadena,int valor){
    valor = *(cadena+0) - '0' + *(cadena+1) - '0' ;
    if(valor < 10){
        return valor;
    }else{
        sumarNodo(transformar(valor), 0);
    }
}

void ListaSimpleCedula::sumar(){
    NodoCedula *p = prPrimero;
    cout<<"La suma de cada dos digitos es: "<<endl;
    while(p != NULL){
    	if(p->getValor()>9){
    		int valor = sumarNodo(transformar(p->getValor()),0);
    		cout<<valor<<" ";
		}else{
			cout<<p->getValor()<<" ";
		}
        p = p->getSiguiente();
   }
   cout<<endl<<endl;
}

void ListaSimpleCedula::imprimirCedula(void)
{
   NodoCedula *p = prPrimero;
   cout<<"Cedula"<<endl;
   while(p != NULL){
        cout<<p->getValor()<<" ";
        p = p->getSiguiente();
   }
   cout<<endl;
}
void ListaSimpleCedula::eliminarInicio(){
    NodoCedula *p = prPrimero;
    if(p == NULL){
        cout<<"Nada que eliminar"<<endl;
        return;
    }else{
    prPrimero = p->getSiguiente();
    }
    delete p;
}

void ListaSimpleCedula::eliminarFinal(){
    NodoCedula *p = prPrimero;
    NodoCedula *aux;
    if(p == NULL){
        cout<<"Nada que eliminar"<<endl;
        return;
    }
    if(p->getSiguiente() == NULL){
        eliminarInicio();
        //cout<<"Nada que eliminar"<<endl;
        return;
    }else{
        while(p->getSiguiente() != NULL){
            aux = p;
            p = p->getSiguiente();
        }
        aux->setSiguiente(NULL);
    }
      delete p;
}


void ListaSimpleCedula::setPrPrimero(NodoCedula *primero){
    prPrimero = primero;
}

NodoCedula* ListaSimpleCedula::getPrPrimero(){
    return prPrimero;
}

ListaSimpleCedula::ListaSimpleCedula(){
    prPrimero = NULL;
}

void ListaSimpleCedula::destruir(){
    NodoCedula *p = prPrimero;
    NodoCedula *actual;
    while(p != NULL){
        actual = p->getSiguiente();
        delete p;
        p = actual;
    }
    prPrimero = NULL;
}

void ListaSimpleCedula::guardarDosDigitos(string cedula){
    string cadena = "";
    int cont=0,aux=0;
    for(int i = aux; i<10; i++){

        if(cont != 2){
            cadena += cedula.at(i);
            cont++;
        }

        if(cont == 2){
            ingresoFinal(atoi(cadena.c_str()));
            cadena = "";
            cont = 0;
        }
    }
    imprimirCedula();
    sumar();
    destruir();
}

void ListaSimpleCedula::buscarPrimos(){
    NodoCedula *p = prPrimero;
    int cont = 0;
    while(p != NULL){
        if(comprobarPrimo(p->getValor())){
        	cont++;
        	cout<<p->getValor()<<" ";
		}
        p = p->getSiguiente();
   }
   cout<<"Existen "<<cont<<" Numeros primos"<<endl;
   cout<<endl;
   destruir();
}

bool ListaSimpleCedula::comprobarPrimo(int n)
{
    int acum=0;
    for(int i=1;i<=n;i++)
    {
        if(n%i==0)
        {
            acum++;
        }
    }
    
    if(acum == 2)
    {
       return true;
    }else{
    	return false;
	}
}

void ListaSimpleCedula::guardarUnDigito(string cedula){
    for(int i = 0; i<10; i++){
    	
        ingresoFinal(cedula.at(i)-'0');
    }
    imprimirCedula();
}

void ListaSimpleCedula::buscarPerfectos(){
    NodoCedula *p = prPrimero;
    int cont = 0;
    while(p != NULL){
        if(comprobarPerfecto(p->getValor())){
        	cont++;
        	cout<<p->getValor()<<" ";
		}
        p = p->getSiguiente();
   }
   cout<<"Existen "<<cont<<" Numeros perfectos"<<endl;
   cout<<endl;
   destruir();
}

bool ListaSimpleCedula::comprobarPerfecto(int n)
{
    int acum=0;
    if(n == 0)
    	return false;
    	
    for(int i=1; i<n;i++)
    {
        if(n%i==0)
        {
            acum=acum+i;
        }
    }
    
    if(acum==n)
    {
        return true;
    }
    else{
        return false;
    }
}
