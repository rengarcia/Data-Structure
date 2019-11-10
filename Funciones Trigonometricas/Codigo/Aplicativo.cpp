#include <stdio.h>
#include <iostream>
#include "FuncionesTrigonometricas.h"
#include "Ingreso.h"


using namespace std;

int main() {
    FuncionesTrigonometricas funciones;
    Ingreso ingreso;
    string angulo1;
    float angulo2;
    float calculo1;
    float calculo2;
    float calculo3;
    cout << "***CALCULO DE FUNCIONES TRIGONOMETRICAS : SENO, COSENO, TANGENTE***" << endl << endl;
    angulo1 = ingreso.leer("Ingrese un angulo: ", 2);
    angulo2 = funciones.radianes(atof(angulo1.c_str()));
    calculo1 = funciones.seno(angulo2);
    calculo2 = funciones.coseno(angulo2);
    calculo3 = funciones.tangente(angulo2);
    system("cls");
    cout << "***CALCULO DE FUNCIONES TRIGONOMETRICAS : SENO, COSENO, TANGENTE***" << endl << endl;
    cout << endl << "SENO DE: " << angulo1 << " ES= " << calculo1 << endl;
    cout << "COSENO DE: " << angulo1 << " ES= " << calculo2 << endl;
    cout << "TANGENTE DE: " << angulo1 << " ES= " << calculo3 << endl;
}
