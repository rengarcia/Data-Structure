/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 2967                                                       *
******************************************************************/
#include <sstream>
#include "ListaSimple.h"
#include "Nodo.h"
#pragma once

////////////////////////////////////////////////////////////////////////
// Name:       ListaSimple::ingresoInicio(Persona obj)
// Purpose:    Implementation of ListaSimple::ingresoInicio()
// Parameters:
// - obj
// Return:     void
////////////////////////////////////////////////////////////////////////

void ListaSimple::ingresoInicio(Persona obj)
{
    prPrimero = new Nodo(obj,prPrimero);
}

////////////////////////////////////////////////////////////////////////
// Name:       ListaSimple::ingresoFinal(Persona obj)
// Purpose:    Implementation of ListaSimple::ingresoFinal()
// Parameters:
// - obj
// Return:     void
////////////////////////////////////////////////////////////////////////

void ListaSimple::ingresoFinal(Persona obj)
{
    Nodo *p = prPrimero;
    Nodo *nuevo;

    if(p == NULL){
        ingresoInicio(obj);
    }else{
        while(p->getSiguiente() != NULL){
            p = p->getSiguiente();
        }
        nuevo = new Nodo(obj, NULL);
        p->setSiguiente(nuevo);
    }
}

////////////////////////////////////////////////////////////////////////
// Name:       ListaSimple::imprimirDatos()
// Purpose:    Implementation of ListaSimple::imprimirDatos()
// Return:     void
////////////////////////////////////////////////////////////////////////

void ListaSimple::imprimirDatos(void)
{
   Nodo *p = prPrimero;
   while(p != NULL){
        cout<<"Nombre: "<<p->getDatos().getNombre()<<endl;
        cout<<"Apellido: "<<p->getDatos().getApellido()<<endl;
        cout<<"Cedula: "<<p->getDatos().getCedula()<<endl;
        cout<<"Id: "<<p->getDatos().getIdPersona()<<endl<<endl;
        p = p->getSiguiente();
   }
}



void ListaSimple::eliminarInicio(){
    Nodo *p = prPrimero;
    if(p == NULL){
        cout<<"Nada que eliminar"<<endl;
        return;
    }else{
    prPrimero = p->getSiguiente();
    }
    delete p;
}

void ListaSimple::eliminarFinal(){
    Nodo *p = prPrimero;
    Nodo *aux;
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



void ListaSimple::buscarnom(string nombreBuscar)
{
    Nodo *p = prPrimero;
    int posicion=1, cont=0;
    while(p!=NULL)
    {
        if(p->getDatos().getNombre() == nombreBuscar)
        {
            cout<<"Nombre: "<<p->getDatos().getNombre()<<endl;
            cout<<"Apellido: "<<p->getDatos().getApellido()<<endl;
            cout<<"Cedula: "<<p->getDatos().getCedula()<<endl;
            cout<<"Id: "<<p->getDatos().getIdPersona()<<endl;
            cout<<"Encontrado en la posicion: "<<posicion<<endl;
            cont++;
        }
        posicion++;
        p = p->getSiguiente();
    }
    if(cont==0)
        cout<<"Nombre no encontrado"<<endl;
}

void ListaSimple::setPrPrimero(Nodo *){

}

Nodo* ListaSimple::getPrPrimero(){

}

ListaSimple::ListaSimple(){
    prPrimero = NULL;
}

ListaSimple::~ListaSimple(){
    Nodo *p = prPrimero;
    Nodo *actual;
    while(p != NULL){
        actual = p->getSiguiente();
        delete p;
        p = actual;
    }
    prPrimero = NULL;
}
