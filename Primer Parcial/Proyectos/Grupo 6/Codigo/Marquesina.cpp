/***********************************************************************
 * Module:  Marquesina.cpp
 * Author:  Kevin Duy, Carlos Puco
 * Modified: sabado, 26 de octubre de 2019 17:21:23
 * Purpose: Implementation of the class Arimaa
 ***********************************************************************/

#include "Marquesina.h"
#include <iostream>
#include "ingreso.h"

using namespace std;

int i,j;

/**
 * @Funcion para moverse en coordenadas
 * @param x: coordenadas del eje de las abscisas
 * @param y: coordendas del eje de las ordenadas 
 */
	
void Marquesina::gotoxy(int x,int y) {  
    HANDLE hcon;  
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
    COORD dwPos;  
    dwPos.X = x;  
    dwPos.Y = y;  
    SetConsoleCursorPosition(hcon,dwPos);  
}

/** 	
 * @brief Funcion para borrar la marquesina generada 
 */
	
void Marquesina::borrar() {
	if(i<=100) {
		gotoxy(i,1);
		cout<< " ";
	} else {
		gotoxy(j+14,1);
		cout<< "     ";
	}

}

/** 	
 * @brief Funcion para ejecutar y realizar la marquesina 
 */
void Marquesina::hacerMarquesina () {
	do {
		for (i=1; i<=100; i++) {
			gotoxy(i,1);
			cout<<"Reto del Arimaa";
			Sleep(100);
			borrar();
		}
		for (j=100; j>=1; j--) {
			gotoxy(j,1);
			cout<<"Reto del Arimaa";
			Sleep (100);
			borrar();
		}
	}while(true);
}

/**
 * @brief Funcion para que el usuario ingrese solo numeros
 * @return int
 */
int Marquesina::ingresarNumero() {
	int numero;
	Ingreso leer;
	gotoxy(0,2);
	cout << "Ingrese el tamanio del tablero";
	Sleep(1000);
	numero = leer.ingresarEntero();
	gotoxy(0,3);
	cout << numero;
	return numero;
}

void generaPDF(PDF &p) {
   	p.setFont(PDF::HELVETICA, 12);
	string filename = "solucion.txt";
	ifstream file(filename.c_str());
	if(!file) {
		cout << "Error no se puede abrir el archivo: " << filename << endl;
	}
	string linea, archivo;
	while(getline(file, linea)) {
		archivo += linea + "\n";
	}
	vector<string> sv = p.wrapText(archivo, 115, true);
	int n = sv.size();
   	for(int i = 0; i < n; i ++) {
   		p.setFont(PDF::HELVETICA, 12);
      	p.showTextXY(sv[i], 100, 745-20 * i);
   }
}

void muestraPDF() {
	DemoFunction functions = generaPDF;
	int n = sizeof(functions) / sizeof(functions);
	for(int i = 0; i < n; i ++) {
	    ostringstream out;
		out << "solucion.pdf";
		string fileName = out.str();
		PDF pdf;
		functions(pdf);
		string errMsg;
		if(!pdf.writeToFile(fileName, errMsg)) {
	    cout << errMsg << endl;
	    }else {
	        cout << endl << endl <<endl <<endl <<"Se genero el PDF" << endl;
	    }
		cout << endl;
	}
}
