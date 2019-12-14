#include "Lista.h"
#include <string.h>


using namespace std;

Lista::Lista()
{
	primero=NULL;
}

Nodo* Lista::getPrimero()
{
	return primero;
}



void Lista::ingresarDatoFinal(string palabra)
{
	Nodo *temp = new Nodo;
	Nodo *aux = primero;
	temp->setPalabra(palabra);
	temp->siguiente=NULL;
	
	if(aux==NULL)
	{
		primero= temp;
	}
	else
	{
		while(aux->siguiente != NULL)
		{
			aux=aux->siguiente;
		}
		aux->siguiente=temp;
	}


}

void Lista::borrarPrimerElemento()
{
	Nodo *aux = primero;
	
	if(aux == NULL)
	{
		cout << "No existen elementos para borrar" <<endl;
	}
	else
	{
		Nodo *temp = primero->siguiente;
	delete primero;
	
	primero=temp;
	}
	
}


bool Lista::verificarCadena(string frase){
	Nodo* recorredor= primero;
	
	while(recorredor->siguiente != NULL)
	{
		int posicion = frase.find(" ");
		string palabra = frase.substr(0,posicion);
		
		if(!(recorredor->getPalabra().compare(palabra) == 0))
		{
			return false;
		}
		else
		{
			recorredor = recorredor->siguiente;	
		}
		
		frase = frase.substr(posicion+1,frase.length()-1);		
	}
	
	return true;
	
}

string Lista::obtenerUltimaPalabra(string frase)
{
    string ultPalabra="";
  
    // Returns first token  
    char *token = strtok((char*)frase.c_str(), " "); 

    while (token != NULL) 
    { 
        ultPalabra = token;
        token = strtok(NULL, " "); 
    }
	 	
	return ultPalabra;
}


void Lista::imprimir() 
{
	Nodo *temp = primero;
	
	while(temp!=NULL)
	{
		cout<<temp->getPalabra() <<", "<<endl;
		temp = temp->siguiente;
	}
	delete temp;

}




Lista::~Lista()
{
	while(primero!=NULL){
		borrarPrimerElemento();
	}
}


