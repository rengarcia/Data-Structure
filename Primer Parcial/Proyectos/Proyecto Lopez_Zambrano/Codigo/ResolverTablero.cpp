#include <iostream>
#include <ctime>
#include <fstream>
#include "ResolverTablero.h"

using namespace std;
int dim = 10;
int n = 1;
fstream enter;

bool ResolverTablero::isSafe(int** Tablero, int x, int y)
{
	if (x >= 0 && x < dim && y >= 0 && y < dim && *(*(Tablero + x) + y) == 1)
		return true;

	return false;
}

int** ResolverTablero::solucion(int** Tablero)
{
	int** sol = GenerarMatriz(dim);
	Encerar(sol, dim);
	enter.open("Soluciones/solucion.txt", fstream::out);
	enter << "Solucion al laberinto" << endl << endl;

	if (backtracking(Tablero, 0, 0, sol) == false) {
		printf("Solution doesn't exist");
		return false;
	}
	return sol;
}

bool  ResolverTablero::backtracking(int** Tablero, int x, int y, int** sol)
{
	if (x == dim - 1 && y == dim - 1) {

		*(*(sol + x) + y) = 2;
		ImprimirText(sol, dim);
		enter.close();
		return true;
	}

	if (isSafe(Tablero, x, y) == true) {
		*(*(sol + x) + y) = 2;

		if (backtracking(Tablero, x + 1, y, sol) == true)
			return true;

		if (backtracking(Tablero, x, y + 1, sol) == true)
			return true;

		*(*(sol + x) + y) = 0;

		return false;
	}
	ImprimirText(sol, dim);
	return false;
}


///Encuentra la posicion del espacion en blanco en la matriz
void ResolverTablero::LocalizarEspacio(int& Fila, int& Columna, int** Tablero, int dim) {
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++)
		{
			if (*(*(Tablero + i) + j) == ' ') {
				Fila = i;
				Columna = j;
				break;
			}
		}
	}
}

///Genera la matriz de 4x4
int** ResolverTablero::GenerarMatriz(int dim)
{
	int** Tablero, j;
	Tablero = (int**)malloc(dim * sizeof(int*));
	for (j = 0; j < dim; j++)
		* (Tablero + j) = (int*)malloc(dim * sizeof(int));
	return Tablero;
}


///Todos los valores de la matriz son 0
void ResolverTablero::Encerar(int** Tablero, int dim)
{

	for (int i = 0; i < dim; i++)
		for (int j = 0; j < dim; j++) {
			if (i == 0 && j == 0) {
				*(*(Tablero + i) + j) = ' ';
			}
			else {
				*(*(Tablero + i) + j) = 0;
			}
		}
	return;
}

void ResolverTablero::ImprimirTablero(int** Tablero, int dim)
{
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++)
		{
			printf("%d", *(*(Tablero + i) + j));
			printf("  ");
			printf("  ");
		}
		printf("\n");
	}
}

void ResolverTablero::RellenarEspacios(int** Tablero, int dim)
{
	int i, j;
	srand(time(NULL));
	for (i = 0; i < dim; i++)
		for (j = 0; j < dim; j++) {
			if (*(*(Tablero + i) + j) == 0) {
				*(*(Tablero + i) + j) = rand() % 2;
			}
		}
	return;
}

void ResolverTablero::ImprimirText(int** sol, int dim) {

	enter << "Intento Numero: " << n << endl;

	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++)
		{
			enter << *(*(sol + i) + j) << " " << " ";

		}
		enter << endl;
	}
	n++;
}

