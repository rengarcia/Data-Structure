/***********************************************************************
 * Module:  Aplicacion.cpp
 * Author:  Carlos Puco, Kevin Duy
 * Modified: Sabado, 11 de enero de 2020 20:20:06
 * Purpose: Implementation of the class Aplicacion
 ***********************************************************************/

#include "Arbol.cpp"

int main()
{
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
    return 0;
}
