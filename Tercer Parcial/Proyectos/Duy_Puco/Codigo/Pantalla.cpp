/***********************************************************************
 * Module:  Pantalla.cpp
 * Author:  Carlos Puco, Kevin Duy
 * Modified: sábado, 26 de noviembre de 2019 20:20:06
 * Purpose: Declaration of the class Pantalla
 ***********************************************************************/

#include "Pantalla.h"
#include <conio.h>

#define TECLA_ARRIBA 72
#define TECLA_ABAJO 80
#define TECLA_DERECHA 77
#define TECLA_IZQUIERDA 75
#define TECLA_ENTER 13

/**
 * @Funcion para moverse en coordenadas
 * @param x: coordenadas del eje de las abscisas
 * @param y: coordendas del eje de las ordenadas 
 */

void Pantalla::gotoxy(int x, int y) {
	HANDLE hCon;
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hCon,dwPos);
}

/**
 * @Funcion para dar color
 * @param x: coordenadas del eje de las abscisas
 * @param y: coordendas del eje de las ordenadas 
 */
void Pantalla::color(int x) {
	SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),x);
}

/**
 * @Funcion genera el formato de la pantalla
 * @param x: coordenadas del eje de las abscisas
 * @param y: coordendas del eje de las ordenadas 
 */
int Pantalla::menu(const char *titulo,const char*opciones[], int numero) {
	Pantalla pantalla;
	bool repite=true;
	int seleccionar=1,tecla;
	int i;
	system("cls");
	do {
		pantalla.gotoxy(10,2);
		pantalla.color(1);
		printf("================================================");
		pantalla.color(2);
		printf("\n\t\t\t%s\t\t\t\n\n",titulo);
		pantalla.color(3); 
		for(i=0;i<numero;i++)
			printf("\t\t%s\n",opciones[i]);		
		pantalla.gotoxy(16,4+seleccionar);
		pantalla.color(250);
		printf("%s",opciones[seleccionar-1]);
		pantalla.color(1);
		pantalla.gotoxy(10,15);
		printf("================================================");
		pantalla.color(5);
		do {
			tecla=getch();
		}while(tecla!=TECLA_ARRIBA && tecla!=TECLA_ABAJO && tecla!= TECLA_ENTER);
		switch(tecla) {
			case TECLA_ARRIBA: {
				seleccionar--;
				if(seleccionar==0)
					seleccionar=numero;			
			}
			break;
			case TECLA_ABAJO: {
				seleccionar++;
				if(seleccionar==numero+1)
					seleccionar=1;
			}
			break;
			case TECLA_ENTER:
				repite=false;
			break;
		}
	}while(repite);
	pantalla.color(7); 
	return seleccionar;
}
