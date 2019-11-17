/**
	Universidad de las Fuerzas Armadas ESPE
    Nombre: Luis Carvajal, Elian Llorente
    NRC: 2967
    Fecha creacion: 30/10/2019
	Fecha ultima modificacion:	7/11/2019
	Docente: Ing. Fernando Solis
*/

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <pthread.h>
#include <windows.h>

using namespace std;

int main(){
    main:
    int opt;
    cout<<endl<<"\t\t\tCODIGOS DE BARRAS"<<endl;
    cout<<"ESCOJA UNA OPCION PARA CONOCER EL NOMBRE DE LOS DESARROLLADORES: "<<endl;
    cout<<"1. ?"<<endl;
    cout<<" O "<<endl;
    cout<<"2. ?"<<endl;
    cout<<"3. SALIR"<<endl<<endl;
    cout<<"OPCION: ";
	cin>>opt;
	switch(opt)
	{
	case 1:
		system("cls");
		system("codebarLuis.png");
		system("cls");
		goto main;
	case 2:
		system("cls");
		system("codebarElian.png");
		system("cls");
		goto main;
    case 3:
        exit(0);
	default:
		cout<<"INGRESE UNA OPCION VALIDA"<<endl;
		system("pause");
		goto main;
	}

}
