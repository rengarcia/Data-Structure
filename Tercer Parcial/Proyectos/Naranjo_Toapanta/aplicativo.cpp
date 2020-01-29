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
#include <iostream>
#include "PersonalLibrary.h"
#include "ingreso.h"
#include <pthread.h>

using namespace std;


void* moverMarquesina(void *marq){

	int a, b, c, n=0,letra=150,pos=1,cont=39,aux,cont1=39,auxg;
	char t[50] ="GRACIAS POR USAR NUESTRO PROGRAMA",auxt[39]=" ";

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


int main()
{
	AltEnter();
    const char *opciones[]={"1) Traductor Palabras","2) Sello ESPE","3) Mostrar Ayuda","4) Codificar","5) Decodificar","6) Generar PDF","7) Codigo de Barras","8) Salir"};
    bool bandera = true;
    string nombre,datos = "Naranjo Jhony 1750184010\nToapanta Antoni 1720273794";
    pthread_t thread1;
    Ingreso leer;
    do{
        int opcion = menu("Bienvenido",opciones,8);
            switch(opcion){
                case 1:
                	system("cls");
                	system("Proyecto20.exe");
                	system("pause");
                    break;
                case 2:
                    system("cls");
                    system("imagenExtras.exe");
                    system("pause");
                    break;
                case 3:
                    system("Traductor.chm");
                    break;
                case 4:
                    system("cls");
                    codificar(datos,0);
                    archivoC(datos);
                    system("codificar.txt");
                    system("pause");
					break;
                case 5:
                    system("cls");
                    decodificar(datos,0);
                    archivoD(datos);
                    system("decodificar.txt");
                    system("pause");
                	break;
                case 6:
                    system("cls");
                    system("Autores.pdf");
                    system("pause");
                    break;
                case 7:
                    system("cls");
                    system("barras.png");
                    system("pause");
                    break;
                case 8:
                    system("cls");
                    pthread_create(&thread1,NULL,moverMarquesina,NULL);
                    system("pause");
                    bandera = false;
                    break;
            }
    }while(bandera);
    return 0;
}

