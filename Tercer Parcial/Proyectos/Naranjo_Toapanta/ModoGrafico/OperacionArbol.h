/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS                   *
*                        ESPE                                     *
*TRABAJO EN GRUPO:                                                *
*          NOMBRES:ANTONI TOAPANTA                                *
*                   JHONY NARANJO                                 *
*MATERIA: ESTRUCTURA DE DATOS                                     *
*NRC:2967                                                         *
*Fecha de Creacion:26/01/2020                                     *
******************************************************************/
#pragma once
#if !defined(__Arbol_OperacionArbol_h)
#define __Arbol_OperacionArbol_h

#include "Arbol.h"
class OperacionArbol
{
public:
   //Arbol *crearNodo(Palabra palabra)
   void insertar(Arbol *&arbol, Palabra palabra);
   void insertarE(Arbol *&arbol, Palabra palabra);
   void mostrar(Arbol *arbol,int cont);
   void eliminar(Arbol *&arbol,Palabra palabra);
   void busqueda(Arbol *arbol, int n,string plbra,string &result);
   void busquedaEspanol(Arbol *arbol, int n,string plbra,string &result);
   void inorden(Arbol *arbol);
   //void space(int tam);
protected:
private:

};

#endif
