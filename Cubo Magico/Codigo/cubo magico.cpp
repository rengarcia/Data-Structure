/**
  * Universidad De las Fuerzas Armadas ESPE
  * Carrera: Ingeniería de Software
  * Materia: Estructura de Datos
  * Tema: Cubo Magico
  * NRC: 2969
*/
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <sstream>
#include "CuboMagico.h"
#include "Ingreso.h"

using namespace std;

int main()
{
	
    int **cuadrado;
    Ingreso ingreso;
    int num;
    string dim;
    do{
    	dim=ingreso.leer("Digite el tamanio del arreglo, solo numeros impares: ",2);
    	istringstream (dim) >> num;
    }while(num%2==0||num<0);
    num=2*num-1;

    cuadrado=(int**)calloc(num,sizeof(int*));
    for(int i=0;i<num;i++){
        *(cuadrado+i)=(int*)calloc(num,sizeof(int));
    }

    CuboMagico cubo=CuboMagico(cuadrado);
    cubo.llenar(num,num);
    cubo.mostrar(num,num);
    
    system("pause");
    return 0;
}
