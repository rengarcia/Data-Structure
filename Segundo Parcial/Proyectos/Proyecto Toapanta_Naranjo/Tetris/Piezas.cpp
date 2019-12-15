/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS                   *
*                        ESPE                                     *
*TRABAJO EN GRUPO:                                                *
*          NOMBRES:ANTONI TOAPANTA                                *
*                   JONNY NARANJO                                 *
*MATERIA: ESTRUCTURA DE DATOS                                     *
*NRC:2967                                                         *
*Fecha de Creacion:09/12/2019                                     *
******************************************************************/

#include "Piezas.h"
#include "miniwin.h"
using namespace miniwin;
////////////////////////////////////////////////////////////////////////
// Name:       Piezas::getX()
// Purpose:    Implementation of Piezas::getX()
// Return:     int
////////////////////////////////////////////////////////////////////////
void Piezas::pieza(int x, int y, int col)
{
    color(col);
    rectangulo_lleno(1+x*50,1+y*50,x*50+50,y*50+50);
}
int Piezas::getX(void)
{
   return x;
}

////////////////////////////////////////////////////////////////////////
// Name:       Piezas::setX(int newX)
// Purpose:    Implementation of Piezas::setX()
// Parameters:
// - newX
// Return:     void
////////////////////////////////////////////////////////////////////////

void Piezas::setX(int newX)
{
   x = newX;
}

////////////////////////////////////////////////////////////////////////
// Name:       Piezas::getY()
// Purpose:    Implementation of Piezas::getY()
// Return:     int
////////////////////////////////////////////////////////////////////////

int Piezas::getY(void)
{
   return y;
}

////////////////////////////////////////////////////////////////////////
// Name:       Piezas::setY(int newY)
// Purpose:    Implementation of Piezas::setY()
// Parameters:
// - newY
// Return:     void
////////////////////////////////////////////////////////////////////////

void Piezas::setY(int newY)
{
   y = newY;
}

////////////////////////////////////////////////////////////////////////
// Name:       Piezas::cubo1()
// Purpose:    Implementation of Piezas::cubo1()
// Return:     int
////////////////////////////////////////////////////////////////////////

int Piezas::cubo1(void)
{
    pieza(getX(),getY(),BLANCO);
   return 1;
}

////////////////////////////////////////////////////////////////////////
// Name:       Piezas::cubo2()
// Purpose:    Implementation of Piezas::cubo2()
// Return:     int
////////////////////////////////////////////////////////////////////////

int Piezas::cubo2(void)
{
    pieza(getX(),getY(),ROJO);
   return 2;
}

////////////////////////////////////////////////////////////////////////
// Name:       Piezas::cubo3()
// Purpose:    Implementation of Piezas::cubo3()
// Return:     int
////////////////////////////////////////////////////////////////////////

int Piezas::cubo3(void)
{
    pieza(getX(),getY(),AZUL);
   return 3;
}

////////////////////////////////////////////////////////////////////////
// Name:       Piezas::cubo4()
// Purpose:    Implementation of Piezas::cubo4()
// Return:     int
////////////////////////////////////////////////////////////////////////

int Piezas::cubo4(void)
{
    pieza(getX(),getY(),AMARILLO);
   return 4;
}

////////////////////////////////////////////////////////////////////////
// Name:       Piezas::cubo5()
// Purpose:    Implementation of Piezas::cubo5()
// Return:     int
////////////////////////////////////////////////////////////////////////

int Piezas::cubo5(void)
{
    pieza(getX(),getY(),VERDE);
   return 5;
}

////////////////////////////////////////////////////////////////////////
// Name:       Piezas::cubo6()
// Purpose:    Implementation of Piezas::cubo6()
// Return:     int
////////////////////////////////////////////////////////////////////////

int Piezas::cubo6(void)
{
    pieza(getX(),getY(),MAGENTA);
   return 6;
}

////////////////////////////////////////////////////////////////////////
// Name:       Piezas::cubo7()
// Purpose:    Implementation of Piezas::cubo7()
// Return:     int
////////////////////////////////////////////////////////////////////////

int Piezas::cubo7(void)
{
    pieza(getX(),getY(),NEWCOLOR);
   return 7;
}

////////////////////////////////////////////////////////////////////////
// Name:       Piezas::cubo8()
// Purpose:    Implementation of Piezas::cubo8()
// Return:     int
////////////////////////////////////////////////////////////////////////

int Piezas::cubo8(void)
{
    pieza(getX(),getY(),VERDECLARO);
   return 8;
}

////////////////////////////////////////////////////////////////////////
// Name:       Piezas::cubo9()
// Purpose:    Implementation of Piezas::cubo9()
// Return:     int
///////////////////s/////////////////////////////////////////////////////

int Piezas::cubo9(void)
{
    pieza(getX(),getY(),CELESTE);
   return 9;
}
////////////////////////////////////////////////////////////////////////
// Name:       Piezas::cubo9()
// Purpose:    Implementation of Piezas::cubo9()
// Return:     int
///////////////////s/////////////////////////////////////////////////////
int Piezas::vacio(void)
{
    pieza(getX(),getY(),NEGRO);
    return 0;
}
////////////////////////////////////////////////////////////////////////
// Name:       Piezas::cubo9()
// Purpose:    Implementation of Piezas::cubo9()
// Return:     int
///////////////////s/////////////////////////////////////////////////////
int Piezas::getNum(void)
{
    return num;
}
////////////////////////////////////////////////////////////////////////
// Name:       Piezas::cubo9()
// Purpose:    Implementation of Piezas::cubo9()
// Return:     int
///////////////////s/////////////////////////////////////////////////////
void Piezas::setNum(int n)
{
    num=n;
}
////////////////////////////////////////////////////////////////////////
// Name:       Piezas::cubo9()
// Purpose:    Implementation of Piezas::cubo9()
// Return:     int
///////////////////s/////////////////////////////////////////////////////
int Piezas::unaPieza(int pieza)
{
    switch(pieza)
    {
        case 1:
            setNum(1);
            return cubo1();
            break;
        case 2:
            setNum(2);
            return cubo2();
            break;
        case 3:
            setNum(3);
            return cubo3();
            break;
        case 4:
            setNum(4);
            return cubo4();
            break;
        case 5:
            setNum(5);
            return cubo5();
            break;
        case 6:
            setNum(6);
            return cubo6();
            break;
        case 7:
            setNum(7);
            return cubo7();
            break;
        case 8:
            setNum(8);
            return cubo8();
            break;
        case 9:
            setNum(9);
            return cubo9();
            break;
        case 0:
            setNum(0);
            return vacio();
            break;
    }
}
