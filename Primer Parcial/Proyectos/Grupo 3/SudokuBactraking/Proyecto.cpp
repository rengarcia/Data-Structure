/**
    *@file Main
    *@version 2.0
    *@author Antoni Toapanta, Jhonny Naranjo
    *@title Main
    *@brief Mi programa se ejecuta aqui
    */
/***********************************************************************
 * Module:  Main.cpp
 * Author:  Antoni Toapanta Jhonny Naranjo
 * Modified: miércoles, 6 de noviembre de 2019 01:54:07
 * Purpose: Declaration of the class Operaciones
 ***********************************************************************/
#include <iostream>
#include<stdlib.h>
#include "Tabla.cpp"
#include "ingreso.h"
#include <pthread.h>
#include <windows.h>
using namespace std;
void *moverMarquesina(void *marq);
void gotoxy(short x, short y);
int main()
{
    pthread_t thread1;
    pthread_t thread2;
    pthread_create(&thread1,NULL,moverMarquesina,NULL);
	main:
    cout<<endl;
    cout<<endl;
    Ingreso lee;
    int opc;
    cout<<"============================================================="<<endl;
    cout<<"\tToapanta Antoni-Naranjo Jhony"<<endl;
    cout<<"\tEstructura de datos\n\t2019-2020"<<endl;
    cout<<"==============================================================\n";

    do{
        cout<<"Escoja la opcion que desea realizar"<<endl;
        cout<<"1. Mostrar solucion sudoku\n2.Mostrar ayuda del programa";
        opc = lee.ingresarInt("\n---> ");
    }while(opc != 1 && opc != 2 );
    if(opc==2)
       system("ayuda.chm");
    if(opc==1){
    Tabla t = Tabla();
    if (t.Sudoku() == true)
    {
        system("cls");
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        t.mostrarT();
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        system("txt2pdf.exe Proyecto.csv SudokuBacktraking.pdf -oao -pfs60 -pps43 -ptc0 -width3000 -height2000");
        system("pause");
        system("cls");
        goto main;

    }
    else
    {
        cout << "No solution exists";
    }
    t.~Tabla();
    system("pause");
    }
    return 0;
}
void gotoxy(short x, short y) {
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void* moverMarquesina(void *marq){

	int a, b, c, n=0,letra=39,pos=1,cont=39,aux,cont1=39,auxg;
	char t[50] ="UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE",auxt[39]=" ";

	do{
		for (a=0;a<42;a++){
			aux=pos;
			for(b=39;b>cont;b--){
				gotoxy(pos,1);
				cout<<t[b];
				pos--;
			}
			aux++;
			pos=aux;
			cont--;
			Sleep (75);
			if(a==40){
				break;
			}
		}
		for(a=3;a<70;a++){
			gotoxy(a-1,1);
			cout<<" ";
			gotoxy(a,1);
			cout<<t;
			Sleep (75);
		}

		pos=70;
		auxg=69;
		for (a=0;a<41;a++){
			gotoxy(auxg,1);
			cout<<" ";
			aux=pos;
			for(b=0;b<=cont1;b++){
				gotoxy(pos,1);
				cout<<t[b];
				pos++;
			}
			cont1--;
			aux++;
			pos=aux;
			auxg++;
			Sleep (75);
		}
		cont1=39;
		letra=39;
		pos=1;
		cont=39;
		c=0;
	}while (c=1);

}
