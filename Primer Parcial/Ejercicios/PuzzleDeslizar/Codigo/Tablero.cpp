/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 2967                                                       *
******************************************************************/
#include "Tablero.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

////////////////////////////////////////////////////////////////////////
// Name:       Tablero::inicializar(int filas, int columnas)
// Purpose:    Implementation of Tablero::inicializar()
// Parameters:
// - filas
// - columnas
// Return:     void
////////////////////////////////////////////////////////////////////////

void Tablero::inicializar(int filas, int columnas) {
    matriz = (int**) malloc(filas * sizeof (int));
    srand(time(NULL));

    for (int i = 0; i < columnas; i++) {
        (*(matriz + i)) = (int*) malloc(columnas * sizeof (int));
    }
}

////////////////////////////////////////////////////////////////////////
// Name:       Tablero::mover(int filaActual, int columnaActual, int filaNueva, int columnaNueva)
// Purpose:    Implementation of Tablero::mover()
// Parameters:
// - filaActual
// - columnaActual
// - filaNueva
// - columnaNueva
// Return:     void
////////////////////////////////////////////////////////////////////////

void Tablero::mover(int filaActual, int columnaActual, int filaNueva, int columnaNueva) {
    int aux;
    aux = *(*(matriz + filaActual) + columnaActual);
    *(*(matriz + filaActual) + columnaActual) = *(*(matriz + filaNueva) + columnaNueva);
    *(*(matriz + filaNueva) + columnaNueva) = aux;
}

////////////////////////////////////////////////////////////////////////
// Name:       Tablero::llenar(int filas, int columnas)
// Purpose:    Implementation of Tablero::llenar()
// Parameters:
// - filas
// - columnas
// Return:     void
////////////////////////////////////////////////////////////////////////

void Tablero::llenar(int filas, int columnas) {
    int numeros = 1;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            *(*(matriz + i) + j) = numeros;
            numeros++;
        }
    }
    *(*(matriz + filas - 1) + columnas - 1) = -1;
}

////////////////////////////////////////////////////////////////////////
// Name:       Tablero::desordenar(int filas, int columnas)
// Purpose:    Implementation of Tablero::desordenar()
// Parameters:
// - filas
// - columnas
// Return:     void
////////////////////////////////////////////////////////////////////////

void Tablero::desordenar(int filas, int columnas) {
    int filaNueva;
    int columnaNueva;
    int auxiliar;
    srand(time(NULL));
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            filaNueva = rand() % (filas);
            columnaNueva = rand() % (columnas);
            auxiliar = (*(*(matriz + i) + j));
            *(*(matriz + i) + j) = *(*(matriz + filaNueva) + columnaNueva);
            (*(*(matriz + filaNueva) + columnaNueva)) = auxiliar;
        }
    }
}

////////////////////////////////////////////////////////////////////////
// Name:       Tablero::getMatriz()
// Purpose:    Implementation of Tablero::getMatriz()
// Return:     int**
////////////////////////////////////////////////////////////////////////

int** Tablero::getMatriz(void) {
    return matriz;
}

////////////////////////////////////////////////////////////////////////
// Name:       Tablero::setMatriz(int** newMatriz)
// Purpose:    Implementation of Tablero::setMatriz()
// Parameters:
// - newMatriz
// Return:     void
////////////////////////////////////////////////////////////////////////

void Tablero::setMatriz(int** newMatriz) {
    matriz = newMatriz;
}

////////////////////////////////////////////////////////////////////////
// Name:       Tablero::Tablero(int filas, int columnas)
// Purpose:    Implementation of Tablero::Tablero()
// Parameters:
// - filas
// - columnas
// Return:     
////////////////////////////////////////////////////////////////////////

Tablero::Tablero(int filas, int columnas) {
    inicializar(filas, columnas);
    llenar(filas, columnas);
    desordenar(filas, columnas);
}

////////////////////////////////////////////////////////////////////////
// Name:       Tablero::~Tablero()
// Purpose:    Implementation of Tablero::~Tablero()
// Return:     
////////////////////////////////////////////////////////////////////////

Tablero::~Tablero() {
    free(matriz);
}

////////////////////////////////////////////////////////////////////////
// Name:       Tablero::verificar(int filas, int columnas)
// Purpose:    Implementation of Tablero::verificar()
// Parameters:
// - filas
// - columnas
// Return:     bool
////////////////////////////////////////////////////////////////////////

bool Tablero::verificar(int filas, int columnas) {
    int numero = 1;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (*(*(matriz + i) + j) != numero) {
                return false;
            }
            numero++;
        }
    }
    return true;
}

////////////////////////////////////////////////////////////////////////
// Name:       Tablero::buscarFila(int filas, int columnas)
// Purpose:    Implementation of Tablero::buscarFila()
// Parameters:
// - filas
// - columnas
// Return:     int
////////////////////////////////////////////////////////////////////////

int Tablero::buscarFila(int filas, int columnas) {

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (*(*(matriz + i) + j) == -1) {
                return i;
            }
        }
    }
}



////////////////////////////////////////////////////////////////////////
// Name:       Tablero::buscarColumna(int filas, int columnas)
// Purpose:    Implementation of Tablero::buscarColumna()
// Parameters:
// - filas
// - columnas
// Return:     void
////////////////////////////////////////////////////////////////////////

int Tablero::buscarColumna(int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (*(*(matriz + i) + j) == -1) {
                return j;
            }
        }
    }
}


////////////////////////////////////////////////////////////////////////
// Name:       Tablero::imprimir(int filas, int columnas)
// Purpose:    Implementation of Tablero::buscarColumna()
// Parameters:
// - filas
// - columnas
// Return:     void
////////////////////////////////////////////////////////////////////////

void Tablero::imprimir(int filas, int columnas) {
    system("cls");
    cout << endl << endl;
    for (int i = 0; i < filas; i++) {
        cout << "\t\t";
        for (int j = 0; j < columnas; j++) {
            if ((*(*(matriz + i) + j)) != -1) {
                cout << *(*(matriz + i) + j) << "\t";
            } else {
                cout << "  \t";
            }
        }
        cout << endl;
    }
}
