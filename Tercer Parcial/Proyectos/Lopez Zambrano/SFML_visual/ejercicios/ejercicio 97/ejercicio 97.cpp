// ejercicio 97.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
    int i = 3;
    cout << "declaramos a la variable i con el valor de 3" << endl;
    cout << "Ingresamos a un bucle con una condicion" << endl;
    while (i < 10) {
        cout << "verificamos si se cumple la condicion para salir del bucle, caso contrario repetir" << endl;
        i += 2;
        cout << "incrementamos el valor de i por 2" << endl;
        cout << "ahora i vale: " << i << endl;
        cout << "imprimimos el valor de i" << endl;
        cout << i << endl;
    }
    cout << "salimos del bucle ya que la condicion no se cumple" << endl;
    cout << "imprimimos hecho" << endl;
    cout << "Hecho." << endl;
    system("pause");
    return 0;
}

