#include <iostream>
#include "Validacion.h"
#include "Matriz.h"
using namespace std;


void Matriz::imprime(int** matriz, int dimFil, int dimCol)
{
	cout << endl;
	for (int i = 0; i < dimFil; i++) {
		for (int j = 0; j < dimCol; j++)
		{
			cout << *(*(matriz + i) + j);
			printf("%*s", j + 5, " ");
		}
		cout << endl;
	}

}

void Matriz::ingreso(int** matriz, int dimFil, int dimCol)
{
	Validacion validacion;
	string aux;
	int numero;
	
	for (int i = 0; i < dimFil; i++) {
		for (int j = 0; j < dimCol; j++) {
			cout << endl;
			cout << "Ingrese el dato para la posicion " << "(" << i + 1 << "," << j + 1 << ") : ";
			cin >> aux;
			aux = validacion.soloNumeros(aux);
			numero = stoi(aux);
			*(*(matriz + i) + j) = numero;
		}
	}
}

int** Matriz::generar(int dimFil, int dimCol)
{
	int** matriz;
	matriz = (int**)malloc(dimFil * sizeof(int*));
	for (int j = 0; j < dimFil; j++) {
		*(matriz + j) = (int*)malloc(dimCol * sizeof(int));
	}

	return matriz;
}

void Matriz::encerar(int** matriz, int dimFil, int dimCol)
{
	int i, j;
	for (i = 0; i < dimFil; i++) {
		for (j = 0; j < dimCol; j++) {
			*(*(matriz + i) + j) = 0;
		}
	}

	return;
}

int* Matriz::Vector(int** matriz, int dimFil, int dimCol)
{
	int* vector = new int[dimCol];
	int auxiliar=0;
	
	for (int j = 0; j < dimCol; j++) {
		for (int i = 0; i < dimFil; i++)
		{
			if (i < dimFil) {
				auxiliar = *(*(matriz + i) + j) + auxiliar;
			}

			if (i == dimFil - 1) {
				*(vector + j) = auxiliar;
				auxiliar = 0;
			}

		}
	}

	return vector;
	
}

bool Matriz::Comparar(int** matriz, int dimFil, int dimCol, int numero)
{
	int auxiliar = 0;
	
	for (int j = 0; j < dimCol; j++) {
		for (int i = 0; i < dimFil; i++)
		{
			if (i < dimFil) {
				auxiliar = *(*(matriz + i) + j) + auxiliar;
			}

			if (i == dimFil - 1) {
				if (numero == auxiliar) {
					return true;
				}

				auxiliar = 0;
			}

		}
	}

	return false;
}

