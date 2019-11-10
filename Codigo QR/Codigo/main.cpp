#include "ingreso.h"
#include "generador.h"
#include <iostream>

using namespace std;

int main() {
	Ingreso leer;
	QR obtener;
	int tamanio;
	char **matriz;
	cout << "Ingrese el tamanioo que desea el QR" << endl;
	tamanio = leer.ingresarEntero();
	obtener.generarQR(tamanio,matriz);
	return 0;
}
