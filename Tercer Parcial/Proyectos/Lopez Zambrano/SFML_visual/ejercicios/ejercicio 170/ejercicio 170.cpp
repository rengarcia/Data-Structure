// ejercicio 170.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "ingreso.h"
using namespace std;
void palabrasLargas(string frase, int longitud);
int main()
{
    string frase = ingresarSoloTexto("Ingrese palabras: ");
    int numero = ingresarEntero("Ingrese numero: ");
    palabrasLargas(frase, numero);
    system("pause");
    return 0;
}

void palabrasLargas(string frase, int longitud)
{
    int lon = frase.length();
    bool flag = false;
    char* palabras = new char[lon];
    strcpy(palabras, frase.c_str());
    char* token;

    /* get the first token */
    token = strtok(palabras, " ");

    /* walk through other tokens */
    while (token != NULL) {
        if (strlen(token) >= longitud) {
            flag = true;
        }

        token = strtok(NULL, " ");
    }
    if (flag)
        cout << "<<Hay palabras largas>>" << endl;
    else
        cout << "<<No hay palabras largas>>" << endl;
}