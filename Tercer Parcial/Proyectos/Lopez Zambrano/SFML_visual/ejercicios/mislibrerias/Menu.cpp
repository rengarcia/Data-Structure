#include "Menu.h"
#include <conio.h>
#include <Windows.h>
#include <iostream>
using namespace std;

/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
Autor: Zambrano Andrés
Fecha Creacion: 118/01/2020
Estructura de Datos
Ing. Fernando Solis
*/
#define TECLA_ARRIBA 72
#define TECLA_ABAJO 80
#define ENTER 13

void gotoxy(int x, int y) {
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hCon, dwPos);
}

int menu(string titulo, string* opciones, int n)
{
	int opcionSeleccionada = 1;
	int tecla;
	bool repite = true;

	do {
		system("cls");
		gotoxy(5, (3 + opcionSeleccionada)); cout << "==>";

		//imprime el titulo
		gotoxy(15, 2); cout << titulo;

		//imprime las opciones
		for (int i = 0; i < n; i++) {
			gotoxy(10, (4 + i)); cout << i + 1 << ") " << *(opciones + i);
		}


		do {
			tecla = _getch();
		} while (tecla != TECLA_ARRIBA && tecla != TECLA_ABAJO && tecla != ENTER);

		switch (tecla) {
		case TECLA_ARRIBA:
			opcionSeleccionada--;

			if (opcionSeleccionada < 1) {
				opcionSeleccionada = n;
			}
			break;
		case TECLA_ABAJO:
			opcionSeleccionada++;

			if (opcionSeleccionada > n) {
				opcionSeleccionada = 1;
			}
			break;
		case ENTER:
			repite = false;
			break;
		}
	} while (repite);
	return opcionSeleccionada;
}