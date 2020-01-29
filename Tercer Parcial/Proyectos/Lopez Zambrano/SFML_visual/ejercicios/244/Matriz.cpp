#include <iostream>
#include "Matriz.h"
using namespace std;

void Matriz::imprime(int** matriz, int dim)
{
	cout << endl;
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++)
		{
			cout << *(*(matriz + i) + j) << " ";
		}
		cout << endl;
	}

}

void Matriz::ingreso(int** matriz, int dim)
{
	int numero;

	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			cout << endl;
			cout << "Ingrese el dato para la posicion " << "(" << i + 1 << "," << j + 1 << ") : ";
			cin >> numero;
			*(*(matriz + i) + j) = numero;
		}
	}
}

int** Matriz::generar(int dim)
{
	int** matriz;
	matriz = (int**)malloc(dim * sizeof(int*));
	for (int j = 0; j < dim; j++) {
		*(matriz + j) = (int*)malloc(dim * sizeof(int));
	}

	return matriz;
}

void Matriz::encerar(int** matriz, int dim)
{
	int i, j;
	for (i = 0; i < dim; i++)
		for (j = 0; j < dim; j++)
			* (*(matriz + i) + j) = 0;
	return;
}
