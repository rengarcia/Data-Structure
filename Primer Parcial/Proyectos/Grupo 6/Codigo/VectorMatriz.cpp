/***********************************************************************
 * Module:  VectorMatriz.cpp
 * Author:  Kevin Duy, Carlos Puco
 * Modified: sabado, 26 de octubre de 2019 17:21:23
 * Purpose: Implementation of the class VectorMatriz
 ***********************************************************************/

#include "VectorMatriz.h"
#include <stdlib.h>

/**
 * @brief reserva un espacio de memoria en la computadora
 * @param int (tipo de numero)
 * @return reserva el espacio depende del tamaño del vector 
 */

int* VectorMatriz::inicializarVector(int tamanio) {
	vector = (int*)malloc(tamanio *sizeof(int));
	return vector;
}

/**
 * @brief llena de datos nulos "0" en el espcio de memoria pedida
 * @param int (tipo de numero)
 * @return el arreglo con valores de cero 
 */

int* VectorMatriz::encerarVector(int tamanio, int *vector) {
	for(int i=0; i<tamanio; i++) {
			*(vector+i) = 0;
		}
	return vector;
}

/**
 * @brief reserva un espacio de memoria en la computadora pero es bidimencional
 * @param int (tipo de numero)
 * @return reserva el espacio depende del tamaño del vector 
 */

int** VectorMatriz::inicializar(int tamanio) {
	matriz = (int**)malloc(sizeof(int *)*tamanio);
	for(int i=0; i<tamanio; i++) {
		*(matriz+i) = (int*)malloc(sizeof(int*)*tamanio);
	}
	return matriz;
}

/**
 * @brief llena de datos nulos "0" en el espcio de memoria pedida en la mtriz bidimencional
 * @param int (tipo de numero)
 * @return el arreglo con valores de cero 
 */

int** VectorMatriz::encerar(int tamanio, int **matriz) {
	for(int i=0; i<tamanio; i++) {
			for(int j=0; j<tamanio; j++) {
				*(*(matriz+i)+j) = 0;
			}
		}
	return matriz;
}
