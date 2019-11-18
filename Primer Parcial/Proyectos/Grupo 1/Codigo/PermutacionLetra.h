/**
	Universidad de las Fuerzas Armadas ESPE
    Alex Chicaiza, Maria Belen Ceron
    NRC: 2967
    Fecha creacion: 26/10/2019
	Fecha ultima modificacion:	7/11/2019
	Docente: Ing. Solis
*/
/***********************************************************************
 * Module:  PermutacionLetra.h
 * Author:  Alex Chicaiza, Maria Belen Ceron
 * Modified: Wednesday, November 6, 2019 3:57:40 PM
 * Purpose: Declaration of the class PermutacionLetra
 ***********************************************************************/

#if !defined(__Class_Diagram_2_PermutacionLetra_h)
#define __Class_Diagram_2_PermutacionLetra_h
//#include "Arreglo.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <cstdlib>
#include <cmath>

class PermutacionLetra
{
public:
    std::fstream enter;
    void permutacion(std::string  aux,char *items,int n,int r);
    int tamanioCadena(char * frase);

protected:
private:
    void generarPermutacion(std::string  aux,char *items,int n,int r);

};

#endif
