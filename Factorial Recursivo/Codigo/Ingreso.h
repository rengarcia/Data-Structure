/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS                   *
*                        ESPE                                     *
*TRABAJO EN GRUPO:                                                *
*          NOMBRES:ANTONI TOAPANTA                                *
*MATERIA: ESTRUCTURA DE DATOS                                     *
*NRC:2967                                                         *
*Fecha de Creacion:16/10/2019                                     *
******************************************************************/
#include <iostream>
#include<stdlib.h>
#include<conio.h>
#include<stdio.h>

using namespace std;

class Ingreso {
public:
	double ingresarDouble(char*,char*);
	int ingresarInt(char*);
};
double Ingreso::ingresarDouble(char *msg,char*p) {
    char tecla;
    int i=0,cont=0;
    p[0]='\0';
    cout<<msg<<endl;
    do
    {
        tecla=getch();
        if(i> 0 && tecla == 8)
        {
            cout<<"\b \b";
            cont--;
            p[--i]='\0';
        }
        else{
            if((tecla>=48 && tecla<=57)||(tecla==46 && cont<=0) )
            {
                cout<<tecla;
                p[i++]=tecla;
                if(tecla==46)
                {
                    cont++;
                }
            }
        }
    }while(tecla!=13 || p[0]=='\0');
    p[i]='\0';
    cout<<endl;
    system("cls");
    return atof(p) ;
}
int Ingreso::ingresarInt(char *p)
{
    char tecla;
    int i=0;
    p[0]='\0';
    cout<<"Ingresa un entero para sacar su respectivo factorial"<<endl;;
    do
    {
        tecla=getch();
        if(i> 0 && tecla == 8)
        {
            cout<<"\b \b";
            p[--i]='\0';
        }
        else{
            if((tecla>=48 && tecla<=57))
            {
                cout<<tecla;
                p[i++]=tecla;
            }
        }
    }while(tecla!=13 || p[0]=='\0');
    p[i]='\0';
    cout<<endl;
    system("cls");
    return atoi(p) ;
}

