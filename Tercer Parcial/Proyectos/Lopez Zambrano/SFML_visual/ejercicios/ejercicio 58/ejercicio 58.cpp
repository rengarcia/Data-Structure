// ejercicio 58.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ingreso.h"
int main()
{
    float numero = ingresarFlotante("Ingrese numero flotante: ");
    if (numero < 0)
        cout << "El numero ingresado es negativo." << endl;
    else
        cout << "El numero ingresado es positivo." << endl;
    system("pause");
    return 0;
}

