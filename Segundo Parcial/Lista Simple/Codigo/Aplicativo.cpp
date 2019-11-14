#include <iostream>
#include "Prototipo.cpp"

using namespace std;

int main(){
	Ingreso leer;
	string op;
	bool comprobar = true;
	Prototipo *lista = new Prototipo();
	do{
		lista->insertarInicio();
		cout << "Desea continuar presione s(si) n(no)" << endl;
		op = leer.ingresarLetra();
		if(op == "s" || op == "S") {
			comprobar = true;
		} else {
			comprobar = false;
		}
	} while (comprobar == true);
	lista->imprimirNodo();
	return 0;
}
