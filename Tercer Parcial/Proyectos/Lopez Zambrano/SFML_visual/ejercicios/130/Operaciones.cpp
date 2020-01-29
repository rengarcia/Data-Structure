#include "Operaciones.h"

int Operaciones::MCD(int num1, int num2)
{
	if (num2 == 0)
		return num1;
	return MCD(num2, num1 % num2);
}

int Operaciones::encontrarMCD(int* lista, int dim)
{
	int resultado = *lista;

	for (int i = 1; i < dim; i++)
	{
		resultado = MCD(*(lista + i), resultado);

		if (resultado == 1)
		{
			return 1;
		}
	}
	return resultado;
}
