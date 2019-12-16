#include "ListaDoble.h"



ListaDoble::ListaDoble()
{
	head = new NodoDoble();
	tail = new NodoDoble();
	head->last = NULL;
	head->next = tail;
	tail->next = NULL;
	tail->last = head;
}


ListaDoble::~ListaDoble()
{
	delete head;
	delete tail;
}

bool ListaDoble::insertarDato(int dato)
{
	return false;
}

void ListaDoble::listaDobleTetris(int tamaño)
{
	int cont = 0;
	do {
		NodoDoble* nuevoNodo = new NodoDoble();
		nuevoNodo->dato = 0;
		nuevoNodo->last = tail->last;
		nuevoNodo->next = tail;
		tail->last->next = nuevoNodo;
		tail->last = nuevoNodo;
		cont = cont + 1;
	} while (cont != tamaño);
}

void ListaDoble::imprimirLista()
{
	std::fstream enter;
	enter.open("Lista.txt", std::fstream::out);
	int numero;
	NodoDoble* aux = head->next;
	enter << "La lista es:\n";
	while (aux != tail) {
		
		if (aux->dato == 0 || aux->dato==-1) {
			std::cout << " ";
			enter << " ";
			aux = aux->next;
		}
		else {
			std::cout << aux->dato;
			numero= aux->dato;
			enter << numero;
			aux = aux->next;
		}
		
	}
}

void ListaDoble::insertarEnLista(Position* pos, int num, int limVer,int limHor)
{
	int cont=0;
	if (pos->getPosY() >= limVer-1) {
		NodoDoble* aux = new NodoDoble();
		aux = head->next;
		while (cont != pos->getPosX() - 3) {
			aux = aux->next;
			cont = cont + 1;
		}
		if (cont % 3 == 0 && (aux->dato ==0 || aux->dato == -1)) {
			if (aux->dato == num) {
				aux->dato = -1;
			}
			else {
				aux->dato = num;
			}
		}
		else {
			if (pos->getPosX() - 3 == 0) {
				if (aux->dato == num) {
					aux->dato = -1;
					return;
				}
				cont = 0;
				aux = head->next;
				while (aux != tail) {
					if ((aux->dato == 0 || aux->dato == -1) && cont%3==0) {
						aux->dato = num;
						return;
					}
					else {
						aux = aux->next;
						cont = cont + 1;
					}
				}
			}
			else if (cont == limHor-8) {
				if (aux->dato == num) {
					aux->dato = -1;
					return;
				}
				cont = pos->getPosX()-3;
				aux = tail->last;
				while (aux != head) {
					if ((aux->dato == 0 || aux->dato == -1) && cont % 3 == 0) {
						aux->dato = num;
						return;
					}
					else {
						aux = aux->last;
						cont = cont - 1;
					}
				}
			}else if(cont%3==0) {
				if (aux->dato == num) {
					aux->dato = -1;
					return;
				}
				cont = 0;
				aux = head->next;
				while (aux != tail) {
					if ((aux->dato == 0 || aux->dato == -1) && cont % 3 == 0) {
						aux->dato = num;
						return;
					}
					else {
						aux = aux->next;
						cont = cont + 1;
					}
				}
				if (aux->dato == num) {
					aux->dato = -1;
					return;
				}
				cont = pos->getPosX() - 3;
				aux = tail->last;
				while (aux != head) {
					if ((aux->dato == 0 || aux->dato == -1) && cont % 3 == 0) {
						aux->dato = num;
						return;
					}
					else {
						aux = aux->last;
						cont = cont - 1;
					}
				}
			}
		}
		
	}
}

bool ListaDoble::perdio(int elementos)
{
	int cont = 0;
	int cont2 = 0;
	NodoDoble* aux = new NodoDoble();
	aux = head->next;
	while (aux != tail) {
		if (aux->dato != 0 ) {
			cont = cont + 1;
		}
		if (aux->dato == -1) {
			cont2 = cont2 + 1;
		}
		aux = aux->next;
	}
	if (cont == elementos && cont2==0) {
		return false;
	}
	return true;
}

bool ListaDoble::gano(int elementos)
{
	int cont = 0;
	int cont2 = 0;
	int cont3 = 0;
	int total = 0;
	NodoDoble* aux = new NodoDoble();
	aux = head->next;
	while (aux != tail) {
		if (aux->dato == -1) {
			cont = cont + 1;
		}
		if (aux->dato == 0 && cont3%3==0) {
			cont2 = cont2 + 1;
		}
		aux = aux->next;
		cont3 = cont3 + 1;
	}
	if (cont2 == elementos) {
		cont2 = cont2 - 1;
	}
	total = cont + cont2;
	if (total == elementos) {
		return false;
	}
	return true;
}
