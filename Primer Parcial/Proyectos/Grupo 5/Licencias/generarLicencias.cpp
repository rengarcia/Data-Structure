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
    cout<<endl<<"\t\t\tCODIGOS QR"<<endl;
    cout<<"ESCOJA UNA OPCION PARA MOSTRAR UNA DE LAS 5 LICENCIAS DEL INSTALADOR: "<<endl;
    cout<<"1. PRIMER LICENCIA"<<endl;
    cout<<"2. SEGUNDA LICENCIA"<<endl;
    cout<<"3. TERCER LICENCIA"<<endl;
    cout<<"4. CUARTA LICENCIA"<<endl;
    cout<<"5. QUINTA LICENCIA"<<endl;
    cout<<"6. SALIR"<<endl<<endl;
    cout<<"OPCION: ";
	cin>>opt;
	switch(opt)
	{
	case 1:
		system("cls");
		system("licencia1.png");
		system("cls");
		goto main;
	case 2:
		system("cls");
		system("licencia2.png");
		system("cls");
		goto main;
    case 3:
		system("cls");
		system("licencia3.png");
		system("cls");
		goto main;
	case 4:
		system("cls");
		system("licencia4.png");
		system("cls");
		goto main;
    case 5:
		system("cls");
		system("licencia5.png");
		system("cls");
		goto main;
    case 6:
        exit(0);
	default:
		cout<<"INGRESE UNA OPCION VALIDA"<<endl;
		system("pause");
		goto main;
	}

}
