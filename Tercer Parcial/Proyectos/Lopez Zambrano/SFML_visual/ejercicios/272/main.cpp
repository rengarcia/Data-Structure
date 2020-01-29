/* Ejercicio N 272:
Disena una funcion llamada es_repeticion que reciba una cadena y nos diga si la cadena esta formada mediante la
concatenacion de una cadena consigo misma. Por ejemplo, es_repeticion(’abab’) devolvera True, pues la cadena ’abab’
esta formada con la cadena ’ab’ repetida; por contra es_repeticion(’ababab’) devolvera False.*/

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
	bool es_valido;

	while (GetAsyncKeyState(VK_ESCAPE) == 0) {
		cout << "Ingrese la frase: "<<endl;
		getline(cin, frase);
		frase = validacion.soloLetras(frase);
		frase = operacion.aMinusculas(frase);

		es_valido=operacion.es_repeticion(frase);
	
		if (es_valido) {
			cout << endl << "Verdadero, la cadena se concatena con si misma" << endl;
		}
	
		else {
			cout << endl <<"Falso, la cadena No se concatena con si misma" << endl;
		}
		
		cout << endl << "******Presione ESC para salir o ENTER para continuar******" << endl << endl;
		system("pause");
		system("cls");
	}


	return 0;	
}