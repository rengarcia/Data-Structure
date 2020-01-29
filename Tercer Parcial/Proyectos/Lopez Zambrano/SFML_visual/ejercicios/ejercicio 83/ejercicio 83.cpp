// ejercicio 83.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ingreso.h"
using namespace std;

int cercano(int* numeros);

int main()
{
    int* numeros = new int[5];
    for (int i = 0; i < 5; i++) {
        *(numeros + i) = ingresarEntero("Ingrese un numero: ");
    }
    cout << "el numero mas cercano a " << *(numeros + 0) << " es el " << cercano(numeros) << endl;
    delete[] numeros;
    system("pause");
    return 0;
}

int cercano(int* numeros)
{
    int primero;
    int temporal;
    int cercano = 0;
    primero = *(numeros + 0);
    for (int i = 1; i < 5; i++) {
        temporal = primero - *(numeros + i);
        if (temporal < 0)
            temporal = temporal * (-1);
        if (cercano == 0)
            cercano = temporal;
        if (cercano > temporal)
            cercano = *(numeros + i);
    }
    return cercano;
}