/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 2967                                                       *
******************************************************************/

#include "Busqueda.h"

////////////////////////////////////////////////////////////////////////
// Name:       Busqueda::ordenamientoBurbuja(int dim, int* a)
// Purpose:    Implementation of Busqueda::ordenamientoBurbuja()
// Parameters:
// - dim
// - a
// Return:     int*
////////////////////////////////////////////////////////////////////////

int* Busqueda::ordenamientoBurbuja(int dim, int* a) {
    int aux;
    for (int i = 0; i < dim - 1; i++) {
        for (int j = 0; j < dim - 1; j++) {
            if (*(a + j)>*(a + j + 1)) {
                aux = *(a + j);
                *(a + j) = *(a + j + 1);
                *(a + j + 1) = aux;
            }
        }
    }

    cout << "El arreglo ordenado por burbuja es:  " << endl;
    for (int i = 0; i < dim; i++) {
        cout << "[" << *(a + i) << "]" << " ";
    }
    cout << endl;
    return a;
}

////////////////////////////////////////////////////////////////////////
// Name:       Busqueda::inicializarVector(int dim)
// Purpose:    Implementation of Busqueda::inicializarVector()
// Parameters:
// - dim
// Return:     int*
////////////////////////////////////////////////////////////////////////

int* Busqueda::inicializarVector(int dim) {
    int* a;
    a = (int*) calloc(dim, sizeof (int));
    return a;
}

////////////////////////////////////////////////////////////////////////
// Name:       Busqueda::ingresoDatos(int dim,int* a)
// Purpose:    Implementation of Busqueda::ingresoDatos()
// Parameters:
// - dim
// - a
// Return:     int*
////////////////////////////////////////////////////////////////////////

int* Busqueda::ingresoDatos(int dim, int* a) {
    Ingreso leer;

    int aux;

    for (int i = 0; i < dim; i++) {
        cout << "Ingrese el elemento de la posicion: " << "[" << i << "]" << endl;
        aux = leer.ingresarEntero();
        *(a + i) = aux;
    }
}

////////////////////////////////////////////////////////////////////////
// Name:       Busqueda::busquedaBinaria(int x, int inicio, int final, int *array)
// Purpose:    Implementation of Busqueda::busquedaBinaria()
// Parameters:
// - x
// - inicio
// - final
// - array
// Return:     int
////////////////////////////////////////////////////////////////////////

int Busqueda::busquedaBinaria(int x, int inicio, int final, int *array) {
    int q;
    q = (inicio + final) / 2;
    if (x == *(array + q)) {
        return q;
    } else if (x>*(array + q)) {
        busquedaBinaria(x, q + 1, final, array);
    }
    else if (x<*(array + q)) {
        busquedaBinaria(x, inicio, q - 1, array);
    }
    else if (inicio >= final)
        return -1;
}
