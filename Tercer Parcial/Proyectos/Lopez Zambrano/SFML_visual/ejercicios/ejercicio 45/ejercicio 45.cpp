// ejercicio 45.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Circunferencia.h"
using namespace std;
int main()
{
    Circunferencia circunferencia;
    double radio;
    cout << "Ingrese el radio del circulo: " << endl;
    cin >> radio;
    circunferencia.setRadio(radio);
    circunferencia.calcularPerimetro(radio);
    circunferencia.calcularArea(radio);
    cout << "El perimetro de la circunferencia es: " << circunferencia.getPerimetro() << endl;
    cout << "El area de la circunferencia es: " << circunferencia.getArea() << endl;
    system("pause");
    return 0;
}


