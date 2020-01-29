/***********************************************************************
 * Module:  Arbol.h
 * Author:  Carlos Puco, Kevin Duy
 * Modified: Sabado, 11 de enero de 2020 20:20:06
 * Purpose: Declaration of the class Arbol
 ***********************************************************************/

#include "Pila.cpp"
#include <string>
#include <fstream>

using namespace std;
pthread_mutex_t ptmutex1;
ofstream archivo;

class Arbol {
	private:
		Pila *cima;
	public:
		Arbol();
		void limpiar();
		void agregar(Nodo*);
		Nodo* mover();
		Nodo* dirigir();
		void insertar(char);
		bool digito(char);
		bool operador(char);
		int convertirANumero(char);
		void construirArbol(string);
		double evaluar();
		double calcular(Nodo*);
		void gotoxy(int x,int y);
		void mostrar(Nodo *nodo, int x, int y);
		void principal();
		void crearMenu();
		
	friend class Nodo;
	friend class Pila;
};
