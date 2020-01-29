// MIslibrerias.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ingreso.h"
#include "Menu.h"
using namespace std;

int main()
{
    string* opciones = new string[3];
    *(opciones + 0) = "saludo";
    *(opciones + 1) = "salu2";
    *(opciones + 2) = "sssssalud";
    
    int opcion = menu("titulopapu", opciones, 3);
    int numero;
    string nombre;

    nombre = ingresarSoloTexto("Ingrese su nombre: ");
    numero = ingresarEntero("Ingrese un numero: ");
    cout << "Su nombre es: " << nombre << " e ingreso el numero " << numero << endl;
    delete[] opciones;
    system("pause");
    return 0;
}

