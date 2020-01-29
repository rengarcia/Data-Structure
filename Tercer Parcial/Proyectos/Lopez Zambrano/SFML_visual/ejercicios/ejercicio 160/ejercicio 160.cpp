// ejercicio 160.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ingreso.h"
using namespace std;
int numeroMayusculas(string cadena, int recorredor, int mayus);
int main()
{
    string palabra = ingresarSoloTexto("Ingrese frase: ");
    cout << "el numero de mayusculas que tiene la frase es: " << numeroMayusculas(palabra, 0, 0) << endl;
    system("pause");
    return 0;
}

int numeroMayusculas(string cadena, int recorredor, int mayus)
{
    if(recorredor == (cadena.length() - 1))
        return mayus;
    else
        if (isupper(cadena.at(recorredor))) {
            mayus++;
        }
    return numeroMayusculas(cadena, recorredor + 1, mayus);
}