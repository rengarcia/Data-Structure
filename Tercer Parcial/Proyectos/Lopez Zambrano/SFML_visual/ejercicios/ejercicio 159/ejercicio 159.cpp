// ejercicio 159.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ingreso.h"
using namespace std;
int espaciosEnBlanco(string cadena,int recorredor,int espacios);
int main()
{
    string palabra = ingresarSoloTexto("Ingrese palabra: ");
    int espacios = espaciosEnBlanco(palabra,0,0);
    cout << "La cantidad de espacios blancos es " << espacios << endl;
    system("pause");
    return 0;
}

int espaciosEnBlanco(string cadena,int recorredor,int espacios)
{
    if (recorredor == (cadena.length() - 1)) {
        return espacios;
    }
    else
    {
        if (isspace(cadena.at(recorredor)))
            espacios++;
        return espaciosEnBlanco(cadena, recorredor + 1, espacios);
    }
}