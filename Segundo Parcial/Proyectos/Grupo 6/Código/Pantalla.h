/***********************************************************************
 * Module:  Pantalla.h
 * Author:  Carlos Puco, Kevin Duy
 * Modified: sábado, 26 de noviembre de 2019 20:20:06
 * Purpose: Declaration of the class Biblioteca
 ***********************************************************************/

#include <iostream>
#include <Windows.h>

using namespace std;

class Pantalla {
	public:
		void gotoxy(int,int);
		int obtenerAncho();
		int obtenerAlto();
		void abrirPantalla();
		void pintar();
		void color(int);
		int menu(const char*,const char* [],int);
};
