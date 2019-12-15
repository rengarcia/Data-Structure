/***********************************************************************
 * Module:  ListaDobleCircular.cpp
 * Author:  ALEX
 * Modified: Saturday, December 14, 2019 8:55:50 PM
 * Purpose: Implementation of the class ListaDobleCircular
 ***********************************************************************/

#include "ListaDobleCircular.h"
#include<stdlib.h>
#include <fstream>

////////////////////////////////////////////////////////////////////////
// Name:       ListaDobleCircular::vacia()
// Purpose:    Implementation of ListaDobleCircular::vacia()
// Return:     bool
////////////////////////////////////////////////////////////////////////

bool ListaDobleCircular::vacia(void)
{
   if(primero==NULL && ultimo==NULL){
        return true;
   }else{
       return false;
   }
}

////////////////////////////////////////////////////////////////////////
// Name:       ListaDobleCircular::insertarInicio(Libro newLibro)
// Purpose:    Implementation of ListaDobleCircular::insertarInicio()
// Parameters:
// - newLibro
// Return:     void
////////////////////////////////////////////////////////////////////////

void ListaDobleCircular::insertarInicio(Libro newLibro)
{
    Nodo* nuevo=new Nodo();
    nuevo->setLibro(newLibro);
    if(vacia()){
        primero=nuevo;
        ultimo=nuevo;
        primero->setSiguiente(primero);
        primero->setAnterior(ultimo);
   }else{
        primero->setAnterior(nuevo);
        nuevo->setAnterior(ultimo);
        nuevo->setSiguiente(primero);
        primero=nuevo;
        ultimo->setSiguiente(primero);
   }
   crearTxt(nuevo);
}

////////////////////////////////////////////////////////////////////////
// Name:       ListaDobleCircular::insertarFinal(Libro newLibro)
// Purpose:    Implementation of ListaDobleCircular::insertarFinal()
// Parameters:
// - newLibro
// Return:     void
////////////////////////////////////////////////////////////////////////

void ListaDobleCircular::insertarFinal(Libro newLibro)
{
    Nodo* nuevo=new Nodo();
    nuevo->setLibro(newLibro);
    if(vacia()){
        primero=nuevo;
        ultimo=nuevo;
        primero->setSiguiente(primero);
        primero->setAnterior(ultimo);
   }else{
       ultimo->setSiguiente(nuevo);
       nuevo->setAnterior(ultimo);
       nuevo->setSiguiente(primero);
       ultimo=nuevo;
       primero->setAnterior(ultimo);
   }
   crearTxt(nuevo);
}

////////////////////////////////////////////////////////////////////////
// Name:       ListaDobleCircular::insertarPosicion(int newPosicion, Libro newLibro)
// Purpose:    Implementation of ListaDobleCircular::insertarPosicion()
// Parameters:
// - newPosicion
// - newLibro
// Return:     void
////////////////////////////////////////////////////////////////////////

void ListaDobleCircular::insertarPosicion(int newPosicion, Libro newLibro)
{
    Nodo* aux =primero;
    int cont=0;

    if(tamanioLista()>=newPosicion){
        while(cont!=newPosicion){
            aux=aux->getSiguiente();
            cont++;
        }
        Nodo* aux2=aux->getAnterior();
        Nodo* nuevo=new Nodo();
        nuevo->setLibro(newLibro);

        aux2->setSiguiente(nuevo);
        nuevo->setAnterior(aux2);
        nuevo->setSiguiente(aux);
        aux->setAnterior(nuevo);
        crearTxt(nuevo);
    }else{
        std::cout<<"LA POSICION ES MAYOR AL TAMAÑO DE LA LISTA\n";
    }

}

////////////////////////////////////////////////////////////////////////
// Name:       ListaDobleCircular::buscarPosicionLibroId(int idLibro)
// Purpose:    Implementation of ListaDobleCircular::buscarPosicionLibroId()
// Parameters:
// - idLibro
// Return:     int
////////////////////////////////////////////////////////////////////////

int ListaDobleCircular::buscarPosicionLibroId(int idLibro)
{
   int contador=0;
   if(!vacia()){
       Nodo* aux=primero;

        do{
            if(idLibro==aux->getLibro().getIdLibro()){
                return contador;
            }
            aux=aux->getSiguiente();
            contador++;
        }while(aux!=primero);
   }
    return -1;
}

////////////////////////////////////////////////////////////////////////
// Name:       ListaDobleCircular::modificarPorId(int idLibro)
// Purpose:    Implementation of ListaDobleCircular::modificarPorId()
// Parameters:
// - idLibro
// Return:     void
////////////////////////////////////////////////////////////////////////

