/* Ejercicio N 244:
Una matriz nula es aquella que solo contiene ceros. Construye una matriz nula de 5 filas y 5 columnas.*/
/*NOTA: Se genera una matriz cuadrada, se pide al usuario ingresar la dimension de la matriz*/

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
	int** matrizInt;
	int dim;
	string aux;

	while (GetAsyncKeyState(VK_ESCAPE) == 0) {
		cout << "Ingrese la dimension para la matriz: ";
		cin >> aux;
		aux = validacion.soloNumeros(aux);
		dim = stoi(aux);

		matrizInt = matriz.generar(dim);
		matriz.encerar(matrizInt,dim);
		matriz.imprime(matrizInt,dim);

		cout << endl << "******Presione ESC para salir o ENTER para continuar******" << endl << endl;
		system("pause");
		system("cls");
	}

	return 0;
}