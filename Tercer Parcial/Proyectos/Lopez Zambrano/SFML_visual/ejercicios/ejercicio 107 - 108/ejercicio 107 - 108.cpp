// ejercicio 107 - 108.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ingreso.h"
using namespace std;
int main()
{
    int resultado = 0;
    int n = ingresarEntero("Ingrese valor para n: ");
    int m = ingresarEntero("Ingrese valor para m: ");
    if (n > m) {
        cout << "n debe ser menor a m." << endl;
    }
    else {
        for (n; n <= m; n++) {
            resultado = resultado + n;
        }
        cout << resultado << endl;
    }
    system("pause");
    return 0;
}


