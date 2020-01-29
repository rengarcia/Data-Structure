/* Ejercicio N 275:
Disena una funcion que devuelva una lista con los numeros perfectos comprendidos entre 1 y n, siendo n un entero
que nos proporciona el usuario.*/

#include <iostream>
#include <string>
#include "Validacion.h"
#include "Operaciones.h"
#include <windows.h>
HANDLE h;
using namespace std;

int main() {
	
	Validacion validacion;
	Operaciones operacion;
	string frase;
	int numero;
	
	while (GetAsyncKeyState(VK_ESCAPE) == 0) {
		cout << "Ingrese el numero N: ";
		getline(cin, frase);
		frase = validacion.soloNumeros(frase);
		numero = stoi(frase);
		operacion.imprimirLista(numero);
		
		cout << endl << "******Presione ESC para salir o ENTER para continuar******" << endl << endl;
		system("pause");
		system("cls");
	}

	return 0;	
}