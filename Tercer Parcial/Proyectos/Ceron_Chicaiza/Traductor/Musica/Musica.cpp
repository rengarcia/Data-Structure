/*******************************************************************
 *	Universidad de las Fuerzas Armadas ESPE
 *	Alex Chicaiza
 *	Maria Belen Ceron
 *	NRC: 2967
 *	Fecha creacion: 19/01/2020
 *	Fecha ultima modificacion:	26/01/2020
 *	Docente: Ing. Fernando Solis
******************************************************************/

/***********************************************************************
 * Module:  Musica.cpp
 * Modified: Sunday, January 19, 2020 4:00:49 PM
 * Purpose: Implementation of the class ABBI
 ***********************************************************************/

#include <iostream>
#include <Windows.h>
#include <MMSystem.h>
#include <fstream>
#include <string>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include "Ingresar.h"
#include "Cifrado.h"
#include "ABBI.h"

#define ARRIBA     72
#define IZQUIERDA  75
#define DERECHA    77
#define ABAJO      80
#define ENTER      13

using namespace std;

int cont = 16;

void gotoxy(short posicionx, short posiciony);
void dibujarCuadro(int x,int y);
void menu();
void reproducir(string cancion);

void leerArchivo();
void traductorInglesEspanol();
void traductorEspanolIngles();
void opcionSonido(string ingles, string espanol);
void empezarProgramas(string nombre);
void solucionTxt();
ABBI* arbolIngles = NULL;
ABBI* arbolEsp = NULL;



int main()
{
	system("Color 3F");
	leerArchivo();
	solucionTxt();

	//system("pause");
	int a, b, c, n = 0, letra = 39, pos = 1, cont = 39, aux, cont1 = 39, auxg;
	char t[50] = "BIENVENIDO AL TRADUCTOR INGLES - ESPANOL", auxt[39] = " ";
	gotoxy(0, 0);
	cout << "*********************************************************************************************************************";
	gotoxy(0, 2);
	cout << "*********************************************************************************************************************";

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
			Sleep(100);
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
			Sleep(100);
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

			Sleep(100);
		}
		cont1 = 39;
		letra = 39;
		pos = 1;
		cont = 39;
		c = 0;



	} while (c = 1);
	
    system("pause");
    return 0;
}

void reproducir(string cancion) {
	
	if (cancion.compare(" ") != 0) {
		char sonido[20];

		// copying the contents of the 
		// string to char array 
		strcpy(sonido, cancion.c_str());
		strcat(sonido, ".wav");

		wchar_t wtext[20];
		mbstowcs(wtext, sonido, strlen(sonido) + 1);//Plus null
		LPWSTR ptr = wtext;

		//Reproducir musica
		PlaySound(ptr, NULL, SND_SYNC);
	}
}

void gotoxy(short posicionx, short posiciony) {
	COORD coordenadaPosicion = { posicionx, posiciony };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordenadaPosicion);
}

void dibujarCuadro(int x, int y) {
	gotoxy(x, y++); cout << "==========================================================";
	gotoxy(x, y++); cout << "||							 ||";
	gotoxy(x, y++); cout << "||							 ||";
	gotoxy(x, y++); cout << "||							 ||";
	gotoxy(x, y++); cout << "||							 ||";
	gotoxy(x, y++); cout << "||							 ||";
	gotoxy(x, y++); cout << "||							 ||";
	gotoxy(x, y++); cout << "||							 ||";
	gotoxy(x, y++); cout << "||							 ||";
	gotoxy(x, y++); cout << "||							 ||";
	gotoxy(x, y++); cout << "||							 ||";
	gotoxy(x, y++); cout << "==========================================================";
}


