// ejercicio 174.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ingreso.h"
using namespace std;
int main()
{
    string ingreso = ingresarCualquierCosa("Ingrese caracteres: ");
    string numeros = "";
    int numeroDigitos = 0;
    bool flag = false;
    for (int i = 0; i < ingreso.length(); i++) {
        if (isdigit(ingreso.at(i))) {
            numeros += ingreso.at(i);
            int j = i;
            while (1) {
                j++;
                if (isdigit(ingreso.at(j))) {
                    numeros += ingreso.at(j);
                }
                else {
                    flag = true;
                    break;
                }
            }
            
            numeros += ", ";
        }
        
    }
    cout << "hay " << numeroDigitos << " digitos y los siguientes numeros: " << numeros << endl;
    system("pause");
    return 0;
}
