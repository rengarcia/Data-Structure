// ejercicio 173.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ingreso.h"
using namespace std;
int main()
{
    string ingreso = ingresarCualquierCosa("Ingrese caracteres: ");
    string numeros = "";
    int numeroDigitos = 0;
    for (int i = 0; i < ingreso.length(); i++) {
        if (isdigit(ingreso.at(i))) {
            numeroDigitos++;
            numeros += ingreso.at(i);
            numeros += ", ";
        }
    }
    cout << "hay " << numeroDigitos << " digitos y los siguientes numeros: " << numeros << endl;
    system("pause");
    return 0;
}


