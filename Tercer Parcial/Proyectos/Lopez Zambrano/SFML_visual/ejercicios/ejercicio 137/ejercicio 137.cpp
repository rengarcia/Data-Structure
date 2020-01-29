// ejercicio 137.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>
#include <math.h>
#include "ingreso.h"
using namespace std;
void gotoxy(int x,int y);
int main()
{
    int a = ingresarEntero("Ingrese desde donde quiere que se muestre la funcion: ");
    int b = ingresarEntero("Ingrese hasta donde quiere que se muestre la funcion: ");
    for (a; a <= b; a++) {
        gotoxy(a, cos(a));
        cout << "*" << endl;
    }
    system("pause");
    return 0;
}

void gotoxy(int x, int y)
{
    COORD c = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
