/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 2967                                                       *
******************************************************************/
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Ordenar{

	private:
		int *matriz;
	public:
		Ordenar();
		void setMatriz(int *);
		int* getMatriz();
		void inicializarMatriz(Ordenar,int);
		void heapify(Ordenar,int , int );
   	 	void heapSort(Ordenar  , int );
    	void imprimir(Ordenar  , int );
    	void llenar(Ordenar ,int );



};
Ordenar::Ordenar(){

}

 void Ordenar::setMatriz(int *v){
 	matriz = v;
}

int* Ordenar::getMatriz(){
	return matriz;
}

void Ordenar::inicializarMatriz(Ordenar v,int tam){
	v.matriz = (int*)malloc(tam*sizeof(int));
	v.setMatriz(v.matriz);
}

void Ordenar::heapify(Ordenar ord, int n, int i){
   // Encuentra más grande entre la raíz, el hijo izquierdo y el derecho
   int mayor = i;
   int izquierda = 2*i + 1;
   int derecha= 2*i + 2;

   if (izquierda< n && *(ord.matriz+izquierda)> *(ord.matriz+mayor))
     mayor = izquierda;

   if ((derecha<n)&& (*(ord.matriz+derecha)>*(ord.matriz+mayor)))
     mayor = derecha;

   // Intercambiar y continuar la heapificación si la raíz no es más grande
   if (mayor != i)
   {
     swap(*(ord.matriz+i), *(ord.matriz+mayor));
     heapify(ord, n, mayor);
   }
}


// Función principal para hacer la ordenación del montón
void Ordenar:: heapSort(Ordenar ord, int n){
   // Construir el montón máximo
   for (int i = n / 2 - 1; i >= 0; i--)
     heapify(ord, n, i);

   // tipo de pila
   for (int i=n-1; i>=0; i--)
   {
     swap(*(ord.matriz+0), *(ord.matriz+i));

     // Heapify elemento raíz para obtener el elemento más alto en la raíz de nuevo
     heapify(ord, i, 0);
   }
}

void Ordenar:: imprimir (Ordenar ord, int n)
{
   for (int i=0; i<n; ++i){

     cout << *(ord.matriz+i) << " ";
   cout << "  ";
   }
}

void Ordenar::llenar(Ordenar ord,int tam){

srand(time(NULL));
for(int i=0;i<tam;i++){

	*(ord.matriz+i)=1+rand()%(100-1);
	cout<<*(ord.matriz+i)<<"   ";
}
cout<<endl;
}
