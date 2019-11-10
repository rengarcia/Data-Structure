/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 2967                                                       *
******************************************************************/
#include "Sudoku.h"

/**
        @brief Esta funcion reserva memoria para almacenar datos
        @param tamanio: el espacio de memoria que se desea para hacer el sudoku
        @return int**
 */

int** Sudoku::inicializar(int tamanio) {
    matriz = (int**) malloc(sizeof (int *)*tamanio);
    for (int i = 0; i < tamanio; i++) {
        *(matriz + i) = (int*) malloc(sizeof (int*)*tamanio);
    }
    return matriz;
}

/**
        @brief Esta funcion se encarga de imprimir el formato para separar la matriz de 9*9 en  3 matrices de 3*3
        @param **matriz: la matriz que se genera para mostrar el sudoku
 */

void Sudoku::tablero(int **matriz) {
    cout << "-------------SUDOKU---------------\n";
    for (int i = 0; i < 9; i++) {
        printf("\n");
        if (i == 3 || i == 6) {
            cout << "----------------------------------\n";
        }
        for (int j = 0; j < 9; j++) {
            if (j == 3 || j == 6) {
                printf("   |");
            }
            cout << " " << *(*(matriz + i) + j) << " ";
        }
    }
}

/**
        @brief Esta funcion se encarga llenar la matriz con numeros aleatorios para realizar el sudoku
        @param **matriz: la matriz que se va a ocupar para generar el sudoku
        @return int**
 */

int** Sudoku::hacerSolucion(int **matriz) {
    srand(time(NULL));
    do {
        contador2 = 0;
        matriz = inicializar(10);
        //Enceramos la matriz
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                *(*(matriz + i) + j) = 0;
                contador1 = 0;
                do {
                    //Se almacenan numeros aleatorios del 1 al 9
                    aleatorio = rand() % 9 + 1;
                    //Si la funcion controlar devuelve 1 se almacena el numero aleatorio generado, si devuelve 0 vuelve a generar un numero aleatorio
                    detente = controlar(aleatorio, 9, i, j, matriz);
                    contador1++;
                    //Hace que termine los dos ciclos for
                    if (contador1 > 15) {
                        i = 9;
                        j = 9;
                    }
                } while (detente == 1);
                *(*(matriz + i) + j) = aleatorio;
                //Aumenta el numero de 1 en 1 hasta llegar a 81 para terminar el ciclo do-while
                contador2++;
            }
        }
    } while (contador2 != 81);
    return matriz;
}

/**
        @brief Esta funcion se de controlar que no se repita un mismo numero del 1 al 9 en una misma fila o columna
        @param numero: el numero aleatorio que se genera
        @param tamanio: el tamaño del sudoku es decir de 9
        @param contador1: recorre las filas de la matriz
        @param contador2: recorre las columnas de la matriz
        @param **matriz: ocupa la matriz que se generó
        return int
 */

int Sudoku::controlar(int numero, int tamanio, int contador1, int contador2, int **matriz) {
    detente = 0;
    for (int i = 0; (i < tamanio && detente == 0); i++) {
        //Se va desplazando y comprueba si el espacio en donde está ubicado es igual al numero aleatorio generado tanto en fila como columna               
        if (*(*(matriz + contador1) + i) == numero || *(*(matriz + i) + contador2) == numero) {
            detente = 1;
        }
    }
    return detente;
}
