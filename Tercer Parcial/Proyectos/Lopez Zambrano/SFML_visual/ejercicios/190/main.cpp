/* Ejercicio N 190:
Una palabra es (alfabetica) si todas sus letras estan ordenadas alfabeticamente. Por ejemplo, (amor), (chino) e
(himno) son palabras (alfabeticas). Disena un programa que lea una palabra y nos diga si es alfabetica o no.*/

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
	string palabra;

	while (GetAsyncKeyState(VK_ESCAPE) == 0) {
		cout << "Ingrese la palabra: " << endl;
		getline(cin, palabra);
		palabra = validacion.soloLetras(palabra);
		palabra = operacion.aMinusculas(palabra);
		operacion.esAlfabetica(palabra);

		if (operacion.esAlfabetica(palabra)) {
			cout << "La palabra es Alfabetica" << endl;
		}
		else
		{
			cout << "La palabra NO es Alfabetica" << endl;
		}
	
		cout << endl << "******Presione ESC para salir o ENTER para continuar******" << endl << endl;
		system("pause");
		system("cls");
	}
	return 0;	
}