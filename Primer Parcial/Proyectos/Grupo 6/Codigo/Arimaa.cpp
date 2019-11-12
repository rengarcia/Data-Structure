/***********************************************************************
 * Module:  Arimaa.cpp
 * Author:  Kevin Duy, Carlos Puco
 * Modified: sabado, 26 de octubre de 2019 17:21:23
 * Purpose: Implementation of the class Arimaa
 ***********************************************************************/
 
#include <stdlib.h>
#include "Arimaa.h"
#include "VectorMatriz.cpp"
#include "Marquesina.cpp"

/**
 * @brief Una función de utilidad para verificar si el tamaño es un índice válido para el tablero de Arimaa N*N 
 * @param int y **matriz bidimencional 
 * @return un valor de verdad o falso de la posicion
 */

bool Arimaa::verificar(int x, int y, int tamanio, int **matriz) {
	return (x >= 0 && x < tamanio && y >= 0 && y < tamanio && *(*(matriz+x)+y) == -1);
}

/**	
 * @brief Esta función resuelve el problema de Arimaa usando Backtraking, esta función utiliza principalmente la funcion solucion()
 * @param int *matriz **matriz
 * @return las posiciones del Arima en el tablero de ajedrez
 */
	
int Arimaa::resolver(int x, int y, int numero, int tamanio, int *moverX, int *moverY, int **matriz) {
	int siguienteX, siguienteY;
	if(numero == tamanio*tamanio) {
		return true;
	}
	for(int i=0; i<tamanio; i++) {
		siguienteX = x + *(moverX+i);
		siguienteY = y + *(moverY+i);
		if(verificar(siguienteX, siguienteY, tamanio,matriz)) {
			*(*(matriz+siguienteX)+siguienteY) = numero;
			if(numero == 36 || numero == 27 || numero == 45 || numero == 20) {
				*(*(matriz+siguienteX)+siguienteY) = 0;
			}
			if(resolver(siguienteX, siguienteY, numero+1, tamanio,moverX, moverY, matriz) == true) {
				return true;
			}else {
				*(*(matriz+siguienteX)+siguienteY) = -1;
			}
		}
		if(contador <= 10) {
			imprimir(tamanio,matriz);
		}
	}
	contador++;
	return false;
}


/** 	
 * @brief Una función de utilidad para generar el archivo de la matriz del proceso de obtención de la solución N*N 
 * @param int **matriz
 * @return las posisciones en un archivo
 */
	
void Arimaa::imprimir(int tamanio,int **matriz) {
	for(int i=0; i<tamanio; i++) {
		for(int j=0; j<tamanio; j++) {
			archivo << *(*(matriz+i)+j) << "     ";
		}
		archivo << endl;
	}
	archivo << endl;
}


/**
 * @brief Una función de utilidad que es recursiva para resolver el problema del caballo dorado de Arimaa 
 * @param int *matriz **matriz
 * @return las posiciones del Arima en el tablero de ajedrez
 */

bool Arimaa::solucion() {
	int tamanio;
	int **matriz;
	VectorMatriz generar;
	Marquesina iniciar;
	tamanio = iniciar.ingresarNumero();
	matriz = generar.inicializar(tamanio);
	matriz = generar.encerar(tamanio,matriz);
	archivo.open("solucion.txt",ios::out);
	for(int i=0; i<tamanio; i++) {
		for(int j=0; j<tamanio; j++) {
			*(*(matriz+i)+j) = -1;
		}
	}
	moverX = generar.inicializarVector(tamanio);
	moverX = generar.encerarVector(tamanio,moverX);
	moverY = generar.inicializarVector(tamanio);
	moverY = generar.encerarVector(tamanio,moverY);
	*(moverX+0) = 2;
	*(moverX+1) = 1;
	*(moverX+2) = -1;
	*(moverX+3) = -2;
	*(moverX+4) = -2;
	*(moverX+5) = -1;
	*(moverX+6) = 1;
	*(moverX+7) = 2;
	*(moverY+0) = 1;
	*(moverY+1) = 2;
	*(moverY+2) = 2;
	*(moverY+3) = 1;
	*(moverY+4) = -1;
	*(moverY+5) = -2;
	*(moverY+6) = -2;
	*(moverY+7) = -1;
	*(*(matriz+0)+0) = 0;
	if(resolver(0,0,1,tamanio,moverX,moverY,matriz) == false) {
		cout << "La solucion no existe";
		return false;
	}else {
		imprimir(tamanio,matriz);
		int esperar;
		cout << endl << endl << endl << "Se creo el archivo";
		muestraPDF();
	}
	archivo.close();
	return true;
}

/* @brief Funcion que muestra el menu principal para que el usuario escoga la opcion que desee */

void Arimaa::menu() {
	bool bandera=false;
    char tecla;
    do {
        cout << endl << endl <<"1. Generar archivo" << endl;
        cout << "2. Abrir QR" << endl;
        cout << "3. Abrir codigo de barras" << endl;
        cout << "4. Abrir ayuda" << endl;
        cout << "5. Salir" << endl;
        cout << "Elije una opcion: ";
        cin >> tecla;
		switch(tecla) {
			case '1': {
				system("cls");
				Arimaa arimaa;
				arimaa.solucion();
				system("pause");
				system("cls");
				break;
			}
			case '2':
				system("cls");
				system("QR.png");
				break;
 
			case '3':
				system("cls");
				system("barra.jpeg");
				break;
 
			case '4':
				system("cls");
				system("Arimaa.chm");
				break;
				
			case '5':
				exit(0);
 				break;
 				
			default:
				system("cls");
				cout << endl << endl << endl << endl << "Opcion no valida.\a\n";
				break;
		}
    }while(bandera!=true);
}

/* 	@brief Funcion que sirve para realizar el primer hilo que contiene el menu principal 
	@param void*: necesario para crear hilos */

void* funcion1(void *arg) {
	Arimaa arimaa;
    pthread_mutex_lock(&ptmutex1); 
    Sleep(50);   
    arimaa.menu(); 	
    pthread_mutex_unlock(&ptmutex1); 
    return NULL;
}

/* 	@brief Funcion que sirve para realizar el segundo hilo que contiene la marquesina 
	@param void*: necesario para crear hilos */

void* funcion2(void *arg) {
	Marquesina marquesina;
    pthread_mutex_lock(&ptmutex1);
    marquesina.hacerMarquesina();
    Sleep(5000);
    pthread_mutex_unlock(&ptmutex1);
    return NULL;
}

/* @brief Función controladora que crea los hilos de la funcion1 y la funcion2 */

void principal() {
	pthread_t pthread1, pthread2;
    if (pthread_create(&pthread1, NULL, funcion1, NULL) ) {
    	cout << ("Error creando el hilo.");
        abort();
    }
    if (pthread_create(&pthread2, NULL, funcion2, NULL) ) {
        printf("Error creando el hilo.");
        abort();
    }
    if (pthread_join(pthread1, NULL)) {
        cout << ("Error creando el hilo.");
        abort();
    }
    if (pthread_join(pthread2, NULL)) {
        cout << ("Error creando el hilo.");
        abort();
    }
}

