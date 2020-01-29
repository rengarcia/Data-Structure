/* Ejercicio N 264:
Define una funcion que convierta grados Farenheit en grados centıgrados.
(Para calcular los grados centıgrados has de restar 32 a los grados Farenheit y multiplicar el resultado por cinco novenos.)*/

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
		cout << "Grados Fahrenheit: ";
		cin >> aux;
		aux = validacion.soloNumeros(aux);
		farenheit = strtof((aux).c_str(), 0);
		celsius = (farenheit - 32) * 5 / 9;
		cout << "Grados Celsius: " << celsius;
		
		cout << endl << "******Presione ESC para salir o ENTER para continuar******" << endl << endl;
		system("pause");
		system("cls");
	}


	return 0;
}