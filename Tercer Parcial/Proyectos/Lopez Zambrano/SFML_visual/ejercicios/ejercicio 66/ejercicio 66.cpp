// ejercicio 66.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ingreso.h"
using namespace std;
int main()
{
    int numero1 = ingresarEntero("Inngrese primer numero: ");
    int numero2 = ingresarEntero("Ingrese segundo numero: ");
    if (numero2 == (numero1 * numero1))
        cout << "el segundo es el cuadrado exacto del primero" << endl;
    else if (numero2 > (numero1 * numero1))
        cout << "el segundo es mayor que el cuadrado del primero" << endl;
    else if (numero2 < (numero1 * numero1))
        cout << "el segundo es menor que el cuadrado del primero" << endl;
    system("pause");
    return 0;   
}

