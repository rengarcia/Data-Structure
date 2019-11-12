/***********************************************************************
 * Module:  ingreso.h
 * Author:  Kevin Duy, Carlos Puco
 * Modified: sabado, 26 de octubre de 2019 17:21:23
 * Purpose: Declaration of the class ingreso
 ***********************************************************************/

#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

class Ingreso {
	public:
		int ingresarEntero();
		double ingresarDouble();
		string ingresarLetra();
		float ingresarFloat();
		bool validar(string);
		bool validarEntero(string);
		bool validarLetra(string);
};

int Ingreso::ingresarEntero() {
		string numero;
		bool valido = false;
		while(!valido) {
			try {
				cin >> numero;
				valido = validarEntero(numero);
				if(!valido) {
					throw numero;
				}
			}catch(string e) {
				cout << "El numero " << e << " no es valido" << endl;
			}
		}
		return atoi(numero.c_str());
	}
	
double Ingreso::ingresarDouble() {
		string numero;
		bool valido = false;
		while(!valido) {
			try {
				cin >> numero;
				valido = validar(numero);
				if(!valido) {
					throw numero;
				}
			}catch(string e) {
				cout << "El numero " << e << " no es valido" << endl;
			}
		}
		return atof(numero.c_str());
	}
	
string Ingreso::ingresarLetra() {
		string palabra;
		bool valido = false;
		while(!valido) {
			try {
				cin >> palabra;
				valido = validarLetra(palabra);
				if(!valido) {
					throw palabra;
				}
			}catch(string e) {
				cout << "La palabra " << e << " no es valida" << endl;
			}
		}
		return palabra;
	}
	
float Ingreso::ingresarFloat() {
		string numero;
		bool valido = false;
		while(!valido) {
			try {
				cin >> numero;
				valido = validar(numero);
				if(!valido) {
					throw numero;
				}
			}catch(string e) {
				cout << "La palabra " << e << " no es valida" << endl;
			}
		}
		return atof(numero.c_str());
	}
	
bool Ingreso::validar(string numero) {
		int inicio = 0;
		if(numero.length() == 0) {
			return 0;
		}
		if(numero[0] == '+' || numero[0] == '-') {
			inicio = 1;
			if(numero.length() == 1) {
				return 0;
			}
		}
		for(int i=inicio; i<numero.length(); i++) {
			if(!isdigit(numero[i]) && numero[i] != '.') {
				return 0;
			}
		}
		return 1;
	}
	
bool Ingreso::validarEntero(string numero) {
		int inicio = 0;
		if(numero.length() == 0) {
			return 0;
		}
		if(numero[0] == '+' || numero[0] == '-') {
			inicio = 1;
			if(numero.length() == 1) {
				return 0;
			}
		}
		for(int i=inicio; i<numero.length(); i++) {
			if(!isdigit(numero[i])) {
				return 0;
			}
		}
		return 1;
}

bool Ingreso::validarLetra(string palabra) {
	char c;
	for(int i=0; i<palabra.size(); i++) {
		c=palabra[i];
		if(isalpha(c) == 0) {
			if(isspace(c) == 0) {
				return 0;
			}
		}
	}
	return 1;
}
