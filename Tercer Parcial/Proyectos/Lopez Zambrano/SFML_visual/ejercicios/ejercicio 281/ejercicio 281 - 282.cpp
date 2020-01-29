// ejercicio 281.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
281 Haz una funci´on que reciba una lista de n´umeros y devuelva la media de dichos n´umeros. Ten cuidado con la lista
vac´ıa (su media es cero).
282 Disenia una funci´on que calcule el productorio de todos los n´umeros que componen una lista.*/

#include <iostream>
#include "ingreso.h"
#include "Lista.h"
#include "Menu.h"
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
	string* opciones = new string[6];
	*(opciones + 0) = "Ingresar dato por cabeza";
	*(opciones + 1) = "Ingresar dato por cola";
	*(opciones + 2) = "Imprimir lista";
	*(opciones + 3) = "Sacar media";
	*(opciones + 4) = "Sacar producto";
	*(opciones + 5) = "Salir";
	int n = 6;

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
			double media = lista.operacion();
			cout << "La media de los numeros es: " << media << endl;
			system("pause");
			repite = true;
			break;
		}
		case 5:{
			system("cls");
			double producto = lista.producto();
			cout << "El producto de los elementos de la lista es: " << producto << endl;
			system("pause");
			repite = true;
			break;
		}
		case 6: {
			system("cls");
			delete[] opciones;
			repite = false;
			break;
		}
		}
	} while (repite);
}
