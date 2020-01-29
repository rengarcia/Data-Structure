/***********************************************************************
 * Module:  Tablero.h
 * Author:  fleia
 * Modified: Monday, January 20, 2020  ‏‎8:49:14 AM
 * Purpose: Declaration of the class Tablero
 ***********************************************************************/

#if !defined(__Class_Diagram_1_Tablero_h)
#define __Class_Diagram_1_Tablero_h

#include "Cuadricula.h"
class Tablero
{
	Color turno = BLANCO;
	bool moverRey(Cuadricula* rey, Cuadricula* nuevaPosicion);
	bool moverReina(Cuadricula* reina, Cuadricula* nuevaPosicion);
	bool moverAlfil(Cuadricula* alfil, Cuadricula* nuevaPosicion);
	bool moverCaballo(Cuadricula* caballo, Cuadricula* nuevaPosicion);
	bool moverTorre(Cuadricula* torre, Cuadricula* nuevaPosicion);
	bool moverPeon(Cuadricula* peon, Cuadricula* nuevaPosicion);
	bool moverPieza(int x1, int y1, int x2, int y2);
	void imprimirTablero();

public:

	Cuadricula** cuadricula = generar(8);

	Cuadricula** generar(int dim);

	bool movimiento();
	void inicializarTablero();
	bool jugar();
};

#endif