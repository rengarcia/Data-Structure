// ejercicio 72.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ingreso.h"
using namespace std;
int main()
{
    char letra = ingresarCaracter("Ingrese un carcater: ");
    if (letra >= 97 && letra <= 122) {
        cout << "es MINUSCULA" << endl;
    }
    if (letra >= 65 && letra <= 90) {
        cout << "es MAYUSCULA" << endl;
    }
    if (!isalpha(letra)) {
        cout << "No es una letra" << endl;
    }
}


