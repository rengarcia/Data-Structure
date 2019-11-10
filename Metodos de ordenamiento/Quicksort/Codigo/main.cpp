/**
 * Universidad De las Fuerzas Armadas ESPE
 * Carrera: Ingeniería de Software
 * Materia: Estructura de Datos
 * Tema: Quicksort
 * NRC: 2969
 */
#include <iostream>
#include "Quicksort.h"
#include "Ingreso.h"


using namespace std;

int main() {
    Ingreso ingreso;
    int n = atoi(ingreso.ingresar("Indique valor entero de numeros a ingresar: ").c_str());
    int* A = (int*) malloc(n * sizeof (int));

    leeCadena(n, A);
    quicksort(A, 0, n - 1);
    muestraCadena(n, A);
    return 0;
}
