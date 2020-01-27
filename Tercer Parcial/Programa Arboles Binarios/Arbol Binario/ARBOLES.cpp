// ARBOLES.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
Autor: Zambrano Andrés
Fecha Creacion: 118/01/2020
Estructura de Datos
Ing. Fernando Solis
*/
#include <iostream>
#include "Menu.h"
#include "ArbolBB.h"
#include "ingreso.h"
using namespace std;
void menuPrincipal();
int main()
{
    menuPrincipal();
    system("pause");
    return 0;
}

void menuPrincipal()
{
    Nodo* arbol = NULL;
    ArbolBB operador;
    int contador = 0;
    bool repite = true;
    bool creador = true;
    string titulo = "MENU DE OPCIONES";
    string* opciones = new string[8];
    *(opciones + 0) = "Insertar Nodo";
    *(opciones + 1) = "Mostrar InOrden";
    *(opciones + 2) = "Mostrar PreOrden";
    *(opciones + 3) = "Mostrar PosOrden";
    *(opciones + 4) = "calcular Nivel";
    *(opciones + 5) = "calcular Altura";
    *(opciones + 6) = "Mostrar arbol";
    *(opciones + 7) = "Salir";
    int n = 8;
    do {
        int opcion = menu(titulo, opciones, n);
        switch (opcion)
        {
        case 1:
        {
            system("cls");
            int dato = ingresarEntero("Ingrese un numero: ");
            operador.insertarNodo(arbol, dato);
            repite = true;
            break;
        }
        case 2:
        {
            system("cls");
            cout << "Mostrando recorrido InOrden" << endl;
            operador.inOrden(arbol);
            cout << endl;
            repite = true;
            system("pause");
            break;
        }
        case 3:
        {
            system("cls");
            cout << "Mostrando recorrido PreOrden" << endl;
            operador.preOrden(arbol);
            cout << endl;
            repite = true;
            system("pause");
            break;
        }
        case 4:
        {
            system("cls");
            cout << "Mostrando recorrido PosOrden" << endl;
            operador.postOrden(arbol);
            cout << endl;
            repite = true;
            system("pause");
            break;
        }
        case 5:
        {
            cout << "Nivel del Arbol" << endl;
            int dato = ingresarEntero("Ingrese dato para encontrar el nivel: ");
            cout << "El nivel del arbol es: " << operador.verNivel(1, arbol, dato) << endl;
            system("pause");
            break;
        }
        case 6:
        {
            system("cls");
            cout << "Altura del arbol: " << operador.altura(arbol);
            system("pause");
            break;
        }
        case 7:
        {
            system("cls");
            operador.mostrarArbol(arbol,contador);
            system("pause");
            break;
        }
        case 8:
        {
            repite = false;
            break;
        }
        }
    } while (repite);
        delete[] opciones;
}