// ejercicio 116.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ingreso.h"
#include "Menu.h"
#include "Vector.h"
#include "Operaciones.h"
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
	Vector v1;
	Vector v2;
	Operaciones operaciones;
	//TITULO Y OPCIONES DEL MENU
	string titulo = "MENU PRINCIPAL";
	string* opciones = new string[9];
	*(opciones + 0) = "Introducir el primer vector";
	*(opciones + 1) = "Introducir el segundo vector";
	*(opciones + 2) = "Calcular la suma";
	*(opciones + 3) = "Calcular la diferencia";
	*(opciones + 4) = "Calcular el producto escalar";
	*(opciones + 5) = "Calcular el producto vectorial";
	*(opciones + 6) = "Calcular el angulo (en grados) entre ellos";
	*(opciones + 7) = "Calcular la longitud";
	*(opciones + 8) = "Finalizar";
	int n = 9;

	do {
		opcion = menu(titulo, opciones, n);

		//ALTERNATIVAS
		switch (opcion)
		{
		case 1: {
			system("cls");
			fflush(stdin);
			double x1 = ingresarDouble("Ingrese valor para x: ");
			double y1 = ingresarDouble("Ingrese valor para y: ");
			double z1 = ingresarDouble("Ingrese valor para z: ");
			v1.setX(x1);
			v1.setY(y1);
			v1.setZ(z1);
			repite = true;
			break;
		}	
		case 2: {
			fflush(stdin);
			system("cls");
			double x2 = ingresarDouble("Ingrese valor para x: ");
			double y2 = ingresarDouble("Ingrese valor para y: ");
			double z2 = ingresarDouble("Ingrese valor para z: ");
			v2.setX(x2);
			v2.setY(y2);
			v2.setZ(z2);
			repite = true;
			break;
		}
		case 3: {
			system("cls");
			Vector resultado = operaciones.sumar(v1, v2);
			resultado.imprimir();
			repite = true;
			break;
		}
		case 4: {
			system("cls");
			Vector diferencia;
			string* opciones = new string[2];
			*(opciones + 0) = "Primer vector menos segundo vector";
			*(opciones + 1) = "Segundo vector menos primer vector";
			int seleccion = menu("Diferencia", opciones, 2);
			switch (seleccion){
				case 1:
					diferencia = operaciones.diferenciar(v1, v2);
					break;
				case 2:
					diferencia = operaciones.diferenciar(v2, v1);
					break;
			}
			delete[] opciones;
			diferencia.imprimir();
			repite = true;
			break;
		}
			
		case 5: {
			double pEscalar = operaciones.productoEscalar(v1, v2);
			cout << "el resultado es: " << pEscalar << endl;
			repite = true;
			break;
		}
			
		case 6: {
			system("cls");
			Vector pVectorial;
			string* opciones = new string[2];
			*(opciones + 0) = "Primer vector por segundo vector";
			*(opciones + 1) = "Segundo vector por primer vector";
			int seleccion = menu("Producto Vectorial", opciones, 2);
			switch (seleccion)
			{
			case 1:
				pVectorial = operaciones.productoVectorial(v1, v2);
				break;
			case 2:
				pVectorial = operaciones.productoVectorial(v2, v1);
				break;
			}
			delete[] opciones;
			pVectorial.imprimir();
			repite = true;
			break;
		}
			
		case 7: {
			double angulo = operaciones.angulo(v1, v2);
			cout << "el angulo entre los vectores es: " << angulo << endl;
			break;
		}
			
		case 8: {
			system("cls");
			double longitud1 = operaciones.longitud(v1);
			double longitud2 = operaciones.longitud(v2);
			cout << "la longitud del vector v1 es:" << longitud1 << endl;
			cout << "la longitud del vector v2 es: " << longitud2 << endl;
			repite = true;
			break;
		}
			
		case 9: {
			repite = false;
			break;
		}
			
		} 
	} while (repite);
}