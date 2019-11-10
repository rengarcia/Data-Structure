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
#include "Matriz.cpp"
#include "ingreso.h"
using namespace std;
int main(){
	main:
	int row,col,exp;
	Matriz p;
	Ingreso lee;
	row= lee.ingresarInt("Ingrese # filas: ");
	p.setfilas(row);
	col= lee.ingresarInt("Ingrese # columnas: ");
	p.setfilas(col);
	cout<<endl;
	
	
	if(row>10&&row>10||row!=col){
		cout<<"la matriz tiene q ser cuadrada y su dimenion menor o igual q 10\n"<<endl;
	}else{
		p.setcolumnas(col);
		p.setfilas(row);
		p.crear();
		p.llenar();
		p.imprimir();
		exp= lee.ingresarInt("Ingrese el exponente: ");
		p.setexp(exp);
		cout<<endl;
		p.multiplicar(p.getexp());
		cout<<"matriz elevada "<<endl;
		p.imprimir();
		
		
	}
	system("pause");
	system("cls");
	goto main;
	return 0;
}
