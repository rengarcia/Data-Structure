#include "Operaciones.h"

int Operaciones:: factorial(int n)
{
	if (n == 0)
		return 1;

	return n * factorial(n - 1);
}

int Operaciones:: combinaciones(int n, int m)
{
	return factorial(n) / (factorial(m) * factorial(n - m));
}