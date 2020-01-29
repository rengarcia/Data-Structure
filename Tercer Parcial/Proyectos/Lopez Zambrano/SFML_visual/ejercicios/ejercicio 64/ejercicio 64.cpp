// ejercicio 64.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ingreso.h"
using namespace std;
int main()
{
    int numero = ingresarEntero("Ingresa un numero: ");
    if (numero % 2 == 0)
        cout << "El numero es par." << endl;
    else
        cout << "El numero es impar." << endl;
    system("pause");
    return 0;
}
