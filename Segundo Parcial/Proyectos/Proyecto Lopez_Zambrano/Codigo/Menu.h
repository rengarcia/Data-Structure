#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include<conio.h>
#include <iostream>
#include <windows.h>

#define ARRIBA 72
#define ABAJO 80
#define ENTER 13

using namespace std;

class Menu {
private:

public:
	Menu();
	void gotoxy(USHORT, USHORT);
	int menu(string titulo, string* opciones, int n);
};

Menu::Menu()
{
}

int Menu::menu(string titulo, string* opciones, int n) {
	int opcionSeleccionada = 1;  // Indica la opcionSeleccionada

	int tecla;

	bool repite = true; // controla el bucle para regresar a la rutina que lo llamo, al presionar ENTER

	do {
		system("cls");
		gotoxy(5, 3 + opcionSeleccionada); cout << "-->" << endl;

		// Imprime el título del menú
		gotoxy(15, 2); cout << titulo;

		// Imprime las opciones del menú
		for (int i = 0; i < n; ++i) {
			gotoxy(10, 4 + i); cout << opciones[i];
		}

		// Solo permite que se ingrese ARRIBA, ABAJO o ENTER

		do {
			tecla = _getch();
			// gotoxy(15, 15); cout << "tecla presionada: " << (char)tecla << " = " << tecla;
		} while (tecla != ARRIBA && tecla != ABAJO && tecla != ENTER);

		switch (tecla) {

		case ARRIBA:   // En caso que se presione ARRIBA

			opcionSeleccionada--;

			if (opcionSeleccionada < 1) {
				opcionSeleccionada = n;
			}

			break;

		case ABAJO:
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

void Menu::gotoxy(USHORT x, USHORT y) {
	COORD cp = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cp);
}
#endif // MENU_H_INCLUDED
