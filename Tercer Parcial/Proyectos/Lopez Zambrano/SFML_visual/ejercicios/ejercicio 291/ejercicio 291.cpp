// ejercicio 291.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*"Define una funci´on que, dados dos par´ametros b y x, devuelva el valor de logb
(x), es decir, el logaritmo en base b de
x."*/
//

#include <iostream>
#include "misFunciones.h"
#include "ingreso.h"
using namespace std;
int main()
{
    double base = ingresarDouble("Ingrese base de logaritmo: ");
    double numero = ingresarDouble("Ingrese numero a sacar logaritmo: ");
    double respuesta = miLogaritmo(base, numero);
    cout << "El logaritmo es: " << respuesta << endl;
    system("pause");
    return 0;
}
