// ejercicio 301 - 302.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*301 Dise˜na una funci´on sin argumentos que devuelva un n´umero aleatorio mayor o igual que 0.0 y menor que 10.0.
Puedes llamar a la funci´on random desde tu funci´on.
· 302 Dise˜na una funci´on sin argumentos que devuelva un n´umero aleatorio mayor o igual que −10.0 y menor que 10.0.*/

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
double aleatorio();
int main()
{
    srand(time(NULL));
    cout << aleatorio() << endl;
    system("pause");
    return 0;
}

double aleatorio()
{
    srand(time(NULL));
    double rando = (rand() % 11) - 10;
    return rando;
}