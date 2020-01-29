/* Ejercicio N 394:
Disena un modulo que facilite el trabajo con conjuntos. Recuerda que un conjunto es una lista en la que no hay
elementos repetidos. Deber´as implementar las siguientes funciones:

	lista_a_conjunto(lista): Devuelve un conjunto con los mismos elementos que hay en lista, pero sin repeticiones. (Ejemplo:
	lista_a_conjunto([1,1,3,2,3]) devolvera la lista [1, 2, 3] (aunque tambien se acepta como equivalente cualquier
	permutacion de esos mismos elementos, como [3,1,2] o [3,2,1]).

	union(A, B): devuelve el conjunto resultante de unir los conjuntos A y B.
	
	interseccion(A, B): devuelve el conjunto cuyos elementos pertenecen a A y a B.
	
	diferencia(A, B): devuelve el conjunto de elementos que pertenecen a A y no a B.
	
	iguales(A, B): devuelve cierto si ambos conjuntos tienen los mismos elementos, y falso en caso contrario. (Nota: ten
	en cuenta que los conjuntos representados por las listas [1, 3, 2] y [2, 1, 3] son iguales.)
*/

#include "Nodo.h"
#include "Operaciones.h"
#include "OperacionesSet.h"
#include <set> 
#include <iostream>
#include <cstdio>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include <iostream>


using namespace std;

#define ARRIBA 72
#define ABAJO  80 
#define ENTER  13

void menuCursor();
void menu();
void gotoxy(int x, int y);
void Selector(int i);


Operaciones operacion;
OperacionesSet operacionSet;
Nodo* lista = NULL;
string frase;
set <int> setA;
set <int> setB;
set <int> setAux;


int main() {

	cout << "Ingrese los datos para el conjunto A, separalos usando SOLO el espacio " << endl;
	cout << "Ejemplo :  1 2 3 45 15" << endl;
	getline(cin, frase);
	frase = operacion.convertir(frase);
	setA = operacionSet.InsertarDatosSet(frase);
	operacionSet.imprimir(setA);

	cout << endl <<"Ingrese los datos para el conjunto B, separalos usando SOLO el espacio " << endl;
	getline(cin, frase);
	frase = operacion.convertir(frase);
	setB = operacionSet.InsertarDatosSet(frase);
	operacionSet.imprimir(setB);

	system("pause");
	system("cls");

	for (;;) {
		menuCursor();
	}

	return 0;

}
void menuCursor() {
	

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
			if (i == 6) {
				i = 0;
			}
			Selector(i);
			break;

		case ENTER:
			Selector(5);

			bool bandera;


			switch (i) {
			case 0:
				cout << endl << endl;
				cout << "Ingrese los datos para la lista, separalos usando SOLO el espacio " << endl;
				cout << "Ejemplo :  1 2 3 45 15" << endl;
				getline(cin, frase);
				frase = operacion.convertir(frase);
				lista = operacion.Insertar(frase);

				setAux = operacionSet.Lista_a_Conjunto(lista);
				operacionSet.imprimir(setAux);

				system("pause");
				break;

			case 1:
				cout << endl << endl;
				setAux = operacionSet.Union(setA, setB);
				operacionSet.imprimir(setAux);
				system("pause");
				break;

			case 2:
				cout << endl << endl;
				setAux = operacionSet.Interseccion(setA, setB);
				operacionSet.imprimir(setAux);
				system("pause");
				break;

			case 3:
				cout << endl << endl;
				setAux = operacionSet.Diferencia(setA, setB);
				operacionSet.imprimir(setAux);
				system("pause");
				break;

			case 4:
				cout << endl << endl;
				bandera = operacionSet.sonIguales(setA, setB);
	
				if (bandera)
					cout << "Son iguales" << endl;
				else
					cout << "No son iguales" << endl;

				system("pause");
				break;

			case 5:
				
				cout << endl << endl << "Saliendo del programa" << endl;
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
	cout << "\tLista a conjunto" << endl;
	cout << "\tUnion(A, B)" << endl;
	cout << "\tInterseccion(A, B)" << endl;
	cout << "\tDiferencia(A, B)" << endl;
	cout << "\tIguales(A, B)" << endl;
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
