/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 2967                                                       *
******************************************************************/
#include <iostream>
#include "Ordenamiento.cpp"

using namespace std;

int main(int argc, char** argv) {
    Ingreso ingreso;
    Ordenamiento ordenar;
    int* arreglo;
    int dimension = atoi(ingreso.ingresar("Indique valor entero de numeros a ingresar: ").c_str());
    arreglo = ordenar.inicializarVector(dimension);
    ordenar.ingresarDatos(dimension, arreglo);
    cout << "\nArreglo antes de ordenar\n";
    ordenar.imprimir(arreglo, dimension);
    ordenar.ordenarShell(arreglo, dimension);
    cout << "\nArreglo ordenado con el metodo ShellSort\n";
    ordenar.imprimir(arreglo, dimension);
    free(arreglo);

    return 0;
}
