/**
	Universidad de las Fuerzas Armadas ESPE
    Nombre: Luis Carvajal, Elian Llorente
    NRC: 2967
    Fecha creacion: 30/11/2019
	Fecha ultima modificacion:	12/12/2019
	Docente: Ing. Fernando Solis
*/
#include <iostream>
#include <windows.h>
#include <conio.h>
#include "PersonalLibrary.h"
#include "ListaDoble.h"
#define ARRIBA     72
#define IZQUIERDA  75
#define DERECHA    77
#define ABAJO      80

using namespace std;

ListaDoble ObjJuego;
int i=21;
/**
 * @brief Funcion que me permite selccionar una opcion del Menu
 * @param tecla que se mueve dentro del menu
 */
void seleccionarOpcion(char tecla){

    gotoxy(30, i); cout<<" ";

    if( tecla == ABAJO && i <=24 ){
        if(i==24){
            i=20;
        }
        i++;
    }

    if( tecla == ARRIBA && i >= 21){
        if(i==21){
            i=25;
        }
        i--;
    }

    if( tecla == 13 )
    {
        if( i == 21 ){
            system("cls");
            ObjJuego.juegoTetris(); // metodo que comienza el juego
      }
        if( i == 22 ){
            system("cls");
            cout<<"CERRAR EL ARCHIVO AYUDA PARA SEGUIR EN EL MENU...."<<endl;
            system("ayuda.chm");
            //system("ayuda.pdf");
            system("pause");
            system("cls");
        }
        if( i == 23 ){
                system("cls");
                ObjJuego.impresion();
                cout<<"\n\n\n\nABRIENDO ARCHIVO CON LAS SOLUCIONES"<<endl;
                system("txt2pdf.exe tetrisPixel.txt respuestas.pdf -oao -pfs60 -pps43 -ptc0 -width3000 -height2000");
                system("pause");
                system("cls");
        }
        if( i == 24 ){
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
            }
        }
       gotoxy(30, i); cout<<">";
}

/**
 * @brief Funcion que muestra el Menu principal
 * @param tecla que se mueve dentro del menu
 */

void menuinicio(char tecla){

	gotoxy(20, 4);cout<<"\n||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||";
	cout<<"\n||||                                                                      ||||\n";
	cout<<  "||||              UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                 ||||";
	cout<<"\n||||                       ESTRUCTURA DE DATOS                            ||||";
	cout<<"\n||||          INTEGRANTES: CARVAJAL LUIS -  LLORENTE ELIAN                ||||";
	cout<<"\n||||                            NRC: 2967                                 ||||";
	cout<<"\n||||                                                                      ||||";
	cout<<"\n||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n\n\n\n\n";
	cout<<"\n||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||";
	cout<<"\n||||                                                                      ||||\n";
	cout<<  "||||                             MENU                                     ||||";
	cout<<"\n||||                                                                      ||||";
	cout<<"\n||||                                                                      ||||";
	cout<<"\n||||                                                                      ||||";
	cout<<"\n||||                                                                      ||||";
	cout<<"\n||||                                                                      ||||";
	cout<<"\n||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n\n\n";

    seleccionarOpcion(tecla);
    gotoxy(31, 21); cout<<" APLICATIVO";
    gotoxy(31, 22); cout<<" AYUDA";
    gotoxy(31, 23); cout<<" PUNTAJE";
    gotoxy(31, 24); cout<<" SALIR";
}

/**
 * @brief Funcion main
 */
int main()
{
    //PlaySound(TEXT("undertale.wav"),NULL,SND_ASYNC);
	AltEnter();
    char tecla;
    while(true){
    system("color e");
    if( kbhit() )
        tecla = getch();
    else
        tecla = ' ';

    menuinicio(tecla);

    Sleep(100);
}


system("pause>null");

return 0;
}


