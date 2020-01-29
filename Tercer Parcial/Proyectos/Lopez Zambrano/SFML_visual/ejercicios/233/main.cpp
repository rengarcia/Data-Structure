/* Ejercicio N 233:
Disena un programa que elimine de una lista todos los elementos de indice par y muestre por pantalla el resultado.
(Ejemplo: si trabaja con la lista [1, 2, 1, 5, 0, 3], esta pasara a ser [2, 5, 3].)
*/
/*Nota: Se refiere a los elementos que tienen raiz exacta*/

#include <iostream>
#include <string>
#include "Operaciones.h"
#include "Nodo.h"
#include "Prototipo.h"
#include <windows.h>
HANDLE h;

using namespace std;

int main() {

	Operaciones operacion;
	string frase;

	while (GetAsyncKeyState(VK_ESCAPE) == 0) {

		cout << "Ingrese la lista de numero, separalos usando SOLO el espacio " << endl;
		cout << "Ejemplo :  1 2 3 45 15" << endl << endl;
		cout << "Lista: ";
		getline(cin, frase);

		frase = operacion.convertir(frase); 
		operacion.separarInsetarNumeros(frase);

		cout << endl << "******Presione ESC para salir o ENTER para continuar******" << endl << endl;
		system("pause");
		system("cls");
	}

	return 0;
}
