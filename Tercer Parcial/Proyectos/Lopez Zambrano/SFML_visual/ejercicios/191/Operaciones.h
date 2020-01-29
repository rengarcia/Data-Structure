#include <string>
#include <iostream>
using namespace std;

class Operaciones
{
public:
	void Palindromo(string cadena);
	string convertir(string cadena);

private:
	string aMinusculas(string cadena);
	string removerEspacioySignos(string cadena);
	string removerAcentuacionyDieresis(string cadena);

};

