#include "Menor.h"
#include "ingreso.h"
string Menor::getMenor()
{
	return menor;
}

void Menor::setMenor(string newMenor)
{
	this->menor = newMenor;
}

void Menor::calcularMenor(int num_palabras)
{
	string menor = "";
	char primeraLetra;
	string primeraPalabra;
	string palabra;
	string* palabras = new string[num_palabras];
	for (int i = 0; i < num_palabras; i++) {
		*(palabras + i) = ingresarPalabra("Ingrese palabra: ");
	}
	primeraPalabra = *(palabras + 0);
	primeraLetra = primeraPalabra.at(0);
	for (int i = 0; i < num_palabras; i++) {
		palabra = *(palabras + i);
		if (primeraLetra > palabra.at(0)) {
			primeraLetra = palabra.at(0);
			menor = palabra;
		}
	}
	setMenor(menor);
	delete[] palabras;
}