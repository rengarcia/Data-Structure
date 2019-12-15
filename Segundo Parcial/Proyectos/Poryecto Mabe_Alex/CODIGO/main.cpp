/**************************************************************
 *	Universidad de las Fuerzas Armadas ESPE
 *	Maria Belen Ceron, Alex Chicaiza
 *	NRC: 2967
 *	Fecha creacion: 08/11/2019
 *	Fecha ultima modificacion:	12/12/2019
 *	Docente: Ing. Fernando Solis
***************************************************************/
#include <iostream>
#include <windows.h>
#include <conio.h>
#include "Cifrado.h"
#include "PersonalLibrary.h"
#include "ListaDoble.h"

#define ARRIBA     72
#define IZQUIERDA  75
#define DERECHA    77
#define ABAJO      80


int cont = 15;
using namespace std;

int i=21;
Cifrado si;
ListaDoble ObjJuego;
void seleccionarOpcion(char tecla);
void menuinicio(char tecla);


void dibujarCuadro() {
	cout << "\t\t==========================================================\n";
	cout << "\t\t||							||\n";
	cout << "\t\t||							||\n";
	cout << "\t\t||							||\n";
	cout << "\t\t||							||\n";
	cout << "\t\t||							||\n";
	cout << "\t\t||							||\n";
	cout << "\t\t||							||\n";
	cout << "\t\t||							||\n";
	cout << "\t\t==========================================================\n";
}

void bran(int cont) {
	gotoxy(18, cont);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	cout << ">";
}
void gotoxy(short posicionx, short posiciony) {
	COORD coordenadaPosicion = { posicionx, posiciony };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordenadaPosicion);
}

void empezarProgramas(string nombre) {
	ShellExecute(NULL, "open", nombre.c_str(), NULL, NULL, SW_SHOWNORMAL);
}
void menu() {
    //system("Color 7A");
	gotoxy(0, 0);
	cout << "*********************************************************************************************************************";
	gotoxy(0, 2);
	cout << "*********************************************************************************************************************";
	gotoxy(0, 3); dibujarCuadro();
	gotoxy(0, 13); dibujarCuadro();
	gotoxy(10, 5); cout << "\t\tUNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE\n\t\t\t* Alex Chicaiza\n\t\t\t* Maria Belen Ceron\n\t\t\tNRC: 2967\n\t\t\tDocente: Ing. Fernando Solis" << endl;
	gotoxy(42, 14); cout << "MENU" << endl;
	gotoxy(18, 15); cout << " 1- JUGAR\n";
	gotoxy(18, 16); cout << " 2- DESARROLLADORES\n";
	gotoxy(18, 17); cout << " 3- GENERAR PDF\n";
	gotoxy(18, 18); cout << " 4- CIFRADO\n";
	gotoxy(18, 19); cout << " 5- MOSTRAR IMAGEN EN CONSOLA\n";
	gotoxy(18, 20); cout << " 6- AYUDA\n";
	gotoxy(18, 21); cout << " 7- SALIR\n";
	gotoxy(18, cont);
	//bran(cont);
	cout << ">";
	if (_kbhit()) {
		switch (_getch()) {

		case ARRIBA:
			if (cont < 16) {
				cont = 22;
			}
			cont--;
			break;
		case ABAJO:
			if (cont > 20) {
				cont = 14;
			}
			cont++;
			break;

		case 13:
			switch (cont) {
			case 15:
				system("cls");
				ObjJuego.juegoTetris();
				system("pause");
				break;

			case 16:
				system("cls");
				empezarProgramas("Desarrolladores.png");
				system("pause");
				break;

			case 17:
				system("cls");
				system("txt2pdf.exe solucion.txt respuestas.pdf -oao -pfs60 -pps43 -ptc0 -width3000 -height2000");
				system("pause");
				break;
			case 18:
				system("cls");
				cout<<"Encriptador\n";
				si.encriptado();
				cout<<"DEncriptador\n";
				si.desencriptado();
				Sleep(200);
				//system("pause");
				break;
			case 19:
				system("cls");

				system("pause");
				break;

			case 20:
				system("cls");
				empezarProgramas("Tetris.chm");
				system("pause");
				break;


			case 21:
				system("cls");
				std::cout << "\tGracias por usar nuestra aplicacion" << std::endl;
				exit(0);
                default:
				break;
			}
			system("cls");
			menu();
			//gotoxy(3, 1);
			break;
		}
	}
}
//ESTA PARTE
void subMenu() {
	int cont2 = 4;

	gotoxy(0,4); cout << "1. Encriptar" << endl;
	gotoxy(0,5); cout << "2. DesEncriptar" << endl;

	gotoxy(0, cont2);
	cout << ">";

	if (_kbhit()) {
		switch (_getch()) {

		case ARRIBA:
			if (cont2 < 4) {
				cont2 = 5;
			}
			cont2--;
			break;
		case ABAJO:
			if (cont2 > 5) {
				cont2 = 4;
			}
			cont2++;
			break;

		case 13:
			switch (cont2) {
			case 4:
				system("cls");
				cout << "hola";
				system("pause");
				break;

			case 5:
				system("cls");
				cout << "Adios";
				system("pause");
			default:
				break;
			}
			system("cls");
			subMenu();

			break;
		}
	}
	system("pause");
}



