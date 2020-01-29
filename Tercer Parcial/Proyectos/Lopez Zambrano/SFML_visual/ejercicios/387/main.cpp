/* Ejercicio N 387:
Otra figura recursiva que es todo un clasico es la criba o triangulo de Sierpinski. En cada nivel de recursion se divide
cada uno de los triangulos del nivel anterior en tres nuevos triangulos. Esta figura muestra los triangulos de Sierpinski para
niveles de recursion de 0 a 4:
*/                                        

#include <iostream>
#include "Operaciones.h"
#include "Validacion.h"
#include <windows.h>
HANDLE h;
using namespace std;

int main()
{
	Operaciones operacion;
	Validacion validacion;

	string temp;
	int opcion;

	while (GetAsyncKeyState(VK_ESCAPE) == 0) {
		cout << "Escoja un nivel de recursividad, del 0 al 4" << endl;
		cin >> temp;
		temp = validacion.soloNumeros(temp);
		opcion = validacion.dentroRango(temp);
	
		int n = operacion.menu(opcion);
		int y = n - 1;
		cout << endl;
		operacion.arbolSierpinskiRecursivo(y,n+1);

		cout << endl <<endl << "******Presione ESC para salir o ENTER para continuar******" << endl << endl;
		system("pause");
		system("cls");
	}


	return 0;
}
