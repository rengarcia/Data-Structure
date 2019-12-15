#include <windows.h>
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "ListaEnlazada.h"
#include "ListaComida.h"

/*
	Universidad de las Fuerzas Armdas
	Miembros: Kevin Zurita
	NRC:2967
	Fecha de creacion:17 de noviembre del 2019
	Fecha de modificacion:11 de diciembre de 2019
	Profesor: Ing. Fernando Solis
*/
void OcultaCursor() {
 CONSOLE_CURSOR_INFO cci = {100, FALSE};
 
 SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}

int main()
{
	srand (time(NULL)); 
	int xCuerpo=30;
	int xComida, yComida=5, valorComida, control=0,elementos=0, gameover=yComida;
	ListaEnlazada listE;	//Lista declara para el cuerpo
	ListaComida list;		//lista declarada para los numeros que caen
	listE.insertarPrimero(0);	//Inicio del cuerpo
 	OcultaCursor();				//se oculta el cursor para que no se vea feo
	gotoxy(xCuerpo,23);
	printf("%s",listE.crearLinea()); // se usa una funcion para transformar los numeros en una linea char* para facilidad de impresion
	char c;
	while(c!=27&&gameover<=23){	//condicion de salida persionar esc y perdida sii los numeros sobreapasan cierto punto, ademas que repite las acciones
		while(!kbhit()){//condicion para que se mueva el juego mientras no se haga nada
				system("cls");	//se borra la pantalla ne cada iteracion para reimprimir los nueros con el efecto de caida
				gotoxy(xCuerpo,23);	//posivion del cuerpo
				printf("%s",listE.crearLinea());
			valorComida=rand()%10;	//valor aleatorio de la comida
			xComida=rand()%77+1;		//posicion aleatoria de la comida
			list.insertarPrimero(valorComida,yComida,xComida); //se inserta la comida con posicion y valor dey
			elementos++;//se suma la cuenta de elementos
			list.imprimirComida(elementos);	//se indica cuantos elementos se puede imprimir ya que se basa en eso apra las posiciones
			if(list.comprobarElementos(xComida,23,elementos,listE.numeroElementos())){	//comprueba si la posicionde el cuerpo y la comdia mas inferior es la misma
				listE.insertarPrimero(list.quitarElemento());//elimina el uultimo elemento de la comida y lo agrega al cuerpo
				elementos--;//resta un lementos
			}
			gameover=yComida+(elementos*2);//comprobacion de game over
			Sleep(150);//Timer para la generacion de elementos
		}
		c=getch();//getch y switch para los movimientos
		switch(c){
			case 75://movimiento de izquierda y reimpresion de cuerpo
				xCuerpo-=1;
				if(xCuerpo<1) xCuerpo=1;
				gotoxy(xCuerpo,23);
				printf("%s",listE.crearLinea());
				gotoxy(xCuerpo+1,23);
				printf(" ");
				break;
			case 77://movimiento de derecha y reimpresion del cuerpo
				xCuerpo+=1;
				if(xCuerpo>78) xCuerpo=78;
				gotoxy(xCuerpo,23);
				printf("%s",listE.crearLinea());
				gotoxy(xCuerpo-1,23);
				printf(" ");
				break;
		if(list.comprobarElementos(xComida,23,elementos,listE.numeroElementos())){//comprobacion en caso de movimientos
				listE.insertarPrimero(list.quitarElemento());
				elementos--;
			}
		}
	}
 return 0;
}
