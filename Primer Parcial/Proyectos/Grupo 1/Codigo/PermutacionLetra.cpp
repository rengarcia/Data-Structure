/**
	Universidad de las Fuerzas Armadas ESPE
    Alex Chicaiza, Maria Belen Ceron
    NRC: 2967
    Fecha creacion: 26/10/2019
	Fecha ultima modificacion:	7/11/2019
	Docente: Ing. Solis
*/

/***********************************************************************
 * Module:  PermutacionLetra.cpp
 * Author:  Alex Chicaiza, Maria Belen Ceron
 * Modified: Wednesday, November 6, 2019 3:57:40 PM
 * Purpose: Implementation of the class PermutacionLetra
 ***********************************************************************/

#include "PermutacionLetra.h"
#include <iostream>
#include <fstream>

#include <cstdlib>
#include <cmath>

//std::fstream enter;
////////////////////////////////////////////////////////////////////////
// Name:       PermutacionLetra::permutacion()
// Purpose:    Implementation of PermutacionLetra::permutacion()
// Return:     void
////////////////////////////////////////////////////////////////////////

void PermutacionLetra::permutacion(std::string  aux,char *items,int n,int r){
    enter.open("solucion.txt",std::fstream::out); //para leer in, para salir es out escribir
	enter<<"\n\n\tUNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE\n"<<std::endl;
	enter<<"\t  INGENIERIA DE SOFTWARE"<<std::endl;
	enter<<"Ingrantes: "<<std::endl;
	enter<<"\t\tMaria Belen Ceron"<<std::endl;
	enter<<"\t\tAlex Chicaiza"<<std::endl;
	enter<<"\n\t\t\tSOLUCION "<<std::endl<<std::endl;
	enter<<"\n\n Numero de permutaciones con repeticion: "<<pow(n,r)<<std::endl;
    enter<<"\n\n Lista de permutaciones con repeticion:"<<std::endl;
    /*char **arch=(char**)malloc(9*sizeof(char));
    for(int i=0;i<9;i++){
        *arch=(char*)malloc(sizeof(char));
    }*/
    generarPermutacion(aux,items,n,r);
    //enter<<"hola"<<std::endl;
    //enter<<"hola"<<std::endl;
    //;
    enter.close();

}

////////////////////////////////////////////////////////////////////////
// Name:       PermutacionLetra::generarPermutacion()
// Purpose:    Implementation of PermutacionLetra::generarPermutacion()
// Return:     void
////////////////////////////////////////////////////////////////////////

void PermutacionLetra::generarPermutacion(std::string  aux,char *items,int n,int r)
{
   char* resp=(char *)aux.c_str();
    if(r>0){
        for(int x=0; x<n; x++){
            generarPermutacion(aux+*(items+x),items,n,r-1);
        }
    }else{
        enter<<"  "<<resp<<std::endl;
        printf("\n%s",resp);
    }
}
