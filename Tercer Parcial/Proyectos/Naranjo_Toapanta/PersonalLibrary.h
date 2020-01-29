/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS                   *
*                        ESPE                                     *
*TRABAJO EN GRUPO:                                                *
*          NOMBRES:ANTONI TOAPANTA                                *
*                   JHONY NARANJO                                 *
*MATERIA: ESTRUCTURA DE DATOS                                     *
*NRC:2967                                                         *
*Fecha de Creacion:26/01/2020                                     *
******************************************************************/
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <ctype.h>
#include <string.h>
#include <fstream>
#include <string>
#include <time.h>
#include <pthread.h>
#include <fstream>

using namespace std;

#define TECLA_ARRIBA 72
#define TECLA_ABAJO 80
#define TECLA_DERECHA 77
#define TECLA_IZQUIERDA 75
#define TECLA_ENTER 13

void gotoxy(int x, int y)
{
	HANDLE hCon;
	hCon=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X=x;
	dwPos.Y=y;
	SetConsoleCursorPosition(hCon,dwPos);
}

void color(int x)
{
	SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),x);
}

int menu(const char *titulo,const char *opciones[], int numero)
{

	bool repite=true;
	int seleccionar=1,tecla;
	int i;
	system("cls");
	do
	{

		gotoxy(10,2);
		color(158);
		printf("================================================");
		color(11);
		printf("\n\t\t\t%s\t\t\t\n\n",titulo);
		color(15); //letras en blanco
		for(i=0;i<numero;i++)
			printf("\t\t%s\n",opciones[i]);
		gotoxy(16,4+seleccionar); //17
		color(249);
		//printf("%c %s",175,opciones[seleccionar-1]); //impresion con asterisco
		printf("%s",opciones[seleccionar-1]);
		color(158);
		gotoxy(10,15);
		printf("================================================");
		color(15);
		do
		{
			tecla=getch();
		}while(tecla!=TECLA_ARRIBA && tecla!=TECLA_ABAJO && tecla!= TECLA_ENTER && tecla !=00);
		switch(tecla)
		{
			case TECLA_ARRIBA:
			{
				seleccionar--;
				if(seleccionar==0)
					seleccionar=numero;
			}
			break;
			case TECLA_ABAJO:
			{
				seleccionar++;
				if(seleccionar==numero+1)
					seleccionar=1;
			}
			break;
			case TECLA_ENTER:
				repite=false;
			break;
			case 0:
				ShellExecute(NULL, TEXT("open"),TEXT("Extras\\Ayuda.chm"),NULL, NULL,SW_SHOWNORMAL);
			break;
		}
	}while(repite);
	color(15);
	return seleccionar;
}

void AltEnter()
{
    keybd_event(VK_MENU,
                0x38,
                0,
                0);
    keybd_event(VK_RETURN,
                0x1c,
                0,
                0);
    keybd_event(VK_RETURN,
                0x1c,
                KEYEVENTF_KEYUP,
                0);
    keybd_event(VK_MENU,
                0x38,
                KEYEVENTF_KEYUP,
                0);
}

void imprimirTXT(char txt[])
{
    string frase;
    ifstream ficheroEntrada;

	color(10);
 	ficheroEntrada.open(txt);
 	while (!ficheroEntrada.eof() )
	{
 		getline(ficheroEntrada, frase);
 		cout << frase << endl;
 	}
 	ficheroEntrada.close();
}

