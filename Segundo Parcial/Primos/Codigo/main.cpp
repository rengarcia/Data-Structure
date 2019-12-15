/**
	Universidad de las Fuerzas Armadas ESPE
	Estructura de Datos
	NRC: 2967
	Docente: Ing. Fernando Solis
*/

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <pthread.h>
#include <conio.h>
#include "NumeroPrimo.h"
#include "Lista.h"

using namespace std;

//Funciones Hilos
void *primoInfinito(void *dato);
void *pararPrimos(void *dato);

bool bandera = true;
Lista *listaNumerosPrimo= new Lista();

int main()
{
	cout<<"Numeros Primos"<<endl;
	pthread_t proceso1;
	pthread_t proceso2;
	pthread_create(&proceso1,NULL,&primoInfinito,NULL);
	pthread_create(&proceso2,NULL,&pararPrimos,NULL);
	pthread_join(proceso1,NULL);
	pthread_join(proceso2,NULL);

    cout<<"Imprecion lista:"<<endl;
	listaNumerosPrimo->Imprimir();
	return 0;
}

void *primoInfinito(void *dato){
    NumeroPrimo validarPrimo;
	int numero=2;
	fstream enter;

	enter.open("SolucionPrimos.txt",fstream::out); //para leer in, para salir es out escribir
	enter<<"\t\tUniversidad de las Fuerzas Armadas ESPE\nEstructura de datos\nNRC: 2967\nDocente: Ing. Fernando Solis\n\nSolucion Numeros Primo"<<endl;
	while (bandera) {
		if(validarPrimo.primo(numero,2)){
			cout << numero<<endl;
			enter<<numero<<endl;
			listaNumerosPrimo->InsertarFinal(numero);
		}
		numero++;
		_sleep(40);
	}
	enter.close();
}
void *pararPrimos(void *dato){
	char salida;
	salida = getch();
	if(salida=13){
		bandera = false;
	}
}
