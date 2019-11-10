/**

        UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE

CARRERA: INGENIERIA DE SOFTWARE
MATERIA: ESTRUCTURA DE DATOS
TEMA: METODOS DE BUSQUEDA: INSERCION
NRC: 2967

 */


#include <stdio.h>
#include <stdlib.h>

class Insercion {
private:
    int *vector;
public:
    int* inicializar(int);
    int* encerar(int, int*);
    int* ingresaNumeros(int, int*);
    void whileRecursivo(int, int, int*);
    void insercionRecursivo(int, int*);
    void mostrar(int, int*);
};

int* Insercion::inicializar(int tamanio) {
    vector = (int*) malloc(tamanio * sizeof (int));
    return vector;
}

int* Insercion::encerar(int tamanio, int *vector) {
    for (int i = 0; i < tamanio; i++) {
        *(vector + i) = 0;
    }
    return vector;
}

int* Insercion::ingresaNumeros(int tamanio, int *vector) {
    vector = inicializar(tamanio);
    vector = encerar(tamanio, vector);
    for (int i = 0; i < tamanio; i++) {
        scanf("%d", vector + i);
    }
    return vector;
}

void Insercion::whileRecursivo(int fin, int j, int *vector) {
    while (j >= 0 && *(vector + j) > fin) {
        *(vector + (j + 1)) = *(vector + j);
        j--;
    }
    *(vector + (j + 1)) = fin;
}

void Insercion::insercionRecursivo(int n, int* vector) {
    if (n <= 1) {
        return;
    }

    insercionRecursivo(n - 1, vector);

    int fin = *(vector + (n - 1));
    int j = n - 2;

    whileRecursivo(fin, j, vector);
}

void Insercion::mostrar(int tamanio, int *vector) {
    for (int i = 0; i < tamanio; i++) {
        printf("%d ", *(vector + i));
    }
}
