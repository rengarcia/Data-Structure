#include "misFunciones.h"
#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int factorial(int numero)
{
    if (numero == 0)
        return 1;
    else
        return numero * factorial(numero - 1);
}

int palabrasConLongitud(string cadena,int n)
{
    int palabrasConLongitud = 0;
    int num = 0;
    for (int i = 0; i < cadena.length(); i++) {
        if (!isspace(cadena.at(i)))
            num++;
        else
            if (num == n) {
                palabrasConLongitud++;
                num = 0;
            }
    }
    return palabrasConLongitud;
}

double miLogaritmo(double b, double x)
{
    double logar = log(x) / log(b);
    return logar;
}