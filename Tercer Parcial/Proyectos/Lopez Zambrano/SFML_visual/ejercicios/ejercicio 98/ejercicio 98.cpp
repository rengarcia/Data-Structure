// ejercicio 98.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
	int i = 1;
	cout << "declaramos la variable i con el valor de 1" << endl;
	cout << "ingresamos a un bucle" << endl;
	while (i < 100) {
		cout << "verificamos si no se cumple la condicion, caso contrario repetimos" << endl;
		cout << "multiplicamos el valor de i por 2" << endl;
		i *= 2;
		cout << "ahora i vale: " << i << endl;
		cout << "imprimimos i" << endl;
		cout << i << endl;
	}
	cout << "salimos del bucle" << endl;
	cout << "finaliza el programa" << endl;
	system("pause");
	return 0;
}

