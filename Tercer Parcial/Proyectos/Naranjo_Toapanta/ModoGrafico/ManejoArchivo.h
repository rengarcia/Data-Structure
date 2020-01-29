/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS                   *
*                        ESPE                                     *
*TRABAJO EN GRUPO:                                                *
*          NOMBRES:ANTONI TOAPANTA                                *
*                   JHONY NARANJO                                 *
*MATERIA: ESTRUCTURA DE DATOS                                     *
*NRC:2967                                                         *
*Fecha de Creacion:26/01/2020                                     *
******************************************************************/
#ifndef MANEJOARCHIVO_H_INCLUDED
#define MANEJOARCHIVO_H_INCLUDED
#include<iostream>
#include<stdlib.h>
#include<string>
#include "Palabra.h"
#include "OperacionArbol.h"
#include "IngresoBloqueTeclas.h"
#include "TransformacionString.h"
#include "Arbol.h"
#include<fstream>
using namespace std;


void write_file(Palabra p)
{
    ofstream archivo;
    archivo.open("Dic.txt",ios::out|ios::app);
    if(archivo.fail())
    {
        cout<<"No se pudo Abrir"<<endl;
        exit(1);
    }
    else{
        archivo<<p.getEspanol()<<";"<<p.getIngles()<<";"<<p.getClave()<<";"<<p.getClaveE()<<endl;
    }

    archivo.close();
}
void open_file(Arbol *&arbol)
{
    ifstream archivo;
    Transformacion transformacion;
    OperacionArbol opA;
    string espanol,ingles,clave,claveE;
    archivo.open("Dic.txt",ios::in);

    if (archivo.fail())
    {
        cout<<"No se puedo acceder al archivo"<<endl;
    }
    else
    {
        while(!archivo.eof()){
            Palabra p;
            getline(archivo,espanol,';');
            getline(archivo,ingles,';');
            getline(archivo,clave,';');
            getline(archivo,claveE,'\n');
            p.setEspanol(espanol);
            p.setIngles(ingles);

            p.setClave(transformacion.stringAint(clave));
            p.setClaveE(transformacion.stringAint(claveE));
            opA.insertar(arbol,p);
        }
    }
    archivo.close();
}
void open_file_espanol(Arbol *&arbol)
{
    Transformacion transformacion;
    ifstream archivo;
    OperacionArbol opA;
    string espanol,ingles,clave,claveE;
    archivo.open("Dic.txt",ios::in);

    if (archivo.fail())
    {
        cout<<"No se puedo acceder al archivo"<<endl;
    }
    else
    {
        while(!archivo.eof()){
            Palabra p;
            getline(archivo,espanol,';');
            getline(archivo,ingles,';');
            getline(archivo,clave,';');
            getline(archivo,claveE,'\n');
            p.setEspanol(espanol);
            p.setIngles(ingles);
            p.setClave(transformacion.stringAint(clave));
            p.setClaveE(transformacion.stringAint(claveE));
            opA.insertarE(arbol,p);
        }
    }
    archivo.close();
}
int clave(string palabra)
{
    int j=0;
    for(int i=0;i<palabra.length();i++)
    {
        j=palabra.at(i)+j;
    }
    if(j>=100 || j<300)
    {
        j=j-100;
    }
    else if(j>=300|| j<650)
    {
        j=j-200;
    }
    else{
        j=j+500;
    }
    return j;
}
void convertirMayusculas(string &palabra)
{
    for(int i=0;i<palabra.length();i++)
    {
        palabra.at(i)=toupper(palabra.at(i));
    }
}
void agregar_Diccionario()
{
    char c;
    string a,b;
    Ingreso ig;
    cout<<"Espanol"<<endl;
    a=ig.ingresarLetras(&c);
    cout<<"Ingles"<<endl;
    b=ig.ingresarLetras(&c);
    Palabra p;
    convertirMayusculas(a);
    convertirMayusculas(b);
    p.setEspanol(a);
    p.setIngles(b);
    p.setClave(clave(b));
    p.setClaveE(clave(a));
    write_file(p);
}


#endif // MANEJOARCHIVO_H_INCLUDED
