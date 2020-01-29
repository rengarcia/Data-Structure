// ejercicio 110.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ingreso.h"
#include "misFunciones.h"
using namespace std;
double combinaciones(int n, int m);
int main()
{
    int n = ingresarEntero("Ingere valor para n: ");
    int m = ingresarEntero("Ingrese valor para m: ");
    cout << "las combinaciones posibles son: " << combinaciones(n, m) << endl;
    system("pause");
    return 0;
}

double combinaciones(int n, int m)
{
    double resultado;
    int numerador = factorial(n);
    int denominador = factorial((n - m)) * factorial(m);
    resultado = numerador / denominador;
    return resultado;
}