void menu() {
	//system("Color 7A");
	Cifrado cifrar;
	gotoxy(0, 0);
	cout << "*********************************************************************************************************************";
	gotoxy(0, 2);
	cout << "*********************************************************************************************************************";
	dibujarCuadro(17,3);
	gotoxy(22, 5); cout << "UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE";
	gotoxy(20, 7); cout << "*Alex Chicaiza";
	gotoxy(20, 8); cout << "*Maria Belen Ceron";
	gotoxy(20, 9); cout << "NRC: 2967";
	gotoxy(20, 10); cout << "Docente: Ing.Fernando Solis";

	dibujarCuadro(17, 14);
	gotoxy(42, 15); cout << "MENU";
	gotoxy(20, 16); cout << "   1- ENGLISH to SPANISH";
	gotoxy(20, 17); cout << "   2- ESPANOL a INGLES";
	gotoxy(20, 18); cout << "   3- DESARROLLADORES";
	gotoxy(20, 19); cout << "   4- GENERAR PDF";
	gotoxy(20, 20); cout << "   5- ENCRIPTAR";
	gotoxy(20, 21); cout << "   6- DESENCRIPTAR";
	gotoxy(20, 22); cout << "   7- MOSTRAR IMAGEN EN CONSOLA";
	gotoxy(20, 23); cout << "   8- AYUDA";
	gotoxy(20, 24); cout << "   9- SALIR";
	gotoxy(20, cont);
	//bran(cont);
	cout << "==>";

	if (_kbhit()) {
		switch (_getch()) {
			case ARRIBA:
				if (cont < 17) {
					cont = 25;
				}
				cont--;
				break;
			case ABAJO:
				if (cont > 23) {
					cont = 15;
				}
				cont++;
				break;

			case ENTER:
				switch (cont) {
				case 16:/*1- ENGLISH to SPANISH*/
					system("cls");
					traductorInglesEspanol();
					system("pause");
					break;

				case 17:/*2- ESPANOL a INGLES*/
					system("cls");
					traductorEspanolIngles();
					system("pause");
					break;

				case 18:/*3- DESARROLLADORES*/
					system("cls");
					empezarProgramas("Desarrolladores.png");
					system("pause");
					break;

				case 19:/*4- GENERAR PDF"*/
					system("cls");
					system("txt2pdf.exe solucion.txt respuestas.pdf -oao -pfs60 -pps43 -ptc0 -width3000 -height2000");
					system("pause");
					break;
				case 20:/*5- INCRIPTAR*/
					system("cls");
					cout << "\n\n\tDOCUMENTO ENCRIPTADO\n";
					cifrar.encriptado();
					Sleep(200);
					system("pause");
					break;
				case 21:/*6- DESINCRIPTAR*/
					system("cls");
					cout << "\n\n\tDOCUMENTO DESENCRIPTADO\n";
					cifrar.desencriptado();
					Sleep(200);
					system("pause");
				case 22:/*7- MOSTRAR IMAGEN EN CONSOLA*/
					system("cls");
					empezarProgramas("Logotipo.exe");
					system("pause");
					break;

				case 23:/*8- AYUDA*/
					system("cls");
					empezarProgramas("Traductor.chm");
					system("pause");
					break;


				case 24:/*9- SALIR*/
					system("cls");
					std::cout << "\tGracias por usar nuestra aplicacion" << std::endl;
					delete arbolEsp;
					delete arbolIngles;
					Sleep(1500);
					exit(0);
				default:
					break;
				}
				system("cls");
				menu();
				gotoxy(3, 1);
				break;
			}
	}
}


void leerArchivo() {

	string ingles;
	string espanol;

	ifstream archivoI;
	ifstream archivoE;

	archivoI.open("PalabrasIngles.txt", ios::in);
	archivoE.open("PalabrasEspanol.txt", ios::in);

	while (!archivoI.eof() && !archivoE.eof()) {
		getline(archivoI, ingles);
		getline(archivoE, espanol);

		arbolIngles->insertarNodo(ingles, espanol, arbolIngles);
		arbolEsp->insertarNodo(espanol, ingles,arbolEsp);
	}
	archivoI.close();
	archivoE.close();
}

