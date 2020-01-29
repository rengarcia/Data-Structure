/* Ejercicio N 255:
Disena un programa que determine si una matriz es prima o no. Una matriz A es prima si la suma de los elementos
de cualquiera de sus filas es igual a la suma de los elementos de cualquiera de sus columnas.*/
/*NOTA: El usuario puede escoger las dimensiones de la matriz*/

#include <iostream>
#include <string>
#include "Matriz.h"
#include "Validacion.h"
#include <windows.h>
HANDLE h;

using namespace std;

int main() {
	Validacion validacion;
	Matriz matriz;
	int** matrizAux;
	int dimFil;
	int dimCol;
	string aux;
	bool bandera;

	while (GetAsyncKeyState(VK_ESCAPE) == 0) {

		cout << "Ingrese la dimension de las Filas: ";
		cin >> aux;
		aux = validacion.dimValida(aux);
		dimFil = stoi(aux);

		cout << "Ingrese la dimension de las Columnas: ";
		cin >> aux;
		aux = validacion.dimValida(aux);
		dimCol = stoi(aux);


		cout << "Ingrese los valores para la matriz: ";
		matrizAux = matriz.generar(dimFil,dimCol);
		matriz.encerar(matrizAux,dimFil,dimCol);
		matriz.ingreso(matrizAux,dimFil,dimCol);
	
		cout << endl << "La matriz actual : ";
		matriz.imprime(matrizAux,dimFil,dimCol);
		
		bandera = matriz.esPrima(matrizAux, dimFil, dimCol);
		
		if (bandera) {
			cout << "La matriz es Prima" << endl;
		}
		else
		{
			cout << "La matriz No es Prima" << endl;
		}

		cout << endl << "******Presione ESC para salir o ENTER para continuar******" << endl << endl;
		system("pause");
		system("cls");
	}

	return 0;
}