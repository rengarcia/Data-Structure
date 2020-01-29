// ejercicio 96.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
    int i = 0;
    cout << "Definimos una variable entera i con el valor de 0" << endl;
    cout << "entramos a un bucle while" << endl;
    while (i < 10) {
        cout << "Verificamos la condicion del bucle, caso contrario repetimos las instrucciones" << endl;
        cout << "imprimimos el valor de i" << endl;
        cout << i << endl;
        i += 2;
        cout << "sumamos el valor de i mas 2" << endl;
        cout << "ahora i vale: " << i << endl;
    }
    cout << "salimos del bucle" << endl;
    cout << "imprimimos hecho" << endl;
    cout << "Hecho" << endl;
    system("pause");
    return 0;
}

