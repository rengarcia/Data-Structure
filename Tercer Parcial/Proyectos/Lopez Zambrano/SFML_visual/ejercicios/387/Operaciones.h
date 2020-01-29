#pragma once
class Operaciones
{
public:
	//Funcion estandar para imprimir el arbol
	void imprimirArbolSierpinski(int n);
	//Funcion recursiva
	int arbolSierpinskiRecursivo(int y, int n);
	int menu(int opcion);

private:
	int baseArbol(int n);
	int funcionAux1(int i, int y);
	int funcionAux2(int x, int y, int n);

};

