/**
 *
 *                                      UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
 *                                          CARRERA DE INGENIERIA DE SOFTWARE
 *                                                  TERCER SEMESTRE
 *
 * PROYECTO DEL PRIMER PARCIAL
 * AUTORES: Sebastian Alvarez
 *          Renan Garcia
 * NRC:
 * FECHA DE MODIFICACION: 5/NOV/2019
 * FECHA DE ENTREGA: 7/NOV/2019
 *
 * STATUS: Finalizado
 */

#pragma once
/**
 *
 * @author Sebastian Alvarez
 * @date 23/SEP/2019
 */
#include <iostream>
#include <string>

using namespace std;

class Ingreso {
public:
	string ingresar(string);
	bool validarTipoFloat(string);
	bool validarTipoInt(string);
	bool validarTipoString(string);
};
/**
 *
 * @brief Ingresa datos desde teclado a valor
 * @param msg el mensage de ingreso
 * @return la conversion de string a flotante
 */
string Ingreso::ingresar(string msg) {
	string dato_a_validar;
	bool esValido = false;

	while (!esValido) {
		try {
			cout << msg;
			getline(cin, dato_a_validar);
			if (msg.find("flotante") != std::string::npos) {
				esValido = validarTipoFloat(dato_a_validar);
			}
			else if (msg.find("entero") != std::string::npos) {
				esValido = validarTipoInt(dato_a_validar);
			}
			else if (msg.find("cadena") != std::string::npos) {
				esValido = validarTipoString(dato_a_validar);
			}

			if (!esValido) {
				throw dato_a_validar;
			}
		}
		catch (string e) {
			cout << "El dato (" << e << ") no es valido" << endl;
		}
	}
	return dato_a_validar;
}
/**
 *
 * @brief Valida si el numero ingresado es realmente un float
 * @param numero el numero ingresado por usuario
 * @return un booleano verdadero si el numero es float y falso si no lo es
 */
bool Ingreso::validarTipoFloat(string numero) {
	int inicio = 0;
	if (numero.length() == 0) {
		return 0;
	}
	if (numero[0] == '+' || numero[0] == '-') {
		inicio = 1;
		if (numero.length() == 1) {
			return 0;
		}
	}
	for (int i = inicio; numero.length() > i; i++) {
		if (!isdigit(numero[i]) && numero[i] != '.') {
			return 0;
		}
	}
	return 1;
}
/**
 *
 * @param numero string a verificar si es Int
 * @return un booleano verdadero si es entero, caso contrario falso
 */
bool Ingreso::validarTipoInt(string numero) {
	int inicio = 0;
	if (numero.length() == 0) {
		return 0;
	}
	if (numero[0] == '+' || numero[0] == '-') {
		inicio = 1;
		if (numero.length() == 1) {
			return 0;
		}
	}
	for (int i = inicio; numero.length() > i; i++) {
		if (!isdigit(numero[i])) {
			return 0;
		}
	}
	return 1;
}
/**
 *
 * @param numero cadena a validar si es un string
 * @return un booleano verdadero si es string, caso contrario falso
 */
bool Ingreso::validarTipoString(string numero) {
	if (numero.length() == 0) {
		return 0;
	}

	for (int i = 0; numero.length() > i; i++) {
		if (isdigit(numero[i])) {
			return 0;
		}
	}
	return 1;
}