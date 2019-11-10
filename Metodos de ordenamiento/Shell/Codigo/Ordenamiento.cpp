/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 2967                                                       *
******************************************************************/

#include "Ordenamiento.h"


////////////////////////////////////////////////////////////////////////
// Name:       Ordenamiento::ingresarDatos(int dim, int* arreglo)
// Purpose:    Implementation of Ordenamiento::ingresarDatos()
// Parameters:
// - dim
// - arreglo
// Return:     void
////////////////////////////////////////////////////////////////////////

void Ordenamiento::ingresarDatos(int dim, int* arreglo) {
    Ingreso ingreso;
    for (int i = 0; i < dim; i++) {
        *(arreglo + i) = atoi(ingreso.ingresar("Ingrese valor entero: ").c_str());
    }
}

////////////////////////////////////////////////////////////////////////
// Name:       Ordenamiento::imprimir(int* arreglo, int dim)
// Purpose:    Implementation of Ordenamiento::imprimir()
// Parameters:
// - arreglo
// - dim
// Return:     void
////////////////////////////////////////////////////////////////////////

void Ordenamiento::imprimir(int* arreglo, int dim) {
    for (int i = 0; i < dim; i++)
        cout << *(arreglo + i) << " ";
}

////////////////////////////////////////////////////////////////////////
// Name:       Ordenamiento::inicializarVector(int dim)
// Purpose:    Implementation of Ordenamiento::inicializarVector()
// Parameters:
// - dim
// Return:     int*
////////////////////////////////////////////////////////////////////////

int* Ordenamiento::inicializarVector(int dim) {
    int* a;
    a = (int*) calloc(dim, sizeof (int));
    return a;
}

////////////////////////////////////////////////////////////////////////
// Name:       Ordenamiento::ordenarShell(int* arreglo, int dim)
// Purpose:    Implementation of Ordenamiento::ordenarShell()
// Parameters:
// - arreglo
// - dim
// Return:     void
////////////////////////////////////////////////////////////////////////

void Ordenamiento::ordenarShell(int* arreglo, int dim) {
    for (int gap = dim / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < dim; i += 1) {
            int temp = *(arreglo + i);
            int j;
            for (j = i; j >= gap && *(arreglo + (j - gap)) > temp; j -= gap)
                *(arreglo + j) = *(arreglo + (j - gap));
            *(arreglo + j) = temp;
        }
    }
}

////////////////////////////////////////////////////////////////////////
// Name:       Ordenamiento::Ordenamiento()
// Purpose:    Implementation of Ordenamiento::Ordenamiento()
// Return:     
////////////////////////////////////////////////////////////////////////

Ordenamiento::Ordenamiento() {
}

////////////////////////////////////////////////////////////////////////
// Name:       Ordenamiento::~Ordenamiento()
// Purpose:    Implementation of Ordenamiento::~Ordenamiento()
// Return:     
////////////////////////////////////////////////////////////////////////

Ordenamiento::~Ordenamiento() {
    // TODO : implement
}
