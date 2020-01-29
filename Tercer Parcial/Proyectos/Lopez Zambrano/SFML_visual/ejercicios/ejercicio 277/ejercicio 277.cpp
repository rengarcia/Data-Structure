// ejercicio 277.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Lista.h"
#include "ingreso.h"
#include "Menu.h"
using namespace std;
void menuGeneral();
int operacion(Lista lista,int resultado);
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
	string* opciones = new string[5];
	*(opciones + 0) = "Ingresar dato por cabeza";
	*(opciones + 1) = "Ingresar dato por cola";
	*(opciones + 2) = "Imprimir lista";
	*(opciones + 3) = "Realizar operacion";
	*(opciones + 4) = "Salir";
	int n = 5;

	do {
		opcion = menu(titulo, opciones, 5);

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
			int respuesta = lista.operacion();
			cout << respuesta << endl;
			system("pause");
			repite = true;
			break;
		}
		case 5: {
			system("cls");
			delete[] opciones;
			repite = false;
			break;
		}
		}
	} while (repite);
}

