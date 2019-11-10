/**
 * Universidad De las Fuerzas Armadas ESPE
 * Carrera: Ingeniería de Software
 * Materia: Estructura de Datos
 * Tema: Cubo Magico
 * NRC: 2969
 */
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void nivel(int *niv);
void cubo(int** matriz, int niv);
int **matriz(int niv);
void impresion(int **matriz, int niv);

void nivel(int *niv) {
    printf("\n\tIngrese el orden del cubo magico: ");
    scanf("%d", niv);
}

int **matriz(int niv) {
    int **matriz1;
    matriz1 = (int**) calloc(sizeof (int*), niv);
    for (int i = 0; i < niv; i++) {
        *(matriz1 + i) = (int*) calloc(sizeof (int), niv);
    }
    return matriz1;
}

void cubo(int** matriz, int niv) {
    int i = 0, j = niv / 2;
    for (int n = 1; n <= niv * niv; n++) {
        (*(*(matriz + i) + j)) = n;
        if (n % niv == 0) {
            i++;
            continue;
        }
        j++;
        i--;
        if (i < 0) i = niv - 1;
        if (j > niv - 1) j = 0;
    }
}

void impresion(int **matriz, int niv) {
    printf("\n\n\tEl Cubo Magico de orden %d x %d es: \n\n\t", niv, niv);
    for (int i = 0; i < niv; i++) {
        for (int j = 0; j < niv; j++) {
            printf("\t%d", (*(*(matriz + i) + j)));
        }
        printf("\n\n\t");
    }
}

int main() {
    char r;
    do {
        system("cls");
        int **matriz1, niv;
        nivel(&niv);
        while (niv % 2 == 0) {
            printf("\n\tEL ORDEN DEL CUBO MAGICO DEBE SER IMPAR\n ");
            nivel(&niv);
        }
        matriz1 = matriz(niv);
        cubo(matriz1, niv);
        impresion(matriz1, niv);
        for (int i = 0; i < niv; i++) {
            free(*(matriz1 + i));
        }
        free(matriz1);
        fflush(stdin);
        printf("\n\tDesea ingresar otros datos (s o S) para SI (n o N) para NO: ");
        scanf("%c", &r);
    } while (r == 's' || r == 'S');
    printf("\n\t");
}

