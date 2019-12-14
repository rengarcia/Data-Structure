#include <cstdlib>
#include <iostream>
#include <string.h>
#include "Nodo.h"
#include "Pila.cpp"
#include "IngresoBloqueTeclas.h"
#include "TraformacionString.h"
using namespace std;

int main() {
    Nodo *pila = NULL;
    char valor, c;
    Ingreso ig;
    string ecuacion;
    Pila opila;
    cout << "Ingrese un ecuacion matematica" << endl;
    ecuacion = ig.ingresarNumeros(&valor);
    for (int i = 0; i < ecuacion.length(); i++) {
        opila.apilar(pila, ecuacion.at(i));
    }
    opila.mostrar(pila, ecuacion.length());
    system("pause");
    return 0;
}
