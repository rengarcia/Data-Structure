// ejercicio 81.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Menor.h"

int main()
{
    Menor palabras;
    palabras.calcularMenor(5);
    cout << "La menor palabra es: " << palabras.getMenor() << endl;
    system("pause");
    return 0;
}

