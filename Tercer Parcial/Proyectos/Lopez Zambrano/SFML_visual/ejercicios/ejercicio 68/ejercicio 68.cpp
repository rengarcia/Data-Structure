// ejercicio 68.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ingreso.h"
#include "Desglosar.h"
using namespace std;
int main()
{
    Desglosar dinero;
    int billetes = ingresarEntero("Ingrese cantidad de billetes: ");
    dinero.desglosarEuros(billetes);
    cout << dinero.getDoscientos() << " billetes de 200 euros"<<endl;
    cout << dinero.getVeinte() << " billetes de 20 euros" << endl;
    cout << dinero.getDiez() << " billetes de 10 euros" << endl;
    cout << dinero.getDos() << " billetes de 2 euros" << endl;
    system("pause");
    return 0;
}

