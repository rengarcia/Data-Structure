// ejercicio 119.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <math.h>
#include "ingreso.h"
using namespace std;
int main()
{
    double exponente;
    double valor = ingresarDouble("Ingrese valor: ");
    for (int i = 2; i <= 100; i++) {
        exponente = (double)1 / i;
        double raiz = powl(valor, (double)exponente);
        cout << "La raiz " << i << " de " << valor << " es: " << raiz << endl;
    }
    system("pause");
    return 0;
}


