/**
	Universidad de las Fuerzas Armadas ESPE
	Estructura de Datos
	NRC: 2967
	Docente: Ing. Fernando Solis
*/

#include "NumeroPrimo.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <pthread.h>
#include <conio.h>


////////////////////////////////////////////////////////////////////////
// Name:       NumeroPrimo::primo(int numero, int i)
// Purpose:    Implementation of NumeroPrimo::primo()
// Parameters:
// - numero
// - i
// Return:     bool
////////////////////////////////////////////////////////////////////////

bool NumeroPrimo::primo(int numero, int i)
{
   if(numero<=i){
		return true;
	}
	if(numero%i==0){
		return false;
	}else{
		return primo(numero,i+1);
	}
}

