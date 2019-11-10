/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* CARRERA: Ingenieria de Software                                *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 2967                                                       *
******************************************************************/
#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

class QR {
	private:
		char **matriz;
		int caracter;
	public:
		char** inicializar(int);
		char** encerar(int,char**);
		void generarQR(int,char**);
};

char** QR::inicializar(int tamanio) {
	matriz = (char**)malloc(sizeof(char *)*tamanio);
	for(int i=0; i<tamanio; i++) {
		*(matriz+i) = (char*)malloc(sizeof(char*)*tamanio);
	}
	return matriz;
}

char** QR::encerar(int tamanio,char **matriz) {
	for(int i=0; i<tamanio; i++) {
			for(int j=0; j<tamanio; j++) {
				*(*(matriz+i)+j) = 0;
			}
		}
	return matriz;
}

void QR::generarQR(int tamanio, char **matriz) {
	matriz = inicializar(tamanio);
	matriz = encerar(tamanio,matriz);
	cout << ' ';
    for(int i=0; i<tamanio*2; i++) {
    	cout << '-';
	} 
    cout << endl;
    srand(time(NULL));
    for(int i=0; i<tamanio; i++) {
        cout << '|';
        for(int j=0; j<tamanio ; j++) {
            caracter = rand()%(2);
            *(*(matriz+i)+j) = caracter;
            if(*(*(matriz+i)+j)==0){
                cout << ' ';
            }else {
                cout << '*';
            }
            cout << ' '; 
        }
        cout << '|' << endl;
    }
    cout << ' ';
    for(int i=0; i<tamanio*2; i++) {
    	cout << '-';
	} 
    cout << endl;
}


