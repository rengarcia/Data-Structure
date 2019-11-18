/**
	Universidad de las Fuerzas Armadas ESPE
    Alex Chicaiza, Maria Belen Ceron
    NRC: 2967
    Fecha creacion: 26/10/2019
	Fecha ultima modificacion:	7/11/2019
	Docente: Ing. Solis
*/

/***********************************************************************
 * Module:  Arreglo.cpp
 * Author:  Alex Chicaiza, Maria Belen Ceron
 * Modified: Tuesday, November 5, 2019 10:35:18 PM
 * Purpose: Implementation of the class Arreglo
 ***********************************************************************/

#include "Arreglo.h"
#include<stdlib.h>
#include <stdio.h>

////////////////////////////////////////////////////////////////////////
// Name:       Arreglo::Arreglo()
// Purpose:    Implementation of Arreglo::Arreglo()
// Return:
////////////////////////////////////////////////////////////////////////

Arreglo::Arreglo()
{
}

////////////////////////////////////////////////////////////////////////
// Name:       Arreglo::~Arreglo()
// Purpose:    Implementation of Arreglo::~Arreglo()
// Return:
////////////////////////////////////////////////////////////////////////

Arreglo::~Arreglo()
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       Arreglo::tamanioCadena(char * frase)
// Purpose:    Implementation of Arreglo::tamanioCadena()
// Parameters:
// - frase
// Return:     int
////////////////////////////////////////////////////////////////////////

int Arreglo::tamanioCadena(char * frase)
{
   if(*frase!='\0'){
            frase++;
        return 1+tamanioCadena(frase);
    }else{
        return 0;
    }
}

////////////////////////////////////////////////////////////////////////
// Name:       Arreglo::invertirCadena(char * frase, char* fraseInvertida, int inicio, int fin)
// Purpose:    Implementation of Arreglo::invertirCadena()
// Parameters:
// - frase
// - fraseInvertida
// - inicio
// - fin
// Return:     void
////////////////////////////////////////////////////////////////////////

void Arreglo::invertirCadena(char * frase, char* fraseInvertida, int inicio, int fin)
{
    if(fin>-1){
        *(fraseInvertida+inicio) =frase[fin];
        inicio++;
        fin--;
        invertirCadena(frase,fraseInvertida,inicio,fin);
    }else{
        *(fraseInvertida+inicio)='\0';
    }
}

