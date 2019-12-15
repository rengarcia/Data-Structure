/***********************************************************************
 * Module:  ImpJuego.cpp
 * Author:  Alan
 * Modified: lunes, 18 de noviembre de 2019 23:20:19
 * Purpose: Implementation of the class ImpJuego
 ***********************************************************************/

#include "ImpJuego.h"
#include <time.h>
#include <stdlib.h>

////////////////////////////////////////////////////////////////////////
// Name:       ImpJuego::generarPiezas()
// Purpose:    Implementation of ImpJuego::generarPiezas()
// Return:     void
////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////
// Name:       ImpJuego::pixelarImagen()
// Purpose:    Implementation of ImpJuego::pixelarImagen()
// Return:     void
////////////////////////////////////////////////////////////////////////

int ImpJuego::generarPiezas()
{
    int numero;
    srand(time(NULL));
    numero = rand() % 9 + 1;
    return numero;
}

void ImpJuego::pixelarImagen(void)
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       ImpJuego::encriptado()
// Purpose:    Implementation of ImpJuego::encriptado()
// Return:     void
////////////////////////////////////////////////////////////////////////

void ImpJuego::encriptado(void)
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       ImpJuego::desencriptado()
// Purpose:    Implementation of ImpJuego::desencriptado()
// Return:     void
////////////////////////////////////////////////////////////////////////

void ImpJuego::desencriptado(void)
{
   // TODO : implement
}