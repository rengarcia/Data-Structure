#pragma once
class Matriz
{
public:
	void imprime(int** matriz, int dim);
	void ingreso(int** matriz, int dim);
	int** generar(int dim);
	void encerar(int** matriz, int dim);
	int** resta(int** matriz1, int** matriz2,int dim);
};

