#include <string>
#include <iostream>
using namespace std;

class Operaciones
{
public: 
	string aMinusculas(string cadena);
	bool  es_repeticion(string cadena);
	
private:
	bool es_igual(char* cadena1, char* cadena2, int dim);
	bool es_impar(int  numero);

};

