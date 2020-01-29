/* Ejercicio N 231:
Disena un programa que lea una cadena y muestre por pantalla una lista con todas sus palabras en minusculas. La
lista devuelta no debe contener palabras repetidas.
Por ejemplo: ante la cadena

Una frase formada con palabras. Otra frase con otras palabras.

el programa mostrara la lista
[’una’, ’frase’, ’formada’, ’con’, ’palabras’, ’otra’, ’otras’].
Observa que en la lista no aparece dos veces la palabra ((frase)), aunque si aparecia dos veces en la cadena leida.
*/

#include <iostream>
#include <string>
#include "Operaciones.h"
#include "Nodo.h"
#include "Prototipo.h"
#include <windows.h>
HANDLE h;

using namespace std;

int main() {

	Prototipo prototipo;
	Operaciones operacion;
	string frase;

	while (GetAsyncKeyState(VK_ESCAPE) == 0) {
	cout << "Ingrese la frase: " << endl;
	getline(cin, frase);

	frase = operacion.convertir(frase);
	operacion.separarInsetarPalabras(frase);

	cout << endl << "******Presione ESC para salir o ENTER para continuar******" << endl << endl;
	system("pause");
	system("cls");
	}

	return 0;
}
