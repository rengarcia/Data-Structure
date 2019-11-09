/***********************************************************************
 * Module:  FuncionesTrigonometricas.h
 * Author:  Alan
 * Modified: sábado, 09 de noviembre de 2019 13:42:38
 * Purpose: Declaration of the class FuncionesTrigonometricas
 ***********************************************************************/

#if !defined(__Funciones_Trigonometricas_FuncionesTrigonometricas_h)
#define __Funciones_Trigonometricas_FuncionesTrigonometricas_h
#include <math.h>
#include <iostream>
#include <stdio.h>
#define PI 3.14159265359
using namespace std;

class FuncionesTrigonometricas
{
public:
   int factorial(int angulo);
   float seno(float angulo);
   float coseno(float angulo);
   float tangente(float angulo);
   float radianes(float angulo);

protected:
private:

};


//Factorial de un Numero
int FuncionesTrigonometricas::factorial (int angulo) 
 {  int factor,i;
    factor=1;  
    for (i=1;i<=angulo;i++) {
	factor=factor*i; 
	}
    return (factor);  
}

// Funcion Seno para un angulo radianes                   
float FuncionesTrigonometricas::seno(float angulo) 
{

    float resultado;
    int i, posicion, precision;
    resultado= angulo; 
    precision=10; 
    for(i=1; i<=precision; i++){
        posicion = i * 2 + 1; 
        if(i%2==0) 
        	resultado += pow(angulo, posicion) / factorial(posicion);
        else 
			resultado -= pow(angulo, posicion) / factorial(posicion);
    }
    
	return resultado; 
}

//Funcion Coseno para un angulo radianes 
float FuncionesTrigonometricas::coseno(float angulo){
	float resultado;
    int i, posicion, precision;
    resultado= 1; 
    precision=15; 
    for(i=1; i<=precision; i++){
        posicion = i * 2; 
        if(i%2==0) 
        resultado += pow(angulo, posicion) / factorial(posicion);
        else 
			resultado -= pow(angulo, posicion) / factorial(posicion);
      }
	return resultado; 

}

//Funcion Tangente para un angulo radianes 
float FuncionesTrigonometricas::tangente(float angulo){
	float coseno;
	float seno;
	float resultado;
	
	coseno=FuncionesTrigonometricas::coseno(angulo);
	seno=FuncionesTrigonometricas::seno(angulo);
	resultado=seno/coseno;
	return resultado;
	
}

float FuncionesTrigonometricas::radianes(float angulo){
	
	float resultado;
	resultado = angulo*(PI/180);
	return resultado;
	
}

#endif