#pragma once
class Nodo {
private:
	int dato;//puede ser de cualquier tipo
	Nodo* derecha;
	Nodo* izquierda;
public:
	Nodo();
	Nodo(int newDato);
	int getDato();
	void setDato(int newDato);
	Nodo*& getDerecha();
	void setDerecha(Nodo* newNodoDerecha);
	Nodo*& getIzquierda();
	void setIzquierda(Nodo* newNodoIzquierda);
protected:

};