/********************************************
 UNIVERSIDAD DE LAS FUERZAAS ARMADAS ESPE
*********************************************
    ESTRUCTURA DE DATOS PROYECTO PRIMER PARCIAL
                 INTEGRANTES:
                - DANIEL AVILA
                - DIEGO ZURITA
FECHA: 
*********************************************/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


class TorresHanoi{
	
	public:
		
		FILE *archivo;
		
		TorresHanoi(){
			
		}
		
		void imprime( int *tab, int fil, int col, int ultNum ){
			int f, c;
			int i, esp;
			archivo=fopen("Solucion.txt","a");

			for( c=col-1; c >= 0; c-- )
			{
				for( f=0; f < fil; f++ )
				{
					int aux1;
					aux1=col*f+c;
					esp = ( ultNum - *(tab +aux1))/2;

					// Espacios a la izquierda
					for( i=0; i < esp; i++ ){
						printf( " " );
						fprintf( archivo," " );
					}

					// Imprime los comodines
					int aux2;
					aux2=col*f+c;
					for( i=0; i < *(tab +aux2); i++ ){
						printf( "*" );
						fprintf(archivo, "*" );
						
					}
					// Espacios a la derecha
					for( i=0; i < esp; i++ ){
						printf( " " );
						fprintf( archivo," " );
					}
					printf("\t");
					fprintf( archivo,"\t" );
					
					};
				printf( "\n\n" );
				fprintf( archivo,"\n\n" );
				
			}
	fclose(archivo);


}

		void mueveDisco( int *tab, int fil, int col, int ultNum, int filOrig, int filDest ){
			
			int cO=col-1, cD=col-1;
		
		
			// Se busca el disco que se encuentre mas arriba y por lo tanto el mas pequeño de la fila de origen.
			while( cO >= 0  &&  *(tab +col*filOrig+cO) == 0 )		{
					cO--;
				};
				
				if( cO < 0 )
					cO = 0;
			
				// Ahora se calcula cual es la posición libre mas arriba de la fila de destino
				while( cD >= 0  &&  *(tab +col*filDest+cD )== 0 ){
					cD--;
				};
			
				// Se mueve el disco de la fila de origen a la de destino:
				*(tab +col*filDest+cD+1) = *(tab +col*filOrig+cO);
				*(tab +col*filOrig+cO )= 0;
			
				// Se imprime el tablero:
				imprime( tab, fil, col, ultNum );
				
			}
		

		void hanoi( int *tab, int col, int fil, int disc, int ultNum, int O, int A, int D ){
			
			if( disc==1 )
			{
				//se imprime la tabla
				printf("\n\nPasos \n\n");
				mueveDisco( tab, col, fil, ultNum, O, D );
				if(fil<=5) ; else if(fil<=10); else if(fil<=15); else if(fil>15);
			}
			else
			{
				hanoi( tab, col, fil, disc-1, ultNum, O, D, A );
		
				printf("\n\nPasos \n\n");
				mueveDisco( tab, col, fil, ultNum, O, D );
				if(fil<=5); else if(fil<=10); else if(fil<=15); else if(fil>15);
		
				hanoi( tab, col, fil, disc-1, ultNum, A, O, D );
			};
		}
};
