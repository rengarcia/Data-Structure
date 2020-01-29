// ejercicio 32.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*Universidad de las Fuerzas Armadas ESPE
  Estructura de Datos
  Zambrano Washington*/
//

#include <iostream>
#include "Triangulo.h"
using namespace std;
int main()
{
    Triangulo triangulo;
    double base;
    double altura;
    cout << "Ingrese base del triangulo: ";
    cin >> base;
    triangulo.setBase(base);
    cout << "Ingrese altura del triangulo: ";
    cin >> altura;
    triangulo.setAltura(altura);
    triangulo.calcularArea(triangulo.getBase(), triangulo.getAltura());
    cout << "El area del triangulo es: " << triangulo.getArea() <<" metros cuadrados"<< endl;
    system("pause");
    return 0;
}

