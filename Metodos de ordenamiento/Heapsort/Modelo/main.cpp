/** 

        UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
	
CARRERA: INGENIERIA DE SOFTWARE
MATERIA: ESTRUCTURA DE DATOS
TEMA: METODOS DE ORDENAMIENTO: ORDENAMIENTO HEAR SORT
NRC: 2967

 */

#include <iostream>
#include <sstream>
#include "Ingreso.h"
#include "Validacion.h"
#include "heapsort.h"

using namespace std;

int main(int argc, char** argv) {
	Ingreso ingreso;
	Validacion validacion;
	string numero;
	int val;
	
	int tam;
	int *matr;
	Ordenar ordenar;
	
	do{
		numero=ingreso.ingresar("Ingrese el tamano de la matriz: ");
		val=validacion.validar(numero);
	}while(val==1);
	istringstream ( numero ) >> tam;
	
	matr= (int*)malloc(tam*sizeof(int));
	ordenar.setMatriz(matr);
	cout<<"Arreglo Desordenado"<<endl;
	cout<<endl;
	ordenar.llenar(ordenar,tam);
	cout<<endl;
	ordenar.heapSort(ordenar, tam);
	cout << "Arreglo Ordenado \n";
	cout<<endl;
	ordenar.imprimir(ordenar, tam);
	cout<<endl;
	
	system("PAUSE");
	return 0;
}
