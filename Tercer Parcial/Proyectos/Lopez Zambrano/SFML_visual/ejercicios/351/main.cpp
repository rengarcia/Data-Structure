/* Ejercicio N 351:
Disena una funcion que reciba una lista y devuelva otra lista cuyo contenido sea la lista original, pero con sus
componentes en orden inverso. La lista original no debe modificarse.
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
	Nodo* listaInversa = NULL;
	string frase;

	while (GetAsyncKeyState(VK_ESCAPE) == 0) {
		cout << "Ingrese los datos para la lista, separalos usando SOLO el espacio " << endl;
		cout << "Ejemplo :  1 2 3 45 15" << endl;
		getline(cin, frase);
		frase = operacion.convertir(frase); 
		lista = operacion.InsertarCola(frase);
		listaInversa = operacion.InsertarCabeza(frase);
	
		cout << " La lista original: ";
		prototipo.imprimir(lista);
		cout << endl;
		cout << " La lista invertida: ";
		prototipo.imprimir(listaInversa);
		cout << endl << "******Presione ESC para salir o ENTER para continuar******" << endl << endl;
		system("pause");
		system("cls");
	}

	return 0;
}
