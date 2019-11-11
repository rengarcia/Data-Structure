/***********************************************************************
 * Module:  Funciones.h
 * Author:  Jonathan
 * Modified: miércoles, 3 de noviembre de 2019 4:09:41 p. m.
 * Purpose: Declaration of the class Funciones
 ***********************************************************************/

#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <iostream>
#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include <fstream>
#include <windows.h>

using namespace std;

class Cadena {
public:
    fstream enter;
    int n, contador;
    char *copy;

    void mostrar(string str) {
        n = str.size();
        copy = (char*) malloc(10 * sizeof (char*));
        strcpy(copy, str.c_str());
        enter << permute(copy, 0, n - 1);
        enter << endl;
        enter.close();
    }

    char permute(char *a, int l, int r) {
        if (l == r)
            enter << a << endl;
        else {
            for (int i = l; i <= r; i++) {
                swap(*(a + l), *(a + i));
                permute(a, l + 1, r);
                swap(*(a + l), *(a + i));
            }
        }
    }

    Cadena(string n) {
        enter.open("combinaciones.txt", fstream::out); //para leer in, para salir es out escribir
        enter << "combinaciones posibles de " << n << endl;
        contador = 0;
    }

    void intercambio ( int *x, int *y ) {
   	int tmp;
 	 tmp = *x;
 	 *x = *y;
 	 *y = tmp;
	}

    void generarPdf() {
        enter.open("combinaciones.txt", std::fstream::in);
        if (enter.fail()) {
            cout << "ERROR";
        } else {
            enter.close();
            system("txt2pdf.exe combinaciones.txt com.pdf -oao -pfs60 -pps43 -ptc0 -width3000 -height2000");
            cout << "EXITO";
        }
    }
};

class Marquesina {
private:
    short x, y;
    const char* mensaje;
public:
    void gotoxy(short x, short y);
    void moverMarquesina(const char* mensaje);
};

void Marquesina::gotoxy(short x, short y) {
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void Marquesina::moverMarquesina(const char* mensaje) {
    int derecha = 0, n = 0, c = 1;
    mensaje = "PERMUTACIONES MEDIANTE BACKTRACKING";
    do {
        for (derecha = 1; derecha <= 75; derecha++) {
            system("cls");
            gotoxy(derecha, 1);
            cout << mensaje;
            Sleep(10);
        }
    } while (c == 1);

}


#endif // FUNCIONES_H_INCLUDED
