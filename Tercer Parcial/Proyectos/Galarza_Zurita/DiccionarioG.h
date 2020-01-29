/*	***** UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE ***** **
** Estructura de Datos									**
** Nombre: Jorge Galarza - Kevin Zurita					**
** NRC: 2742											**
** Fecha de realizacion: 01/12/2019						**
** Fecha de modificacion: 12/12/2019					**
** Ing. Fernando Solis									**
*/	
#include <winbgim.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include <windows.h>
#include "ArbolBinario.h"
#include "Ingreso.h"

class DiccionarioG{
	public:
		void lineas();
		void defaulto();
		void diccionario();
		string minuscula(string);
};
string DiccionarioG::minuscula(string palabra){
	string aux;
	for (int i=0; i<palabra.length(); i++){
		aux=tolower(palabra.at(i));
        palabra.replace(i,1,aux.c_str());
	}
    return palabra;
}

void DiccionarioG::lineas(){
	setcolor(0);
	line(45,60,280,60);
	line(45,100,280,100);
	line(45,140,280,140);
	line(45,180,280,180);
	line(45,220,280,220);
	line(45,260,280,260);
	line(45,300,280,300);
	line(45,340,280,340);
	line(45,380,280,380);	
	line(45,420,280,420);
	line(45,460,280,460);
	line(45,500,280,500);
	line(45,540,280,540);
	line(310,60,545,60);
	line(310,100,545,100);
	line(310,140,545,140);
	line(310,180,545,180);
	line(310,220,545,220);
	line(310,260,545,260);
	line(310,300,545,300);
	line(310,340,545,340);
	line(310,380,545,380);	
	line(310,420,545,420);
	line(310,460,545,460);
	line(310,500,545,500);
	line(310,540,545,540);
}

void DiccionarioG::defaulto(){
	setcolor(8);
	rectangle(15,15,575,575);
	rectangle(30,30,560,560);
	line(295,30,295,560);
	setfillstyle(1,6);
	floodfill(20,20,8);
	setfillstyle(1,15);
	floodfill(35,35,8);
	floodfill(305,550,8);
}

void DiccionarioG::diccionario(){
	NodoArbol* aIngles=NULL;
	NodoArbol* aEspaniol=NULL;
	NodoArbol* aPronunciacion=NULL;
	ArbolBinario tree;
	tree.llenarDiccionario(aIngles,aEspaniol,aPronunciacion);
	initwindow(600,600);
	defaulto();
	lineas();
	setcolor(15);
	settextstyle(8, 0, 4);
	outtextxy(65,295,"Dictionary");
	outtextxy(95,260,"English");
	outtextxy(330,260,"Diccionario");
	outtextxy(355,295,"Espaniol");
	char tecla;
	int i=0;
	do{
	tecla=getch();
	switch(tecla){
		case 75:
			if(i!=1){
			i=1;
			setfillstyle(1,15);
			floodfill(425,170,8);	
			setcolor(15);
			outtextxy(330,260,"Diccionario");
			outtextxy(355,295,"Espaniol");
			lineas();
			setcolor(1);
			setfillstyle(1,1);
			rectangle(150,150,180,200);
			floodfill(165,170,1);
			line(140,200,166,230);
			line(190,200,164,230);
			line(140,200,190,200);
			floodfill(165,210,1);
			}
			break;
		case 77:
			if(i!=2){
			i=2;
			setcolor(15);
			setfillstyle(1,15);
			floodfill(165,170,8);
			outtextxy(65,295,"Dictionary");
			outtextxy(95,260,"English");
			lineas();
			setcolor(1);
			setfillstyle(1,1);
			rectangle(410,150,440,200);
			floodfill(425,170,1);
			line(400,200,426,230);
			line(450,200,424,230);
			line(400,200,450,200);
			floodfill(425,210,1);
			}
			break;
		case 13:
			if(i==1||i==2){
				Ingreso ingresar;
				cleardevice();
				defaulto();
				lineas();
				string traducir;
				setcolor(15);
				settextstyle(8, 0, 3);
				if(i==1){
				outtextxy(105,60,"Enter the word to translate");
				getch();
				traducir=ingresar.ingresarString("Enter the word to translate");
				cleardevice();
				defaulto();
				lineas();
				setcolor(15);
				outtextxy(50,60,"Original word");
				outtextxy(315,60,"Traduced word");
				outtextxy(50,110,traducir.c_str());
				outtextxy(315,110,tree.Traduccion(aIngles,aEspaniol,minuscula(traducir)).c_str());
				Sleep(3000);
				}else if(i==2){
				outtextxy(90,60,"Ingrese la palabra a traducir");
				getch();
				traducir=ingresar.ingresarString("Ingrese la palabra a traducir");
				cleardevice();
				defaulto();
				lineas();
				setcolor(15);
				outtextxy(50,60,"Palabra Original");
				outtextxy(315,60,"Palabra Traducida");
				outtextxy(50,110,traducir.c_str());
				outtextxy(315,110,tree.Traduccion(aEspaniol,aIngles,minuscula(traducir)).c_str());
				outtextxy(315,160,tree.Traduccion(aEspaniol,aPronunciacion,minuscula(traducir)).c_str());
				tree.voz(tree.Traduccion(aEspaniol,aIngles,minuscula(traducir)));
				Sleep(3000);
				}				
				cleardevice();
				defaulto();
				lineas();
				setcolor(15);
				settextstyle(8, 0, 4);
				outtextxy(65,295,"Dictionary");
				outtextxy(95,260,"English");
				outtextxy(330,260,"Diccionario");
				outtextxy(355,295,"Espaniol");
			}
		}
	}while(tecla!=27);
}


