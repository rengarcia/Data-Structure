/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 2967                                                       *
******************************************************************/
#include <iostream>
#include <fstream>  
#include "Reina.h"
#include "Ingreso.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

int main(int argc, char** argv) {
	int n;
	cout<<"\tCuantas reinas: "<<endl;
	cin>>n;
	Reina *obj= new Reina(n);
	obj->solucionReinas();
	cout<<"Se creo el archivo solucion.txt"<<endl;

	return 0;
}

