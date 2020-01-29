// ejercicio 117.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ingreso.h"
using namespace std;
int main()
{
    int numero = ingresarEntero("Ingresa un numero: ");
    for (int i = 1; i <= 10  ; i++) {
        cout << numero << " x " << i << " = " << (numero * i) << endl;
    }
    system("pause");
    return 0;
}


