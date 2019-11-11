/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 2967                                                       *
******************************************************************/
#include<iostream>
#include "Busqueda.h"
using namespace std;
////////////////////////////////////////////////////////////////////////
// Name:       Busqueda::Busqueda(int* arrg, int n)
// Purpose:    Implementation of Busqueda::Busqueda()
// Parameters:
// - arrg
// - n
// Return:     
////////////////////////////////////////////////////////////////////////

Busqueda::Busqueda(int* arrg, int n) {
    this->arreglo = arrg;
    this->tamanio = n;
}

////////////////////////////////////////////////////////////////////////
// Name:       Busqueda::busquedaSecuencial()
// Purpose:    Implementation of Busqueda::busquedaSecuencial()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Busqueda::busquedaSecuencial(int clave) {
    bool encontrado = true;
    //Buscar clave o dato en el arreglo.
    for (int j = 0; j < tamanio; j++) {
        if (*(arreglo + j) == clave) {
            cout << "Se encontro el " << clave << " en la posicion [" << j + 1 << "]" << endl;
            encontrado = false;
        }
    }

    delete[] arreglo;

    if (encontrado)
        cout << "No se encontro el dato" << endl;
}

////////////////////////////////////////////////////////////////////////
// Name:       Busqueda::getArreglo()
// Purpose:    Implementation of Busqueda::getArreglo()
// Return:     int*
////////////////////////////////////////////////////////////////////////

int* Busqueda::getArreglo(void) {
    return arreglo;
}

////////////////////////////////////////////////////////////////////////
// Name:       Busqueda::setArreglo(int* newArreglo)
// Purpose:    Implementation of Busqueda::setArreglo()
// Parameters:
// - newArreglo
// Return:     void
////////////////////////////////////////////////////////////////////////

void Busqueda::setArreglo(int* newArreglo) {
    arreglo = newArreglo;
}

////////////////////////////////////////////////////////////////////////
// Name:       Busqueda::getTamanio()
// Purpose:    Implementation of Busqueda::getTamanio()
// Return:     int
////////////////////////////////////////////////////////////////////////

int Busqueda::getTamanio(void) {
    return tamanio;
}

////////////////////////////////////////////////////////////////////////
// Name:       Busqueda::setTamanio(int newTamanio)
// Purpose:    Implementation of Busqueda::setTamanio()
// Parameters:
// - newTamanio
// Return:     void
////////////////////////////////////////////////////////////////////////

void Busqueda::setTamanio(int newTamanio) {
    tamanio = newTamanio;
}
