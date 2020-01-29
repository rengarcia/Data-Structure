// ejercicio 60.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ingreso.h"
using namespace std;
int main()
{
    int persona1 = ingresarEntero("Ingrese la edad de la persona 1: ");
    int persona2 = ingresarEntero("Ingrese la edad de la persona 2: ");
    if (persona1 == persona2)
        cout << "tienen la misma edad!" << endl;
    else if (persona1 > persona2)
        cout << "la persona 1 es mayor a la persona 2" << endl;
    else if (persona1 < persona2)
        cout << "la persona 2 es mayor a la persona 1" << endl;
    system("pause");
    return 0;
}


