/**  @brief Proyecto Estructura de Datos Primer Parcial*/

/**   UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE 	*
*		Ingenieria de Sofware               	*
*		Estructura de Datos						*
*												*
*	@author Jorge Luis Galarza	- Kevin Zurita	*
*	NRC:2967									*
*	@date 07/11/2019							*
*	Ingeniero Fernando Solis					*
*	Version: 1.0
	
*/

#include <iostream>
#include "WordMatrix.h"
#include <conio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <winbgim.h>
#include "Ingresar.h"

void* marquesina(void*);
void gotoxy(int,int);
void* proceso(void*);

using namespace std;

int main()
{ 
	//Creacion de hilos
	void *status;
	pthread_t thread1;
	pthread_t thread2;
	pthread_create (&thread1 , NULL , marquesina , ( void *) & thread2);	
	pthread_create (&thread2 , NULL , proceso , ( void *) & thread1);
	pthread_join(thread1, &status);
	pthread_join(thread2, &status);

	system("pause");

	return 0; 

}

// Proceso
/**
* @brief Funcion en donde se encuentra todo el proceso del proyecto
* @param Void puntero para la creacion de hilos
* @return Void puntero para la creacion de hilos
*/
void* proceso(void *data)
{
	Ingreso ing;
	bool bandera = true;
	int dimension;
	string palabra; 
	char tecla;
	system("cls");
	cout<<endl;
	cout<<endl;
	cout<<endl;

		cout<<"\t Seleccione lo que desea realizar \t\t\t\t Ingrese 5 para ayuda"<<endl;
		cout<<"1. Ejercicio Backtracking (Encontrar una palabra dentro de una matriz)"<<endl; 
		cout<<"2. Codigo QR \t\t\t 3. Codigo de Barras \t\t\t 4. Salir"<<endl; 
		
		do
		{
			cin>>tecla;
			switch(tecla){
		
				break;
			case 49: //1
			{
				system("cls");
				cout << "\n\n"<<endl;
				cout<<"La dimension predeterminada de la matriz es de 10x10"<<endl;
				dimension = 10;
				WordMatrix w = WordMatrix(dimension);
				char ** m;
   				m =(char **)malloc(dimension*sizeof(char *));
    			for(int j=0;j<dimension;j++)
        		*(m+j)=(char *)malloc(dimension*sizeof(char));
    			srand(time(NULL));
    			for(int i=0;i<dimension;i++)
       				for(int j=0;j<dimension;j++){
						int x = (rand()%26)+97;
						char c=(char)x;
            			*(*(m+i)+j)=c;
    				}
		    	initwindow(650,650);
				settextstyle(8, 0, 4);
				int x=0;
				for(int i=55; i<=600;i+=60){
					int y=0;
					for(int j=55;j<=600;j+=60){
						char* output;
						output=(char *)malloc(1*sizeof(char));
						sprintf(output,"%c",*(*(m+x)+y));
						outtextxy(j,i,output);
						free(output);
						y++;
					}
					x++;
					}
					rectangle(25,25,625,625);
					for(int i=85;i<=625;i+=60){
						line(i,25,i,625);
						line(25,i,625,i);
					}
			palabra=ing.ingresarString("Ingrese la palabra que desea buscar en la matriz");
		    closegraph();
   			system("cls");
		    cout << "\n\n\n"<<endl;
		    gotoxy(0,15);
			if (w.searchWord(m, palabra)) {
		            cout<<"Intento acertado (Se saldrá del programa automaticamente)"<<endl;
					exit(-1);
				} else {
					cout<<"Fallo"<<endl;
					exit(-1);
				}    
				bandera = false;
				break;
			}
			case 50: //2
			{
			system("CodigoQR.png");
				break;
			}
			case 51: //3
			{
			system("CodigoDeBarras.png");
			break;
			}
			case 52: //4
			{
			system("cls");
			cout << "\n"<<endl;
			cout <<"Gracias por usar el programa, hasta luego"<<endl;
			exit(-1);
			break;
			}
		case 53: 
			system("AyudaProyecto1.chm");
			break;	
		default:
			{
				cout <<"\n\n\n\n"<<endl;
				cout <<"Opcion no valida"<<endl;
				Beep(500,100);
				break;
			}
		}	
	}while(bandera);
	
}


// Marquesina
/**
* @brief Funcion para el desplazamiento de la marquesina
* @param Void puntero para la creacion de hilos
* @return Void puntero para la creacion de hilos
*/
void* marquesina(void *data){

	int a, b, c, n=0,letra=39,pos=1,cont=39,aux,cont1=39,auxg;
	char t[50] ="Bienvenidos Proyecto Estructura de Datos",auxt[39]=" ";

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

// Funcion gotoxy
/**
* @brief Funcion gotoxy, usado en el desplazamiento de la marquesina
* @param Enteros x e y, que indican la posicion horizontal y vertical de la consola.
* @return Void
*/
void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 }
