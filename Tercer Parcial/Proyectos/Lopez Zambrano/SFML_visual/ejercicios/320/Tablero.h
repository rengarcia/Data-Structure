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

	Cuadricula** generar(int dim) {
		Cuadricula** a = new Cuadricula * [dim];
		for (int i = 0; i < dim; ++i) {
			a[i] = new Cuadricula[dim];
		}
		return a;
	}

	bool movimiento();
	void inicializarTablero();
	bool jugar();
};

