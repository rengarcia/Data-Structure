/* Ejercicio 320
Disena un programa que permita que dos personas jueguen al ajedrez. El programa debe verificar que todos los
movimientos son validos.
*/

#include <iostream>
#include <cstdio>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include <string>
#include "Tablero.h"

using namespace std;

#define ARRIBA 72
#define ABAJO  80 
#define ENTER  13

void menuCursor();
void menu();
void gotoxy(int x, int y);
void Selector(int i);


int main() {
	for (;;) {
		menuCursor();
	}
	return 0;
}

void menuCursor() {
	int i = 0;
	Selector(i);
	menu();
	gotoxy(3, 1);
	char tecla;

	Tablero tablero;
	string s;
	bool nuevoJuego = true;


	while (true) {
		tecla = _getch();

		switch (tecla) {
		case ARRIBA:
			i--;
			if (i < 0) {
				i = 3;
			}
			Selector(i);
			break;

		case ABAJO:
			i++;
			if (i == 0) {
				i = 1;
			}
			if (i == 2) {
				i = 0;
			}
			Selector(i);
			break;

		case ENTER:
			Selector(5);

			switch (i) {
			case 0:
				
				while (nuevoJuego) {
					tablero.inicializarTablero();
					while (tablero.jugar());
					cout << "Quieres juegar de nuevo? (y para si, cualquier otra tecla para no) ";
					cin >> s;
					if (s != "y")
						nuevoJuego = false;
				}



				system("pause");
				break;

			case 1:
				cout << endl;
				cout << "Saliendo del programa" << endl;
				exit(0);

			}
			system("cls");
			menu();
			gotoxy(3, 1);
			break;
		}
	}
}

void menu() {
	system("cls");
	cout << "|*********************Menu*************************|" << endl;
	cout << "\tJugar Ajedrez" << endl;
	cout << "\tSalir del programa" << endl;
	cout << "|**************************************************|" << endl;
}

void gotoxy(int x, int y) {
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}

void Selector(int i) {
	gotoxy(1, 1 + i);
}
