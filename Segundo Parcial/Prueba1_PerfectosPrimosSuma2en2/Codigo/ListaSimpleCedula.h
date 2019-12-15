/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 2967                                                       *
******************************************************************/


#include <iostream>
#include "NodoCedula.h"
#pragma once

using namespace std;

class ListaSimpleCedula
{
public:
    int sumarNodo(char* cadena,int valor);
    void guardarDosDigitos(string cedula);
    char* transformar(int valor);
    void sumar();
    void guardarUnDigito(string cedula);
    bool comprobarPrimo(int n);
    void buscarPrimos();
    bool comprobarPerfecto(int n);
    void buscarPerfectos();
   void ingresoInicio(int obj);
   void ingresoFinal(int obj);
   void imprimirCedula(void);
   void eliminarInicio();
   void eliminarFinal();
   void setPrPrimero(NodoCedula *);
   NodoCedula* getPrPrimero();
   ListaSimpleCedula();
   void destruir();

protected:
private:
    NodoCedula *prPrimero;
};
