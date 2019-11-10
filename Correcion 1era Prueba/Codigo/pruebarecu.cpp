
/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 2967                                                       *
******************************************************************/
#include <stdio.h>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "MatrizP.h"
#include "ingreso.h"
int main(){
	
	Matriz nuevo;
	int fil,col,exp;
	Entry leer;
	fil=leer.enterokay("ingrese numero de filas :");
	col=leer.enterokay("ingrese numero de columnas :");
	exp=leer.enterokay("ingrese el exponente");
	nuevo=Matriz(fil,col);
	
	nuevo.crearMatriz();
	nuevo.llenarMatriz();
	nuevo.imprimirMatriz();
	nuevo.multiplicarMatriz(exp);
	nuevo.imprimirMatriz();
	
	return 0;
}
