/*---------------------------------------------
*  Universidad de las Fuerzas Armadas Espe     *
* Nombres: Angel Cárdenas, Edison Baéz         *
* NRC: 2967                                    *
* Fecha: 07/11/2019                            *
*                                              *
*----------------------------------------------*/

#include<iostream>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include"Ingreso.h"
#include"Ayuda.h"
#define MAX 1000

using namespace std;

bool mt[MAX][MAX];
int V,E;

bool freeColor(int v, int color[], int c){
	for (int i=0;i<V;i++){
		if(mt[v][i] && c== color[i]){
			return false;
		}
	}
	return true;
}
bool btColoring(int m, int color[],int v){
	if(v==V) {
		return true;	
	}
	for(int i=1; i<=m; i++){
		if(freeColor(v,color, i)){
			color[v]=i;
			if(btColoring(m, color, v+1)){
				
				return true;
			}		
			color [v] =0;
		}
	}
	return false;
}

void solve(int color[]){
	for(int i=0;i<V;i++){
		cout<<color[i]<<" ";
	}
	cout<<"\n";
}

bool isColored(int C){
	int color[V];
	for(int i=0;i<V;i++){
		color[i]=0;
	}
	if(!btColoring(C,color,0)){
		return false;
	}
	solve(color);
	return true;
}

int main(){
	int C;
	int a,b;
	Ingreso ingresar;
	Ayuda ayudar;
	string numV;
	
	cout<<">Ingrese los vertices y las aristas del grafo a colorear"<<endl;
	numV=ingresar.leer("Vertices del grafo: ",1);
	istringstream(numV)>>V; //vertices 
	
	numV=ingresar.leer("Aristas del grafo: ",1);
	istringstream(numV)>>E;//aristas
	
	cout<<">Ingrese las coordenadas de cada nodo: "<<endl;
	while(E--){
		numV=ingresar.leer("Coordenada1: ",1);
		istringstream(numV)>>a; 
		
		numV=ingresar.leer("Coordenada2: ",1);
		istringstream(numV)>>b; 
	
		mt[a][b]=true;
		mt[b][a]=true;//grafico no dirigido (adyacencia)
	}
	numV=ingresar.leer("++INGRESE LOS COLORES QUE DESEA PARA LA SOLUCION++",1);
	istringstream(numV)>>C;


	if(isColored(C)){
		cout<<"Esa es la solucion con "<<C<<" colores"<<endl;
	}else
	{
		
		cout<<"No hay solucion con "<<C<<" color/es"<<endl;	
	}
	
	ayudar.mostrarAyuda();
	
	return 0;
	
}
