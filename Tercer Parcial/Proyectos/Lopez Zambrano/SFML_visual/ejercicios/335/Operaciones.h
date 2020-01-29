#include <string>
#include <iostream>
using namespace std;

class Operaciones
{
public:
	string convertir(string cadena);
	Nodo* Insertar(string cadena);
	string removerDobleEspacio(string cadena);
	Nodo* eliminarDuplicados(Nodo* lista);
	Nodo* primos (Nodo* lista);

private:
	bool esPrimo (int numero);
	bool esComun(Nodo* lista, int numero);
};

