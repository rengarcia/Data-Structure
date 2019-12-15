/**************************************************************
 *	Universidad de las Fuerzas Armadas ESPE
 *	Maria Belen Ceron, Alex Chicaiza
 *	NRC: 2967
 *	Fecha creacion: 08/11/2019
 *	Fecha ultima modificacion:	12/12/2019
 *	Docente: Ing. Fernando Solis
***************************************************************/
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <ctype.h>
#include <string.h>

#include <time.h>
#include <pthread.h>
#include <fstream>

using namespace std;

#define TECLA_ARRIBA 72
#define TECLA_ABAJO 80
#define TECLA_DERECHA 77
#define TECLA_IZQUIERDA 75
#define TECLA_ENTER 13

void gotoxy(int x, int y)
{
	HANDLE hCon;
	hCon=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X=x;
	dwPos.Y=y;
	SetConsoleCursorPosition(hCon,dwPos);
}

void color(int x)
{
	SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),x);
}

void AltEnter()
{
    keybd_event(VK_MENU,
                0x38,
                0,
                0);
    keybd_event(VK_RETURN,
                0x1c,
                0,
                0);
    keybd_event(VK_RETURN,
                0x1c,
                KEYEVENTF_KEYUP,
                0);
    keybd_event(VK_MENU,
                0x38,
                KEYEVENTF_KEYUP,
                0);
}





void numbers(int numero,int x,int y)
{
	switch(numero){
			case 0:

				color(1);// num 0 azul
				gotoxy(x,y-1);
				printf("  =====");gotoxy(x,y++);
				printf("|| 0 ||");gotoxy(x,y++);
				printf(" =====",219,219,219,219);gotoxy(x,y++);

				break;

			case 1:
				color(2);
				gotoxy(x,y-1);
				printf("  =====");gotoxy(x,y++);
				printf("|| 1 ||");gotoxy(x,y++);
				printf(" =====",219,219,219,219);gotoxy(x,y++);
				break;


			case 2:
				color(11);
				gotoxy(x,y-1);
				printf("  =====");gotoxy(x,y++);
				printf("|| 2 ||");gotoxy(x,y++);
				printf(" =====",219,219,219,219);gotoxy(x,y++);
				break;


			case 3:
				color(12);
				gotoxy(x ,y-1);
				printf("  =====");gotoxy(x,y++);
				printf("|| 3 ||");gotoxy(x,y++);
				printf(" =====",219,219,219,219);gotoxy(x,y++);
				break;

			case 4:
				color(5);
				gotoxy(x,y-1);
				printf("  =====");gotoxy(x,y++);
				printf("|| 4 ||");gotoxy(x,y++);
				printf(" =====",219,219,219,219);gotoxy(x,y++);
				break;

			case 5:
				color(6);
				gotoxy(x,y-1);
				printf("  =====");gotoxy(x,y++);
				printf("|| 5 ||");gotoxy(x,y++);
				printf(" =====",219,219,219,219);gotoxy(x,y++);
				break;

			case 6:
				color(15);
				gotoxy(x,y-1);
				printf("  =====");gotoxy(x,y++);
				printf("|| 6 ||");gotoxy(x,y++);
				printf(" =====",219,219,219,219);gotoxy(x,y++);
				break;

			case 7:
				color(8);
				gotoxy(x,y-1);
				printf("  =====");gotoxy(x,y++);
				printf("|| 7 ||");gotoxy(x,y++);
				printf(" =====",219,219,219,219);gotoxy(x,y++);
				break;

			case 8:
				gotoxy(x,y-1);
				printf("  =====");gotoxy(x,y++);
				printf("|| 8 ||");gotoxy(x,y++);
				printf(" =====",219,219,219,219);gotoxy(x,y++);
			    break;

			case 9:
				color(10);
				gotoxy(x,y-1);
				printf("  =====");gotoxy(x,y++);
				printf("|| 9 ||");gotoxy(x,y++);
				printf(" =====",219,219,219,219);gotoxy(x,y++);
			    break;
		}
}
void margen()
{
	color(15);
    for(int i=30; i < 99; i++)
	{
    	//PARTE SUPERIOR
    	gotoxy (i, 3); printf("=");
    	//PARTE INFERIOR
        gotoxy(i, 40); printf("=");
    }
    for(int j=3; j < 40; j++)
	{
    	//PARTE IZQUIERDA
        gotoxy (29,j);  printf("||");
        //PARTE DERECHA
        gotoxy(99,j);  printf("||");
    }
    //ESQUINAS
    color(15);
    gotoxy(99,40);	printf("||");

}

void borrar(int numero)
{
	color(15);
    for(int i=31; i < 99; i++)
	{
    	//PARTE SUPERIOR
    	for(int j=4;j<numero;j++){
            gotoxy (i, j); printf(" ");
    	}
    }
}
