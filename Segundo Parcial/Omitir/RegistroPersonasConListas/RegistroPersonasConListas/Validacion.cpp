#include "Validacion.h"
#include <string>
#include <sstream>
using namespace std;

string Validacion::soloLetras(string cadena) {
	
	for (int i = 0; i < cadena.length(); i++) {
		if (!isalpha(cadena[i])&&cadena[i]!=' ') {
			cout << "Dato no valido, Reingrese" << endl;
			cin >> cadena;
			i = 0;
		}
	}
	return cadena;

}

//Valida que solo sean numeros y tenga maximo 10 caracteres
string Validacion::soloNumeros(string cadena) {
	for (int i = 0; i < cadena.length(); i++) {
		if (!isdigit(cadena[i]) || cadena.length() > 10) {
			cout << "Texto no valido, Reingrese" << endl;
			cin >> cadena;
			i = 0;
		}
	}
	return cadena;
}



string Validacion::validacionCedula(string dato) {
	
	int num = stoi(dato);

	int mul1 = 0, mul2 = 0, res, cont = 1, sum1 = 0, sum2 = 0, sum3 = 0, ult_n1, ult_n2;
	int  coc1, coc2;
	do {
		mul1 = 0; mul2 = 0; sum1 = 0; sum2 = 0; sum3 = 0; cont = 1;
		while (num < 999999999 || num>9999999999)
		{
			printf("Numero no valido, reingrese por favor:\n");
			cin >> num;
		}
		ult_n1 = num % 10;
		coc1 = num / 10;
		num = coc1;
		do {
			do {
				coc2 = num / 10;
				res = num % 10;
				if (cont % 2 == 0)
				{
					mul2 = res * 1;
					if (mul2 >= 10)
						mul2 -= 9;
					sum2 += mul2;
				}
				else
				{
					mul1 = res * 2;
					if (mul1 >= 10)
						mul1 -= 9;
					sum1 += mul1;
				}
				cont++;
				num = coc2;
			} while (coc2 != 0);
			sum3 = sum1 + sum2;
			if ((sum3 % 10) != 0)
			{
				ult_n2 = sum3 / 10;
				ult_n2++;
				ult_n2 *= 10;
				ult_n2 -= sum3;
			}
			else
				ult_n2 -= ult_n2;
			if (ult_n2 == ult_n1) {
				return dato;
			}
		} while (ult_n2 == ult_n1);
		printf("El numero de cedula no es valido!! Reingresalo\n");
		cin >> num;
	} while (ult_n2 != ult_n1);
}


string Validacion::validacionId(string dato) {

	for (int i = 0; i < dato.size(); i++)
	{
		if (!isdigit(dato[i]) && !isalpha(dato[i]) && dato[i] != ' ') {
			cout << "Dato no valido, Reingrese" << endl;
			cin >> dato;
			i = 0;
		}
	}

	return dato;
}

