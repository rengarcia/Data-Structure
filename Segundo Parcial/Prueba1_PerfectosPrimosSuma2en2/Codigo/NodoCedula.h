/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 2967                                                       *
******************************************************************/
#pragma once

class NodoCedula
{
public:
    NodoCedula *getSiguiente(void);
    int getValor(void);
    void setValor(int newValor);
    NodoCedula(int obj, NodoCedula *sig);
    void setSiguiente(NodoCedula* newSiguiente);
    NodoCedula();
protected:
private:
    int valor;
    NodoCedula *siguiente;
};



