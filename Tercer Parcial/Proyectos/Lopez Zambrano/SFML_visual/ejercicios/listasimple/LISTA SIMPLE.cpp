// LISTA SIMPLE.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Menu.h"
#include "Lista.h"
#include "ingreso.h"
using namespace std;
void menuGeneral();
int main()
{
	menuGeneral();
    system("pause");
    return 0;
}

void menuGeneral()
{
	int opcion;
	bool repite = true;
	Lista lista;
	//TITULO Y OPCIONES DEL MENU
	string titulo = "MENU PRINCIPAL";
	string* opciones = new string[4];
	*(opciones + 0) = "Ingresar dato por cabeza";
	*(opciones + 1) = "Ingresar dato por cola";
	*(opciones + 2) = "Imprimir lista";
	*(opciones + 3) = "Salir";
	int n = 4;

	do {
		opcion = menu(titulo, opciones, n);

		//ALTERNATIVAS
		switch (opcion)
		{
		case 1: {
			system("cls");
			fflush(stdin);
			int ingreso;
			ingreso = ingresarEntero("Ingrese un numero: ");
			lista.ingresarDatoInicio(ingreso);
			repite = true;
			break;
		}
		case 2: {
			fflush(stdin);
			system("cls");
			int ingreso;
			ingreso = ingresarEntero("Ingrese un numero: ");
			lista.ingresarDatoFinal(ingreso);
			repite = true;
			break;
		}
		case 3: {
			system("cls");
			lista.imprimir();
			system("pause");
			repite = true;
			break;
		}
		case 4: {
			system("cls");
			delete[] opciones;
			repite = false;
			break;
		}
		}
	} while (repite);
}
