/***********************************************************************
 * Module:  VectorMatriz.h
 * Author:  Kevin Duy, Carlos Puco
 * Modified: sabado, 26 de octubre de 2019 17:21:23
 * Purpose: Declaration of the class VectorMatriz
 ***********************************************************************/

class VectorMatriz {
	private:
		int *vector;
		int **matriz;
	public:
		int* inicializarVector(int);
		int* encerarVector(int,int*);
		int** inicializar(int);
		int** encerar(int,int**);
};
