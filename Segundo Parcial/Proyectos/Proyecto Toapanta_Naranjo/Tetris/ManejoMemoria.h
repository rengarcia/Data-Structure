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
#ifndef MANEJOMEMORIA_H_INCLUDED
#define MANEJOMEMORIA_H_INCLUDED
#include<iostream>
#include <conio.h>
#include<time.h>
#include <stdio.h>
#include<fstream>
using namespace std;

int **reservar(int fila,int colum)
{
    int **m,j;
    m=new int*[fila];//reservando memoria de filas
    for(int i=0;i<fila;i++)
    {
        m[i]=new int[colum];//reservar columnas
    }
    return m;
}
void agregar(int **matriz,int tam)
{
    for(int i=0;i<tam;i++)
    {
        for(int j=0;j<tam;j++)
        {
            cout<<i+1<<" "<<j+1<<endl;
            cin>>*(*(matriz+i)+j);
        }
    }

}
void mostrar(int**matriz,int fila,int columna)
{

    for(int i=0;i<fila;i++)
    {
        for(int j=0;j<columna;j++)
        {
            cout<<*(*(matriz+i)+j);
        }
        cout<<endl;
    }
}
void liberarMemoria(int **matriz,int columna)
{
    for(int i=0;i<columna;i++)
    {
        delete[] matriz[i];
    }
    delete []matriz;
}
void encerar(int ** m,int fila, int columna)
{
    for(int i=0;i<fila;i++)
    {
        for(int j=0;j<columna;j++)
        {
            *(*(m+i)+j)=0;
        }
    }
}
void agregarPosicion(int**matriz,int x, int y,int valor)
{
    *(*(matriz+y)+x)=valor;
}
void escribirArchivo(int **guardar,int x , int y)
{
    ofstream archivo;
    archivo.open("MovimientoTetris.csv",ios::out | ios::app);
    if(archivo.fail())
    {
        cout<<"No se pudo Abrir"<<endl;
        exit(1);
    }
    else{
        for(int i=0;i<x;i++)
        {
            for(int j=0;j<y;j++)
            {
                archivo<<*(*(guardar+i)+j)<<" \t";
            }
            archivo<<" \n";
            archivo<<" \n";
        }
    }
    archivo<<" \n";
    archivo<<" \n";
    archivo<<" \n";
    archivo<<" \n";
    archivo.close();
}
void archivoJuego(string nombre,int nivel,int puntos)
{
    ofstream archivo;
    archivo.open("Datos.txt",ios::out);
    if(archivo.fail())
    {
        cout<<"No se pudo Abrir"<<endl;
        exit(1);
    }
    else{
                archivo<<nombre<<" "<<nivel<<" "<<" "<<puntos;
    }
    archivo.close();
}
#endif // MANEJOMEMORIA_H_INCLUDED
