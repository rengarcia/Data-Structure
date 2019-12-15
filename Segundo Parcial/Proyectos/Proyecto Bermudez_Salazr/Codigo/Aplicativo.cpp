#include <iostream>
#include <stdio.h>
#include "ManejoNodo.h"
#include "Nodo.h"
#include "Pantalla.h"
#include <Windows.h>
# include <conio.h>
#include "ImpJuego.h"
#include <fstream>


#define DERECHA 77
#define IZQUIERDA 75
#define ESCAPE 27


/*
	Universidad de las Fuerzas Armadas ESPE
Carrera: Ingeniería de Software
Nombre: Kevin Salazar, Alan Bermudez
NRC:
Fecha de elaboracion:07/10/2019
Fecha de ultima modificacion:07/11/2019
	Tetris
*/

using namespace std;

int main() {
	ManejoNodo mn;
	Pantalla pantalla;
	ImpJuego ij;
	string nombre;
	bool terminar = false;
	int numero;
	int siguienteNumero;
	int puntuacion = 0;
	char tecla;
	int x = 20;
	int y = 5;
	int inicio;
	int final;
	int posicion = 1;
	numero = ij.generarPiezas();
	siguienteNumero = ij.generarPiezas();
	
	
	cout << "Ingrese el nombre del jugador: ";
	cin >> nombre;	
	pantalla.tablero(nombre,numero, puntuacion);
	pantalla.gotoxy(x, y);

	pantalla.ocultarCursor();

	while (!terminar) {
		if (_kbhit()) {
			tecla = _getch();
			if (tecla == '1') {
				
					system("C:/Users/kevin/Desktop/ProyectoEstructuras/IndianaCroft/IndianaCroft/C++/IndianaCroft/IndianaCroft/AyudaIndianaCroft.chm");
				
			}
		
			if (tecla == ESCAPE) {	

				terminar = true;
			}
			else if (tecla == DERECHA) {
				pantalla.gotoxy(x, y);
				cout << " ";
				x++;
				posicion++;
			}
			else if (tecla == IZQUIERDA) {
				pantalla.gotoxy(x, y);
				cout << " ";
				x--;	
				posicion--;
			}
			
		}
		Sleep(100);		
		pantalla.gotoxy(x, y);
		cout << numero;
		pantalla.gotoxy(x, y);
		y++;
		cout << " ";
		pantalla.gotoxy(x, y);
		cout << numero;
		

		if (y == 43) {			
			if (posicion < 1) {
				mn.insertar(numero, false);
			}else if (posicion > mn.getLongitud()) {
				mn.insertar(numero, true);
			}
			else {
				mn.insertarEnMedio(posicion, numero);
			}
			pantalla.borrarLinea();			
			y = 5;
			x = 20;
			
			numero = siguienteNumero;
			siguienteNumero = ij.generarPiezas();
			pantalla.gotoxy(63, 10);
			cout << siguienteNumero;
			if (mn.getLongitud() > 1) {
				if (mn.borrar()) {
					pantalla.gotoxy(57, 13);
					puntuacion += 5;
					cout << puntuacion;
					pantalla.gotoxy(1, 1);
					cout << mn.getLongitud();
				}				
			}
			pantalla.gotoxy(20 - (mn.getLongitud() / 2), 43);
			posicion = (mn.getLongitud() / 2) + 1;
			mn.imprimir();
			
		}	
		if (mn.getLongitud()==40) {
			system("cls");
			pantalla.gotoxy(20, 40);
			cout << "USTED HA PERDIDO :'C"<<endl;
			system("pause");
			exit(0);
		}
	}
	mn.imprimir(); 
	fstream doc;
	doc.open("Lista.txt", fstream::in);

	doc.close();
	system("cls");
	system("txt2pdf.exe Lista.txt Lista.pdf -oao -pfs60 -pps43 -ptc0 -width3000 -height2000");
	
}