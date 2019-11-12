/**
    *@file Manejo Memoria.h
    *@version 2.0
    *@author Antoni Toapanta
    *@title Funciones Independientes
    *@brief Funciones Utilizadas en la Reserva de memoria y escritura en un archivo
    */
/***********************************************************************
 * Module: Manejo de memoria.h
 * Author:  RODRIGO
 * Modified: miércoles, 20 de octubre de 2019 01:54:07
 * Purpose: Declaration of the class Operaciones
 ***********************************************************************/
#ifndef MANEJOMEMORIA_H_INCLUDED
#define MANEJOMEMORIA_H_INCLUDED
#include<iostream>
#include <conio.h>
#include<time.h>
#include <stdio.h>
#include<fstream>
using namespace std;
/**
    @brief Reservar memoria
    @param Fila,Columna
    @return Una reserva de memoria dinamica entera
    */
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
/**
    @brief Agregar a mi arreglo dinamico
    @param **matriz,tamanio
    @return Nada
    */
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
/**
    @brief Muestrai arreglo dinamico
    @param **matriz,fila,columna
    @return Nada
    */
void mostrar(int**matriz,int fila,int columna)
{
    for(int i=0;i<fila;i++)
    {
        for(int j=0;j<columna;j++)
        {
            if(*(*(matriz+i)+j)!=0)
            {
                cout<<*(*(matriz+i)+j)<<"\t";
            }
            else{
                cout<<" "<<"\t";
            }
        }
        cout<<endl;
        cout<<endl;
    }
}
/**
    @brief Libera memoria
    @param **matriz,columna
    @return Nada
    */
void liberarMemoria(int **matriz,int columna)
{
    for(int i=0;i<columna;i++)
    {
        delete[] matriz[i];
    }
    delete []matriz;
}
/**
    @brief Llena de 0 mi matriz
    @param **matriz,columna
    @return Nada
    */
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
/**
    @brief Llena de aleatorioa una arreglo Unidimencional
    @param **matriz,columna
    @return Nada
    */
void llenarAleatorioUni(int *m,int tam)
{
    int aux;
    //srand(time(NULL));
    for(int i=0;i<tam;i++)
        {
            aux=1+rand()%tam;
            int aux2 = 0;
            while(aux2 < i)
            {

                if(aux != *(m+aux2))
                {
                    aux2++;
                }
                else
                {
                    aux = (1 + rand() % tam);
                    aux2 = 0;
                }
            }
            *(m+i) = aux;
        }
}
/**
    @brief Escribe en un archivo csv
    @param **matriz,columna
    @return Nada
    */
void escribirArchivo(int **guardar,int tam)
{
    ofstream archivo;
    archivo.open("Proyecto.csv",ios::out | ios::app);
    if(archivo.fail())
    {
        cout<<"No se pudo Abrir"<<endl;
        exit(1);
    }
    else{
        for(int i=0;i<tam;i++)
        {
            for(int j=0;j<tam;j++)
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
#endif // MANEJOMEMORIA_H_INCLUDED
