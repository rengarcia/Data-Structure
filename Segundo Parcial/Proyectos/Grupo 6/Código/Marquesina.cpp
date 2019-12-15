/***********************************************************************
 * Module:  Marquesina.cpp
 * Author:  Kevin Duy, Carlos Puco
 * Modified: sabado, 26 de noviembre de 2019 17:21:23
 * Purpose: Implementation of the class Marquesina
 ***********************************************************************/

#include "Marquesina.h"
#include "Pantalla.cpp"
#include <iostream>

using namespace std;

int i,j;

/** 	
 * @brief Funcion para borrar la marquesina generada 
 */
	
void Marquesina::borrar() {
	Pantalla pantalla;
	if(i<=50) {
		pantalla.gotoxy(i,1);
		cout<< " ";
	} else {
		pantalla.gotoxy(j+5,1);
		cout<< "     ";
	}

}

/** 	
 * @brief Funcion para ejecutar y realizar la marquesina 
 */
void Marquesina::hacerMarquesina () {
	Pantalla pantalla;
		for (i=1; i<=50; i++) {
			pantalla.gotoxy(i,1);
			cout<<"Tetris";
			Sleep(100);
			borrar();
		}
		for (j=50; j>=1; j--) {
			pantalla.gotoxy(j,1);
			cout<<"Tetris";
			Sleep (100);
			borrar();
		}
}

/**
 * @brief genera el pdf generado 
 * @param  void 
 * @return genera y graba en el pdf 
 */
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
	vector<string> sv = p.wrapText(archivo, 300, true);
	int n = sv.size();
   	for(int i = 0; i < n; i ++) {
   		p.setFont(PDF::HELVETICA, 12);
      	p.showTextXY(sv[i], 100, 745-20 * i);
   }
}

/**
 * @brief Mostrar el pdf generado 
 * @param  void 
 * @return Mostrara el pdf 
 */
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
