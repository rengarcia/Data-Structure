#pragma once
class Matriz
{
public:
	void imprime(int** matriz, int dimFil, int dimCol);
	void ingreso(int** matriz, int dimFil, int dimCol);
	int** generar(int dimFil, int dimCol);
	void encerar(int** matriz, int dimFil, int dimCol);
	int* Vector(int** matriz, int dimFil,int dimCol);
	bool Comparar(int** matriz, int dimFil, int dimCol, int numero);

};

