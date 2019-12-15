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

#ifndef MANEJOTABLERO_H_INCLUDED
#define MANEJOTABLERO_H_INCLUDED
#include "miniwin.h"
#include"Piezas.h"
#include<time.h>
#include <string>
#include <fstream>
#include <sstream>
using namespace miniwin;
void pintar(int **tablero,int x, int y)
{
    Piezas p;
    for(int i=0;i<x;i++)
    {
        for(int j=0;j<y;j++)
        {
            p.setX(j);
            p.setY(i);
            p.unaPieza(*(*(tablero+i)+j));
        }
    }
}
bool colision(int **tabla,Piezas p)
{
    if(p.getY()<19)
    {
       p.setY(p.getY()+1);
    }
    p.unaPieza(*(*(tabla+p.getY())+p.getX()));
    if(p.getNum()!=0){
        return true;
    }
    else{
        return false;
    }
}
void llenarNuevaTabla(int **tabla,ListaCircularDoble lista)
{
    for(int i=0;i<30;i++)
    {
        *(*(tabla+13)+i)=lista.buscarPosicion(i);
    }
}
string lectura()
{
    ifstream archivo;
    string texto;
    archivo.open("Nombre.txt",ios::in);
    if(archivo.fail())
    {
        exit(1);
    }
    else{
        while(!archivo.eof())
        {
            getline(archivo,texto);
        }
    }
    archivo.close();
    return texto;
}
void margenJuego( int  pieza, int nivel, int puntos,string nombre)
{
    Piezas p;
    stringstream out,out2;
    out<<puntos;
    out2<<nivel;
    color(AZUL);
    linea(50,0,50,700);
    color(AZUL);
    linea(650,0,650,700);
    color(AZUL);
    linea(50,700,650,700);
    color(BLANCO);
    texto(700,100,"Pieza Siguiente");
    p.setX(15);
    p.setY(3);
    p.unaPieza(pieza);
    color(BLANCO);
    texto(700,250,"Nombre del Jugador:");
    texto(760,300,nombre);
    texto(700,350,"Nivel");
     texto(760,400,out2.str());
    texto(700,450,"Puntos:");
    texto(760,500,out.str());
}
void manejoNiveles(int puntos,int &nivel,int&tiempo)
{
    if(puntos==100)
    {
        nivel++;
        tiempo=30;
    }
    else if(puntos==200)
    {
        nivel++;
        tiempo=10;
    }
    else if(puntos==300)
    {
        nivel++;
        tiempo=5;
    }
}

#endif // MANEJOTABLERO_H_INCLUDED
