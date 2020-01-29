// ejercicio 104.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ingreso.h"
using namespace std;
int main()
{
    int n = ingresarEntero("Ingrese valor inicial: ");
    int m = ingresarEntero("Ingrese valor final: ");
    int incremento = n;
    for (n; n <= m; n += incremento) {
        cout << n << endl;
    }
    system("pause");
    return 0;
}
