#include "NodoChar.h"
#include "NodoInt.h"
#include "NodoDouble.h"
#include <string>
using namespace std;

class OperacionesNodo
{
public:
	void push_char(NodoChar*& referencia, char dato);
	void pop_char(NodoChar*& referencia);
	char top_char(NodoChar*& referencia);
	void imprimir_char(NodoChar* referencia);
	void destruirPila_char(NodoChar* referencia);

	//Nodo con tipo de dato entero
	void push_int(NodoInt*& referencia, int dato);
	void pop_int(NodoInt*& referencia);
	int top_int(NodoInt*& referencia);
	void imprimir_int(NodoInt* referencia);
	void destruirPila_int(NodoInt* referencia);

	//Nodo con tipo de dato double
	void push_double(NodoDouble*& referencia, double dato);
	void pop_double(NodoDouble*& referencia);
	double top_double(NodoDouble*& referencia);
	void imprimir_double(NodoDouble* referencia);
	void destruirPila_double(NodoDouble* referencia);

	string invertirCadena(string cadena);
};

