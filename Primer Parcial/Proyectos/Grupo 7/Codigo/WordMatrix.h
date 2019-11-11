/**
 * @class WordMatrix
 *
 * @brief Clase encargada de controlar backtraking del proyecto
 *
 * @author Jorge Galarza - Kevin Zurita
 *
 * @version 1.0
 *
 */

#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <winbgim.h>
#include <conio.h>
using namespace std;

class WordMatrix {
	private:
		int** solution;
		int dimension;
		int path = 1;
    	int count = 1; 
    	int intentos=1;
    	FILE * pFile;
	public:
		WordMatrix(int);
		WordMatrix();
		bool searchWord(char** , string);
		bool search(char**,string,int,int,int,int);
		void print(int,int);
		void dibujarMatriz();
};

/**
* @brief Constructor
*/
	WordMatrix::WordMatrix(int N) {
		dimension=N;
		solution =(int **)malloc(N*sizeof(int *));
    	for(int j=0;j<N;j++)
        	*(solution+j)=(int *)malloc(N*sizeof(int));
        	
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
                *(*(solution+i)+j)=0;
			}
		}
		pFile = fopen ("myfile.txt","w");
		if (pFile!=NULL)
  		{
    		fprintf (pFile, "Matriz de %d x %d \n",N,N);
    		fclose (pFile);
  		}
	}

/**
* @brief Constructor vacio
*/
    WordMatrix::WordMatrix() {
 
    }

   
	/**
	* @brief Metodo encargado de buscar la palabra 
	* @param Void puntero para la creacion de hilos
	* @return Void puntero para la creacion de hilos
	*/
	bool WordMatrix::searchWord(char** matrix, string word){
		int N = dimension;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {     
				if (search(matrix, word, i, j, 0, N)) {
					print(i,j);
					dibujarMatriz();
					pFile = fopen("myfile.txt","r");
					system("txt2pdf.exe myfile.txt respuestas.pdf -oao -pfs40 -pps43 -ptc0 -width3000 -height2000");
					return true;
				}                   
			}
		}
		pFile = fopen("myfile.txt","r");
		system("txt2pdf.exe out.txt respuestas.pdf -oao -pfs60 -pps43 -ptc0 -width3000 -height2000");
		return false;
	}

	/**
* @brief Metodo de backtraking para la identificacion de la palabra digitada
* @param Matriz generada aleatoriamente
* @param Palabra digitada por el usuario
* @param entero row, que indicara la fila a buscar
* @param entero col, que indicara la columna a buscar
* @param entero index, axuliar para la busqueda
* @param entero N, dimension de la matriz
* @return Boolean
*/
	bool WordMatrix::search(char** matrix, string word, int row, int col, int index, int N){
		if (*(*(solution+row)+col)!= 0 || word.at(index) != *(*(matrix+row)+col)) {
			print(row,col);
			return false;
		}
		if (index == word.length() - 1) {
			*(*(solution+row)+col) = path++;
			return true;
		}
		*(*(solution+row)+col) = path++;

		if (row + 1 < N && search(matrix, word, row + 1, col, index + 1, N)) {
			return true;
		}
		if (row - 1 >= 0 && search(matrix, word, row - 1, col, index + 1, N)) {
			return true;
		}
		if (col + 1 < N && search(matrix, word, row, col + 1, index + 1, N)) {
			return true;
		}
		if (col - 1 >= 0 && search(matrix, word, row, col - 1, index + 1, N)) {
			return true;
		}
		if (row - 1 >= 0 && col + 1 < N && search(matrix, word, row - 1, col + 1, index + 1, N)) {
			return true;
		}
		if (row - 1 >= 0 && col - 1 >= 0 && search(matrix, word, row - 1, col - 1, index + 1, N)) {
			return true;
		}
		if (row + 1 < N && col - 1 >= 0 && search(matrix, word, row + 1, col - 1, index + 1, N)) {
			return true;
		}
		if (row + 1 < N && col + 1 < N && search(matrix, word, row + 1, col + 1, index + 1, N)) {
			return true;
		}    
		*(*(solution+row)+col) = 0;
		path=1;;
		return false;
	}

	/**
	* @brief Metodo encargado de imprimir (en un archivo .txt) los intentos necesarios para llegar a la solucion
	* @param x: indica la fila de la matriz
	* @param y: indica la columna de la matriz
	* @return Void
	*/
	void WordMatrix::print(int x, int y) {
		pFile = fopen ("myfile.txt","a");
		if (pFile!=NULL)
  		{
		//printf("Intendo N %d \n",intentos);
		fprintf (pFile,"Intento N %d \n",intentos);
		intentos++;
		for(int i=0;i<dimension;i++){
			for(int j=0;j<dimension;j++)
			{		
				if(i==x&&j==y){
					//printf("1");
					fprintf (pFile, "1");
				}
				else{	
				//printf("%d",*(*(solution+i)+j));
				fprintf (pFile,"%d",*(*(solution+i)+j));
				}
				//printf("%*s",j+5,"");
				fprintf (pFile,"%*s",j+5,"");
			}
		//printf("\n");
		fprintf (pFile,"\n");
		}
		}
		fclose (pFile);
		
	}
	
	/**
	* @brief Metodo encargado de dibujar matrices en consola grafica
	* @return Void
	*/
	void WordMatrix::dibujarMatriz(){
		initwindow(650,650);
    	
		settextstyle(8, 0, 4);
		int x=0;
		for(int i=55; i<=600;i+=60){
			int y=0;
			for(int j=55;j<=600;j+=60){
				char* output;
				output=(char *)malloc(1*sizeof(int));
				sprintf(output,"%d",*(*(solution+x)+y));
				outtextxy(j,i,output);
				free(output);
				y++;
			}
			x++;
		}
		setcolor(15);
	rectangle(25,25,625,625);
	for(int i=85;i<=625;i+=60){
		line(i,25,i,625);
		line(25,i,625,i);
	}
	system("PAUSE");
	cleardevice();
	closegraph();
	}
	
	

	
	

