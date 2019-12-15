/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 2967                                                       *
******************************************************************/

#if !defined(__Class_Diagram_1_ListaSimple_h)
#define __Class_Diagram_1_ListaSimple_h
#include <sstream>
#pragma once
#include "Persona.h"
#include "Nodo.h"

class ListaSimple
{
public:

   void ingresoInicio(Persona obj);
   void ingresoFinal(Persona obj);
   void eliminarInicio();
   void eliminarFinal();
   void imprimirDatos(void);
   void setPrPrimero(Nodo *);
   void buscarnom(string );
   Nodo* getPrPrimero();
   ListaSimple();
   ~ListaSimple();

protected:
private:
    Nodo *prPrimero;
};

#endif
