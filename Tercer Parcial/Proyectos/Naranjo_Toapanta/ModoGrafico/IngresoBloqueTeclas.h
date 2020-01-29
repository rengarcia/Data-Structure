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
#include <iostream>
#include<stdlib.h>
#include<conio.h>
#include<stdio.h>
#include<string>

using namespace std;

class Ingreso {
public:
	double ingresarDouble(char*,char*);
	int ingresarInt(char*);
	char ingresCaracter(char*);
	string ingresarLetras(char*);
	string ingresarNumeros(char*);
};

