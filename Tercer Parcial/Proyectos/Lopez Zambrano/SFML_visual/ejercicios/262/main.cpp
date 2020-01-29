/* Ejercicio N 262:
Define una funcion llamada raiz_cubica que calcula la raiz cubica de un numero dado por el usuario*/

/*NOTA: Para la resolucion de este problema se utilizo la busca binaria, para que de manera repetitiva se 
busque busque un valor que al mutiplicarse 3 veces, de como resultado aproximadamente el numero ingresado*/
#include <iostream>
#include <string>
#include "Validacion.h"
#include "Operaciones.h"
#include <windows.h>
HANDLE h;
using namespace std;

int main()
{
	Validacion validacion;
	Operaciones operacion;
	float numero, resultado;
	string aux;
	bool bandera=false;

	while (GetAsyncKeyState(VK_ESCAPE) == 0) {
		cout << "Ingrese el numero: ";
		getline(cin, aux);
		aux = validacion.soloNumeros(aux);
		numero = strtof((aux).c_str(), 0);
		numero = validacion.mayorA1(numero);

		if (numero < 0) {
			bandera = true;
			aux = operacion.eliminarSigno(aux);
			numero = strtof((aux).c_str(), 0);
		}

		resultado = operacion.raiz_cubica(numero);

		if (bandera) {
			cout << "Raiz cubica : -" << resultado << endl;
		}
		else {
			cout << "Raiz cubica : " << resultado << endl;
		}
		cout << endl << "******Presione ESC para salir o ENTER para continuar******" << endl << endl;
		system("pause");
		system("cls");
	}

	return 0;
}