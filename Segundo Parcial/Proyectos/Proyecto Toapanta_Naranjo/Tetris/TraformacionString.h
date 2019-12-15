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
#ifndef TRAFORMACIONSTRING_H_INCLUDED
#define TRAFORMACIONSTRING_H_INCLUDED
#include<string>
#include<stdlib.h>
#include <sstream>
#include<iostream>
using namespace std;
char*trasformarStringChar(string str)
{
    char *c= new char(str.length());
    c=(char*)str.c_str();
    return c;
}
int*arregloEntero(string str)
{
    int *e = new int(str.length());
    for(int i=0; i<str.length();i++)
    {
        *(e+i)=(int)str.at(i)-48;
    }
    return e;
}
int stringAint(string str)
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

#endif // TRAFORMACIONSTRING_H_INCLUDED
