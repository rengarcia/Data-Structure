#include "Nodo.h"
#include "Prototipo.h"
#include "Operaciones.h"

Prototipo prototipo;

bool Operaciones::esPerfecto(int numero)
{
	if (numero == 0) {
		return false;
	}

	int i = 1;
	int suma = 0;

	while (i < numero) {
		if (numero % i == 0)
			suma = suma + i;
		i++;
	}

	if (suma == numero)
		return true;
	else
		return false;
}

void Operaciones::imprimirLista(int numero)
{
	Nodo* nodo = NULL;

	for (int i = 0; i <= numero; i++) {
		if (esPerfecto(i)) {
			prototipo.insertarCola(&nodo, i);
		}
	}
	prototipo.imprimir(nodo);

}
