/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 2967                                                       *
******************************************************************/
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
using namespace std;

class CuboMagico{
private:
  int **cuadrado;
public:
    CuboMagico(int **);
    void llenar(int,int);
    void mostrar(int, int);
    int **getCuboMagicoCuadrado();
    void setCuboMagicoCuadrado(int **);

};

CuboMagico::CuboMagico(int **_cuadrado){
    cuadrado=_cuadrado;
}

int **CuboMagico::getCuboMagicoCuadrado(){
    return cuadrado;
}

void CuboMagico::setCuboMagicoCuadrado(int **_cuadrado){
    cuadrado=_cuadrado;
}


void CuboMagico::llenar(int a,int b){
    int x=0,k=0,p=1,j=0,t=0,s=0,d=0;
        x=(b-1)/2;
        t=((a+1)/2);
        s=(a-x-1)/2;
        d=x;

         for(int g=0; g<((a+1)/2);g++){
            j=g;
            k=g;
        for( int i=x;i>=j;i--){
            *(*(cuadrado+i)+k)=p;
             if( k<(d-s) ){
                *(*(cuadrado+i)+(k+t))=p;
			}
            if(k>(d+s)){
                *(*(cuadrado+i)+(k-t))=p;
            }
            if(i>(d+s)){
                *(*(cuadrado+(i-t))+k)=p;
            }
            if(i<(d-s)){
                *(*(cuadrado+(i+t))+k)=p;
            }

            k++;
            p++;
        }
        x++;
    }
}

void CuboMagico::mostrar(int a,int b){
   system("cls");
    int x=0,t=0,s=0;
        t=((a+1)/2);
        x=(b-1)/2;
        s=(a-x-1)/2;

        for(int l=0;l<a;l++){
                cout<<"\n\t";
            for(int h=0;h<b;h++){
                if(h>=(x-s) && h<=(x+s) && l<=(x+s) && l>=(x-s)){
                    cout<<"\t"<<*(*(cuadrado+l)+h);
                }
        	}
		}
}

