// ejercicio 266 - 267.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*266 Define una funci´on que convierta radianes en grados.
(Recuerda que 360 grados son 2π radianes.)
· 267 Define una funci´on que convierta grados en radianes
*/

#define PI 3.14159265

#include <iostream>
#include "ingreso.h"
using namespace std;
double gradosARadianes(double angulo);
double radianesAGrados(double angulo);
int main()
{
    double numero = ingresarDouble("Ingrese grados a convertir: ");
    cout << "El angulo "<<numero<<" en radianes es:"<< gradosARadianes(numero) << endl;
    system("pause");
    return 0;
}

double gradosARadianes(double angulo)
{
    double conversion = angulo * (PI / 180);
    return conversion;
}

double radianesAGrados(double angulo)
{
    double conversion = angulo * (180 / PI);
    return conversion;
}