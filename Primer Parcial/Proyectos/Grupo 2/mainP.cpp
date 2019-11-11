/***********************************************************************
 * Module:  Principal (Main)
 * Author:  Jonathan Picado
 * Author:  Cesar Naula
 * Modified: miércoles, 5 de noviembre de 2019 20:09:41 p. m.
 * Purpose: Declaration of Main Function
 ***********************************************************************/
#include "Funciones.h"
#include <conio.h>
#include <windows.h>
#define help 59
using namespace std;

int main() {

    string str;

        cout << "Ingrese una Palabra " << endl;
        cin >> str;
        Cadena *obj = new Cadena(str);
        obj->mostrar(str);
        obj->generarPdf();
        cout << "Se creo el archivo Combinaciones.txt" << endl;
    return 0;
}


