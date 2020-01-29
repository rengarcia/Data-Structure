// ejercicio 113.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ingreso.h"
using namespace std;
int main()
{
    bool flag = false;
    do {
        string frase = ingresarSoloTexto("Ingrese texto: ");
        for (int i = 0; i < frase.length(); i++) {
            if (isupper(frase.at(i)))
                flag = true;
        }
        if (!flag)
            break;
    } while (flag);
}
