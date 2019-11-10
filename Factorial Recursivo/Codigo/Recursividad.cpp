/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS                   *
*                        ESPE                                     *
*TRABAJO EN GRUPO:                                                *
*          NOMBRES:ANTONI TOAPANTA                                *
*MATERIA: ESTRUCTURA DE DATOS                                     *
*NRC:2967                                                         *
*Fecha de Creacion:30/09/2019                                     *
******************************************************************/
#include<iostream>
#include "Ingreso.h"
#include<stdlib.h>
#include "Dato.h"

using namespace std;

int main()
{
    Ingreso leer;
    char valor;
    Dato dato=Dato();
    dato.setValor(leer.ingresarInt(&valor));
    dato.setValor(dato.factorial(dato.getValor()));
    cout<<"El factorial del numero ingresado es: "<<dato.getValor()<<endl;
    system("pause");
    return 0;
}
