/********************************************
 UNIVERSIDAD DE LAS FUERZAAS ARMADAS ESPE
*********************************************
    ESTRUCTURA DE DATOS PROYECTO PRIMER PARCIAL
                 INTEGRANTES:
                - DANIEL AVILA
                - DIEGO ZURITA
FECHA: 
*********************************************/

#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include <winalleg.h> 
#include<fstream>
#include <sstream>
#include "Ingreso.h"
#include "Validacion.h"
#include "TorresHanoi.h"
#define ARRIBA 72
#define ABAJO 80
#define ENTER 13
BITMAP *buffer;
BITMAP *roca;
BITMAP *enemigo;


ifstream f;


using namespace std;

class Grafico{
	public:
		
		//Funcion que define el dibujito de las torres en las x 
		//y el fantasma en las y
		void dibujarMapa(){
			
		//La imagen que muestra la pantalla
		//las x son las rocas 
		//Las y son los fantasmitas
			char mapa[30][30]={
			"yyyyyyyyyyyyyyyyyyyyyyyyyyyyy",
		    "y                           y",	
			"y	      x       x     x     y",	          	          	
			"y	              x     x     y",
			"y	     xxx      x     x     y",	          	          	
			"y	              x     x     y",
			"y	    xxxxx     x     x     y",	          	          	
			"y	              x     x     y",
			"y	   xxxxxxx    x     x     y",	          	          	
			"y                           y",
			"yyyyyyyyyyyyyyyyyyyyyyyyyyyyy",
			"y                           y",
			"y	  x    x         x        y",     	
		    "y	  x    x                  y", 
		    "y	  x    x        xxx       y",    	
			"y	  x    x                  y",
		    "y	  x    x       xxxxx      y",	
		    "y	  x    x                  y",
		    "y	  x    x      xxxxxxx     y",
			"yyyyyyyyyyyyyyyyyyyyyyyyyyyyy",	
			};
					
			int row,col;
			
			for(row=0;row<35;row++){
				for(col=0;col<35;col++){
					if(mapa[row][col]=='x'){
						draw_sprite(buffer, roca, col*35,row*35);
					}
					if(mapa[row][col]=='y'){
						draw_sprite(buffer, enemigo, col*35,row*35);
					}
				}
			}
		}
		
	
	void imprimirPantalla(){
		
		blit(buffer, screen,0,0,0,0,1000,700);
		
	}

	int musica(char* archivo){
		
		MIDI *sonido;
		if(install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, "")!=0){
			allegro_message("Error inicializando el sistema de sonido\n%s\n",allegro_error);
			return 2;
		}
		sonido=load_midi(archivo);
		play_midi(sonido,FALSE);
	}
		void iniciarAllegro(){
		
		allegro_init();//inicia la libreria allegro
		install_keyboard();//para el uso del teclado 

		set_color_depth(32);//saca el color de fondo de las imagenes como la del enemigo "fantasmita rojo"
		set_gfx_mode(GFX_AUTODETECT_WINDOWED, 1000, 700, 0, 0);//tamaño de la pantalla virtual
		
		buffer = create_bitmap(1000, 700);
		roca = load_bitmap("roca.bmp",NULL);//cargo las imagenes que estoy usando
		enemigo = load_bitmap("enemigo.bmp",NULL);
	}
};

class Menus{
	
