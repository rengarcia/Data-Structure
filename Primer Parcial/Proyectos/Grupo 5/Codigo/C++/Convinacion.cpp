/***********************************************************************
 * Module:  Convinacion.cpp
 * Author:  Luis Carvajal, Elian Llorente
 * Modified: miércoles, 6 de noviembre de 2019 1:04:26
 * Purpose: Implementation of the class Convinacion
 ***********************************************************************/

#include "Convinacion.h"
#include<fstream>
#include<iostream>
using namespace std;
int n=0,ev,count;
ofstream g("out.txt");

////////////////////////////////////////////////////////////////////////
// Name:       Convinacion::backtraking(int* str, int k)
// Purpose:    Implementation of Convinacion::backtraking()
// Parameters:
// - str
// - k
// Return:     void
////////////////////////////////////////////////////////////////////////
/**
 * @brief Funcion recursiva que muestra las combinaciones posibles
 * @param st arreglo tipo puntero de los numeros a combinar
 * @param k contador
 * @return La lista de los numeros que se van a combinar
 */
void Convinacion::backtraking(int* st, int k)
{
   if(k==n+1){
   	for(int i = 1; i < k; i++)
   		g << *(st+i) << " ";
		count++;
		g<< " Solucion: "<<count<<endl;
	}else{
		for(int i = 1; i <= n; i++)
		{
			*(st+k) = i;
			ev=1;
				if(*(st+j) == *(st+k))
					ev=0;
			if(ev)
				backtraking(st, k+1);
		}
	}
}

////////////////////////////////////////////////////////////////////////
// Name:       Convinacion::archivo()
// Purpose:    Implementation of Convinacion::archivo()
// Return:     void
////////////////////////////////////////////////////////////////////////

/**
 * @brief Genera un archivo txt, lee y escribe
 */
void Convinacion::archivo(){
	FILE *file1 , *file2, *file3;
    int data1 =0;
    int data2 =0;

    file1 = fopen ( "out.txt", "r" );
    file2 = fopen ( "out2.txt" , "w" );

    while ( (data1 = fgetc ( file1 )) != EOF ) {
        fputc ( data1, file2 );
    }

    fclose ( file1 );
    fclose ( file2 );

    file2 = fopen ( "out2.txt", "r" );
    file3 = fopen ( "out2.doc" , "w" );

    while ( (data2 = fgetc ( file2 )) != EOF ) {
        fputc ( data2, file3 );
    }

    fclose ( file3 );
    fclose ( file2 );

}

////////////////////////////////////////////////////////////////////////
// Name:       Convinacion::mostrar(int* str, int k)
// Purpose:    Implementation of Convinacion::mostrar()
// Parameters:
// - str
// - k
// Return:     void
////////////////////////////////////////////////////////////////////////

/**
 * @brief Muestra los numeros a combinar
 * @param st arreglo tipo puntero de los numeros a combinar
 * @param k contador
 * @return La lista de los numeros que se van a combinar
 */

void Convinacion::mostrar(int* st, int k)
{
	cout<<"\n\n\n\n\n\n\nNUMEROS QUE SE VAN A COMBINAR: "<<endl;
   	for(int i = 1; i <= n; i++)
		{
			*(st+k) = i;
			cout<<*(st+k)<<" ";
		}
	cout<<endl;
}
