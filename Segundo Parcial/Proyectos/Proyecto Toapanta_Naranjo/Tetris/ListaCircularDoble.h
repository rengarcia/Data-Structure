/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS                   *
*                        ESPE                                     *
*TRABAJO EN GRUPO:                                                *
*          NOMBRES:ANTONI TOAPANTA                                *
*                   JONNY NARANJO                                 *
*MATERIA: ESTRUCTURA DE DATOS                                     *
*NRC:2967                                                         *
*Fecha de Creacion:09/12/2019                                     *
******************************************************************/

#if !defined(__Class_Diagram_1_ListaSimple_h)
#define __Class_Diagram_1_ListaSimple_h

#include <iostream>
#include "Nodo.h"

using namespace std;

class ListaCircularDoble
{
public:
    bool vacia();
    int cantidad();
    void borrarIguales(int&puntos);
    void borrarPosicion(int posicion);
    void recursivo(Nodo *p, int posicion, bool bandera,int&puntos);
    void insertarPosicion(int obj, int pos);
    int buscarPosicion(int posicion);
   void ingresoInicio(int obj);
   void ingresoFinal(int obj);
   void imprimirDatos();
   int tamLista();
   ListaCircularDoble();
   void destruir();
   void setPrimero(Nodo *newPrimero);
   Nodo* getPrimero();
protected:
private:
    Nodo *primero;
};

#endif
