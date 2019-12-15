/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 2967                                                       *
******************************************************************/

#include "NodoCedula.h"


////////////////////////////////////////////////////////////////////////
// Name:       NodoCedula::getSiguiente()
// Purpose:    Implementation of NodoCedula::getSiguiente()
// Return:       NodoCedula *
////////////////////////////////////////////////////////////////////////



NodoCedula* NodoCedula::getSiguiente(){
    return siguiente;
}

int NodoCedula::getValor(void){
    return valor;
}

void NodoCedula::setValor(int newValor){
    valor = newValor;
}

NodoCedula::NodoCedula(int obj, NodoCedula *sig){
    valor = obj;
    siguiente = sig;
}

////////////////////////////////////////////////////////////////////////
// Name:       NodoCedula::setSiguiente(NodoCedula* newSiguiente)
// Purpose:    Implementation of NodoCedula::setSiguiente()
// Parameters:
// - newSiguiente
// Return:     void
////////////////////////////////////////////////////////////////////////

void NodoCedula::setSiguiente(NodoCedula* newSiguiente)
{
   siguiente = newSiguiente;
}

NodoCedula::NodoCedula()
{
    siguiente = NULL;
}

