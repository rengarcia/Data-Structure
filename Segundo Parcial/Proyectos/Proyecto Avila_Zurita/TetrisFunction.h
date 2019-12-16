#pragma once
#include <stdio.h>  
#include <windows.h>
#include <iostream>
#include <string.h>
#include <time.h>
#include <conio.h>
#include "Position.h"
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

class TetrisFunction
{
private:
	int limiteAleatorio;
	int saltos;
public:
	//Constructor
	TetrisFunction(int limiteAleatorio,int saltos);
	//Destructor
	~TetrisFunction();
	void gotoxy(int x, int y);
	void frame(int limVer,int limHoriz);
	void hideCursor();
	void imprimir(int limVer, int limHoriz, Position*& pos);

};

