/**
	Universidad de las Fuerzas Armadas ESPE
    Nombre: Luis Carvajal, Elian Llorente
    NRC: 2967
    Fecha creacion: 30/11/2019
	Fecha ultima modificacion:	12/12/2019
	Docente: Ing. Fernando Solis
*/

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <ctype.h>
#include <string.h>
#include <fstream>
#include <string>
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



/**
 * @brief Funcion que genera los cubos en el tablero del juego
 * @param numero cubo de un color especifico para cada numero del 1-9
 * @param x coordenada 
 * @param y coordenada
 */
void numbers(int numero,int x,int y)
{
	switch(numero){
		case 0:
				color(1);//num 0 azul
				gotoxy(x,y++);
				printf("%c%c%c%c",219,219,219,219);gotoxy(x,y++);
				printf("%c0%c%c",219,219,219);gotoxy(x,y++);
				color(15);//num 0 azul

				break;

			case 1:
				color(2);// 1 verde
				gotoxy(x,y++);
				printf("%c%c%c%c",219,219,219,219);gotoxy(x,y++);
				printf("%c1%c%c",219,219,219);gotoxy(x,y++);
				break;


			case 2:
				color(11);// 2 celeste
				gotoxy(x,y++);
				printf("%c%c%c%c",219,219,219,219);gotoxy(x,y++);
				printf("%c2%c%c",219,219,219);gotoxy(x,y++);
				break;


			case 3:
				color(12);// 3 rojo
				gotoxy(x,y++);
				printf("%c%c%c%c",219,219,219,219);gotoxy(x,y++);
				printf("%c3%c%c",219,219,219);gotoxy(x,y++);
				break;

			case 4:
				color(5);// 4 morado
				gotoxy(x,y++);
				printf("%c%c%c%c",219,219,219,219);gotoxy(x,y++);
				printf("%c4%c%c",219,219,219);gotoxy(x,y++);
				break;

			case 5:
				color(6);// 5 amarillo
				gotoxy(x,y++);
				printf("%c%c%c%c",219,219,219,219);gotoxy(x,y++);
				printf("%c5%c%c",219,219,219);gotoxy(x,y++);
				break;

			case 6:
				color(15);// 6 blanco
				gotoxy(x,y++);
				printf("%c%c%c%c",219,219,219,219);gotoxy(x,y++);
				printf("%c6%c%c",219,219,219);gotoxy(x,y++);
				break;

			case 7:
				color(8);// 7 gris
				gotoxy(x,y++);
			    printf("%c%c%c%c",219,219,219,219);gotoxy(x,y++);
				printf("%c7%c%c",219,219,219);gotoxy(x,y++);
				break;

			case 8:
				color(13);// 8 mas celeste
				gotoxy(x,y++);
				printf("%c%c%c%c",219,219,219,219);gotoxy(x,y++);
				printf("%c8%c%c",219,219,219);gotoxy(x,y++);
			    break;

			case 9:
				color(10);// 9 verde claro
				gotoxy(x,y++);
				printf("%c%c%c%c",219,219,219,219);gotoxy(x,y++);
				printf("%c9%c%c",219,219,219);gotoxy(x,y++);
			    break;
		}
}
/**
 * @brief Funcion que genera el margen del Juego
 */
void margen()
{
	color(15);
    for(int i=30; i < 99; i++)
	{
    	//PARTE SUPERIOR
    	gotoxy (i, 3); printf("%c",177);
    	//PARTE INFERIOR
        gotoxy(i, 40); printf("%c",177);
    }
    for(int j=3; j < 40; j++)
	{
    	//PARTE IZQUIERDA
        gotoxy (30,j);  printf("%c",177);
        //PARTE DERECHA
        gotoxy(99,j);  printf("%c",177);
    }
    //ESQUINAS
    color(15);
    gotoxy(99,40);	printf("%c",177);

}
