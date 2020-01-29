#pragma once
class Matriz
{
public:
	void imprime(int** matriz, int dimFil, int dimCol);
	void ingreso(int** matriz, int dimFil, int dimCol);
	int** generar(int dimFil, int dimCol);
	void encerar(int** matriz, int dimFil, int dimCol);
	bool esTringular(int** matriz, int dimFil,int dimCol);
};

