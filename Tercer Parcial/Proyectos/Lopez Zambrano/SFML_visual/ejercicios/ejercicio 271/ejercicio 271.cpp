// ejercicio 271.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
271 Dise˜na una funci´on que reciba una cadena y devuelva cierto si empieza por min´uscula y falso en caso contrario.*/

#include <iostream>
#include "ingreso.h"
using namespace std;
bool empiezaMinuscula(string cadena);
int main()
{
    string cadena = ingresarSoloTexto("Ingrese cadena: ");
    if (empiezaMinuscula(cadena))
        cout << "Empieza por minuscula" << endl;
    else
        cout << "No empieza por minuscula" << endl;
    system("pause");
    return 0;
}

bool empiezaMinuscula(string cadena)
{
    if (islower(cadena.at(0)))
        return true;
    else
        return false;
}
