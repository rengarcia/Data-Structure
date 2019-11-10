/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 2967                                                       *
******************************************************************/
#include "Matriz.h"
#include <stdio.h>
#include <iostream>
#include <time.h>
#include <stdlib.h>



int** Matriz::getmatriz(void)
{
   return matriz;
}

void Matriz::setmatriz(int** newMatriz)
{
   matriz = newMatriz;
}

int Matriz::getfilas(void)
{
   return filas;
}

void Matriz::setfilas(int newFilas)
{
   filas = newFilas;
}

int Matriz::getexp(void)
{
   return filas;
}

void Matriz::setexp(int newExp)
{
   exp = newExp;
}

int Matriz::getcolumnas(void)
{
   return columnas;
}

void Matriz::setcolumnas(int newColumnas)
{
   columnas = newColumnas;
}

/**
 		 * @brief Constructor matriz vacio
 		 */
Matriz::Matriz()
{
}

/**
		  * @brief crear crea la matriz
		  * @return void
		*/

void Matriz::crear(void)
{
    matriz =(int **)calloc(filas,sizeof(int *)*filas);
    for(int j=0;j<columnas;j++)
        *(matriz+j)=(int *)calloc(columnas,sizeof(int*)*columnas);
}

/**
		  * @brief crear llena la matriz
		  * @return void
		*/

void Matriz::llenar(void)
{
   srand(time(NULL));
    	for(int i=0;i<filas;i++)
        	for(int j=0;j<columnas;j++){
        		*(*(matriz+i)+j)=1;//1+rand()%9;
			}
}

/**
		  * @brief imprime la matriz
		  * @return void
		*/

void Matriz::imprimir(void)
{
   for(int i=0;i<filas;i++){
			for(int j=0;j<columnas;j++)
			{
				printf("%5d",*(*(matriz+i)+j));
				
			}
		printf("\n");
		}
}

 /**
		  * @brief multiplica la matriz
		  * @param int
		  * @return void
		*/
void Matriz::multiplicar(int exponente)
{
   int** mT1;
		
        mT1 =(int **)calloc(filas,sizeof(int *)*filas);
    	for(int j=0;j<columnas;j++){
    		*(mT1+j)=(int *)calloc(columnas,sizeof(int*)*columnas);
		}
        
		  	
		for(int i=0;i<filas;i++)
        	for(int j=0;j<columnas;j++){
        		*(*(mT1+i)+j)=*(*(matriz+i)+j);
			}	
			
		for(int k=1;k<exponente;k++){
			int ** mT3;
			mT3 =(int **)calloc(filas,sizeof(int *)*filas);
    		for(int j=0;j<columnas;j++)
        		*(mT3+j)=(int *)calloc(columnas,sizeof(int*)*columnas);
        	
					for(int i=0;i<filas;i++){
				for(int j=0;j<filas;j++){
					for(int h=0;h<filas;h++){
						*(*(mT3+i)+j)=*(*(mT3+i)+j)+(*(*(mT1+i)+h))*(*(*(matriz+h)+j));
					}
				}
			}
			matriz=mT3;
		}
}


