/* Ejercicio N 265:
Define una funcion que convierta grados centıgrados en grados Farenheit.*/

#include <iostream>
#include "Validacion.h"
#include <windows.h>
HANDLE h;
using namespace std;

int main() {

	Validacion validacion;
	string aux;
	float celsius, farenheit;

	while (GetAsyncKeyState(VK_ESCAPE) == 0) {

		cout << "Grados Celsius: ";
		cin >> aux;
		aux = validacion.soloNumeros(aux);
		celsius = strtof((aux).c_str(), 0);
		farenheit = (9.0 * celsius / 5.0) + 32;
		cout << "Grados Fahrenheit: " << farenheit;
		
		cout << endl << "******Presione ESC para salir o ENTER para continuar******" << endl << endl;
		system("pause");
		system("cls");
	}

	return 0;
}