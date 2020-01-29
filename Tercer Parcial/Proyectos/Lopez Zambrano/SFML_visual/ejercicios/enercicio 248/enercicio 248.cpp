// enercicio 248.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Identidad.h"
#include "ingreso.h"
int main()
{
    Identidad obj;
    float** matriz;
    float** inversa;
    float** respuesta;
    int dimension = 0;
    do {
        system("cls");
        dimension = ingresarEntero("Ingrese dimension de la matriz: ");
    } while (dimension == 0 || dimension < 0);

    //RESERVO MEMORIA PARA LAS MATRICES
    matriz = obj.inicializar(dimension);
    inversa = obj.inicializar(dimension);
    respuesta = obj.inicializar(dimension);

    //ENCERO LAS MATRICES PARA EVITAR CUALQUIER FALLA
    obj.encerar(dimension, matriz);
    obj.encerar(dimension, respuesta);
    obj.encerar(dimension, inversa);

    //PIDO QUE SE INGRESEN LOS VALORES DE LA MATRIZ
    matriz = obj.ingresarNumeros(dimension, matriz);
    cout << "Matriz ingresada: " << endl;
    obj.mostrar(dimension, matriz);

    cout << "\n\n\n";

    //CALCULO LA INVERSA DE LA MATRIZ ANTES INGRESADA
    inversa = obj.calcularInversa(dimension, matriz);
    cout << "Matriz inversa: " << endl;
    obj.mostrarInversa(dimension, inversa);

    cout << "\n\n\n";

    //MULTIPLICO LA MATRIZ CON SU INVERSA Y GUARDO EL RESULTADO (MATRIZ IDENTIDAD) EN RESPUESTA
    respuesta = obj.multiplicar(dimension, matriz, inversa);
    cout << "Matriz resultante (identidad): " << endl;
    obj.mostrar(dimension, respuesta);


    system("pause");
    return 0;
}