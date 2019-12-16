#pragma once
#include <cstddef>
class NodoDoble
{
private:
	int dato;
	NodoDoble* next;
	NodoDoble* last;
public:
	NodoDoble();
	~NodoDoble();

	friend class ListaDoble;
};

