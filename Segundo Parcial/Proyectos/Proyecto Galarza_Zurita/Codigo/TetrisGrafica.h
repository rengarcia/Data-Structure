#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <winbgim.h>
#include <windows.h>
#include <string>
#include <mmsystem.h>
#include <sstream>
#include "ListaCD.h"


class TetrisGrafica{
	public:
		int grafica();
};

int TetrisGrafica::grafica(){
//	char soundfile[] = "C:/Users/JORGE GALARZA/Desktop/Proyecto/Proyecto Segundo Parcial/Codigo/Tetris99.wav";
//	PlaySound((LPCSTR)soundfile, NULL, SND_FILENAME | SND_ASYNC );
	ListaCD list;
	srand(time(NULL));
    int y=1,j=550, filas=0, puntaje=0;
    initwindow(1300,650);
	rectangle(25,25,1275,625);
	settextstyle(8, 0, 4);
	setfillstyle(1, 0);
	char c;
	char* cN=new char[1];
	int x=rand()%10;
	string num;
	stringstream out;
	int posx=600,posy=50;
	sprintf(cN,"%d",x);
	while(c!=27||list.numeroFila()>=10){
		while(!kbhit()){
		setcolor(x+1);
		outtextxy(posx,posy,cN);
		Sleep(250);
		setcolor(15);
		rectangle(posx-5,posy-5,posx+20,posy+40);
		setcolor(0);
		floodfill(posx,posy,15);
		rectangle(posx-5,posy-5,posx+20,posy+40);
		setcolor(3);
		posy+=50;
		if(posy>(550-(filas*50))){
			int column=posx/120;
			list.insertarEntre(x,column);
		//	list.mostrar();
			if(list.numeroElementos()>=2){
				puntaje=list.chequeoEliminar(puntaje);
		//		list.mostrar();
			}
			filas=list.numeroFila();
			posy=50;
			posx=600;
			free(cN);
			cN=new char[1];
			x=rand()%10;
			sprintf(cN,"%d",x);
			setcolor(0);
			floodfill(600,325,15);
			for(int i=1;i<=list.numeroElementos();i++){
				pnodo aux=list.returnNodo(i);
				char* temp = new char[1];
				sprintf(temp,"%d",aux->getValorTetris());
				setcolor(aux->getValorTetris()+1);
				outtextxy(aux->getColumnas()*120,550-((aux->getFilas()-1)*50),temp);
				free(temp);
				}
			}
		}
	c=getch();
		switch(c){
			case 75:
				if(posx==120)
					posx=120;
				else
            		posx-=120;
            	break; 
            case 77:
                if(posx==1200)
					posx=1200;
				else
            		posx+=120;
            	break;
		}
	}
	PlaySound(NULL, NULL, 0);
	list.generarArchivo();
	return puntaje;
}
