#include "OperacionesPolaca.h"
#include "NodoChar.h"
#include "OperacionesNodo.h"
#include "Validaciones.h"
#include <iostream>

OperacionesNodo operacion;
Validaciones validacion; 


string OperacionesPolaca::infijaAPosfija(string infix) {
	infix = '(' + infix + ')';
	NodoChar* nodo = NULL;
	string resultado;

	for (int i = 0; i < infix.size(); i++) {

		if (isalpha(infix.at(i)) || isdigit(infix[i]))
			resultado += infix.at(i);
		else if (infix.at(i) == '(')
		
		operacion.push_char(nodo, '(');

		else if (infix.at(i) == ')') {
			
			while (operacion.top_char(nodo) != '(') {
				resultado += operacion.top_char(nodo);

				operacion.pop_char(nodo);
			}

			operacion.pop_char(nodo);
		}
		else {
			if (validacion.esOperador(operacion.top_char(nodo))) {
				while (obtenerPrioridad(infix.at(i)) <= obtenerPrioridad(operacion.top_char(nodo))) {
					resultado += operacion.top_char(nodo);

					operacion.pop_char(nodo);
				}
				operacion.push_char(nodo, infix.at(i));
			}
		}
	}
	return resultado;
}

string OperacionesPolaca::infijaAPrefija(string infix) {
	
	operacion.invertirCadena(infix);

	for (int i = 0; i < infix.size(); i++) {

		if (infix.at(i) == '(') {
			infix.at(i) = ')';    
			i++;
		}
		else if (infix.at(i) == ')') {
			infix.at(i) = '(';
			i++;
		}
	}

	string prefix = infijaAPosfija(infix);

	operacion.invertirCadena(prefix);

	return prefix;
}

int OperacionesPolaca::obtenerPrioridad(char C) {
	if (C == '-' || C == '+')
		return 1;
	else if (C == '*' || C == '/')
		return 2;
	else if (C == '^')
		return 3;
	else
	return 0;
}