/**
 *
 *                             UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
 *                                CARRERA DE INGENIERIA DE SOFTWARE
 *                                         TERCER SEMESTRE
 *
 * PROYECTO DEL SEGUNDO PARCIAL
 * AUTORES: Sebastian Alvarez
 *          Renan Garcia
 * NRC:2967
 * FECHA DE MODIFICACION: 11/DIC/2019
 * FECHA DE ENTREGA: 12/DIC/2019
 *
 * STATUS: Finalizado
 */

#include <iostream>
#include <string>
#include <Windows.h>
#include <time.h>
#include <cstdlib>
#include <conio.h>
#include "UtilMenu's.h"
#include "NumberCList.h"
#include "Imagen.h"
#include "Pantalla.h"
#include "Impresion.h"

#define UP 72
#define DOWN 80
#define ENTER  13
#define ESCAPE 27
#define LEFT 75
#define RIGHT 77

using namespace std;

void VisualMenu(CircularList, int);

void showInformation() {
	std::cout <<
		"							UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE\n" <<
		"				Este videojuego fue desarrollado como proyecto de segundo parcial para la\n" <<
		"				materia de Estructura de Datos utilizando: \n" <<
		"				Lenguaje: C++\n" <<
		"				IDE: Visual Studio Community 2019\n" <<
		"				Libreria grafica: SFML 2.5.1\n\n\n" <<
		"				Desarrollado por: Sebastian Alvarez y Renan Garcia" << std::endl;
}

int main() {
	CircularList CList;
	int posY = 0;
	
	for (;;) {
		VisualMenu(CList, posY);
	}

	return 0;
}

void VisualMenu(CircularList CList, int posY) {
	menuSelecInformation();
	char key;
	
	while (true) {
		key = _getch();

		switch (key) {
		case UP:
			posY--;
			if (posY < 0) {
				posY = 2;
			}
			utilMenu(posY);
			break;

		case DOWN:
			posY++;
			if (posY == 0) {
				posY = 1;
			}
			if (posY > 2) {
				posY = 0;
			}
			utilMenu(posY);
			break;

		case ENTER:
			Pantalla screen;
			Impresion printer;
			bool GAMEOVER = false;
			int numero, siguienteNumero, x, y, yBarra, posicion;
			char tecla;

			switch (posY) {
			case 0:
				/*Show information about the game*/
				showInformation();
				hConWnd = GetConsoleWndHandle();
				if (hConWnd) {
					BCX_Bitmap("images/logo.bmp", hConWnd, 123, 1, 1, 0, 0);
					Sleep(3000);
					system("pause");
				}

				system("pause");
				break;

			case 1:
				/*PLAY NOW!*/
				std::cout << "COMENZANDO..." << std::endl;
				Sleep(2000);
				system("cls");
				system("color F3");

				screen.tablero();
				srand(time(NULL));
				x = 13, y = 1;
				yBarra = 29, posicion = 13;
				numero = printer.generarPiezas();
				siguienteNumero = printer.generarPiezas();
				screen.gotoxy(x, y);
				screen.ocultarCursor();
				CList.insertNode(0, true);

				while (!GAMEOVER) {
					Sleep(150);
					
					screen.borrarLinea(29);
					screen.gotoxy(x, y);
					cout << numero;
					screen.gotoxy(x, y);
					cout << " ";
					y++;
					screen.gotoxy(x, y);
					cout << numero;
					screen.gotoxy(posicion, yBarra);
					CList.printCList();

					if (y == 29) {
						if (x < posicion) {
							CList.insertNode(numero, false);
							posicion--;
						}
						else if (x > posicion + CList.getNumberOfNodes()-1) {
							CList.insertNode(numero, true);
						}
						else if (x >= posicion && x <= posicion + CList.getNumberOfNodes()-1) {
							CList.insertIn(numero, x-posicion);
						}
						if (CList.getNumberOfNodes() == 26) {
							GAMEOVER = true;
						}
						//CList.updateCList();
						CList.saveInTxt();

						y = 1;
						x = 13;
						numero = siguienteNumero;
						siguienteNumero = printer.generarPiezas();
						screen.gotoxy(x, y);
						cout << siguienteNumero;
					}

					if (_kbhit()) {
						tecla = _getch();
						if (tecla == ESCAPE) {
							GAMEOVER = true;
						}
						else if (tecla == RIGHT && x != 25) {
							screen.borrarLinea(y);
							x++;
						}
						else if (tecla == LEFT && x != 0) {
							screen.borrarLinea(y);
							x--;
						}
					}
				}
				CList.printCList();
				/*PDF creation*/
				system("java -jar dist/textToPdf.jar");

				system("pause");
				break;

			case 2:
				/*Exit*/

				std::cout << "Gracias por jugar :)" << std::endl;
				exit(0);
			}
			utilMenu(posY);
			break;
		}
	}
}