bool validacionCaracter(char cadena[]){
	int i;
	for(i=0;cadena[i]!='\0';i++)
	{
		if((cadena[i]<65||cadena[i]>90)&&(cadena[i]<97||cadena[i]>122)&&cadena[i]!=32&&cadena[i]!=-92&&cadena[i]!=-91)
		{
			printf("______________________________________________________\nDato Incorrecto !!\nNo puede contener caracteres especiales, ni numeros\nVuelva a ingresar por favor\n______________________________________________________\n\n");
			return true;
			break;
		}
	}
	return false;
}
void guardarNombre(string nombre)
{
    ofstream arch;
    arch.open("Nombre.txt",ios::out);
    arch<<nombre;
    arch.close();
}
void numbers(int numero,int x,int y)
{
	switch(numero){
		case 0:
				color(1);
				gotoxy(x,y++);
				printf("%c%c%c%c%c%c",219,219,219,219,219,219);gotoxy(x,y++);
				printf("%c%c%c%c%c%c",219,219,219,219,219,219);gotoxy(x,y++);
				printf("%c%c%c%c%c%c",219,219,219,219,219,219);gotoxy(x,y++);
				printf("%c%c%c%c%c%c",219,219,219,219,219,219);gotoxy(x,y++);
				printf("%c%c%c%c%c%c",219,219,219,219,219,219);gotoxy(x,y++);
				break;

			case 1:
				color(2);
				gotoxy(x,y++);
				printf("%c%c%c%c%c%c",219,219,219,219,219,219);gotoxy(x,y++);
				printf("%c%c%c%c%c%c",219,219,219,219,219,219);gotoxy(x,y++);
				printf("%c%c%c%c%c%c",219,219,219,219,219,219);gotoxy(x,y++);
				printf("%c%c%c%c%c%c",219,219,219,219,219,219);gotoxy(x,y++);
				printf("%c%c%c%c%c%c",219,219,219,219,219,219);gotoxy(x,y++);
				break;


			case 2:
				color(3);
				gotoxy(x,y++);
				printf("%c%c%c%c%c%c",219,219,219,219,219,219);gotoxy(x,y++);
				printf("%c%c%c%c%c%c",219,219,219,219,219,219);gotoxy(x,y++);
				printf("%c%c%c%c%c%c",219,219,219,219,219,219);gotoxy(x,y++);
				printf("%c%c%c%c%c%c",219,219,219,219,219,219);gotoxy(x,y++);
				printf("%c%c%c%c%c%c",219,219,219,219,219,219);gotoxy(x,y++);
				break;


			case 3:
				color(4);
				gotoxy(x,y++);
				printf("%c%c%c%c%c%c",219,219,219,219,219,219);gotoxy(x,y++);
				printf("%c%c%c%c%c%c",219,219,219,219,219,219);gotoxy(x,y++);
				printf("%c%c%c%c%c%c",219,219,219,219,219,219);gotoxy(x,y++);
				printf("%c%c%c%c%c%c",219,219,219,219,219,219);gotoxy(x,y++);
				printf("%c%c%c%c%c%c",219,219,219,219,219,219);gotoxy(x,y++);
				break;

			case 4:
				color(6);
				gotoxy(x,y++);
				printf("%c%c%c%c%c%c",219,219,219,219,219,219);gotoxy(x,y++);
				printf("%c%c%c%c%c%c",219,219,219,219,219,219);gotoxy(x,y++);
				printf("%c%c%c%c%c%c",219,219,219,219,219,219);gotoxy(x,y++);
				printf("%c%c%c%c%c%c",219,219,219,219,219,219);gotoxy(x,y++);
				printf("%c%c%c%c%c%c",219,219,219,219,219,219);gotoxy(x,y++);
				break;

			case 5:
				color(7);
				gotoxy(x,y++);
				printf("%c%c%c%c%c%c",219,219,219,219,219,219);gotoxy(x,y++);
				printf("%c%c%c%c%c%c",219,219,219,219,219,219);gotoxy(x,y++);
				printf("%c%c%c%c%c%c",219,219,219,219,219,219);gotoxy(x,y++);
				printf("%c%c%c%c%c%c",219,219,219,219,219,219);gotoxy(x,y++);
				printf("%c%c%c%c%c%c",219,219,219,219,219,219);gotoxy(x,y++);
				break;

			case 6:
				color(12);
				gotoxy(x,y++);
				printf("%c%c%c%c%c%c",219,219,219,219,219,219);gotoxy(x,y++);
				printf("%c%c%c%c%c%c",219,219,219,219,219,219);gotoxy(x,y++);
				printf("%c%c%c%c%c%c",219,219,219,219,219,219);gotoxy(x,y++);
				printf("%c%c%c%c%c%c",219,219,219,219,219,219);gotoxy(x,y++);
				printf("%c%c%c%c%c%c",219,219,219,219,219,219);gotoxy(x,y++);
				break;

			case 7:
				color(9);
				gotoxy(x,y++);
			    printf("%c%c%c%c%c%c",219,219,219,219,219,219);gotoxy(x,y++);
				printf("%c%c%c%c%c%c",219,219,219,219,219,219);gotoxy(x,y++);
				printf("%c%c%c%c%c%c",219,219,219,219,219,219);gotoxy(x,y++);
				printf("%c%c%c%c%c%c",219,219,219,219,219,219);gotoxy(x,y++);
				printf("%c%c%c%c%c%c",219,219,219,219,219,219);gotoxy(x,y++);
				break;

			case 8:
				color(10);
				gotoxy(x,y++);
				printf("%c%c%c%c%c%c",219,219,219,219,219,219);gotoxy(x,y++);
				printf("%c%c%c%c%c%c",219,219,219,219,219,219);gotoxy(x,y++);
				printf("%c%c%c%c%c%c",219,219,219,219,219,219);gotoxy(x,y++);
				printf("%c%c%c%c%c%c",219,219,219,219,219,219);gotoxy(x,y++);
				printf("%c%c%c%c%c%c",219,219,219,219,219,219);gotoxy(x,y++);
			    break;

			case 9:
				color(11);
				gotoxy(x,y++);
				printf("%c%c%c%c%c%c",219,219,219,219,219,219);gotoxy(x,y++);
				printf("%c%c%c%c%c%c",219,219,219,219,219,219);gotoxy(x,y++);
				printf("%c%c%c%c%c%c",219,219,219,219,219,219);gotoxy(x,y++);
				printf("%c%c%c%c%c%c",219,219,219,219,219,219);gotoxy(x,y++);
				printf("%c%c%c%c%c%c",219,219,219,219,219,219);gotoxy(x,y++);
			    break;
		}
}
string lectura()
{
    ifstream archivo;
    string texto;
    archivo.open("Datos.txt",ios::in);
    if(archivo.fail())
    {
        exit(1);
    }
    else{
        while(!archivo.eof())
        {
            getline(archivo,texto);
        }
    }
    archivo.close();
    return texto;
}
void codificar(string &nombre,int i)
{
        do
        {
            if(i%2==0)
            {
                nombre.at(i)=(nombre.at(i)+6)+nombre.length();
            }
            else{
                nombre.at(i)=(nombre.at(i)+3)-nombre.length();
            }
            i++;
        }while(i!=nombre.length());

}
void decodificar(string &nombre,int i)
{
        do
        {
            if(i%2==0)
            {
                nombre.at(i)=(nombre.at(i)-6)-nombre.length();
            }
            else{
                nombre.at(i)=(nombre.at(i)-3)+nombre.length();
            }
            i++;
        }while(i!=nombre.length());

}
void archivoC(string nombre)
{
    ofstream archivo;
    archivo.open("codificar.txt",ios::out);
    if(archivo.fail())
    {
        cout<<"No se pudo Abrir"<<endl;
        exit(1);
    }
    else{
                archivo<<nombre;
    }
    archivo.close();
}
void archivoD(string nombre)
{
    ofstream archivo;
    archivo.open("decodificar.txt",ios::out);
    if(archivo.fail())
    {
        cout<<"No se pudo Abrir"<<endl;
        exit(1);
    }
    else{
                archivo<<nombre;
    }
    archivo.close();
}

