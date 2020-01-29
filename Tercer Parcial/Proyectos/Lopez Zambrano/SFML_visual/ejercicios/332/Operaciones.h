#include <string>
#include <iostream>
using namespace std;

class Operaciones
{
public:
	string convertir(string cadena);
	Nodo* Insetar(string cadena);
	string removerDobleEspacio(string cadena);
	Nodo* eliminarDuplicados(Nodo* lista);
	Nodo* diferencia (Nodo* lista1, Nodo* lista2);
private:
	bool esComun(Nodo* lista, int numero);
};

