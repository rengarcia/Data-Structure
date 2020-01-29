/* Ejercicio N 250:
Dise˜na un programa que lea dos matrices y calcule la diferencia entre la primera y la segunda*/

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
	int** matrizAux1;
	int** matrizAux2;
	int** resultado;
	int dim;
	string aux;

	while (GetAsyncKeyState(VK_ESCAPE) == 0) {

		cout << "Ingrese la dimension para las matrices: ";
		cin >> aux;
		aux = validacion.dimValida(aux);
		dim = stoi(aux);

		cout << "Ingrese los valores de la primera matriz: ";
		matrizAux1 = matriz.generar(dim);
		matriz.encerar(matrizAux1,dim);
		matriz.ingreso(matrizAux1,dim);
		matriz.imprime(matrizAux1,dim);

		cout << endl;
		cout << "Ingrese los valores de la segunda matriz: ";
		matrizAux2 = matriz.generar(dim);
		matriz.encerar(matrizAux2, dim);
		matriz.ingreso(matrizAux2, dim);
		matriz.imprime(matrizAux2, dim);

		cout << endl;
		cout << "El resultado de la resta de matrices es: "<<endl;
		resultado = matriz.resta(matrizAux1, matrizAux2, dim);
		matriz.imprime(resultado, dim);

		cout << endl << "******Presione ESC para salir o ENTER para continuar******" << endl << endl;
		system("pause");
		system("cls");
	}


	return 0;
}