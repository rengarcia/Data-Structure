#include <string>
#include <iostream>
using namespace std;

class Operaciones
{
public:
	string convertir(string cadena);
	Nodo* Insetar(string cadena);
	string removerDobleEspacio(string cadena);
	Nodo* Interseccion(Nodo* lista1, Nodo* lista2);
	Nodo* eliminarDuplicados(Nodo* lista);

private:
	bool esComun(Nodo* lista, int numero);
};

