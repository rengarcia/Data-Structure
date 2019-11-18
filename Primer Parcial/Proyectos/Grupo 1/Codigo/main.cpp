/**
	Universidad de las Fuerzas Armadas ESPE
    Alex Chicaiza, Maria Belen Ceron
    NRC: 2967
    Fecha creacion: 26/10/2019
	Fecha ultima modificacion:	7/11/2019
	Docente: Ing. Solis
*/

#include <stdio.h>
#include <windows.h>
#include <iostream>
#include "PermutacionLetra.h"
#include "Ingresar.h"
#include "Arreglo.h"

using namespace std;

void* moverMarquesina(void *marquesina);
void gotoxy(short posicionx, short posiciony);

int main(){
    pthread_t hilo1;
    pthread_t hilo2;
    pthread_create(&hilo1,NULL,moverMarquesina,NULL);
    main;
    cout<<"\n\n\n\n\n\n\n";

    DWORD modoConsola;
    INPUT_RECORD evento;
    BOOL SALIR = FALSE;

    Ingreso lectura;
    Arreglo arr;
    PermutacionLetra ejecutar;

    /**
    *Esta funcion sirve para capturar los numeros del teclado
    * */
    HANDLE hstdin = GetStdHandle( STD_INPUT_HANDLE );

    /**
    *Sirve para mantener el diseño de la consola
    **/
    GetConsoleMode( hstdin, &modoConsola );

    /**
    *Con esta funcion identifica las teclas especiales como f1
    */
    SetConsoleMode( hstdin, 0 );

    cout<<"\t\tUNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE\n* Alex Chicaiza\n* Maria Belen Ceron\nNRC: 2967\nDocente: Ing. Fernando Solis"<<endl;
    //system("cls");

    cout<<"*********************************************************"<<endl;
    cout<<"*\tANTES DE USAR LEA LA AYUDA PRESIONANDO f1\t*"<<endl;
    cout<<"*********************************************************"<<endl;
    cout<<"\t\tMENU DE  OPCIONES"<<endl;
    cout<<"\n1.Generar PDF de permutacion\n2.Comenzar permutaciones"<<endl;

    while (!SALIR){
        if (WaitForSingleObject( hstdin, 0 ) == WAIT_OBJECT_0){  /* if kbhit */
            DWORD count;

            /**
            *Captura los eventos al presionar una tecla
            */
            ReadConsoleInput( hstdin, &evento, 1, &count );
        }
        if ((evento.EventType == KEY_EVENT)  &&  !evento.Event.KeyEvent.bKeyDown){
            switch (evento.Event.KeyEvent.wVirtualKeyCode){

                case VK_ESCAPE:
                    SALIR = TRUE;
                    break;

                case VK_F1:
                    system("Ayuda.hnd");
                    break;
                case VK_NUMPAD1:
                    system("txt2pdf.exe solucion.txt respuestas.pdf -oao -pfs60 -pps43 -ptc0 -width3000 -height2000");
                    break;
                case VK_NUMPAD2:
                    pthread_create(&hilo1,NULL,NULL,NULL);
                    system("cls");
                    char* items=lectura.ingresarLetras("Ingrese las letras a permutar: ");
                    int n,r;
                    n=arr.tamanioCadena(items);
                    system("cls");
                    r=lectura.ingresarEnteros("Grupo de permutacion: ");
                    system("cls");
                    cout<<"\n Lista de elementos:\n ";
                    for(int x=0; x<n; x++){
                        cout<<items[x]<<",";
                    }
                    cout<<"\n\n Numero de permutaciones con repeticion: "<<pow(n,r);
                    cout<<"\n\n Lista de permutaciones con repeticion:\n ";

                    ejecutar.permutacion("",items,n,r);
                    Sleep(7000);
                    system("cls");
                    return main();
                    break;
            }
            evento.Event.KeyEvent.wVirtualKeyCode=-1;
        }
    }

    return 0;
}
void gotoxy(short posicionx, short posiciony) {
    COORD coordenadaPosicion = {posicionx, posiciony};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordenadaPosicion);
}
void* moverMarquesina(void *marquesina){

	int a, b, c, n=0,letra=39,pos=1,cont=39,aux,cont1=39,auxg;
	char t[50] ="BIENVENIDO AL PROGRAMA DE PERMUTACIONES\n",auxt[39]=" ";

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
