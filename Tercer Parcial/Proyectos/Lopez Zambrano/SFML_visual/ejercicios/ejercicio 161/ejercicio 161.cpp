// ejercicio 161.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ingreso.h"
using namespace std;
void digitoEnCadena(string cadena);
int main()
{
    string palabras = ingresarCualquierCosa("Ingrese palabras: ");
    digitoEnCadena(palabras);
    system("pause");
    return 0;
}

void digitoEnCadena(string cadena)
{
    bool flag;
    for (int i = 0; i < cadena.length(); i++) {
        if (isdigit(cadena.at(i)))
            flag = true;
        else
            flag = false;
    }
    if (flag)
        cout << "<<Contiene digitos>>" << endl;
    else
        cout << "<<No contiene digitos>>" << endl;
}