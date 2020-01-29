/* Ejercicio N 317:
Disena un programa que permita jugar a dos personas al tres en raya.
*/

#include <iostream>
#include "Jugador.h"
#include "Operaciones.h"
#include <windows.h>
HANDLE h;
using namespace std;

int main() {

	Operaciones operaciones;
	Jugador jugador;
	bool opcion = false;

	while (GetAsyncKeyState(VK_ESCAPE) == 0) {

		int** matriz = operaciones.generarMatriz(3);
		operaciones.encerar(matriz);
		operaciones.imprimir(matriz);

		int contador = 0;
		while (contador < 5) {
			opcion = jugador.jugador1(matriz);
			operaciones.imprimir(matriz);
			if (opcion) {
				cout << endl << "Gano el jugador 1 !!!" << endl;
				break;
			}

			if (contador == 4) {
				cout << endl<< endl << "Juego terminado ningun jugador gano" << endl;
				break;
			}

			opcion = jugador.jugador2(matriz);
			operaciones.imprimir(matriz);
			if (opcion) {
				cout<< endl <<"Gano el jugador 2 !!!"<< endl;
				break;
			}
			contador++;
		}

		cout << endl << "******Presione ESC para salir o ENTER para continuar******" << endl << endl;
		system("pause");
		system("cls");
	}


	return 0;
}