/********************************************
 UNIVERSIDAD DE LAS FUERZAAS ARMADAS ESPE
*********************************************
	ESTRUCTURA DE DATOS PROYECTO PRIMER PARCIAL
				 INTEGRANTES:
				- DANIEL AVILA
				- DIEGO ZURITA
FECHA:
*********************************************/

#include <iostream>
#include <stdio.h>
#include "ListaDoble.h"
#include "TetrisFunction.h"
#include "Position.h"
int main()
{
	system("Menu.exe");
	int n = 6;//Numero de elementos a insertar
	int m = 0;
	if (n >= 11) {
		m = 9;
	}
	else {
		m = n;
	}
	int MAXH = 0;
	bool escape=true;
	int cont = 0;
	int MAXV = 0;
	MAXH = 3 * (n - 1) + 8;
	MAXV = (int) (0.60 * MAXH);
	Position* pos = new Position();
	ListaDoble lista = ListaDoble();
	lista.listaDobleTetris(MAXH-7);
	system("color F9");
	TetrisFunction tetris = TetrisFunction(m+1,3);
	tetris.hideCursor();
	tetris.frame(MAXV, MAXH);
	do {
		if (lista.gano(n) == false) {
			escape = false;
		}
		if (lista.perdio(n) == false) {
			escape = false;
		}
		tetris.imprimir(MAXV, MAXH, pos);
		tetris.gotoxy(3, MAXV - 1);
		lista.imprimirLista();
		lista.insertarEnLista(pos, pos->getNum(), MAXV, MAXH);
		Sleep(150);
	} while (escape);

	tetris.gotoxy(0,MAXV+10);

	lista.insertarEnLista(pos, pos->getNum(), MAXV, MAXH);
	system("cls");
	std::cout << "La lista es:\n";
	lista.imprimirLista();
	std::cout << "\n";
	
	system("pause");

	return 0;
}