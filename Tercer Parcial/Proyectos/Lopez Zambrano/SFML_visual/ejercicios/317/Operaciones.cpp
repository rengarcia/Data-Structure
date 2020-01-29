#include "Operaciones.h"
#include <iostream> 

using namespace std;
int** Operaciones::generarMatriz(int dim)
{
	int** matriz = new int* [dim];
	for (int i = 0; i < dim; ++i)
		matriz[i] = new int[dim];

	return matriz;
}
void Operaciones::imprimir(int** matriz)
{
	for (int i = 0; i < 3; i++) {
		cout << endl;
		for (int j = 0; j < 3; j++) {
			cout << *(*(matriz + i) + j) << " ";
		}
	}
}

void Operaciones::encerar(int** matriz)
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			 *(*(matriz + i) + j) = 0;
		}
	}

}
