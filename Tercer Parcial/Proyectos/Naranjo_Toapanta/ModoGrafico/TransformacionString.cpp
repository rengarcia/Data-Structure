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
#include<string>
#include<stdlib.h>
#include <sstream>
#include<iostream>
#include "TransformacionString.h"
using namespace std;

char* Transformacion::trasformarStringChar(string str)
{
    char *c= new char(str.length());
    c=(char*)str.c_str();
    return c;
}
int* Transformacion::arregloEntero(string str)
{
    int *e = new int(str.length());
    for(int i=0; i<str.length();i++)
    {
        *(e+i)=(int)str.at(i)-48;
    }
    return e;
}
int Transformacion::stringAint(string str)
{
    return atoi(str.c_str());
}
template <class Dato>
string arreglosAstring(Dato *arrayDato,int tam)
{
    ostringstream aux;
    for(int i=0;i<tam;i++)
    {
        aux<<*(arrayDato+i);
    }
    return aux.str();
}

