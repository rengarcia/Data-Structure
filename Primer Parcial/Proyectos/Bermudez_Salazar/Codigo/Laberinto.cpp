/***********************************************************************
 * Module:  Laberinto.cpp
 * Author:  Alan
 * Modified: sábado, 02 de noviembre de 2019 11:21:49
 * Purpose: Implementation of the class Laberinto
 ***********************************************************************/

#include "Laberinto.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

////////////////////////////////////////////////////////////////////////
// Name:       Laberinto::Laberinto(int filas, int columnas)
// Purpose:    Implementation of Laberinto::Laberinto()
// Parameters:
// - filas
// - columnas
// Return:     
////////////////////////////////////////////////////////////////////////

Laberinto::Laberinto(int filas, int columnas)
{
	this->filas = filas;
	this->columnas = columnas;
	laberinto = (int**)malloc(filas * sizeof(int*));
	for (int i = 0; i < filas; i++) {
		*(laberinto + i) = (int*)malloc(columnas * sizeof(int));
	}
	srand(time(NULL));
	system("D:\\NetBeansProjects\\IndianaCroft\\dist\\IndianaCroft.jar");
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			*(*(laberinto + i) + j) = -1;
		}
	}

	for (int i = 1; i < filas - 1; i++) {
		for (int j = 1; j < columnas - 1; j++) {
			*(*(laberinto + i) + j) = (rand() % 3)+1;
		}
	}
	*(*(laberinto + filas - 1) + 1) = 0;
}

////////////////////////////////////////////////////////////////////////
// Name:       Laberinto::~Laberinto()
// Purpose:    Implementation of Laberinto::~Laberinto()
// Return:     
////////////////////////////////////////////////////////////////////////

Laberinto::~Laberinto()
{
	// TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       Laberinto::getLaberinto()
// Purpose:    Implementation of Laberinto::getLaberinto()
// Return:     int**
////////////////////////////////////////////////////////////////////////

int** Laberinto::getLaberinto(void)
{
	return laberinto;
}

////////////////////////////////////////////////////////////////////////
// Name:       Laberinto::imprimir()
// Purpose:    Implementation of Laberinto::imprimir()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Laberinto::imprimir() {


	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
			if (*(*(laberinto + i) + j) != -1)
				printf("%d\t", *(*(laberinto + i) + j));
			else
				printf("*\t");
		}
		cout << endl;

	}
}
