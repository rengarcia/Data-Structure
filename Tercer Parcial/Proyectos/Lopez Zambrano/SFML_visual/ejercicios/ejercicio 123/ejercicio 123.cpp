// ejercicio 123.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ingreso.h"
using namespace std;
int main()
{
    int n = ingresarEntero("Ingrese valor para n:");
    int m = ingresarEntero("Ingrese valor para m: ");
    int sumatorio = 0;
    for (int i=1; i <= m; i ++) {
        sumatorio += n;
    }
    cout << sumatorio << endl;
    system("pause");
    return 0;
}


