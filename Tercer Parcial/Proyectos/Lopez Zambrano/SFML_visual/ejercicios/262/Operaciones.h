#include <string>
#include <iostream>
using namespace std;

class Operaciones
{
public: 
	double raiz_cubica(double numero);
	string eliminarSigno(string cadena);

private:
	double diferencial(double numero, double mitad);
};

