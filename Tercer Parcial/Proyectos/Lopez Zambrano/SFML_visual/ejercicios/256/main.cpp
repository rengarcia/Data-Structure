/* Ejercicio N 256:
Disena un programa que diga si una matriz es o no es diagonal superior.*/
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
	
		bandera = matriz.esTringular(matrizAux,dimFil,dimCol);
		
		if (bandera) {
			cout << endl <<"La matriz es triangular superior " << endl;
		}
		else
		{
			cout << endl <<"La matriz no es traingular superior" << endl;
		}


		cout << endl << "******Presione ESC para salir o ENTER para continuar******" << endl << endl;
		system("pause");
		system("cls");
	}

	return 0;
}