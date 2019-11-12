/***********************************************************************
 * Module:  Arimaa.h
 * Author:  Kevin Duy, Carlos Puco
 * Modified: sabado, 26 de octubre de 2019 17:21:23
 * Purpose: Declaration of the class Arimaa
 ***********************************************************************/
 
#include <fstream>
#include <pthread.h>

using namespace std;

int contador=0;
pthread_mutex_t ptmutex1;

class Arimaa {
	private:
		ofstream archivo;
		int tamanio;
		int *moverX;
		int *moverY;
	public:
		bool verificar(int,int,int,int**);
		int resolver(int,int,int,int,int*,int*,int**);
		void imprimir(int,int**);
		bool solucion();
		void* funcion1(void*);
		void* funcion2(void*);
		void principal();
		void menu();
};
