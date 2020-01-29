/*	***** UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE ***** **
** Estructura de Datos									**
** Nombre: Jorge Galarza - Kevin Zurita					**
** NRC: 2742											**
** Fecha de realizacion: 01/12/2019						**
** Fecha de modificacion: 12/12/2019					**
** Ing. Fernando Solis									**
*/	
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include "NodoArbol.h"

using namespace std;
typedef NodoArbol* pnodo;

class ArbolBinario{
	public:
		void voz(string);
		void llenarDiccionario(pnodo&, pnodo&, pnodo&);
		void crearNodoArbol(int, string, pnodo&);
		void insertarNodoArbol(pnodo&, int, string);
		int CodigoPalabra(pnodo, string);
		string PalabraCodigo(pnodo, int);
		string Traduccion(pnodo, pnodo, string);
};

void ArbolBinario::crearNodoArbol(int id, string palabra, pnodo& tree)
{
	pnodo nodoArbol = new NodoArbol(id, palabra);
	tree = nodoArbol;
}

void ArbolBinario::insertarNodoArbol(pnodo& tree, int id, string palabra){
		if (tree == NULL)
	{
		crearNodoArbol(id, palabra, tree);
	}
	else if (id < tree->getId()){
		insertarNodoArbol(tree->izquierda, id, palabra);
	}
	else if (id >= tree->getId()){
		insertarNodoArbol(tree->derecha, id, palabra);
	}
}


string ArbolBinario::PalabraCodigo(pnodo tree, int code)
{
	while (tree != NULL)
	{
		if (tree->getId() == code)
		{
			return tree->getPalabra();
		}
		tree = tree->derecha;
	}
	return "No disponible.";
}

int ArbolBinario::CodigoPalabra(pnodo tree, string palabra)
{
	while (tree != NULL)
	{
		if (tree->getPalabra() == palabra)
		{
			return tree->getId();
		}
		tree = tree->derecha;
	}
	return 0;
}

string ArbolBinario::Traduccion(pnodo ArbolIngles, pnodo ArbolEspaniol,string word)
{
	return PalabraCodigo(ArbolEspaniol, CodigoPalabra(ArbolIngles, word));
}

void ArbolBinario::llenarDiccionario(pnodo& ArbolIngles, pnodo& ArbolEspaniol, pnodo& ArbolTraduccion){
	string line;
	fstream out;
	out.open("diccionario.txt",fstream::in);
	ifstream myfile ("diccionario.txt");

	if (myfile.is_open())
  	{    	
	  while ( getline (myfile,line) )
    	{
    		int id = atoi(line.substr(0,line.find("/")).c_str());
    		string words=line.substr(line.find("/")+1,line.length());
    		insertarNodoArbol(ArbolIngles,id,words.substr(0,words.find("/")));
    		words=words.substr(words.find("/")+1,words.length());
    		insertarNodoArbol(ArbolEspaniol,id,words.substr(0,words.find("/")));
    		insertarNodoArbol(ArbolTraduccion,id,words.substr(words.find("/")+1,words.length()));
    	}
    	myfile.close();
    	out.close();
	}
}

void ArbolBinario::voz(string cad){
std::ofstream audio("reproducir.vbs");
audio<<"Dim SAPI"<<endl;
audio<<"set SAPI = CreateObject (\"sapi.spvoice\")"<<endl;
audio<<"SAPI.Speak"<<"\""<<cad<<"\""<<endl;
audio.close();
system("reproducir.vbs");
}
