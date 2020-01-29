#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "Laberinto.h"
#include "ImpProceso.h"
#include <cstdlib>
#include <conio.h>
#include <Windows.h>
using namespace std;

int main() {
	char tecla;
	bool salir = false;
	cout << "Bienvenido a Indiana Croft" << endl;
	cout << "Pulsa enter para empezar" << endl;
	cout << "Pulsa 1 para ayuda" << endl;
	
	while (!salir) {
		if (_kbhit()) {
			if (_getch() == 49) {
				system("AyudaIndianaCroft.chm");
			}
			if (_getch() == 13) {
				Laberinto laberinto(3 + 2, 3 + 2);
				ImpProceso proceso;
				proceso.generarSolucion(laberinto.getLaberinto(), 4, 1, 5, 0);
				salir = true;
			}
			Sleep(30);
		}		
	}
	return 0;
}
