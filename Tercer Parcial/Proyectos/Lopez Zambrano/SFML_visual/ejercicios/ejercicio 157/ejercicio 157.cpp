// ejercicio 157.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ingreso.h"
using namespace std;
string invertirCadena(string cadena,int longitudC);
int main()
{
    string cadena = ingresarSoloTexto("Ingrese palabras: ");
    cout << "la cadena invertida es: " << invertirCadena(cadena, cadena.length() - 1) << endl;
    system("pause");
    return 0;
}

string invertirCadena(string cadena, int longitudC)
{
    if (longitudC < 0)
        return "";
    else
        return cadena.at(longitudC) + invertirCadena(cadena, longitudC - 1);
}
