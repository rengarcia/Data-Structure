/**
	Universidad de las Fuerzas Armadas ESPE
    Nombre: Luis Carvajal, Elian Llorente
    NRC: 2967
    Fecha creacion: 30/10/2019
	Fecha ultima modificacion:	7/11/2019
	Docente: Ing. Fernando Solis
*/

#include "Convinacion.cpp"
#include "Ingreso.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void *moverMarquesina(void *marq);
void gotoxy(short x, short y);

using namespace std;
int main(){
    pthread_t thread1;
    pthread_t thread2;
    pthread_create(&thread1,NULL,moverMarquesina,NULL);
	main:
	int *st,opt;
	Convinacion c;
	Ingreso lee;
	system("cls");
	cout<<"\n\n\n\n||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||";
	cout<<"\n||||                                                                      ||||\n";
	cout<<  "||||              UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                 ||||";
	cout<<"\n||||                       ESTRUCTURA DE DATOS                            ||||";
	cout<<"\n||||          INTEGRANTES: CARVAJAL LUIS - ELIAN LLORENTE                 ||||";
	cout<<"\n||||                            NRC: 2967                                 ||||";
	cout<<"\n||||                                                                      ||||";
	cout<<"\n||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n\n\n\n\n";

	cout<<"\n||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||";
	cout<<"\n||||                                                                      ||||\n";
	cout<<  "||||                             MENU                                     ||||";
	cout<<"\n||||                       1. APLICATIVO                                  ||||";
	cout<<"\n||||                       2. AYUDA                                       ||||";
	cout<<"\n||||                       3. SOLUCIONES                                  ||||";
	cout<<"\n||||                       4. SALIR                                       ||||";
	cout<<"\n||||                                                                      ||||";
	cout<<"\n||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n\n\n";

	opt=lee.ingresarInt(" ELIGA UNA OPCION: ");

	switch(opt)
	{
	case 1:
		system("cls");
		st=(int*)calloc(n,sizeof(int*)*n);
		Ingreso lectura;
        n=lectura.ingresarInt("\n\n\n\nINGRESE ENTERO A DESCOMPONER: \n\n\n\n");
		if(n>=10){
			cout<<"\n\n\n\n\nEL ENTERO DEBE SER MENOR QUE 10"<<endl;
			system("pause");
			system("cls");
			goto main;
		}else{
		c.mostrar(st,1);
		c.backtraking(st,1);
		system("pause");
		system("cls");
		goto main;
		}

	case 2:

		system("help.chm");
		system("cls");
		goto main;

	case 3:
		system("cls");
		c.archivo();
		cout<<"\n\n\n\nABRIENDO ARCHIVO CON LAS SOLUCIONES"<<endl;
		system("txt2pdf.exe out.txt respuestas.pdf -oao -pfs60 -pps43 -ptc0 -width3000 -height2000");
		system("pause");
		goto main;


	case 4:
		system("cls");
		cout<<"\n\n\n||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||";
		cout<<"\n||||                                                                      ||||\n";
		cout<<  "||||                                                                      ||||";
		cout<<"\n||||                  GRACIAS POR USAR ESTE PROGRAMA                      ||||";
		cout<<"\n||||               ESPERAMOS QUE HAYA SIDO DE TU AGRADO                   ||||";
		cout<<"\n||||                                                                      ||||";
		cout<<"\n||||                                                                      ||||";
		cout<<"\n||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n\n\n";
		system("pause");
		exit(0);
	default:
		system("cls");
		cout<<"INGRESE UNA OPCION CORRECTA"<<endl;
		system("pause");
		goto main;
	}
	goto main;

}

void gotoxy(short x, short y) {
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void* moverMarquesina(void *marq){

	int a, b, c, n=0,letra=39,pos=1,cont=39,aux,cont1=39,auxg;
	char t[50] ="BIENVENIDOS A ESTRUCTURA DE DATOS",auxt[39]=" ";

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


