#include <stdio.h> 
#include <time.h>
#include <iostream>
#include <ctime>
#include "ResolverTablero.h"
#include "dibujarMatriz.h"

using namespace std;

using namespace std;
enum Movimientos {
	MovArriba = 0,
	MovAbajo = 1,
	MovIzquierda = 2,
};

void Mover(int**, const Movimientos);
void Randomizar(int**);

int dimension = 10;

int main()
{	

	ResolverTablero comandos;
	dibujarMatriz dibujo;

	int** TableroRellenado = comandos.GenerarMatriz(dimension);
	int** TableroInicial = comandos.GenerarMatriz(dimension);
	int** Solucion = comandos.GenerarMatriz(dimension);
	int nuevoMovimiento;


	comandos.Encerar(TableroInicial, dimension);
	cout << "\n" << endl;
	srand(time(NULL));

	while (*(*(TableroInicial + dimension - 1) + dimension - 1) != ' ') {
		//"1 = Arriba, 0 = Abajo, 2 = Derecha, 3 = Izquierda"
		nuevoMovimiento = rand() % (3);
		Movimientos movimiento = (Movimientos)nuevoMovimiento;
		Mover(TableroInicial, movimiento);
	};


	int fila;
	int columna;
	comandos.LocalizarEspacio(fila, columna, TableroInicial, dimension);
	*(*(TableroInicial + fila) + columna) = 1;
	*(*(TableroInicial + 7) + 7) = 1;

	TableroRellenado = TableroInicial;

	cout << "Tablero Inicial:" << endl;
	cout << "\n" << endl;
	comandos.RellenarEspacios(TableroRellenado, dimension);
	comandos.ImprimirTablero(TableroRellenado, dimension);
	cout << "\n" << endl;

	cout << "Tablero Solucionado:" << endl;
	cout << "\n" << endl;
	Solucion = comandos.solucion(TableroRellenado);
	comandos.ImprimirTablero(Solucion, dimension);

	dibujo.DibujarNuevoTablero(TableroRellenado,Solucion);

	free(TableroInicial);
	return 0;
}

void Mover(int** Tablero, const Movimientos nuevoMovimiento) {

	ResolverTablero comandos2;
	int PosicionFila;
	int PosicionColumna;
	comandos2.LocalizarEspacio(PosicionFila, PosicionColumna, Tablero, dimension);

	int MovimientoFila(PosicionFila);
	int MovimientoColumna(PosicionColumna);
	switch (nuevoMovimiento) {

	case MovArriba:
	{
		MovimientoFila = PosicionFila + 1;
		break;
	}
	case MovAbajo:
	{
		MovimientoFila = PosicionFila - 1;
		break;
	}
	case MovIzquierda:
	{
		MovimientoColumna = PosicionColumna + 1;
		break;
	}

	}
	// Controlar que no se salga de los limites
	if (MovimientoFila >= 0 && MovimientoFila < dimension && MovimientoColumna >= 0 && MovimientoColumna < dimension) {
		(*(*(Tablero + PosicionFila) + PosicionColumna)) = (*(*(Tablero + MovimientoFila) + MovimientoColumna));
		(*(*(Tablero + PosicionFila) + PosicionColumna)) = 1;
		(*(*(Tablero + MovimientoFila) + MovimientoColumna)) = ' ';
	}
}

///El metodo Randomizar coloca todas los numeros y el espacion en una posicion aleatoria
void Randomizar(int** Tablero) {

	srand((unsigned int)time(0));
	for (int h = 0; h < 100; ++h) {
		int movimiento = (rand() % 4);
		switch (movimiento) {
		case 0:
		{
			Mover(Tablero, MovArriba);
			break;
		}
		case 1:
		{
			Mover(Tablero, MovAbajo);
			break;
		}
		case 2:
		{
			Mover(Tablero, MovIzquierda);
			break;
		}

		}
	}
}

