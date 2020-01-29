// ejercicio 80.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Maximo.h"
using namespace std;
int main()
{
    Maximo numeros;
    numeros.encontrarMaximo(5);
    cout << "el maximo de los numeros ingresados es: " << numeros.getMaximo() << endl;
    system("pause");
    return 0;
}


