#include <string>
#include <iostream>
using namespace std;

class Operaciones
{
public:
	string convertir(string cadena);
	Nodo* Insetar(string cadena);
	NodoPar* recorrerCadenas(Nodo* lista1, Nodo* lista2);
	void InsertarPar(int numero, Nodo* lista);
	string removerDobleEspacio(string cadena);
	Nodo* eliminarDuplicados(Nodo* lista);
private:
	bool esComun(Nodo* lista, int numero);
};

