#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>
#include "NodoTetris.h"

using namespace std;

typedef NodoTetris* pnodo;

class ListaCD{
	private:
        pnodo primero;
        pnodo ultimo;
    public:
    	ListaCD();
        void insertarPrimero(int, int);
		void insertarUltimo(int, int);
		void insertarEntre(int, int);
		int chequeoEliminar(int);
		void mostrar();
		int numeroFila();
		bool listaVacia();
		int numeroElementos();
		void unirLista();
		pnodo returnNodo(int);
		void generarArchivo();
};

ListaCD::ListaCD(){
	primero=NULL;
	ultimo=NULL;
}

bool ListaCD::listaVacia(){
	 return primero == NULL; 
}

void ListaCD::insertarPrimero(int value, int column){
   pnodo anterior;
   pnodo siguiente;
   if(listaVacia()) {                
      primero = new NodoTetris(value,1,column);
      primero->sig=primero;
      primero->ant=primero;
      ultimo=primero;
   } else {
   	if(ultimo==primero){
      anterior = primero;
      column=anterior->getColumnas()-1;
      if(column==0){
      	column=1;
      	anterior->setColumnas(2);
	  }
	  primero = new NodoTetris(value,numeroFila(),column);
      primero->sig=anterior;
      anterior->ant=primero;  
      anterior->sig=primero;
      ultimo=anterior;
	   }
	   else{
	   	anterior = primero;
	   	column=anterior->getColumnas()-1;
	   	if(column==0){
	   		column=1;
		   }
	  	primero = new NodoTetris(value,numeroFila(),column);
      	primero->sig=anterior;
      	anterior->ant=primero;  
      	ultimo->sig=primero;
      	pnodo aux=primero->sig;
      	while(aux!=primero){
      		aux->setColumnas(aux->ant->getColumnas()+1);
      		aux=aux->sig;
		  }
	   } 
	}
}

void ListaCD::insertarUltimo(int value, int column){
	pnodo temp;
   if(listaVacia()) {                
      primero = new NodoTetris(value,1,column);
      primero->sig=primero;
      primero->ant=primero;
      ultimo=primero;
   } else {
   	if(ultimo==primero){
	  temp = new NodoTetris(value,numeroFila(),primero->getColumnas()+1);
      primero->sig=temp; 
      temp->sig=primero;
      temp->ant=primero;
      ultimo=temp;
	   }
	   else{
   		temp = new NodoTetris(value,numeroFila(),ultimo->getColumnas()+1);
   		ultimo->sig=temp;
   		temp->ant=ultimo;
   		temp->sig=primero;
   		ultimo=temp;
	   }
	}
}

