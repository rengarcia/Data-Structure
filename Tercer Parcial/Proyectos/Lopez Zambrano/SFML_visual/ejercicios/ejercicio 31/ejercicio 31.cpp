// ejercicio 31.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*31 Dise˜na un programa que, a partir del valor del lado de un cuadrado (3 metros), muestre el valor de su per´ımetro (en
metros) y el de su ´area (en metros cuadrados).
(El per´ımetro debe darte 12 metros y el ´area 9 metros cuadrados.)
*/
#include <iostream>
#include "areaCuadrado.h"
using namespace std;
int main()
{
    //VARIABLES
    Cuadrado cuadrado;
    int lado;
    //INGRESOS
    cout << "Ingrese valor de lado del cuadrado" << endl;
    cin >> lado;
    //SETTEO
    cuadrado.setLado(lado);
    //OPERACIONES
    cuadrado.calcularArea(cuadrado.getLado());
    cuadrado.calcularPerimetro(cuadrado.getLado());
    //IMPRESIONES
    cout << "El perimetro del cuadrado es: ";
    cout<< cuadrado.getPerimetro() << endl;
    cout << "El area del cuadrado es: ";
    cout<< cuadrado.getArea() << endl;
    system("pause");
    return 0;
}
