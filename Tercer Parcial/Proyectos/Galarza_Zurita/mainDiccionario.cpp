/*	***** UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE ***** **
** Estructura de Datos									**
** Nombre: Jorge Galarza - Kevin Zurita					**
** NRC: 2742											**
** Fecha de realizacion: 01/12/2019						**
** Fecha de modificacion: 12/12/2019					**
** Ing. Fernando Solis									**
*/	
#include <iostream>
#include <stdio.h>
#include <string>
#include <windows.h>
#include "DiccionarioG.h"

using namespace std;
void cifrado();
void decifrado();

int main(){
	DiccionarioG graf;
	graf.diccionario();
	system("txt2pdf.exe diccionario.txt diccionariopdf.pdf -oao -pfs60 -pps43 -ptc0 -width3000 -height2000");
	cifrado();
	decifrado();
}

void cifrado()
{
	char arch_in[]="diccionario.txt";
	char arch_out[]="diccionariocifrado.txt";
	char c;
	FILE *ofp,*ifp;
	ifp=fopen(arch_in,"r");
	ofp=fopen(arch_out,"w");
//	system("txt2pdf.exe Datos.txt Datospdf.pdf -oao -pfs60 -pps43 -ptc0 -width3000 -height2000");
	while((c= fgetc(ifp))!=EOF)
	{
		fputc(c+5-3+7-9+4+2-3,ofp);

	}
	fclose(ofp);
	fclose(ifp);
}
void decifrado()
{
	char arch_in[]="diccionariodecifrado.txt";
	char arch_out[]="diccionariocifrado.txt";
	char c;
	FILE *ofp,*ifp;
	ofp=fopen(arch_in,"w");
	ifp=fopen(arch_out,"r");
	
	
	while((c= fgetc(ifp))!=EOF)
	{
		fputc(c-5+3-7+9-4-2+3,ofp);

	}
	fclose(ofp);
	fclose(ifp);
}
