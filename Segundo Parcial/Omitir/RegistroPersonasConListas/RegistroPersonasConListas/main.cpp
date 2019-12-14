/*Universidad de las fuerzas armadas ESPE
 * Estructura de Datos
 * Ingenieria de Software
 * David Lopez
 * Pregrado S-II
 * creacion: 13 de Noviembre 2019
 * modificacion:
 */

#include "NodoPersona.h"
#include "Persona.h"
#include "Prototipo.h"
#include "Validacion.h"
#include "ConstruirObjeto.h"
#include <iostream>
#include <cstdio>
#include <conio.h>
#include <windows.h>
#include <cstdlib>

#define ARRIBA 72
#define ABAJO  80 
#define ENTER  13

void menuCursor();
void menu();
void gotoxy(int x, int y);
void Selector(int i);

/*
IMPORTANTE!!!!!

El metodo insertarCabeza siempre retorna un dato tipo Node*, por ello seguir siempre el siguiente 
formato:
nodo = prototipo.insertarCabeza(nodo, persona)

El metodo insertarCola SOLO!! debe retornar un dato tipo Node*, cuando se le usa para insertar el primer
valor de la lista. Ejemplo:
nodo = prototipo.insertarCola(nodo, persona)

En cualquier otra circunstacia debe usarse como si no retornara nada. Ejemplo:
prototipo.insertarCola(nodo, persona)

*/

int main() {

	
	for (;;) {
		menuCursor();
	}

	return 0;

}
void menuCursor() {
	ConstruirObjeto construir;
	Persona persona;
	NodoPersona* nodo = NULL;
	Prototipo prototipo;
	Validacion validacion;

	//Este contador sirva para saber que formato de insercion por cola hay que usar 
	int contador = 1;

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
			if (i == 4) {
				i = 0;
			}
			Selector(i);
			break;

		case ENTER:
			Selector(5);
	
			switch (i) {
			case 0:
				persona = construir.construirPersona();
				nodo = prototipo.insertarCabeza(nodo, persona);
				cout << "Usuario insertado exitosamente" << endl;
				contador++;
				system("pause");
				break;

			case 1:
				persona = construir.construirPersona();
				
				if (contador == 1) {
					nodo = prototipo.insertarCola(nodo, persona);
					contador++;
				}
				else {
					prototipo.insertarCola(nodo, persona);
				}

				cout << "Usuario insertado exitosamente" << endl;
				system("pause");
				break;

			case 2:
				if (nodo == NULL) {
					cout << "Aun no se han ingresado datos" << endl;
				}

				prototipo.imprimir(nodo);
				system("pause");
				break;
			
			case 3:
				std::cout << "Saliendo del programa" << std::endl;
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
	cout << "\tIngresar Persona al inicio de la lista" <<endl;
	cout << "\tIngresar Persona al final de la lista" << endl;
	cout << "\tMostrar lista " <<endl;
	cout << "\tSalir " << endl;
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