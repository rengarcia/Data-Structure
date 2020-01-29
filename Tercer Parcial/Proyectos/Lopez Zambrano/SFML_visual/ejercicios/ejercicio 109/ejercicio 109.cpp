// ejercicio 109.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ingreso.h"
using namespace std;
int factorial(int numero);
int main()
{
    int numero = ingresarEntero("Ingrese un numero para sacar su factorial: ");
    cout << factorial(numero) << endl;
    system("pause");
    return 0;
}

int factorial(int numero)
{
    if (numero == 0)
        return 1;
    else
        return numero * factorial(numero - 1);
}

