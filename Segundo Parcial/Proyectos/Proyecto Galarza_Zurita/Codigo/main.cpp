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
#include <stdlib.h>
#include <time.h>
#include <winbgim.h>
#include <windows.h>
#include <string>
#include "TetrisGrafica.h"
#include "Jugador.h"
#include <string>
#include <iostream>
#include <fstream>


void cifrado();
void decifrado();

using namespace std;
int main() 
{ 
FILE * pFile;
	Jugador player;
	string nombre;
	cout << "\n\n\n\n\n\n\n"<<endl;
	cout << "Ingrese su nombre"<<endl;
	cin >> nombre;
	player.setNombre(nombre);
	TetrisGrafica tGraf;
	int x=tGraf.grafica();
	player.setPuntaje(x);
	ofstream file;
  	file.open("Datos.txt");
  	file <<"Jugador: " <<nombre<<" "<<"Puntaje: "<<x;
  	file.close();
	cifrado();
	decifrado();
	
	
	return 0; 
} 

void cifrado()
{
	char arch_in[]="Datos.txt";
	char arch_out[]="DatosCifrado.txt";
	char c;
	FILE *ofp,*ifp;
	ifp=fopen(arch_in,"r");
	ofp=fopen(arch_out,"w");
	system("txt2pdf.exe Datos.txt Datospdf.pdf -oao -pfs60 -pps43 -ptc0 -width3000 -height2000");
	while((c= fgetc(ifp))!=EOF)
	{
		fputc(c+5-3+7-9+4+2-3,ofp);

	}
	fclose(ofp);
	fclose(ifp);
}
void decifrado()
{
	char arch_in[]="DatosDecifrado.txt";
	char arch_out[]="DatosCifrado.txt";
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
