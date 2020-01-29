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
#if !defined(__Arbol_Arbol_h)
#define __Arbol_Arbol_h
#include "Palabra.h"
class Arbol
{
public:
   Palabra getPalabra(void);
   void setPalabra(Palabra newPalabra);
   Arbol* getDer(void);
   void setDer(Arbol* newDer);
   Arbol* getIzq(void);
   void setIzq(Arbol* newIzq);
   Arbol();
   ~Arbol();
    Arbol* der;
   Arbol* izq;
protected:
private:
   Palabra palabra;



};

#endif
