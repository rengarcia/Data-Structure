/* Ejercicio N 332:
Dise˜na una funcion que reciba dos listas y devuelva los elementos que pertenecen a la primera pero no a la segunda,
sin repetir ninguno (diferencia de conjuntos).
Ejemplo: si recibe las listas [1, 2, 1] y [2, 3, 2, 4], devolvera la lista [1].
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
	Nodo* lista1 = NULL;
	Nodo* lista2 = NULL;
	Nodo* listaDiferencia = NULL;
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
	
		listaDiferencia = operacion.diferencia(lista1, lista2);
		prototipo.imprimir(listaDiferencia);
	
		cout << endl << "******Presione ESC para salir o ENTER para continuar******" << endl << endl;
		system("pause");
		system("cls");
	}


	return 0;
}
