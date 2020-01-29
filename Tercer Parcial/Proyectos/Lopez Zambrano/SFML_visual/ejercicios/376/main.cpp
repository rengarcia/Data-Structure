/* Ejercicio N 376:
Disena un programa que, a partir de un valor n leido de teclado, muestre [n,m]para m entre 0 y n. El programa llamara a
una funcion combinaciones definida recursivamente.
*/
/*
NOTA: 
	Solo se puede calcular el factorial de forma precisa usando recursividad hasta el numero 12 con "int", 
	de ahi en adelante hay que usar char* y la funcion es mas compleja. Por ello este programa acepta solo enteros
	del 1 al 12
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
	int n, m;

	while (GetAsyncKeyState(VK_ESCAPE) == 0) {
	cout << "Ingrese el valor de n: ";
	getline(cin, temp);
	temp = validacion.soloNumeros(temp);
	n = stoi(temp);
	n = validacion.nValida(n);

	cout << "Ingrese el valor de m: ";
	getline(cin, temp);
	temp = validacion.soloNumeros(temp);
	m = stoi(temp);
	m = validacion.mValida(n,m);
	
	cout <<endl<<"El numero combinatorio entre [n,m] es: "<< operaciones.combinaciones(n,m)<<endl;
	cout << endl << "El numero combinatorio entre [n,0] es: " << operaciones.combinaciones(n, 0) << endl;

	cout << endl << "******Presione ESC para salir o ENTER para continuar******" << endl << endl;
	system("pause");
	system("cls");
	}


	return 0;
}