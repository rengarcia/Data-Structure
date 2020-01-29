// ejercicio 95.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
    int i = 0;
    cout << "Inicializamos la variable i con el valor de 0" << endl;
    cout << "Utilizamos una sentencia de bucle while" << endl;
    while (i <= 3) {
        cout << "Imprimimos el valor de i" << endl;
        cout << i << endl;
        cout << "Incrementamos el valor de i por 1" << endl;
        i += 1;
        cout << "ahora i vale: " << i << endl;
        cout << "Verificamos si se cumple la condicion de bucle, caso contrario repetimos" << endl;
    }
    cout << "la condicion del bucle ya no se cumple" << endl;
    cout << "salimos del bucle" << endl;
    cout << "imprimimos el mensaje hecho" << endl;
    cout << "Hecho" << endl;
    system("pause");
    return 0;
}


