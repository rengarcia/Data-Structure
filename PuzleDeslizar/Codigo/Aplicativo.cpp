#include "Tablero.cpp"
#include "Grafico.cpp"
#include <iostream>
#include "Ingreso.h"

#define ARRIBA 72
#define ABAJO 80
#define DERECHA 77
#define IZQUIERDA 75


int main(){
	Grafico grafico;
	Ingreso ingreso;
	
	int filaNueva;
	int columnaNueva;
	int filaActual;
	int columnaActual;
	int filas;
	int columnas;
	int numero = 0;
	bool finJuego = false;
	char tecla;
	string entrada;	
	
	grafico.ocultarCursor();
	
	entrada = ingreso.leer("Ingrese el numero de filas", 1);
	filas = atoi(entrada.c_str());
	entrada = ingreso.leer("Ingrese el numero de columnas", 1);
	columnas = atoi(entrada.c_str());	
	
	Tablero tablero(filas,columnas);
	
	filaActual = tablero.buscarFila(filas,columnas);
	columnaActual = tablero.buscarColumna(filas,columnas);

	filaNueva = filaActual;
	columnaNueva = columnaActual;	
	
		
	tablero.imprimir(filas,columnas);
	
	while (!tablero.verificar(filas,columnas)) {		
		if (kbhit()) {
			tecla = getch();			
			if (tecla == DERECHA && columnaActual != 0) {
				columnaNueva--;
				tablero.mover(filaActual, columnaActual, filaNueva, columnaNueva);
				columnaActual = columnaNueva;
				tablero.imprimir(filas,columnas);				
			}
			if (tecla == IZQUIERDA && columnaActual != filas-1) {
				columnaNueva++;
				tablero.mover(filaActual, columnaActual, filaNueva, columnaNueva);
				columnaActual = columnaNueva;
				tablero.imprimir(filas,columnas);
			}
			if (tecla == ARRIBA && filaActual != columnas -1) {
				filaNueva++;
				tablero.mover(filaActual, columnaActual, filaNueva, columnaNueva);
				filaActual = filaNueva;				
				tablero.imprimir(filas,columnas);
			}
			if (tecla == ABAJO && filaActual != 0) {
				filaNueva--;				
				tablero.mover(filaActual, columnaActual, filaNueva, columnaNueva);
				filaActual = filaNueva;				
				tablero.imprimir(filas,columnas);
			}			
		}
		Sleep(30);
	}
	cout << "Puzle resuelto correctamente" << endl;		
}