int main()
{
	AltEnter();
    char tecla;
    int a, b, c, n = 0, letra = 39, pos = 1, cont = 39, aux, cont1 = 39, auxg;
	char t[50] = "BIENVENIDO AL JUEGO DEL TETRIS", auxt[39] = " ";
	gotoxy(0, 0);
	cout << "*********************************************************************************************************************";
	gotoxy(0, 2);
	cout << "*********************************************************************************************************************";
	gotoxy(0, 3); dibujarCuadro();

	gotoxy(0, 13); dibujarCuadro();


	do {
		for (a = 0; a < 30; a++) {
			aux = pos;
			for (b = 39; b > cont; b--) {
				gotoxy(pos, 1);
				cout << t[b];
				menu();
				pos--;
			}
			aux++;
			pos = aux;
			cont--;
			Sleep(75);
			if (a == 40) {
				break;
			}
		}
		for (a = 3; a < 70; a++) {
			gotoxy(a - 1, 1);
			cout << " ";
			gotoxy(a, 1);
			cout << t;
			menu();
			Sleep(75);
		}

		pos = 70;

		auxg = 69;
		for (a = 0; a < 41; a++) {
			gotoxy(auxg, 1);
			cout << " ";
			aux = pos;
			for (b = 0; b <= cont1; b++) {
				gotoxy(pos, 1);
				cout << t[b];
				pos++;
				menu();
			}
			cont1--;
			aux++;
			pos = aux;
			auxg++;

			Sleep(75);
		}
		cont1 = 39;
		letra = 39;
		pos = 1;
		cont = 39;
		c = 0;



	} while (c = 1);


system("pause>null");

return 0;
}


void seleccionarOpcion(char tecla){

gotoxy(30, i); cout<<" ";

if( tecla == ABAJO && i <=24 ){

    if(i==24){
        i=20;
    }
    i++;

}
if( tecla == ARRIBA && i>= 21){
    if(i==21){
        i=25;
    }
    i--;
}

if( tecla == 13 ){

    if( i == 21 ){
		system("cls");

    	ObjJuego.juegoTetris(); // metodo que comienza el juego

      }

    if( i == 22 ){
    	system("cls");
    	system("help.chm");
    	system("pause");
		system("cls");
	}
    if( i == 23 ){
    		system("cls");
    		ObjJuego.impresion();
    		system("pause");
			system("cls");
	}
    if( i == 24 ){

    	system("cls");
		cout<<"\n\n\n||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||";
		cout<<"\n||||                                                                      ||||\n";
		cout<<  "||||                                                                      ||||";
		cout<<"\n||||                  GRACIAS POR USAR ESTE PROGRAMA                      ||||";
		cout<<"\n||||               ESPERAMOS QUE HAYA SIDO DE TU AGRADO                   ||||";
		cout<<"\n||||                                                                      ||||";
		cout<<"\n||||                                                                      ||||";
		cout<<"\n||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n\n\n";
		system("pause");
		exit(0);

	}
}


   gotoxy(30, i); cout<<">";
}



void menuinicio(char tecla){

}
