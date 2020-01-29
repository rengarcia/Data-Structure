#include "Operaciones.h"
#include <iostream>
using namespace std;

void Operaciones::imprimirArbolSierpinski(int n)
{
	for (int y = n - 1; y >= 0; y--) {

		for (int i = 0; i < y; i++) {
			cout << " ";
		}

		for (int x = 0; x + y < n; x++) {

			if (x & y)
				cout << " " << " ";
			else
				cout << "* ";
		}

		cout << endl;
	}
}

int Operaciones::arbolSierpinskiRecursivo(int y, int n)
{
	if (y == 0) {
		baseArbol(n - 1);
		return 0;
	}

	funcionAux1(0, y);

	funcionAux2(0, y, n);

	cout << endl;
	arbolSierpinskiRecursivo(y - 1, n);
}

int Operaciones::menu(int opcion)
{
	int n;
	switch (opcion) {
	case 0:
		n = 4;
		break;

	case 1:
		n = 8;
		break;

	case 2:
		n = 16;
		break;

	case 3:
		n = 32;
		break;

	case 4:
		n = 64;
		break;
	}
	
	return n;
}

int Operaciones::baseArbol(int n)
{
	if (n == 1) {
		return 0;
	}

	cout << " *";

	baseArbol(n - 1);
}

int Operaciones::funcionAux1(int i, int y)
{
	if (i == y - 1) {
		return 0;
	}
	cout << " ";
	funcionAux1(i + 1, y);
}

int Operaciones::funcionAux2(int x, int y, int n)
{
	if (x + y == n - 1) {
		return 0;
	}

	if (x & y) {
		cout << " " << " ";
	}
	else {
		cout << "* ";
	}

	funcionAux2(x + 1, y, n);
}
