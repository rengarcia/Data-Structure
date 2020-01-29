// ejercicio 132 - 133.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <math.h>
#include "ingreso.h"
using namespace std;
bool esPrimo(int numero);
bool esPrimoOptimizado(int numero);
int main()
{
    int num = ingresarEntero("Ingrese un numero: ");
    if (esPrimoOptimizado(num))
        cout << "el numero " << num << " es primo." << endl;
    else
        cout << "el numero " << num << " no es primo." << endl;
    system("pause");
    return 0;
}

bool esPrimo(int numero)
{
    bool flag = true;
    for (int i = 2; i <= (numero / 2); i++) {
        if (numero % i == 0)
            flag = false;
    }
    return flag;
}

bool esPrimoOptimizado(int numero)
{
    bool flag = true;
    for (int i = 2; i <= (int)sqrt(numero); i++) {
        if (numero % i == 0)
            flag = false;
    }
    return flag;
}