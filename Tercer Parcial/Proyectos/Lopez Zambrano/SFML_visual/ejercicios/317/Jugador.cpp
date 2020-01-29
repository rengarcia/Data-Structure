#include "Jugador.h"
#include "Validacion.h"
#include <iostream>

using namespace std;
Validacion validacion;

bool Jugador::jugador1(int** matriz)
{
	int fila = 0;
	int columna = 0;
	string temp;

	//condiciones de victoria
	int vic1 = 0;
	int vic2 = 0;
	int vic3 = 0;
	int vic4 = 0;

	bool result = false;

	cout << endl << "Jugador 1" << endl;
	cout << "Ingrese fila: ";
	cin >> temp;
	temp = validacion.soloNumeros(temp);
	fila = stoi(temp) - 1;

	cout <<"Ingrese columna: ";
	cin >> temp;
	temp = validacion.soloNumeros(temp);
	columna = stoi(temp) - 1;

	while ( columna > 2 || fila > 2 || *(*(matriz + fila) + columna) == 1 || *(*(matriz + fila) + columna) == 2 ) {
		cout << "Los valores ingresados estan fuera de rango o la casilla ya esta ocupada" << endl;
		cout<< "Ingrese fila: ";
		cin >> temp;
		temp = validacion.soloNumeros(temp);
		fila = stoi(temp) - 1;

		cout << "Ingrese columna: ";
		cin >> temp;
		temp = validacion.soloNumeros(temp);
		columna = stoi(temp) - 1;
	}

	*(*(matriz + fila)+columna) = 1;

	for (int i = 0; i < 3; i++) {
		vic1 = 0;
		vic2 = 0;
		if (*(*(matriz + i) + i) == 1) {
			vic3++;
		}
		if (*(*(matriz + i) + 2-i) == 1) {
			vic4++;
		}
		for (int j = 0; j < 3; j++) {
			if (*(*(matriz + i) + j) == 1) {
				vic1++;
			}
			if (*(*(matriz + j) + i) == 1) {
				vic2++;
			}
		}
		if (vic1 == 3 || vic2 == 3 || vic3 == 3 || vic4 == 3) {
			result = true;
		}
	}
	return result;
}

bool Jugador::jugador2(int** matriz)
{
	int fila = 0;
	int columna = 0;
	string temp;

	//condiciones de victoria
	int vic1 = 0;
	int vic2 = 0;
	int vic3 = 0;
	int vic4 = 0;

	bool result = false;
	
	cout << endl <<"Jugador 2" << endl;
	cout << "Ingrese fila: ";
	cin >> temp;
	temp = validacion.soloNumeros(temp);
	fila = stoi(temp) - 1;

	cout << "Ingrese columna: ";
	cin >> temp;
	temp = validacion.soloNumeros(temp);
	columna = stoi(temp) - 1;

	while (columna > 2 || fila > 2 || *(*(matriz + fila) + columna) == 1 || *(*(matriz + fila) + columna) == 2) {
		cout << "Los valores ingresados estan fuera de rango o la casilla ya esta ocupada" << endl;
		cout << "Ingrese fila" << endl;
		cin >> temp;
		temp = validacion.soloNumeros(temp);
		fila = stoi(temp) - 1;

		cout << "Ingrese columna" << endl;
		cin >> temp;
		temp = validacion.soloNumeros(temp);
		columna = stoi(temp) - 1;
	}

	*(*(matriz + fila) + columna) = 2;

	for (int i = 0; i < 3; i++) {
		vic1 = 0;
		vic2 = 0;
		if (*(*(matriz + i) + i) == 2) {
			vic3++;
		}
		if (*(*(matriz + i) + 2 - i) == 2) {
			vic4++;
		}
		for (int j = 0; j < 3; j++) {
			if (*(*(matriz + i) + j) == 2) {
				vic1++;
			}
			if (*(*(matriz + j) + i) == 2) {
				vic2++;
			}

			if (vic1 == 3 || vic2 == 3 || vic2 == 3 || vic4 == 3) {
				result = true;
			}
		}
	}
	return result;
}

