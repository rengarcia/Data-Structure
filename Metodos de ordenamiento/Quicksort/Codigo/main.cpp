/*Universidad de las fuerzas armadas ESPE
 * Estructura de Datos
 * Ingenieria de Software
 * Renan Garcia
 * Pregrado S-II
 * creacion: 14 de Octubre
 * modificacion: 18 de octubre
 */
#include <iostream>
#include "Quicksort.h"
#include "Ingreso.h"


using namespace std;

int main()
{
    Ingreso ingreso;
    int n = atoi(ingreso.ingresar("Indique valor entero de numeros a ingresar: ").c_str());
    int* A = (int*)malloc(n * sizeof(int));

    leeCadena(n, A);
    quicksort(A, 0, n - 1);
    muestraCadena(n, A);
    return 0;
}
