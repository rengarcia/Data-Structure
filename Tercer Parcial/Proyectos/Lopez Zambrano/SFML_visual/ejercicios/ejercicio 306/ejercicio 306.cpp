// ejercicio 306.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*Dise˜na una funci´on es_primo que determine si un n´umero es primo (devolviendo True) o no (devolviendo False).
Dise˜na a continuaci´on un procedimiento muestra_primos que reciba un n´umero y muestre por pantalla todos los n´umeros
primos entre 1 y dicho n´umero.
*/

#include <iostream>
#include <math.h>
#include "ingreso.h"
using namespace std;
bool esPrimo(int numero);
void mostrarPrimos(int numeroLimite);
int main()
{
    int numero = ingresarEntero("Ingrese un numero: ");
    if (esPrimo(numero))
        cout << "el numero " << numero << " es primo" << endl;
    else
        cout << "el numero no es primo" << endl;
    mostrarPrimos(numero);
    system("pause");
    return 0;
}

bool esPrimo(int numero)
{
    int divisor = 1;
    for (int i = 1; i <= sqrt(numero); i++) {
        if (numero % i == 0) {
            divisor++;
        }
    }
    if (divisor > 2)
        return false;
    return true;
}

void mostrarPrimos(int numeroLimite)
{
    for (int i = 1; i <= numeroLimite; i++) {
        if (esPrimo(i))
            cout << i << endl;
    }
}