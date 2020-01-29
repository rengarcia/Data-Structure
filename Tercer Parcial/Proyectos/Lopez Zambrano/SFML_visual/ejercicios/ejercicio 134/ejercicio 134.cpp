// ejercicio 134.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ingreso.h"
using namespace std;
int main()
{
    int mayor = 0;
    do {
        int numero = ingresarEntero("Ingrese un numero: ");
        if (numero < 0)
            break;
        if (mayor < numero)
            mayor = numero;
        cout << numero << endl;
    } while (1);
    cout << "el numero mas grande que se ingreso fue: " << mayor << endl;
    cout << "ADIOS" << endl;
    system("pause");
    return 0;
}


