// ejercicio 286.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*286 Define una funci´on que, dada una cadena x, devuelva otra cuyo contenido sea el resultado de concatenar 6 veces x
consigo misma.*/

#include <iostream>
#include "ingreso.h"
using namespace std;
string concatenador(string cadena);
int main()
{
    string cadena = ingresarSoloTexto("Ingrese cadena: ");
    cout << "La nueva cadena es: " << concatenador(cadena) << endl;
    system("pause");
    return 0;
}

string concatenador(string cadena)
{
    string resultado = "";
    for (int i = 0; i < 6; i++) {
        resultado = resultado + cadena;
    }
    return resultado;
}