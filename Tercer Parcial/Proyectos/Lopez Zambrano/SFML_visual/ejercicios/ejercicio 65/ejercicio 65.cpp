// ejercicio 65.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ingreso.h"
using namespace std;
int main()
{
    int numero = ingresarEntero("Ingrese un numero: ");
    if (!((numero / 2) % 2 == 0))
        cout << "el numero " << numero << " es el doble del numero " << (numero / 2) << endl;
    else
        cout << "el numero " << numero << " no es doble de un numero impar." << endl;
    system("pause");
    return 0;
}