void traductorInglesEspanol() {

	system("cls");
	Ingreso leer;
	fstream enter;
	enter.open("solucion.txt", fstream::app);
	string ingles;
	string espanol;
	char* buscar = (char*)(malloc(sizeof(char)));
	bool bandera = true;

	cout << endl << endl;
	string msg1 = "INGRESE LA PALABRA EN INGLES:  ";
	ingles = leer.ingresarLetras(msg1);
	
	strcpy(buscar, ingles.c_str());
	_strupr(buscar);

	espanol = arbolIngles->buscar(arbolIngles, buscar);

	if (espanol.compare(" ") == 0) {
		espanol = "PALABRA NO EXISTE EN LA BASE DE DATOS";
		cout << "\t" << espanol << endl;
		bandera = false;
	}

	if (!bandera) {
		opcionSonido(" ", " ");
	}
	else {
		opcionSonido(buscar, espanol);
	}
	enter << "\tTRADUCCION INGLES ESPANOL" << endl;
	enter << "\t" << buscar << "\t-\t" << espanol << endl<<endl;

}

void traductorEspanolIngles() {

	system("cls");
	Ingreso leer;
	fstream enter;
	enter.open("solucion.txt", fstream::app);
	string palabra;
	string resultado;
	char* buscar = (char*)(malloc(sizeof(char)));
	bool bandera = true;
	cout << endl << endl;
	string msg1="INGRESE LA PALABRA EN ESPANOL:  ";
	palabra=leer.ingresarLetras(msg1);

	// copying the contents of the 
	// string to char array 
	strcpy(buscar, palabra.c_str());
	_strupr(buscar);

	resultado = arbolEsp->buscar(arbolEsp, buscar);

	if (resultado.compare(" ") == 0) {
		resultado = "PALABRA NO EXISTE EN LA BASE DE DATOS";
		cout << "\n\t" << resultado << endl;
		bandera = false;
	}
	
	if (!bandera) {
		opcionSonido(" ", " ");
	}
	else {
		opcionSonido(resultado, buscar);
	}
	enter << "\tTRADUCCION ESPANOL INGLES" << endl;
	enter << "\t" << buscar << "\t-\t" << resultado << endl << endl;
}

void opcionSonido(string ingles, string espanol) {

	int flecha = 6;
	bool bandera = true;
	do {
		gotoxy(2, 6); cout << "   1. Sonido espanol";
		gotoxy(2, 7); cout << "   2. Sonido ingles";
		gotoxy(2, 8); cout << "   3. Salir";
		gotoxy(2, flecha); cout << "==>";
		switch (_getch())
		{
		case ARRIBA:
			flecha--;
			if (flecha < 6) {
				flecha = 8;
			}
			break;
		case ABAJO:
			flecha++;
			if (flecha > 8) {
				flecha = 6;
			}
			break;
		case ENTER:
			switch (flecha)
			{
			case 6:
				reproducir(espanol);
				break;
			case 7:
				reproducir(ingles);
				break;
			case 8:
				bandera = false;
				break;
			default:
				break;
			}
		default:
			break;
		}
	} while (bandera);
	gotoxy(0, 11);
}


void empezarProgramas(string nombre) {
	char s[] = "open";
	wchar_t wtext[5];
	mbstowcs(wtext, s, strlen(s) + 1);
	LPWSTR ptr = wtext;

	char n[20];
	strcpy(n, nombre.c_str());
	wchar_t wtext2[20];
	mbstowcs(wtext2, n, strlen(n) + 1);
	LPWSTR ptr2 = wtext2;

	ShellExecute(NULL, ptr, ptr2, NULL, NULL, SW_SHOWNORMAL);
}

void solucionTxt() {
	fstream enter;
	enter.open("solucion.txt", fstream::out); //para leer in, para salir es out escribir
	enter << "\n\n\t\t\tUNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE\n" << endl;
	enter << "\t\t\t\tINGENIERIA DE SOFTWARE" << endl<<endl;
	enter << "  Ingrantes: " << endl;
	enter << "\t\t\t-Maria Belen Ceron" << endl;
	enter << "\t\t\t-Alex Chicaiza" << endl;
	enter << "\n\n\t\t\tSOLUCIONES " << endl << endl;
	enter.close();
}
