/* Ejercicio N 348:
Disena una funcion duplica que reciba una lista de numeros y la modifique duplicando el valor de cada uno de sus
elementos. (Ejemplo: la lista [1, 2, 3] se convertira en [2, 4, 6].)
*/
#include <iostream>
#include <string>
#include "Nodo.h"
#include "Prototipo.h"
#include "Operaciones.h"
#include <windows.h>
HANDLE h;

using namespace std;

int main() {
	
	Prototipo prototipo;
	Operaciones operacion;
	Nodo* lista = NULL;
	Nodo* listaDuplicada = NULL;
	string frase;

	while (GetAsyncKeyState(VK_ESCAPE) == 0) {
		cout << "Ingrese los datos para la lista, separalos usando SOLO el espacio " << endl;
		cout << "Ejemplo :  1 2 3 45 15" << endl;
		getline(cin, frase);
		frase = operacion.convertir(frase); 
		lista = operacion.Insertar(frase);
	
		listaDuplicada = operacion.Duplicar(lista);
		prototipo.imprimir(listaDuplicada);
		cout << endl << "******Presione ESC para salir o ENTER para continuar******" << endl << endl;
		system("pause");
		system("cls");
	}

	return 0;
}
