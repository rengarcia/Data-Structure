/* Ejercicio N 372:
Disena una funcion recursiva que calcule el numero de digitos que tiene un numero entero
*/
#include <iostream>
#include "Validacion.h"
#include <windows.h>
HANDLE h;

using namespace std;

int contarDigitos(int numero)
{
	if (numero == 0)
		return 0;

	return 1 + contarDigitos(numero / 10);
}

int main() {
	Validacion validacion;
	string temp;
	int numero;

	while (GetAsyncKeyState(VK_ESCAPE) == 0) {
		cout << "Ingrese el numero: ";
		getline(cin, temp);
		temp = validacion.soloNumeros(temp);
		numero = stoi(temp);

		cout << "Numero de Digitos: " << contarDigitos(numero)<<endl;

		cout << endl << "******Presione ESC para salir o ENTER para continuar******" << endl << endl;
		system("pause");
		system("cls");
	}

	return 0;
}