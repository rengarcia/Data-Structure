/* Ejercicio N 129:
Haz un programa que calcule el maximo comun divisor (mcd) de dos enteros positivos. El mcd es el numero mas
grande que divide exactamente a ambos numeros.*/

/*NOTA: Para la solucion se usa el algoritmo de Euclides*/

#include <iostream>
#include <string>
#include <windows.h>
#include "Validacion.h"

using namespace std;
HANDLE h;

int MCD(int num1, int num2)
{
	if (num2 == 0)
		return num1;

	return MCD(num2, num1 % num2);

}

int main() {

	int edad;
	Validacion validacion;
	int num1, num2;
	string var1, var2;

	while (GetAsyncKeyState(VK_ESCAPE) == 0) {

		cout << "Ingrese el primer numero: " << endl;
		cin >> var1;
		var1 = validacion.soloNumeros(var1);
		num1 = stoi(var1);

		cout << "Ingrese el segundo numero: " << endl;
		cin >> var2;
		var2 = validacion.soloNumeros(var2);
		num2 = stoi(var2);

		cout << "El MCD de  " << num1 << " y " << num2 << " es: " << MCD(num1, num2)<<endl<<endl;
		cout << "******Presione ESC para salir o ENTER para continuar******" << endl<<endl;

		system("pause");
		system("cls");
	}
	
	return 0;
}