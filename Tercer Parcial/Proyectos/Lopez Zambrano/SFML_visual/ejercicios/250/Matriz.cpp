#include <iostream>
#include "Validacion.h"
#include "Matriz.h"
using namespace std;


void Matriz::imprime(int** matriz, int dim)
{
	cout << endl;
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++)
		{
			cout << *(*(matriz + i) + j);
			printf("%*s", j + 5, " ");
		}
		cout << endl;
	}

}

void Matriz::ingreso(int** matriz, int dim)
{
	Validacion validacion;
	string aux;
	int numero;
	
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			cout << endl;
			cout << "Ingrese el dato para la posicion " << "(" << i + 1 << "," << j + 1 << ") : ";
			cin >> aux;
			aux = validacion.soloNumeros(aux);
			numero = stoi(aux);
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

int** Matriz::resta(int** matriz1, int** matriz2,int dim)
{
	int** resultado = generar(dim);
	encerar(resultado, dim);

	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++)
		{
			*(*(resultado + i) + j) = *(*(matriz1+ i) + j) - *(*(matriz2 + i) + j);
			
		}
	}

	return resultado;

}
