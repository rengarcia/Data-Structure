// ejercicio 122.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ingreso.h"
using namespace std;

int main()
{
    do {
        int valor = ingresarEntero("Ingrese un valor: ");
        if (valor >= 2 && valor % 2 == 0) {
            for (int i = 0; i <= valor; i += 2) {
                cout << i << endl;
            }
            break;
        }
        if (valor >= 2 && !(valor % 2 == 0)) {
            for (int i = 2; i < valor; i += 2) {
                cout << i << endl;
            }
            break;
        }
    } while (1);
    system("pause");
    return 0;
}


