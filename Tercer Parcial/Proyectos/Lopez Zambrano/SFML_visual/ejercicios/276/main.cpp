/* Ejericion N 276
Define una funcion que devuelva el numero de dias que tiene un ano determinado. Ten en cuenta que un anio es
bisiesto si es divisible por 4 y no divisible por 100, excepto si es tambien divisible por 400, en cuyo caso es bisiesto.
(Ejemplos: El numero de dias de 2002 es 365: el numero 2002 no es divisible por 4, asi que no es bisiesto. El anio 2004 es
bisiesto y tiene 366 dias: el numero 2004 es divisible por 4, pero no por 100, asi que es bisiesto. El anio 1900 es divisible por
4, pero no es bisiesto porque es divisible por 100 y no por 400. El anio 2000 si es bisiesto: el numero 2000 es divisible por 4
y, aunque es divisible por 100, tambien lo es por 400.)
*/

#include <iostream>
#include "Validacion.h"
#include <windows.h>
HANDLE h;
using namespace std;

bool bisiesto(int numero) {

	if (numero % 4 == 0 && numero % 100 == 0 && numero % 400 == 0) {
		return true;
	}
	else if (numero % 4 == 0 && numero % 100 != 0) {
		return true;
	}
	else if (numero % 4 == 0 && numero % 100 == 0) {
		return false;
	}
	else
	{
		return false;
	}
}

int main() {

	Validacion validacion;
	string aux;
	int year;

	while (GetAsyncKeyState(VK_ESCAPE) == 0) {
		cout << "Ingrese el anio: ";
		cin >> aux;
		aux = validacion.soloNumeros(aux);
		year = stoi(aux);

		if (bisiesto(year)) {
			cout << "Es bisiesto, tiene 366 dias" << endl;
		}
		else
		{
			cout << "No es bisiesto, tiene 365 dias" << endl;
		}
		cout << endl << "******Presione ESC para salir o ENTER para continuar******" << endl << endl;
		system("pause");
		system("cls");
	}


	return 0;
}