void ListaCD::insertarEntre(int value, int column){
	pnodo aux;
	pnodo sig;
	pnodo control;
	aux=primero;
	if(listaVacia()){
		insertarPrimero(value,column);
	}else{
	if(column<=primero->getColumnas()&&numeroFila()==primero->getFilas()){
		insertarPrimero(value,column);
	}
	else if(column>=ultimo->getColumnas()&&numeroFila()==ultimo->getFilas()){
		insertarUltimo(value,column);
	}
	else{
		if(numeroFila()!=primero->getFilas()){
			if(ultimo->getFilas()!=numeroFila()){
				pnodo temp=new NodoTetris(value,numeroFila(),column);
				ultimo->sig=temp;
				temp->ant=ultimo;
				temp->sig=primero;
				ultimo=temp;
			}else{		
				while(aux->getFilas()!=numeroFila()){
					aux=aux->sig;
				}
				control=aux;
				if(column<=aux->getColumnas()){
					int x= aux->getColumnas()-1;
					if(x<=0){
						x=1;
					}
					pnodo temp=new NodoTetris(value,numeroFila(),x);
					sig=aux->ant;
					sig->sig=temp;
					temp->ant=sig;
					temp->sig=aux;
					aux->ant=temp;
					aux=sig;
					temp=temp->sig;
					while(temp!=primero){
						temp->setColumnas(temp->ant->getColumnas()+1);
						temp=temp->sig;
					}
						if(ultimo->getColumnas()>10){
						aux->setColumnas(aux->getColumnas()-1);
						aux=aux->sig;
						while(aux!=primero){
						aux->setColumnas(aux->getColumnas()-1);
						aux=aux->sig;
					}
					}
				}else if(column>aux->getColumnas()){
					while(aux->getColumnas()+1!=column){
						aux=aux->sig;
					}
					if(aux->sig==primero){
						pnodo temp=new NodoTetris(value,numeroFila(),ultimo->getColumnas()+1);
						ultimo->sig=temp;
						temp->ant=ultimo;
						temp->sig=primero;
						ultimo=temp;
						aux=control;
						if(ultimo->getColumnas()>10){
						aux->setColumnas(aux->getColumnas()-1);
						aux=aux->sig;
						while(aux!=primero){
						aux->setColumnas(aux->getColumnas()-1);
						aux=aux->sig;
						}
						aux=control;
						if(ultimo->getColumnas()>10){
						aux->setColumnas(aux->getColumnas()-1);
						aux=aux->sig;
						while(aux!=primero){
						aux->setColumnas(aux->getColumnas()-1);
						aux=aux->sig;
						}
						}
					}
					}else{ 
						pnodo temp=new NodoTetris(value,numeroFila(),aux->getColumnas()+1);
						sig=aux->sig;
						sig->ant=temp;
						temp->sig=sig;
						temp->ant=aux;
						aux->sig=temp;
						while(temp!=primero){
							temp->setColumnas(temp->ant->getColumnas()+1);
							temp=temp->sig;
						}
						aux=control;
						if(ultimo->getColumnas()>10){
						aux->setColumnas(aux->getColumnas()-1);
						aux=aux->sig;
						while(aux!=primero){
						aux->setColumnas(aux->getColumnas()-1);
						aux=aux->sig;
							}
						}
					}
					}else{
						while(aux->getColumnas()+1!=column){
						aux=aux->sig;
						}
					pnodo temp=new NodoTetris(value,numeroFila(),column);
					sig=aux->ant;
					sig->sig=temp;
					temp->ant=sig;
					temp->sig=aux;
					aux->ant=temp;
					aux=temp->sig;
					while(aux!=primero){
						aux->setColumnas(aux->ant->getColumnas()+1);
						aux=aux->sig;
					}
					aux=control;
					if(ultimo->getColumnas()>10){
						aux->setColumnas(aux->getColumnas()-1);
						aux=aux->sig;
						while(aux!=primero){
						aux->setColumnas(aux->getColumnas()-1);
						aux=aux->sig;
					}
					}
				}				
				}
				}else{
					while(aux->getColumnas()!=column+1){
						aux=aux->sig;
					}
					pnodo temp=new NodoTetris(value,numeroFila(),aux->ant->getColumnas()+1);
					sig=aux->ant;
					sig->sig=temp;
					temp->ant=sig;
					temp->sig=aux;
					aux->ant=temp;
					aux=primero->sig;
					while(aux!=primero){
						aux->setColumnas(aux->ant->getColumnas()+1);
						aux=aux->sig;
					}
					if(ultimo->getColumnas()>10){
						aux->setColumnas(aux->getColumnas()-1);
						aux=aux->sig;
						while(aux!=primero){
						aux->setColumnas(aux->getColumnas()-1);
						aux=aux->sig;
					}
					}
				}
		}
	}
}
void ListaCD::mostrar(){
	if(listaVacia()){
	}else{
		pnodo aux;
   	aux = primero;
   	int idC=aux->getColumnas();
   	int idF=aux->getFilas();
   	do{
   		aux->imprimir();
      	aux=aux->sig;
   	}while(aux->getColumnas()!=idC||aux->getFilas()!=idF);
   	cout<<endl<<endl;
	}
}

