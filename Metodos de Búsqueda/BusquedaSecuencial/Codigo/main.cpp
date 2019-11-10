/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
CARRERA: SOFTWARE
MATERIA: ESTRUCTURA DE DATOS
TEMA: BUSQUEDA SECUENCIAL
NRC: 2967
 */
#include<iostream>
#include<stdlib.h>
#include <conio.h>
#include <iostream>
#include "Busqueda.h"
#include "Ingreso.h"

using namespace std;

int main() {

    int clave, tamanio, num;
    int * arreglo;
    Ingreso ingresar;
    cout << "Busqueda Secuencial" << endl;
    tamanio = ingresar.ingresarInt("Ingrese la dimension del arreglo: ");
    cout << endl;

    arreglo = (int *) malloc(tamanio * sizeof (int));

    //Ingreso de datos al arreglo
    for (int i = 0; i < tamanio; i++) {
        cout << "\nIngrese dato [" << i + 1 << "]: ";
        (*(arreglo + i)) = ingresar.ingresarInt("");
    }

    clave = ingresar.ingresarInt("Ingrese el numero que desea buscar: ");
    cout << endl;

    Busqueda buscar = Busqueda(arreglo, tamanio);
    buscar.busquedaSecuencial(clave);

    system("pause");
    return 0;
}


