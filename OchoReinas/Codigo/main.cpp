/** 

        UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
	
CARRERA: INGENIERIA DE SOFTWARE
MATERIA: ESTRUCTURA DE DATOS
TEMA: METODOS DE ORDENAMIENTO: ORDENAMIENTO SHELL SORT
NRC: 2967

 */
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