	public:
		void menuInicio(){
system ("color 9F" );
	printf("\t\t\t================================================\n");
	gotoxy(5,1);
	cout<<"\t\t\t\t\t------MENU------"<<endl;
	gotoxy(5,2);
	cout<<"\t\t\t\t*  Insertar numero de discos";
	gotoxy(5,3);
	cout<<"\t\t\t\t*  Generar PDF del resultado";
	gotoxy(5,4);
	cout<<"\t\t\t\t*  Salir\n";
	printf("\t\t\t================================================");
}

void gotoxy(int x,int y){
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y= y;
	SetConsoleCursorPosition(hcon,dwPos);
}

void Selector(int i)
{
	gotoxy(30,2+i);
}

void menuDinamico(){
	int i = 0;
	char tecla;
	TorresHanoi torres;
	ifstream doc;
	Grafico grafico;
	Validacion validacion;
	Ingreso ingreso;
	int col=3;
	int fil; 
	string fila;
	int* tablero;
	int f;
	int c;
	int disc=1;
	int ultNum;
	int cont=0;
	int valida;
	FILE *archivo;
	
	
	menuInicio();
	Selector(i);
	while(true){
		tecla = getch();
		switch(tecla)
		{
			case ARRIBA:
				i--;
				if(i < 0)
				{
					i = 5;
				}
				Selector(i);
				break;
			case 59:
				system("cls");
				cout<<"Ayuda"<<endl;
				system("TorresDeHanoi.chm");
				system("pause");
				system("cls");
				menuDinamico();
				break;
			case ABAJO:
				i++;
				if(i == 0)
				{
					i = 1;
				}
				if(i == 3)
				{
					i = 0;
				}
				Selector(i);
				break;
			case ENTER:
				Selector(7);
				switch(i)
				{
					case 0:
						system("cls");
						archivo=fopen("Solucion.txt","w+");
						printf("***************Torres de Hanoi******************\n\n");
									
						do{
							fila=ingreso.ingresar("Ingrese el numero de discos: ");
							valida=validacion.validar(fila);
							system("cls");
												
						}while(valida==1);
											
						istringstream ( fila ) >> fil;
											
						tablero = (int *)malloc( sizeof(int) );
										
						// Resetea las torres poniendo los discos en una de ellas y 0 en el resto.
						for( f=0; f < col; f++ )
							for( c=fil-1; c >= 0; c-- )
								if( f==0 ){
									int i;
									i=fil*f+c;
									*(tablero +i) = disc;
									disc+=2;
								}
								else{
									int j;
									j=fil*f+c;
									*(tablero +j) = 0;
								}
										
						ultNum = disc;
										
						// Se imprime el tablero antes de iniciar ningún movimiento
						torres.imprime( tablero, col, fil, ultNum );
											
						// Se llama a hanoi para que nos muestre la solucion
						torres.hanoi( tablero, col, fil, fil, ultNum, 0, 1, 2 );
											
						printf("La solucion se guardo en el documento Solucion.txt\n\n");
						printf("Se abrira una representacion grafica de las torres de Hanoi\n\n");
						printf("Una vez dentro presionar 'esc' para abandonar la pantalla grafica\n\n\n");
											
						fclose(archivo);
							
						system ("pause");
						grafico.iniciarAllegro();		
						while(!key[KEY_ESC]){
						grafico.musica("Rock_And_Roll.mid");
						grafico.dibujarMapa();
						grafico.imprimirPantalla();
						readkey();
						}
						allegro_exit();

						system("cls");
						menuDinamico();
						break;
					case 1:
						system("cls");
															
						doc.open("Solucion.txt",fstream::in);
						if(doc.fail()){
							system("cls");
							cout<<"ERROR: El archivo de agenda no esta creado\n";
							system("pause");
							system("cls");
							menuDinamico();
						}
						else{
							doc.close();
							system("cls");
							system("txt2pdf.exe Solucion.txt Solucion.pdf -oao -pfs60 -pps43 -ptc0 -width3000 -height2000");
							cout<<"Archivo generado exitosamente\n";
							system("pause");
							system("cls");
							menuDinamico();
						}
					
																				
					default:
					exit(0);
			}
		}
	}
}



void portada()
{
	system ("color 9F" );
	
	cout<<"\t\t\t\t\tBIENVENIDOS A NUESTRO PROGRAMA"<<endl;
	
	cout<<"\n\n"<<endl;
	
	cout<<"\t\t\t\t:::             :::::::::      ::::::::::    "<<endl;
	cout<<"\t\t\t\t:::            :::     :::    :::            "<<endl;
	cout<<"\t\t\t\t:::            :::     :::    :::            "<<endl;
	cout<<"\t\t\t\t:::            :::::::::::    ::::::::::     "<<endl;
	cout<<"\t\t\t\t:::            :::::::::::            :::    "<<endl;
	cout<<"\t\t\t\t:::     :::    :::     :::            :::    "<<endl;
	cout<<"\t\t\t\t:::::::::::    :::     :::    ::::::::::     "<<endl;

	cout<<"\n";

	cout<<"\t\t:::::::::::     :::::::::     :::::::::     :::::::::     :::::::::::     ::::::::::     "<<endl;
	cout<<"\t\t    :::        :::     :::    :::    :::    :::    :::    :::            :::             "<<endl;
	cout<<"\t\t    :::        :::     :::    :::    :::    :::    :::    :::            :::             "<<endl;
	cout<<"\t\t    :::        :::     :::    :::::::::     :::::::::     :::::::         :::::::::      "<<endl;
	cout<<"\t\t    :::        :::     :::    :::  ::       :::  ::       :::                    :::     "<<endl;
	cout<<"\t\t    :::        :::     :::    :::   ::      :::   ::      :::                    :::     "<<endl;
	cout<<"\t\t    :::         :::::::::     :::    ::     :::    ::     :::::::::::    ::::::::::      "<<endl;
	
	cout<<"\n";
	
	cout<<"\t::::::::::      :::::::::::      :::     :::     :::::::::     ::::      :::     :::::::::     :::::::     "<<endl;
	cout<<"\t:::      :::    :::              :::     :::    :::     :::    ::: :     :::    :::     :::      :::       "<<endl;
	cout<<"\t:::      :::    :::              :::     :::    :::     :::    :::  :    :::    :::     :::      :::       "<<endl;
	cout<<"\t:::      :::    :::::::          :::::::::::    :::::::::::    :::   :   :::    :::     :::      :::       "<<endl;
	cout<<"\t:::      :::    :::              :::::::::::    :::::::::::    :::    :  :::    :::     :::      :::       "<<endl;
	cout<<"\t:::      :::    :::              :::     :::    :::     :::    :::     : :::    :::     :::      :::       "<<endl;
	cout<<"\t::::::::::      :::::::::::      :::     :::    :::     :::    :::      ::::     :::::::::     :::::::     "<<endl;
	
	cout<<"\n";
	system("PAUSE");
}
};


int main()
{
	Menus menu;
	menu.portada();
	system("cls");
	menu.menuDinamico();
	return 0;
}
END_OF_MAIN();


