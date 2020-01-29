// ejercicio 303.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*303 Para dise˜nar un juego de tablero nos vendr´a bien disponer de un ✭✭dado electr´onico✮✮. Escribe una funci´on Python
sin argumentos llamada dado que devuelva un n´umero entero aleatorio entre 1 y 6.
*/
#include <iostream>
#include <stdlib.h>
#include<time.h>
using namespace std;
int dado();
int main()
{
    srand(time(NULL));
    cout << dado() << endl;
    cout << dado() << endl;
    cout << dado() << endl;
    cout << dado() << endl;
    cout << dado() << endl;
    cout << dado() << endl;
    system("pause");
    return 0;
}

int dado()
{
    int numero = (rand() % 6) + 1;
    return numero;
}
