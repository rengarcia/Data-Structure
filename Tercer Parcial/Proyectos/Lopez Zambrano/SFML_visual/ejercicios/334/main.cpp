﻿/*Ejercicio N 334:
Disena una funcion que, dada una lista de nombres y una letra, devuelva una lista con todos los nombres que
empiezan por dicha letra.
 */

#include <iostream>
#include <cstdio>
#include <conio.h>
#include <windows.h>
#include <string>
#include "Nodo.h"
#include "Prototipo.h"
#include "Validacion.h"


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

	Nodo* nodo = NULL;
	Nodo* listaNombres;
	Prototipo prototipo;
	Validacion validacion;
	string temp;
	char inicial;

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

			switch (i) {
			case 0:
				cout << "Ingrese el nombre: ";
				cin >> temp;
				temp = validacion.soloLetras(temp);
				temp = prototipo.aMinusculas(temp);
				prototipo.insertarCola(&nodo, temp);
				system("pause");
				break;

			case 1:
				cout << "Ingrese la inicial: ";
				cin >> temp;
				temp = validacion.unCaracter(temp);
				temp = prototipo.aMinusculas(temp);
				inicial = temp.at(0);
				listaNombres = prototipo.buscarDato(nodo, inicial);
				prototipo.imprimir(listaNombres);
				system("pause");
				break;

			case 2:
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
	cout << "\tIngresar nombres para la lista" << endl;
	cout << "\tBuscar nombres por letra inicial" << endl;
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