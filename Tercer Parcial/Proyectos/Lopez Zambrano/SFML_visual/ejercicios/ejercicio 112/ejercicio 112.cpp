// ejercicio 112.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ingreso.h"
using namespace std;
int main()
{
    do {
        int numero = ingresarEntero("Hola, Ingrese un numero del 0 al 10: ");
        if (!(numero < 0 || numero >10)) {
            break;
        }
    } while (1);
    system("pause");
    return 0;
}


