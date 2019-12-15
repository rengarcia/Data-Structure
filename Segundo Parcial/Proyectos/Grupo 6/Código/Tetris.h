#include <windows.h>
int n = 1;
int x = 1;
int y = 20;
int tamanio = 2;
int cont = 0;
int **cuerpo;
int direccion = 3;
int auxiliar = 1;
int aumenta = 1;
int numero = (rand()%9)+1;
int mantenerY = 47;

/***********************************************************************
 * Module:  Tetris.h
 * Author:  Kevin Duy, Carlos Puco
 * Modified: sabado, 26 de octubre de 2019 17:21:23
 * Purpose: Implementation of the class Tetris
 ***********************************************************************/

#include <conio.h>
#include <fstream>

#define IZQUIERDA 75
#define DERECHA 77
#define ESC 27

using namespace std;

pthread_mutex_t ptmutex1;
ofstream archivo;

class Tetris {
	private:
		char tecla;
	public:
		void guardarPosicion();
		int moverNumero();
		void borrarNumero();
		void teclear();
		void mantener();
		void moverAbajo();
		void ubicar(int);
		void principal();
		void crearMenu();
};
