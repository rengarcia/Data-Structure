/***********************************************************************
 * Module:  Raiz.cpp
 * Author:  Edison Baez
 * Modified: sábado, 9 de noviembre de 2019 12:15:09
 * Purpose: Implementation of the class Raiz
 ***********************************************************************/
#include<iostream>
#include<math.h>
#include "Raiz.h"

using namespace std;

////////////////////////////////////////////////////////////////////////
// Name:       Raiz::calcular()
// Purpose:    Implementation of Raiz::calcular()
// Return:     float
////////////////////////////////////////////////////////////////////////

void Raiz::calcular(float a, float b, float c)
{
	Raiz raiz;
	
   float raizValidacion;
			
			raizValidacion=b*b-4*a*c;
			if(raizValidacion<0){
				cout<<"No existe solucion"<<endl;
			}else{
				
				raiz.setResult1((-b+sqrt(raizValidacion))/(2*a));
				raiz.setResult2((-b-sqrt(raizValidacion))/(2*a));
				cout<<"La primera solucion es: x1="<<raiz.getResult1()<<endl;
				cout<<"La segunda solucion es: x2="<<raiz.getResult2()<<endl;
				
			}
}

////////////////////////////////////////////////////////////////////////
// Name:       Raiz::getResult1()
// Purpose:    Implementation of Raiz::getResult1()
// Return:     float
////////////////////////////////////////////////////////////////////////

float Raiz::getResult1(void)
{
   return result1;
}

////////////////////////////////////////////////////////////////////////
// Name:       Raiz::setResult1(float newResult1)
// Purpose:    Implementation of Raiz::setResult1()
// Parameters:
// - newResult1
// Return:     void
////////////////////////////////////////////////////////////////////////

void Raiz::setResult1(float newResult1)
{
   result1 = newResult1;
}

////////////////////////////////////////////////////////////////////////
// Name:       Raiz::getResult2()
// Purpose:    Implementation of Raiz::getResult2()
// Return:     float
////////////////////////////////////////////////////////////////////////

float Raiz::getResult2(void)
{
   return result2;
}

////////////////////////////////////////////////////////////////////////
// Name:       Raiz::setResult2(float newResult2)
// Purpose:    Implementation of Raiz::setResult2()
// Parameters:
// - newResult2
// Return:     void
////////////////////////////////////////////////////////////////////////

void Raiz::setResult2(float newResult2)
{
   result2 = newResult2;
}

////////////////////////////////////////////////////////////////////////
// Name:       Raiz::Raiz()
// Purpose:    Implementation of Raiz::Raiz()
// Return:     
////////////////////////////////////////////////////////////////////////

Raiz::Raiz()
{
}
