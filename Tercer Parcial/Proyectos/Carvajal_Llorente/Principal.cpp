/**
	Universidad de las Fuerzas Armadas ESPE
    Nombre: Luis Carvajal, Elian Llorente
    NRC: 2967
    Fecha creacion: 12/01/2020
	Fecha ultima modificacion:	27/01/2020
	Docente: Ing. Fernando Solis
*/
#include "Arbol.h"
#include <cstdlib>
#include <stdio.h>
#include <time.h>
#include <ctime>
#include <conio.h>
#include <Windows.h>
#include <fstream>

#define ARRIBA 72
#define ABAJO 80
#define ENTER 13

typedef Arbol *arbol;
Arbol aux;

void llenarArbol(arbol&, arbol&);
void reproducir(string);
void traducir();
void gotoxy(int x, int y);
void Recuadro(const char titulo[]);
int DesplegarMenu(const char titulo[], const char *opciones[], int n);

int main()
{
	traducir();
	return 0;

}

void reproducir(string cad) {
	std::ofstream audio("reproducir.vbs");
	audio << "Dim SAPI" << endl;
	audio << "set SAPI = CreateObject (\"sapi.spvoice\")" << endl;
	audio << "SAPI.Speak" << "\"" << cad << "\"" << endl;
	audio.close();
	system("reproducir.vbs");
}

void llenarArbol(arbol &arbolIn, arbol &arbolEs) {
	string line;
	fstream archivo;
	archivo.open("traductor.txt", fstream::in);
	ifstream file("traductor.txt");
	if (file.is_open())
	{
		while (getline(file, line))
		{
			int id = atoi(line.substr(0, line.find(",")).c_str());
			string words = line.substr(line.find(",") + 1, line.length());
			aux.insertar(arbolIn, id, words.substr(0, words.find(",")));
			aux.insertar(arbolEs, id, words.substr(words.find(",") + 1, words.length()));
		}
		file.close();
		archivo.close();
	}
}

void Recuadro(const char titulo[])
{
	system("cls");
	system("color D");

	printf("\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB\n");
	printf("\xBA\t\t                                                              \xBA\n");
	printf("\xCC\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xB9\n");
	printf("\xBA                                                                             \xBA\n");
	printf("\xBA                                                                             \xBA\n");
	printf("\xBA                                                                             \xBA\n");
	printf("\xBA                                                                             \xBA\n");
	printf("\xBA                                                                             \xBA\n");
	printf("\xBA                                                                             \xBA\n");
	printf("\xBA                                                                             \xBA\n");
	printf("\xBA                                                                             \xBA\n");
	printf("\xBA                                                                             \xBA\n");
	printf("\xBA                                                                             \xBA\n");
	printf("\xBA                                                                             \xBA\n");
	printf("\xBA                                                                             \xBA\n");
	printf("\xBA                                                                             \xBA\n");
	printf("\xBA                                                                             \xBA\n");
	printf("\xBA                                                                             \xBA\n");
	printf("\xBA                                                                             \xBA\n");
	printf("\xBA                                                                             \xBA\n");
	printf("\xBA                                                                             \xBA\n");
	printf("\xBA                                                                             \xBA\n");
	printf("\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC\n");
}

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x; coord.Y = y;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hStdOut, coord);
}

int DesplegarMenu(const char titulo[], const char *opciones[], int n)
{
	int opcionSeleccionada = 1;
	int tecla;
	bool repite = true; 

	do {
		Recuadro(titulo);
		gotoxy(5, 3 + opcionSeleccionada); cout << "=>" << endl;

		gotoxy(30, 2); cout << titulo;

		for (int i = 0; i < n; ++i) {
			gotoxy(10, 4 + i); cout << (i + 1) << ") " << opciones[i];
		}

		do {
			tecla = _getch();
		} while (tecla != ARRIBA && tecla != ABAJO && tecla != ENTER);

		switch (tecla) {

		case ARRIBA:

			opcionSeleccionada--;

			if (opcionSeleccionada < 1) {
				opcionSeleccionada = n;
			}

			break;

		case ABAJO:
			opcionSeleccionada++;

			if (opcionSeleccionada > n) {
				opcionSeleccionada = 1;
			}

			break;

		case ENTER:
			repite = false;
			break;
		}

	} while (repite);

	return opcionSeleccionada;
}

void traducir() {

	string palabra, traduccion;
	arbol arbolIn = NULL;
	arbol arbolEs = NULL;
	bool val;
	int opc;
	llenarArbol(arbolIn, arbolEs);
	
	do
	{
		const char* titulo = "TRADUCTOR DE PALABRAS";
		const char* opciones[] = { "Traducir de Ingles a Espaniol", "Traducir de Espaniol a Ingles", "Ayuda", "Salir" };
		opc = DesplegarMenu(titulo, opciones, 4);

		switch (opc)
		{
		case 1:
			Recuadro(titulo);
			gotoxy(5, 3);
			cout << "Ingrese una palabra en ingles: ";
			cin >> palabra;
			for (int i = 0; i < palabra.length(); i++) {
				palabra[i] = tolower(palabra[i]);
			}
			//Inglés a español.
			traduccion = aux.Traducir(arbolIn, arbolEs, palabra);
			gotoxy(5, 5);
			cout << "Traduccion: " << traduccion << endl;
			reproducir(traduccion);
			gotoxy(5, 6);
			system("pause");
			break;

		case 2:
			Recuadro(titulo);
			gotoxy(5, 3);
			cout << "Ingrese una palabra en espaniol: ";
			cin >> palabra;
			for (int i = 0; i < palabra.length(); i++) {
				palabra[i] = tolower(palabra[i]);
			}
			//Español a inglés.
			traduccion = aux.Traducir(arbolEs, arbolIn, palabra);
			gotoxy(5, 5);
			cout << "Traduccion: " << traduccion << endl;
			reproducir(traduccion);
			gotoxy(5, 6);
			system("pause");
			break;
		case 3:
			Recuadro(titulo);
			gotoxy(5, 3);
			system("HelpTraductor.chm");
			system("pause");
			break;
		case 4:
			Recuadro(titulo);
			gotoxy(5, 3);
			cout << "Cerrando programa..." << endl;
			system("pause");
			break;
		}

	} while (opc != 4);
}
