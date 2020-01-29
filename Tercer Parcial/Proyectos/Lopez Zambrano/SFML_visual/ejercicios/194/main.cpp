/* Ejercicio N 194:
Hay un tipo de pasatiempos que propone descifrar un texto del que se han suprimido las vocales. Por ejemplo,
el texto (.n .j.mpl. d. p.s.t..mp.s), se descifra sustituyendo cada punto con una vocal del texto. La solucion es (un
ejemplo de pasatiempos). Disena un programa que ayude al creador de pasatiempos. El programa recibira una cadena y
mostrara otra en la que cada vocal ha sido reemplazada por un punto.*/

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
	string resultado;

	while (GetAsyncKeyState(VK_ESCAPE) == 0) {

		cout << "Ingrese la frase: "<<endl;
		getline(cin, frase);
		frase = validacion.soloLetras(frase);
		frase = operacion.aMinusculas(frase);
	
		resultado = operacion.Pasatiempo(frase);
		cout << "Frase convertida: " << endl;
		cout << resultado << endl;

		cout << endl << "******Presione ESC para salir o ENTER para continuar******" << endl << endl;
		system("pause");
		system("cls");
	}

	return 0;	
}