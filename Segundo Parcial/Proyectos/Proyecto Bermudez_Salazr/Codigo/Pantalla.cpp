/***********************************************************************
 * Module:  Pantalla.cpp
 * Author:  Alan
 * Modified: lunes, 18 de noviembre de 2019 23:20:19
 * Purpose: Implementation of the class Pantalla
 ***********************************************************************/

#include "Pantalla.h"
#include <Windows.h>
#include <iostream>
#include <cwchar>
using namespace std;

////////////////////////////////////////////////////////////////////////
// Name:       Pantalla::gotoxy(int x, int y)
// Purpose:    Implementation of Pantalla::gotoxy()
// Parameters:
// - x
// - y
// Return:     void
////////////////////////////////////////////////////////////////////////

void Pantalla::gotoxy(int x, int y)
{
    HANDLE h_con;
    h_con = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(h_con, dwPos);
}

////////////////////////////////////////////////////////////////////////
// Name:       Pantalla::dimensionPantalla()
// Purpose:    Implementation of Pantalla::dimensionPantalla()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Pantalla::dimensionPantalla(void)
{
    int ancho, alto;

    ancho = GetSystemMetrics(SM_CXSCREEN);
    alto = GetSystemMetrics(SM_CYSCREEN);

    cout << "Resolucion de pantalla > " << ancho << "x" << alto << endl;
    
}

void Pantalla::tablero(string nombre, int numero, int puntuacion)
{
	system("cls");
	const char horizontal = 205;
	const char vertical = 186;
	const char esquinaDerechaS = 187;
	const char esquinaDerechaI = 188;
	const char esquinaIzquierdaS = 201;
	const char esquinaIzquierdaI = 200;
	for (int i = 4; i < 40; i++)
	{
		gotoxy(i, 4);
		cout << horizontal;
		gotoxy(i, 44);
		cout << horizontal;
	}

	for (int i = 5; i < 44; i++)
	{
		gotoxy(4, i);
		cout << vertical;
		gotoxy(40, i);
		cout << vertical;
	}
	gotoxy(40, 4);
	cout << esquinaDerechaS;
	gotoxy(40, 44);
	cout << esquinaDerechaI;
	gotoxy(4, 4);
	cout << esquinaIzquierdaS;
	gotoxy(4, 44);
	cout << esquinaIzquierdaI;
	cout << endl;
	gotoxy(45, 7);
	cout << "Jugador: " << nombre;
	gotoxy(45, 10);
	cout << "Siguiente numero: " << numero;
	gotoxy(45, 13);
	cout << "Puntuacion: " << puntuacion;
}

void Pantalla::ocultarCursor()
{
    HANDLE h_con;
    h_con = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize = 28;
    cci.bVisible = FALSE;
    SetConsoleCursorInfo(h_con, &cci);
}

void Pantalla::borrarLinea()
{
	for (int i = 5; i < 40; i++)
	{
		gotoxy(i, 43);
		cout << " ";
	}
}

