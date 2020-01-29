// ejercicio 88.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ingreso.h"
using namespace std;
void tipoCaracter(char caracter);
int main()
{
    char caracter = ingresarCaracter("Ingrese un caracter: ");
    tipoCaracter(caracter);
    system("pause");
    return 0;
}

void tipoCaracter(char caracter)
{
    if (isalpha(caracter)) {
        if (caracter >= 65 && caracter <= 90)
            if (caracter == 65 || caracter == 69 || caracter == 73 || caracter == 79 || caracter == 85)
                cout << "vocal MAYUSCULA." << endl;
            else
                cout << "consonante MAYUSCULA." << endl;
        else
            if (caracter >= 97 && caracter <= 122)
                if (caracter == 97 || caracter == 101 || caracter == 105 || caracter == 111 || caracter == 117)
                    cout << "vocal minuscula" << endl;
                else
                    cout << "consonante minuscula." << endl;
    }
    else
        cout << "otro caracter." << endl;
        
  


}