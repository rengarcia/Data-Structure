// ejercicio 167.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ingreso.h"
#include "misFunciones.h"
using namespace std;
int main()
{
    int n = ingresarEntero("Ingrese numero: ");
    cin.ignore();
    string palabras = ingresarSoloTexto("Ingrese palabras: ");
    int pal = palabrasConLongitud(palabras, n);
    cout << "existen " << pal << " con esa longitud" << endl;
    system("pause");
    return 0;
}

