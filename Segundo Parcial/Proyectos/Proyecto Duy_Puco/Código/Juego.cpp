/***********************************************************************
 * Module:  Juego.cpp
 * Author:  Kevin Duy, Carlos Puco
 * Modified: sabado, 26 de noviembre de 2019 17:21:23
 * Purpose: Implementation of the class Juego.cpp
 ***********************************************************************/

#include "Tetris.cpp"
#include <conio.h>

/* @brief Función controladora que crea los hilos de la funcion1 y la funcion2 */

int main() {
	pthread_t pthread1, pthread2, pthread3;
	archivo.open("solucion.txt",ios::out);
    if (pthread_create(&pthread1, NULL, funcion1, NULL) ) {
    	cout << ("Error creando el hilo.");
        abort();
    }
    if (pthread_create(&pthread2, NULL, funcion2, NULL) ) {
        printf("Error creando el hilo.");
        abort();
    }
    if (pthread_create(&pthread3, NULL, funcion3, NULL) ) {
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
    if (pthread_join(pthread3, NULL)) {
        cout << ("Error creando el hilo.");
        abort();
    }
	return 0;
}