int ListaCD::numeroElementos(){
	pnodo aux;
   	aux = primero;
   	int idC=aux->getColumnas();
   	int idF=aux->getFilas();
   	int i=0;
   	if(primero==NULL){
   		return 0;
	   }
	if(primero==ultimo){
		return 1;
	}
   	do{
   		i++;
      	aux=aux->sig;
   	}while(aux->getColumnas()!=idC||aux->getFilas()!=idF);	
   	return i;
}

int ListaCD::chequeoEliminar(int puntaje){
	if(!listaVacia()){
		unirLista();
	int p=1;
	pnodo aux=primero;
	pnodo temp;
	if(numeroElementos()>=2){
		if(numeroElementos()==2){
		if(aux->getValorTetris()==aux->sig->getValorTetris()){
			delete primero;
			delete ultimo;
			primero=NULL;
			ultimo==NULL;
		}
		}
		else{
			while(aux!=ultimo){
			temp=aux->sig;
				if(aux->getValorTetris()==temp->getValorTetris()&&aux->getFilas()==temp->getFilas()){
					if(aux==primero){
					primero=aux->sig->sig;
					ultimo->sig=primero;
					pnodo aux1=aux;
					pnodo aux2=aux->sig;
					aux=aux->sig->sig;
					delete aux1;
					delete aux2;
					}else{
					if(aux->sig==ultimo){
					ultimo=aux->ant;
					}
					aux->ant->sig=temp->sig;
					temp->sig->ant=aux->ant;
					pnodo aux1=aux;
					pnodo aux2=aux->sig;
					aux=aux->sig->sig;
					delete aux1;
					delete aux2;
					}
				unirLista();
				puntaje+=100;
				chequeoEliminar(puntaje);
				}
			aux=aux->sig;
			}
			aux=primero;
			while(aux!=ultimo){
				temp=aux->sig;
				while(temp!=ultimo){
					if(aux->getColumnas()==temp->getColumnas()&&aux->getFilas()+1==temp->getFilas()){
						if(aux->getValorTetris()==temp->getValorTetris()){
							if(aux==primero){
								if(temp==ultimo){
								pnodo aux1=primero;
								pnodo aux2=ultimo;
								primero=aux->sig;
								ultimo=temp->ant;
								ultimo->sig=primero;
								temp=ultimo->ant;
								aux=primero;
								delete aux1;
								delete aux2;
								}else{
								pnodo aux1=primero;
								pnodo aux2=temp;
								primero=aux->sig;
								ultimo->sig=primero;
								temp->ant->sig=temp->sig;
								temp->sig->ant=temp->ant;
								temp=temp->ant;
								aux=primero;
								delete aux1;
								delete aux2;
								}
							}else{
								if(temp==ultimo){
									pnodo aux1=aux;
									pnodo aux2=ultimo;
									ultimo=temp->ant;
									ultimo->sig=primero;
									aux->ant->sig=aux->sig;
									aux->sig->ant=aux->ant;
									aux=aux->ant;
									temp=ultimo->ant;
									delete aux1;
									delete aux2;
								}else{
									pnodo aux1=aux;
									pnodo aux2=temp;
									temp->ant->sig=temp->sig;
									temp->sig->ant=temp->ant;
									aux->sig->ant=aux->ant;
									aux->ant->sig=aux->sig;
									aux=aux->ant;
									temp=temp->ant;
									delete aux1;
									delete aux2;
								}
							}
						unirLista();
						puntaje+=100;
						chequeoEliminar(puntaje);
						}
					}
					temp=temp->sig;
				}
				aux=aux->sig;
			}
		}
	}	
	return puntaje;
	}
}

int ListaCD::numeroFila(){
	return (numeroElementos()/10+1);
}

