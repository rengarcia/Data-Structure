/* Ejercicio N 130:
Haz un programa que calcule el maximo comun divisor (mcd) de tres enteros positivos. El mcd de tres numeros es
el numero mas grande que divide exactamente a los tres.*/

/*NOTA: Para la solucion se usa el algoritmo de Euclides, y para un numero "n" de elementos*/

#include <iostream>
#include <string>
#include "Validacion.h"
#include "Operaciones.h"
#include <windows.h>

using namespace std;
HANDLE h;

int main() {
	
	Validacion validacion;
	Operaciones operacion;
	string var1,var2;
	int temporal, dim;

	while (GetAsyncKeyState(VK_ESCAPE) == 0) {

		cout << "Ingrese el numero de valores que quiere ingresar: ";
		cin >> var1;
		var1 = validacion.soloNumeros(var1);
	
		dim = stoi(var1);
		int* lista = new int[dim];


		for (int i = 0; i < dim; i++) {
			cout << "Ingrese el valor "  << i + 1 << " : ";
			cin >> var2;
			var2 = validacion.soloNumeros(var2);
			temporal = stoi(var2);
			*(lista + i) = temporal;
		}

		cout << endl << "El MCD de es: "<< operacion.encontrarMCD(lista, dim) << endl;

		cout << endl << "******Presione ESC para salir o ENTER para continuar******" << endl << endl;
		system("pause");
		system("cls");
	}

	return 0;
}