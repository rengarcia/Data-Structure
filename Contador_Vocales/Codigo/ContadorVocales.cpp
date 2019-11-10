/***********************************************************************
 * Module:  ContadorVocales.cpp
 * Author:  ALEX
 * Modified: Saturday, November 9, 2019 8:09:30 PM
 * Purpose: Implementation of the class ContadorVocales
 ***********************************************************************/

#include "ContadorVocales.h"

////////////////////////////////////////////////////////////////////////
// Name:       ContadorVocales::contarVoacales(char * cadena)
// Purpose:    Implementation of ContadorVocales::contarVoacales()
// Parameters:
// - cadena
// Return:     int
////////////////////////////////////////////////////////////////////////

int ContadorVocales::contarVocales(char * cadena)
{
   if(*cadena=='\0')
    {
        return 0;
    }
    else
    {
        switch(*cadena)
        {
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
            cadena++;
            return 1+contarVocales(cadena);
        }
        cadena++;
        return contarVocales(cadena);
    }
}
