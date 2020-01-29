#include <iostream> 
#include <set> 
#include <iterator> 

using namespace std;

class OperacionesSet
{
public:
	void imprimir(set<int> setTemp);
	set<int> InsertarDatosSet(string cadena);
	set<int> Lista_a_Conjunto(Nodo* referencia);
	set<int> Union(set<int> setAux1, set<int> setAux2);
	set<int> Interseccion(set<int> setAux1, set<int> setAux2);
	set<int> Diferencia(set<int> setAux1, set<int> setAux2);
	bool sonIguales(set<int> setAux1, set<int> setAux2);

private:
	bool esComun(int valor, set<int> setAux2);

};