void ListaDobleCircular::modificarPorId(int idLibro,Libro libro)
{
    Nodo* aux =primero;
    Nodo* modificar = new Nodo();
    modificar->setLibro(libro);
    int posicion=buscarPosicionLibroId(idLibro);
    int cont=0;
    bool bandera=true;
    if(posicion!=-1 && !vacia()){

        while(cont!=posicion){
            aux=aux->getSiguiente();
            cont++;
        }
    }else{
        bandera=false;
    }

    if(bandera){
            if(cont==0){/** CUANDO EN LA LISTA SOLO EXISTA UN NODO EN LA LISTA */
                primero=NULL;
                ultimo=NULL;
                insertarInicio(libro);
            }else{

                Nodo* aux2=aux->getAnterior();
                Nodo* aux3=aux->getSiguiente();
                aux2->setSiguiente(modificar);
                modificar->setAnterior(aux2);
                modificar->setSiguiente(aux3);
                aux3->setAnterior(modificar);
            }
        std::cout<<"LIBRO MODIFICADO\n";
        imprimirNodo(modificar);
        free(aux);

    }else{
        std::cout<<"NO EXISTE ID PARA MODIFICAR\n";
    }
}

////////////////////////////////////////////////////////////////////////
// Name:       ListaDobleCircular::eliminar(int id)
// Purpose:    Implementation of ListaDobleCircular::eliminar()
// Parameters:
// - id
// Return:     void
////////////////////////////////////////////////////////////////////////

void ListaDobleCircular::eliminar(int idLibro)
{
    Nodo* aux =primero;
    int posicion=buscarPosicionLibroId(idLibro);
    int cont=0;
    bool bandera=true;
    if(posicion!=-1 && !vacia()){

        while(cont!=posicion){
            aux=aux->getSiguiente();
            cont++;
        }
    }else{
        bandera=false;
    }

    if(bandera){
            if(cont==0){/** CUANDO EN LA LISTA SOLO EXISTA UN NODO EN LA LISTA */
                primero=NULL;
                ultimo=NULL;
            }
            if(cont==1){/** CUANDO EN LA LISTA SOLO EXISTAN DOS NODOS EN LA LISTA*/
                primero=aux->getAnterior();
                ultimo=aux->getAnterior();
                primero->setSiguiente(primero);
                primero->setAnterior(ultimo);

            }else{/** CUANDO EN LA LISTA EXISTAN MAS DE DOS NODO EN LA LISTA*/

                Nodo* aux2=aux->getAnterior();
                Nodo* aux3=aux->getSiguiente();
                aux2->setSiguiente(aux3);
                aux3->setAnterior(aux2);
            }
        std::cout<<"LIBRO ELIMINADO\n";
        imprimirNodo(aux);
        free(aux);

    }else{
        std::cout<<"NO EXISTE ID PARA ELIMINAR\n";
    }

}

////////////////////////////////////////////////////////////////////////
// Name:       ListaDobleCircular::imprimir()
// Purpose:    Implementation of ListaDobleCircular::imprimir()
// Return:     void
////////////////////////////////////////////////////////////////////////

void ListaDobleCircular::imprimir(void)
{
    Nodo* aux=primero;
    if(!vacia()){

        do{
            std::cout<<"////////////////////////////////////////////////////////////////////////"<<std::endl;
            std::cout<<"  IDENTI LIBRO: "<<aux->getLibro().getIdLibro()<<std::endl;
            std::cout<<"  NOMBRE LIBRO: "<<aux->getLibro().getNombreLibro()<<std::endl;
            std::cout<<"  IDENTI AUTOR: "<<aux->getLibro().getAutor().getPersona().getId()<<std::endl;
            std::cout<<"  NOMBRE AUTOR: "<<aux->getLibro().getAutor().getPersona().getNombre();
            std::cout<<" "<<aux->getLibro().getAutor().getPersona().getApellido()<<std::endl;
            std::cout<<"  CORREO AUTOR: "<<aux->getLibro().getAutor().getPersona().getCorreo()<<std::endl;
            std::cout<<"  IDENTI. PAIS : "<<aux->getLibro().getPais().getIdPais()<<std::endl;
            std::cout<<"  NOMBRE  PAIS : "<<aux->getLibro().getPais().getNombrePais()<<std::endl;
            std::cout<<"  NACIONALIDAD : "<<aux->getLibro().getPais().getNacionalidad()<<std::endl;
            std::cout<<"  NUM. PUBLICA.: "<<aux->getLibro().getAutor().getNumPublicacion()<<std::endl;
            std::cout<<"  IDENTI EDITORIAL: "<<aux->getLibro().getEditorial().getIdEditorial()<<std::endl;
            std::cout<<"  NOMBRE EDITORIAL: "<<aux->getLibro().getEditorial().getNombreEditorial()<<std::endl;
            std::cout<<"  CONTAC EDITORIAL: "<<aux->getLibro().getEditorial().getContactoEditorial()<<std::endl;
            std::cout<<"////////////////////////////////////////////////////////////////////////"<<std::endl<<std::endl;

            aux=aux->getSiguiente();
        }while(aux!=primero);
    }else{
        std::cout<<"LISTA DOBLE VACIA\n";
    }
}

