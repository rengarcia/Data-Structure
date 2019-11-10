/***********************************************************************
 *  UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
 * Modulo:  main.cpp
 * Modificacion: Saturday, November 9, 2019
 * Implementacion: Ejecucion de contador de vocales
 ***********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "Ingreso.h"
#include "ContadorVocales.h"


int main() {
    //declaracion de las clases Ingreso y lectura
	Ingreso lectura;
	ContadorVocales calcular;

    int contador;
    char * cadena=lectura.leer("\n Ingrese oracion: ");

    strupr(cadena); //comversion de de cadena de minuscula a mayuscula

    contador=calcular.contarVocales(cadena);//llamando al metodo de la calse ContadorVocales

    printf("\n\n  Hay %i Vocales \n\n", contador);

    free(cadena); //liberando la memoria


    system("pause");
    return 0;
}

