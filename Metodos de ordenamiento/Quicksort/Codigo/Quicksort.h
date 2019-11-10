/**
 * Universidad De las Fuerzas Armadas ESPE
 * Carrera: Ingeniería de Software
 * Materia: Estructura de Datos
 * Tema: Quicksort
 * NRC: 2969
 */
#include <iostream>
#include <stdlib.h>
#include "Ingreso.h"

using namespace std;

void leeCadena(int cant, int* n) {
    Ingreso ingreso;

    for (int i = 0; i < cant; i++) {
        *(n + i) = atoi(ingreso.ingresar("Ingrese valor entero: ").c_str());
    }
}

void muestraCadena(int cant, int* n) {
    cout << "Cadena ordenada por Quicksort" << endl;
    for (int i = 0; i < cant; i++) {
        printf("%d ", *(n + i));
    }
}

void quicksort(int* A, int izq, int der) {
    int aux;
    int i = izq;
    int j = der;
    int x = *(A + ((izq + der) / 2));
    do {
        while ((*(A + i) < x) && (j <= der)) {
            i++;
        }

        while ((x < *(A + j)) && (j > izq)) {
            j--;
        }

        if (i <= j) {
            aux = *(A + i);
            *(A + i) = *(A + j);
            *(A + j) = aux;
            i++;
            j--;
        }

    } while (i <= j);

    if (izq < j)
        quicksort(A, izq, j);
    if (i < der)
        quicksort(A, i, der);
}