////////////////////////////////////////////////////////////////////////
// Name:       ListaDobleCircular::imprimirNodo(Nodo* nodo)
// Purpose:    Implementation of ListaDobleCircular::imprimirNodo()
// Parameters:
// - nodo
// Return:     void
////////////////////////////////////////////////////////////////////////

void ListaDobleCircular::imprimirNodo(Nodo* nodo)
{

    std::cout<<"////////////////////////////////////////////////////////////////////////"<<std::endl;
    std::cout<<"  IDENTI LIBRO: "<<nodo->getLibro().getIdLibro()<<std::endl;
    std::cout<<"  NOMBRE LIBRO: "<<nodo->getLibro().getNombreLibro()<<std::endl;
    std::cout<<"  IDENTI AUTOR: "<<nodo->getLibro().getAutor().getPersona().getId()<<std::endl;
    std::cout<<"  NOMBRE AUTOR: "<<nodo->getLibro().getAutor().getPersona().getNombre();
    std::cout<<" "<<nodo->getLibro().getAutor().getPersona().getApellido()<<std::endl;
    std::cout<<"  CORREO AUTOR: "<<nodo->getLibro().getAutor().getPersona().getCorreo()<<std::endl;
    std::cout<<"  IDENTI. PAIS : "<<nodo->getLibro().getPais().getIdPais()<<std::endl;
    std::cout<<"  NOMBRE  PAIS : "<<nodo->getLibro().getPais().getNombrePais()<<std::endl;
    std::cout<<"  NACIONALIDAD : "<<nodo->getLibro().getPais().getNacionalidad()<<std::endl;
    std::cout<<"  NUM. PUBLICA.: "<<nodo->getLibro().getAutor().getNumPublicacion()<<std::endl;
    std::cout<<"  IDENTI EDITORIAL: "<<nodo->getLibro().getEditorial().getIdEditorial()<<std::endl;
    std::cout<<"  NOMBRE EDITORIAL: "<<nodo->getLibro().getEditorial().getNombreEditorial()<<std::endl;
    std::cout<<"  CONTAC EDITORIAL: "<<nodo->getLibro().getEditorial().getContactoEditorial()<<std::endl;
    std::cout<<"////////////////////////////////////////////////////////////////////////"<<std::endl<<std::endl;
}

////////////////////////////////////////////////////////////////////////
// Name:       ListaDobleCircular::tamanioLista()
// Purpose:    Implementation of ListaDobleCircular::tamanioLista()
// Return:     int
////////////////////////////////////////////////////////////////////////

int ListaDobleCircular::tamanioLista(void)
{
    int cont=0;
    if(!vacia()){
        Nodo* aux=primero;
        do{
            aux=aux->getSiguiente();
            cont++;
        }while(aux!=primero);
    }
    return cont;
}

////////////////////////////////////////////////////////////////////////
// Name:       Persona::crearTxt(Nodo* nodo)
// Purpose:    Implementation of Persona::crearTxt()
// Parameters:
// - nodo
// Return:     void
////////////////////////////////////////////////////////////////////////

void ListaDobleCircular::crearTxt(Nodo* nodo)
{
    std::fstream enter;
	enter.open("BIBIOTECA.txt", std::fstream::app);
    enter<<"////////////////////////////////////////////////////////////////////////"<<std::endl;
    enter<<"  IDENTI LIBRO: "<<nodo->getLibro().getIdLibro()<<std::endl;
    enter<<"  NOMBRE LIBRO: "<<nodo->getLibro().getNombreLibro()<<std::endl;
    enter<<"  IDENTI AUTOR: "<<nodo->getLibro().getAutor().getPersona().getId()<<std::endl;
    enter<<"  NOMBRE AUTOR: "<<nodo->getLibro().getAutor().getPersona().getNombre();
    enter<<" "<<nodo->getLibro().getAutor().getPersona().getApellido()<<std::endl;
    enter<<"  CORREO AUTOR: "<<nodo->getLibro().getAutor().getPersona().getCorreo()<<std::endl;
    enter<<"  IDENTI. PAIS : "<<nodo->getLibro().getPais().getIdPais()<<std::endl;
    enter<<"  NOMBRE  PAIS : "<<nodo->getLibro().getPais().getNombrePais()<<std::endl;
    enter<<"  NACIONALIDAD : "<<nodo->getLibro().getPais().getNacionalidad()<<std::endl;
    enter<<"  NUM. PUBLICA.: "<<nodo->getLibro().getAutor().getNumPublicacion()<<std::endl;
    enter<<"  IDENTI EDITORIAL: "<<nodo->getLibro().getEditorial().getIdEditorial()<<std::endl;
    enter<<"  NOMBRE EDITORIAL: "<<nodo->getLibro().getEditorial().getNombreEditorial()<<std::endl;
    enter<<"  CONTAC EDITORIAL: "<<nodo->getLibro().getEditorial().getContactoEditorial()<<std::endl;
    enter<<"////////////////////////////////////////////////////////////////////////"<<std::endl;
}

