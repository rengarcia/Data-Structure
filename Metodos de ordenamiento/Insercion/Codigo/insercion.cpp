/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 2967                                                       *
******************************************************************/
#include <stdio.h>
#include "recursivo.h"
#include "ingreso.h"

int main() {
    Ingreso leer;
    Insercion insercion;
    int *vector, tamanio;
    printf("Ingrese el tamanio del vector: ");
    tamanio = leer.ingresarEntero();
    printf("Ingrese los datos del vector: ");
    vector = insercion.ingresaNumeros(tamanio, vector);
    insercion.mostrar(tamanio, vector);
    printf("\nEl vector ordenado es: \n");
    insercion.insercionRecursivo(tamanio, vector);
    insercion.mostrar(tamanio, vector);
}
