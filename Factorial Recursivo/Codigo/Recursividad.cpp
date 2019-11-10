/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* CARRERA: Ingenieria de Software                                *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 2967                                                       *
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
