/** 

	UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
	
CARRERA: INGENIERIA DE SOFTWARE
MATERIA: ESTRUCTURA DE DATOS
TEMA: METODOS DE BUSQUEDA: BUSQUEDA BINARIA
NRC: 2967

*/

#include <iostream>
#include "Busqueda.h"

using namespace std;
int main(int argc, char** argv) {
	Ingreso leer;
	Busqueda b;

	int dim,numero,pos;
	int* vector;
	int* vectorOrdenado;

	vector = b.inicializarVector(dim);
	vectorOrdenado = b.inicializarVector(dim);
	
	cout << "Ingrese la dimension deseada del arreglo: " << endl;
  	dim = leer.ingresarEntero();
  
  	b.ingresoDatos(dim, vector);
  	vectorOrdenado = b.ordenamientoBurbuja(dim, vector);
  	
  	cout << "Ingrese el elemento a buscar:"<<endl;
    numero = leer.ingresarEntero();
   pos= b.busquedaBinaria(numero,0,dim-1,vectorOrdenado);
   cout << "El elemento: "<<"["<<numero<<"]"<< " se encuentra en la posicion: "<<"["<<pos<<"]"<<" del arreglo"<<endl;
  	 
  	free(vector);
  	free(vectorOrdenado);
	return 0;
}
