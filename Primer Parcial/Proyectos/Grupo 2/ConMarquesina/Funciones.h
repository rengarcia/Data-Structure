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

void gotoxy(int columna, int linea) {
    COORD coord;
    coord.X = columna;
    coord.Y = linea;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void *moverMarquesina(void *args) {
    int c = 1;
    char *mensaje = "PERMUTACIONES MEDIANTE BACKTRACKING\n";
    do {
        int x = 10;
        Sleep(1500);
        system("cls");
        for (int i = 0; i < strlen(mensaje); i++) {
            gotoxy(x, 3);
            x++;
            cout << mensaje[i];
            fflush(stdout);
            Sleep(15);
        }
    } while (c == 1);
}

void *pedir_palabra(void *args) {

    string str;
    gotoxy(12, 12);
    Sleep(1500);
    cout << "\nIngrese una Palabra ";
    cin >> str;
    Cadena *obj = new Cadena(str);
    fflush(stdout);
    obj->mostrar(str);
    //obj->generarPdf();


    cout << "Se creo el archivo Combinaciones.txt" << endl;
}
#endif // FUNCIONES_H_INCLUDED
