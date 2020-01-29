/* Ejercicio N 333:
Disena una funcion que, dada una lista de numeros, devuelva otra lista que solo incluya sus numeros impares.
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
	Nodo* listaImpares = NULL;
	string frase;

	while (GetAsyncKeyState(VK_ESCAPE) == 0) {
		cout << "Ingrese los datos para la lista, separalos usando SOLO el espacio " << endl;
		cout << "Ejemplo :  1 2 3 45 15" << endl;
		getline(cin, frase);
		frase = operacion.convertir(frase); 
		lista = operacion.Insertar(frase);
		lista = operacion.eliminarDuplicados(lista);

		listaImpares = operacion.impares(lista);
		prototipo.imprimir(listaImpares);
		cout << endl << "******Presione ESC para salir o ENTER para continuar******" << endl << endl;
		system("pause");
		system("cls");
	}


	return 0;
}
