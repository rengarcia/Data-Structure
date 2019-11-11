/***********************************************************************
 * Module:  Principal (Main)
 * Author:  Jonathan Picado
 * Author:  Cesar Naula
 * Modified: miércoles, 5 de noviembre de 2019 20:09:41 p. m.
 * Purpose: Declaration of Main Function
 ***********************************************************************/
#include "Funciones.h"

using namespace std;

int main() {
	
	pthread_t hilo1,hilo2;
	pthread_create(&hilo1,NULL,&pedir_palabra,NULL);
	pthread_create(&hilo2,NULL,&moverMarquesina,NULL);
	pthread_join(hilo2,NULL);
	pthread_join(hilo1,NULL);
    
    
    return 0;
}


