/* Ejercicio N 336:
Disena una funcion que, dada una lista de numeros, devuelva una lista con todos los pares de numeros que podemos
formar con uno de la primera lista y otro de la segunda. Por ejemplo, si se suministran las listas [1, 3, 5] y [2, 5], la lista
resultante es
[[1, 2], [1, 5], [3, 2], [3, 5], [5, 2], [5, 5]].
*/
#include <iostream>
#include <string>
#include "Nodo.h"
#include "NodoPar.h"
#include "Prototipo.h"
#include "Operaciones.h"
#include <windows.h>
HANDLE h;

using namespace std;

int main() {
	
	Prototipo prototipo;
	Operaciones operacion;
	Nodo* lista1 = NULL;
	Nodo* lista2 = NULL;
	NodoPar* nodoPar = NULL;
	string frase; 
	
	while (GetAsyncKeyState(VK_ESCAPE) == 0) {

		cout << "Ingrese los datos para la primera lista, separalos usando SOLO el espacio " << endl;
		cout << "Ejemplo :  1 2 3 45 15" << endl;
		getline(cin, frase);
		frase = operacion.convertir(frase); 
		lista1 = operacion.Insetar(frase);
		lista1 = operacion.eliminarDuplicados(lista1);

		cout << "Ingrese los datos para la segunda lista, separalos usando SOLO el espacio:" << endl;
		getline(cin, frase);
		frase = operacion.convertir(frase);
		lista2 = operacion.Insetar(frase);
		lista2 = operacion.eliminarDuplicados(lista2);
	
		nodoPar = operacion.recorrerCadenas(lista1, lista2);
		prototipo.imprimir(nodoPar);
	
		cout << endl << "******Presione ESC para salir o ENTER para continuar******" << endl << endl;
		system("pause");
		system("cls");
	}

	return 0;
}
