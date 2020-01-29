// ejercicio 39.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Interes.h"
using namespace std;
int main()
{
    Interes euros;
    double cantEuros;
    double porcentaje;
    int anio;
    double interes;
    cout << "Ingrese cantidad de euros: " << endl;
    cin >> cantEuros;
    cout << "Ingrese tasa de interes: " << endl;
    cin >> porcentaje;
    cout << "Ingrese anios: " << endl;
    cin >> anio;
    euros.setCapital(cantEuros);
    euros.setPorcentaje(porcentaje);
    euros.setAnio(anio);
    interes = euros.calcularInteres(euros.getCapital(), euros.getPorcentaje(), euros.getAnio());
    cout << "el interes de " << euros.getCapital() << " al " << euros.getPorcentaje() << " % es: " << interes << endl;
    system("pause");
    return 0;
}

