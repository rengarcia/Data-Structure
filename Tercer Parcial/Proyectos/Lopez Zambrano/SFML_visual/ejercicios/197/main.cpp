/* Ejercicio N 197:
Una de las tecnicas de criptografia mas rudimentarias consiste en sustituir cada uno de los caracteres por otro situado
n posiciones mas a la derecha. Si n = 2, por ejemplo, sustituiremos la (a) por la (c), la (b) por la (e), y asi sucesivamente.
El problema que aparece en las ultimas n letras del alfabeto tiene facil solucion: en el ejemplo, la letra (y) se sustituira por
la (a) y la letra (z) por la (b). La sustitucion debe aplicarse a las letras minusculas y mayusculas y a los d´ıgitos (el (0) se
sustituye por el (2), el (1) por el (3) y ası hasta llegar al (9), que se sustituye por el (1)).
Disena un programa que lea un texto y el valor de n y muestre su version criptografiada.

Ejercicio N 198:
Disena un programa que lea un texto criptografiado siguiendo la tecnica descrita en el apartado anterior y el valor
de n utilizado al encriptar para mostrar ahora el texto decodificado.
*/

#include <iostream>
#include <cstdio>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include <string>
#include "Validacion.h"
#include "Operaciones.h"
using namespace std;

#define ARRIBA 72
#define ABAJO  80 
#define ENTER  13

void menuCursor();
void menu();
void gotoxy(int x, int y);
void Selector(int i);


int main() {
	for (;;) {
		menuCursor();
	}
	return 0;
}
void menuCursor() {

	Validacion validacion;
	Operaciones operacion;
	string frase;
	string aux;
	int n;


	int i = 0;
	Selector(i);
	menu();
	gotoxy(3, 1);
	char tecla;

	while (true) {
		tecla = _getch();

		switch (tecla) {
		case ARRIBA:
			i--;
			if (i < 0) {
				i = 3;
			}
			Selector(i);
			break;

		case ABAJO:
			i++;
			if (i == 0) {
				i = 1;
			}
			if (i == 3) {
				i = 0;
			}
			Selector(i);
			break;

		case ENTER:
			Selector(3);

			switch (i) {
			case 0:
				cout << endl << endl;
				cout << "Ingrese la frase: " << endl;
				getline(cin, frase);
				cout << "Ingrese el valor de n: " << endl;
				cin >> aux;
				while ((getchar()) != '\n');
				aux = validacion.soloNumeros(aux);
				n = stoi(aux);
				n = validacion.valorN(n);

				frase = validacion.soloLetrasyNumeros(frase);
				frase = operacion.aMinusculas(frase);
				frase = operacion.Encriptar(frase, n);

				cout << "La frase incriptada es: " << endl;
				cout << frase << endl;

				system("pause");
				break;

			case 1:
				cout << endl << endl;
				cout << "Ingrese la frase: " << endl;
				getline(cin, frase);
				cout << "Ingrese el valor de n: " << endl;
				cin >> aux;
				while ((getchar()) != '\n');
				aux = validacion.soloNumeros(aux);
				n = stoi(aux);
				n = validacion.valorN(n);

				frase = validacion.soloLetrasyNumeros(frase);
				frase = operacion.aMinusculas(frase);
				frase = operacion.Desencriptar(frase, n);

				cout << "La frase Desencriptada es: " << endl;
				cout << frase << endl;

				system("pause");
				break;

			case 2:
				cout << endl << endl;
				cout << "Saliendo del programa" << endl;
				exit(0);

			}
			system("cls");
			menu();
			gotoxy(3, 1);
			break;
		}
	}
}

void menu() {
	system("cls");
	cout << "|*********************Menu*************************|" << endl;
	cout << "\tEncriptar frase" << endl;
	cout << "\tDesencriptar frase" << endl;
	cout << "\tSalir del programa" << endl;
	cout << "|**************************************************|" << endl;
}

void gotoxy(int x, int y) {
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}

void Selector(int i) {
	gotoxy(1, 1 + i);
}
