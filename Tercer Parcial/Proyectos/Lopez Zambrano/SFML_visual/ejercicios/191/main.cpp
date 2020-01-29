/* Ejercicio N 191:
Disena un programa que nos diga si una cadena es palındromo o no. Una cadena es palındromo si se lee igual de
izquierda a derecha que de derecha a izquierda. Por ejemplo, ’ana’ es un palındromo.

Ejercicio N 192:
Una frase es pal´ındromo si se lee igual de derecha a izquierda que de izquierda a derecha, pero obviando los espacios
en blanco y los signos de puntuacion. Por ejemplo, las cadenas ’se verla al reves’, ’anita lava la tina’, ’luz azul’
y ’la ruta natural’ contienen frases palindromas. Disena un programa que diga si una frase es o no es palindroma.
*/

#include <iostream>
#include <string>
#include "Operaciones.h"
#include <windows.h>
HANDLE h;

using namespace std;

int main() {
	
	Operaciones operacion;
	string frase;

	while (GetAsyncKeyState(VK_ESCAPE) == 0) {
		cout << "Ingrese la frase: " << endl;
		getline(cin, frase);
		frase = operacion.convertir(frase);

		operacion.Palindromo(frase);
		
		cout << endl << "******Presione ESC para salir o ENTER para continuar******" << endl << endl;
		system("pause");
		system("cls");
	}
	return 0;	
}