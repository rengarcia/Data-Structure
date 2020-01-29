/* Ejercicio N 422:
Disena una funcion fecha_valida que devuelva True si la fecha es v´alida y False en caso contrario. Para comprobar
la validez de una fecha debes verificar que el mes este comprendido entre 1 y 12 y que el dia lo este entre 1 y el numero de
dias que corresponde al mes. Por ejemplo, la fecha 31/4/2000 no es valida, ya que abril tiene 30 dias.
Ten especial cuidado con el mes de febrero: recuerda que tiene 29 o 28 dias segun sea el anio bisiesto o no. Usa, si te
conviene, la funcion definida anteriormente.
*/
/*
NOTA: 
	Se establecio como:
	- Minimo Anio valido 1700
	- Maximo Anio valido 5000
	para establecer parametros de valides para los anios. 
*/

#include <iostream>
#include "Validacion.h"
#include "Operaciones.h"
#include <windows.h>
HANDLE h;
using namespace std;

int main() {
	Validacion validacion;
	Operaciones operaciones;
	string temp;
	int dia, mes,anio;

	while (GetAsyncKeyState(VK_ESCAPE) == 0) {
		cout << "Ingrese el dia: ";
		getline(cin, temp);
		temp = validacion.soloNumeros(temp);
		dia = stoi(temp);

		cout << "Ingrese el mes: ";
		getline(cin, temp);
		temp = validacion.soloNumeros(temp);
		mes = stoi(temp);
	
		cout << "Ingrese el anio: ";
		getline(cin, temp);
		temp = validacion.soloNumeros(temp);
		anio = stoi(temp);


		cout << endl <<"La fecha: " << dia << "/" << mes << "/" << anio << endl;

		if (operaciones.fecha_valida(dia, mes, anio)) {
			cout << "Es valida!" << endl;
		}

		else
		{
			cout << "No es valida!" << endl;
		}
		
		cout << endl << "******Presione ESC para salir o ENTER para continuar******" << endl << endl;
		system("pause");
		system("cls");
	}

	return 0;
}