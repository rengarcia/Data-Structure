/***********************************************************************
 * Module:  ImpProceso.cpp
 * Author:  Alan
 * Modified: sábado, 02 de noviembre de 2019 11:23:17
 * Purpose: Implementation of the class ImpProceso
 ***********************************************************************/

#include "ImpProceso.h"

////////////////////////////////////////////////////////////////////////
// Name:       ImpProceso::generarSolucion(Laberinto laberinto)
// Purpose:    Implementation of ImpProceso::generarSolucion()
// Parameters:
// - laberinto
// Return:     int
////////////////////////////////////////////////////////////////////////

void ImpProceso::generarSolucion(int** laberinto, int fila_actual, int columna_actual, int n, int direccion) {
	fstream enter;
	enter.open("INDIANA_CROFT.txt", fstream::out);
	enter << "SOLUCION INDIANA CROFT " << n - 2 << "*" << n - 2 << endl << endl;
	int counter = 0;
	
	if (direccion < 3) {

		switch (direccion) {
		case 0: //arriba
			if (*(*(laberinto + fila_actual - 1) + columna_actual) > 0) {
				(*(*(laberinto + fila_actual- 1) + columna_actual))--;

				
				counter++;
				enter << "PASO " << counter << endl;
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < n; j++) {
						enter <<*(*(laberinto + i) + j)<< " ";
					}
					enter << endl;
				}
				if (validar(laberinto, n)) {
					cout << "El laberinto fue resuelto correctamente" << endl;
				}
				else {
					generarSolucion(laberinto, fila_actual-1, columna_actual, n, 0);
				}

			}
			else {
				generarSolucion(laberinto, fila_actual, columna_actual, n, direccion+1);
			}
			break;

		case 1://abajo	
			if (*(*(laberinto + fila_actual + 1) + columna_actual) > 0) {
				(*(*(laberinto + fila_actual+1) + columna_actual))--;
				counter++;
				enter << "PASO " << counter << endl;
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < n; j++) {
						enter << *(*(laberinto + i) + j) << "\t";
					}
					enter << endl;
				}
				if (validar(laberinto, n)) {
					//return void;
				}

				generarSolucion(laberinto, fila_actual, columna_actual, n, 0);
			}
			else {
				generarSolucion(laberinto, fila_actual-1, columna_actual, n, direccion+1);
			}
			break;

		case 2:	//izquierda
			if (*(*(laberinto + fila_actual) + columna_actual - 1) > 0) {
				(*(*(laberinto + fila_actual) + columna_actual-1))--;
				counter++;
				enter << "PASO " << counter << endl;
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < n; j++) {
						enter << *(*(laberinto + i) + j) << "\t";
					}
					enter << endl;
				}
				if (validar(laberinto, n)) {
					//return void;
				}
				generarSolucion(laberinto, fila_actual, columna_actual, n, 0);
			}
			else {
				generarSolucion(laberinto, fila_actual-1, columna_actual, n, direccion+1);
			}
			break;

		case 3://derecha
			if (*(*(laberinto + fila_actual) + columna_actual + 1) > 0) {
				(*(*(laberinto + fila_actual) + columna_actual+1))--;
				counter++;
				enter << "PASO " << counter << endl;
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < n; j++) {
						enter << *(*(laberinto + i) + j) << "\t";
					}
					enter << endl;
				}
				if (validar(laberinto, n)) {
					//return void;
				}
				generarSolucion(laberinto, fila_actual, columna_actual, n, 0);
			}
			else {
				generarSolucion(laberinto, fila_actual--, columna_actual, n, direccion+1);
			}
			break;
		}
	}
	else {
		printf("\nNO hay la solucion");
		enter.close();
	}
}

bool ImpProceso::validar(int** laberinto, int n) {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if ((*(*(laberinto + i) + j)) > 0) {
				return false;
			}
		}
	}

	return true;
}
