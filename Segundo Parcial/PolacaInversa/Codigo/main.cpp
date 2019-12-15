#include<iostream>
#include "NodoChar.h"
#include "OperacionesPolaca.h"
#include "Validaciones.h"
#include <cstdio>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
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
			if (i == 3) {
				i = 0;
			}
			Selector(i);
			break;

		case ENTER:
			Selector(5);

			Validaciones validacion;
			string cadena,aux;
			OperacionesPolaca operacion;

			switch (i) {
			case 0:
				do{
					cout << "Ingrese la expresion en infijo: ";
					cin >> cadena;
				} while (!validacion.esInfija(cadena));
				
				aux = operacion.infijaAPosfija(cadena);
				cout << "Posfija: " << endl << aux << endl;

				system("pause");
				break;

			case 1:
				do {
					cout << "Ingrese la expresion en infijo: ";
					cin >> cadena;
				} while (!validacion.esInfija(cadena));

				aux = operacion.infijaAPrefija(cadena);
				cout << "Prefija: " << endl << aux << endl;
				
				system("pause");
				break;

			case 2:
				cout << endl << endl;
				cout << "Saliendo del programa" << endl;
				exit(0);
				break;

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
	cout << "\tNotacion Posfijo" << endl;
	cout << "\tNotacion Prefijo" << endl;
	cout << "\tSalir del Programa" << endl;
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