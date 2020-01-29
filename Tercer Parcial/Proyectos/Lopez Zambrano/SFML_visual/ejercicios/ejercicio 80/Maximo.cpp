#include "Maximo.h"
#include "ingreso.h"
int Maximo::getMaximo()
{
	return maximo;
}

void Maximo::setMaximo(int newMaximo)
{
	this->maximo = newMaximo;
}

void Maximo::encontrarMaximo(int cant_numeros)
{
    int maximo = 0;
    int* numeros = new int[cant_numeros];
    for (int i = 0; i < cant_numeros; i++) {
        *(numeros + i) = ingresarEntero("Ingrese numero: ");
        if (maximo < *(numeros + i)) {
            maximo = *(numeros + i);
        }
    }
    setMaximo(maximo);
    delete[] numeros;
}