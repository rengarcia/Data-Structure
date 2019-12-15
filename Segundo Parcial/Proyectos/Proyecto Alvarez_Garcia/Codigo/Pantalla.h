#pragma once
#include <Windows.h>
#include <iostream>
#include <cwchar>

using namespace std;

class Pantalla {
public:
	void gotoxy(int x, int y);
	void tablero();
	void ocultarCursor();
	void borrarLinea(int posY);
};

void Pantalla::gotoxy(int x, int y)
{
	HANDLE h_con;
	h_con = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(h_con, dwPos);
}

void Pantalla::tablero()
{
	cout <<
		" ____________________________ \n" <<
		"||                          ||\n" <<
		"||                          ||\n" <<
		"||                          ||\n" <<
		"||                          ||\n" <<
		"||                          ||\n" <<
		"||                          ||\n" <<
		"||                          ||\n" <<
		"||                          ||\n" <<
		"||                          ||\n" <<
		"||                          ||\n" <<
		"||                          ||\n" <<
		"||                          ||\n" <<
		"||                          ||\n" <<
		"||                          ||\n" <<
		"||                          ||\n" <<
		"||                          ||\n" <<
		"||                          ||\n" <<
		"||                          ||\n" <<
		"||                          ||\n" <<
		"||                          ||\n" <<
		"||                          ||\n" <<
		"||                          ||\n" <<
		"||                          ||\n" <<
		"||                          ||\n" <<
		"||                          ||\n" <<
		"||                          ||\n" <<
		"||                          ||\n" <<
		"||                          ||\n" <<
		"||                          ||\n" <<
		" ____________________________ \n" << endl;
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

void Pantalla::borrarLinea(int posY)
{
	for (int i = 2; i < 26; i++)
	{
		gotoxy(i, posY);
		cout << " ";
	}
}