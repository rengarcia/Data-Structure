#pragma once
#include <time.h>
#include <stdlib.h>

class Impresion {
public:
	int generarPiezas();
};

int Impresion::generarPiezas() {
	int numero;
	srand(time(NULL));
	numero = rand() % 5 + 1;
	return numero;
}