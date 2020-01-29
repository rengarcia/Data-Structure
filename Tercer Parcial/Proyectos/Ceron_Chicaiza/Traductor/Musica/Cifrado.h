/*******************************************************************
 *	Universidad de las Fuerzas Armadas ESPE
 *	Alex Chicaiza
 *	Maria Belen Ceron
 *	NRC: 2967
 *	Fecha creacion: 19/01/2020
 *	Fecha ultima modificacion:	26/01/2020
 *	Docente: Ing. Fernando Solis
******************************************************************/

/***********************************************************************
 * Module:  Cifrado.h
 * Modified: Sunday, January 24, 2020 3:41:28 PM
 * Purpose: Declaration of the class Cifrado
 ***********************************************************************/

#if !defined(__Cifrado_Cifrado_h)
#define __Cifrado_Cifrado_h

#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include<string>


using namespace std;

class Cifrado
{
public:
	void encriptado();
	void desencriptado();
private:
	FILE* archivo, * nuevo;

};

#endif