/*void ListaCD::ordenarLista(){
	if(!listaVacia()){
		pnodo control=primero;
	while(control->getFilas()!=1){
		primero=control->sig;
		ultimo->sig=control;
		control->ant=ultimo;
		control->sig=primero;
		ultimo=control;
		control=primero;
	}
	int i=1, f=1, row, ordenamiento=numeroElementos();
	bool flag=true, flag2;
	int c=numeroElementos()%10;
	if(c!=0){
		row=numeroFila();
	}else{
		row=numeroElementos()/10;
	}
	while(row>0){
		pnodo aux=control;
		if(ordenamiento>=10){
		if(flag==true){
			if(aux->getColumnas()!=1){
				aux->setColumnas(1);
			}
			flag=false;
			}
		}
		while(i!=10){
			if(aux->getFilas()==f){
				if(aux->sig->getColumnas()!=aux->getColumnas()+1&&aux->sig->getFilas()==aux->getFilas()){
					aux->sig->setColumnas(aux->getColumnas()+1);
				}
				i++;
				aux=aux->sig;
			}
			else{
				aux->ant->sig=aux->sig;
				aux->sig->ant=aux->ant;
				ultimo->sig=aux;
				aux->ant=ultimo;
				aux->sig=primero;
				ultimo=aux;
				aux=control;
				i=1;
			}
			if(i==10){
				pnodo temp=aux->sig;
				if(temp->getColumnas()>temp->sig->getColumnas()&&temp->getFilas()==temp->sig->getFilas()){
					temp->ant->sig=temp->sig;
					temp->sig->ant=temp->ant;
					ultimo->sig=temp;
					temp->ant=ultimo;
					temp->sig=primero;
					ultimo=temp;
				}
				row--;
				control=aux->sig;
				flag=true;
				f++;
				ordenamiento-=10;
			}
			if(aux->sig==primero||ordenamiento==1){
				row--;
				i=10;
			}
		}
		i=1;
	}
	pnodo aux=primero;
	while(aux!=ultimo){
		if(aux->sig->getColumnas()>10){
			aux->sig->setColumnas(aux->sig->getColumnas()-10);
		}
		aux=aux->sig;
	}
	pnodo ayuda;
	aux=primero;
	while(aux!=ultimo){
	if(aux->getColumnas()>aux->sig->getColumnas()&&aux->getFilas()==aux->sig->getFilas()){
		aux->ant->sig=aux->sig;
		aux->sig->ant=aux->ant;
		ayuda=aux->sig;
			while(ayuda->sig->getFilas()==aux->getFilas()){
			ayuda=ayuda->sig;
			}
		ayuda->sig->ant=aux;
		aux->sig=ayuda->sig;
		ayuda->sig=aux;
		aux->ant=ayuda;
	}
		aux=aux->sig;
	}
	}
}*/

void ListaCD::unirLista(){
	mostrar();
	if(!listaVacia()){
		if(numeroElementos()<10){
			pnodo aux=primero->sig;
			while(aux!=primero){
				aux->setColumnas(aux->ant->getColumnas()+1);
				aux->setFilas(1);
				aux=aux->sig;
			}
		}else{
			pnodo control=primero;
			pnodo aux=primero;
			int filas=1;
			int help=numeroElementos();
			while(help>10){
			aux->setColumnas(1);
			for(int i=1;i<=10;i++){
				control=control->sig;
				}
			aux=aux->sig;
			while(aux!=control){
				int p=aux->ant->getColumnas();
				if(p>=10){
					p=0;
				}
				aux->setColumnas(p+1);
				aux->setFilas(filas);
				aux=aux->sig;
			}
			filas++;
			aux=control;
			help-=10;
			if(help>=10){
				aux->setColumnas(1);
			}
			}
			aux=aux->sig;
			while(aux!=primero){
				aux->setColumnas(aux->ant->getColumnas()+1);
				aux=aux->sig;
			}
			}
		}
	}

pnodo ListaCD::returnNodo(int i){
	pnodo aux=primero;
	if(i==1){
		return primero;
	}
	for(int x=1;x<i;x++){
		aux=aux->sig;
	}
	return aux;
}

void ListaCD::generarArchivo(){
	pnodo aux=primero;
	ofstream file;
	file.open("Lista.txt");
	file<<"Lista Jugadores"<<"\n";

	do{
		file<<"Valor: "<<aux->getValorTetris()<<" Filas: "<<aux->getFilas()<<" Columnas: "<<aux->getColumnas()<<"\n";
		aux=aux->sig;
	}while(aux!=primero);
	file.close();
}

