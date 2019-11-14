/**
  * Universidad De las Fuerzas Armadas ESPE
  * Carrera: Ingeniería de Software
  * Materia: Estructura de Datos
  * NRC: 2969
  * @file ingreso.h
  * @version 1.0.0
  * @date 23/09/2019
  * @author Kevin Duy
  * @title Division
  * @brief Validacion del ingreso de datos
*/

#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

class Ingreso {
	public:
		int ingresarEntero();
		double ingresarDouble();
		float ingresarFloat();
		string ingresarLetra();
		bool validar(string);
		bool validarEntero(string);
		bool validarLetra(string);
		int validarCedula();
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

int Ingreso::validarCedula() {
	Ingreso leer;
	bool comprobar = true;
	int cedula,ced,pares,impares,total,dec=0;
    int a,b,c,d,e,f,g,h,i,j,k;
	while(comprobar){
    cout<<"Ingrese su cedula: "<<endl;
    cedula = ingresarEntero();
    ced=cedula;
    a=cedula/1000000000;
    cedula=cedula-(a*1000000000);
    b=cedula/100000000;
    cedula=cedula-(b*100000000);
    c=cedula/10000000;
    cedula=cedula-(c*10000000);
    d=cedula/1000000;
    cedula=cedula-(d*1000000);
    e=cedula/100000;
    cedula=cedula-(e*100000);
    f=cedula/10000;
    cedula=cedula-(f*10000);
    g=cedula/1000;
    cedula=cedula-(g*1000);
    h=cedula/100;
    cedula=cedula-(h*100);
    i=cedula/10;
    cedula=cedula-(i*10);
    j=cedula/1;
    cedula=cedula-(j*1);
    if (cedula>240000000){
        cout<<"Numero de cedula invalido."<<endl;
        comprobar = true;
    }else{
	        pares=b+d+f+h;
	        a=a*2;
	        if (a>9){
	            a=a%10+a/10;
	        }
	        c=c*2;
	        if (c>9){
	            c=c%10+c/10;
	        }
	        e=e*2;
	        if (e>9){
	            e=e%10+e/10;
	        }
	        g=g*2;
	        if (g>9){
	            g=g%10+g/10;
	        }
	        i=i*2;
	        if (i>9){
	            i=i%10+i/10;
	        }
	        impares=a+c+e+g+i;
	        total=pares+impares;
	        while (dec-total!=j && dec<total+10){
	            dec=dec+10;
	        }
	        if (dec-total==j){
	            cout<<"valido"<<endl;
	            comprobar = false;
	        }else {
	            cout<<"Cedula erronea"<<endl;
	            comprobar = true;
	        }
        }
	}
	return ced;
}
