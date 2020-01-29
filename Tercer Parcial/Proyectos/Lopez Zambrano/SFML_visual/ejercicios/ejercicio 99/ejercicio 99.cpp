// ejercicio 99.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
    int i = 10;
    cout << "declaramos la variable i con el valor de 10" << endl;
    cout << "ingresamos al bucle" << endl;
    cout << "verificamos si se cumple la condicion o no" << endl;
    while (i < 2) {
        i *= 2;
        cout << "multiplicamos el valor de i por 2" << endl;
        cout << "ahora i vale:" << i << endl;
        cout << i << endl;
    }
    cout << "finaliza el programa" << endl;
    system("pause");
    return 0;
}

