/* Ejercicio N 266:
Define una funcion que convierta radianes en grados.*/

#include <iostream>
#include "Validacion.h"
#include <windows.h>
HANDLE h;
using namespace std;

float Convertir(float radian) {
	float pi = 3.14159;
	return(radian * (180 / pi));
}

int main() {
	Validacion validacion;
	string aux;
	float radian;

	while (GetAsyncKeyState(VK_ESCAPE) == 0) {
		cout << "Radianes: ";
		cin >> aux;
		aux = validacion.soloNumeros(aux);
		radian = strtof((aux).c_str(), 0);
		float grados = Convertir(radian);
		cout << "Grados: " << grados << endl;

		cout << endl << "******Presione ESC para salir o ENTER para continuar******" << endl << endl;
		system("pause");
		system("cls");
	}

	return 0;
}