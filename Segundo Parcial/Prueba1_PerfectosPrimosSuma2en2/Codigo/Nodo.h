/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 2967                                                       *
******************************************************************/

#if !defined(__Class_Diagram_1_Nodo_h)
#define __Class_Diagram_1_Nodo_h

#include "Persona.h"

class Nodo
{
public:
    Persona getDatos(void);
    Nodo *getSiguiente(void);
    void setDatos(Persona newDatos);
    void setSiguiente(Nodo* newSiguiente);
    Nodo();
    Nodo(Persona obj, Nodo *siguiente);

protected:
private:
    Persona datos;
    Nodo *siguiente;
};

#endif
