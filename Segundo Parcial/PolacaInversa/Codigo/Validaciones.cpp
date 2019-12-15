#include "Validaciones.h"
#include <string>

bool Validaciones::esOperador(char c) {
	return (!isalpha(c) && !isdigit(c));
}

bool Validaciones::esInfija(std::string cadena){
	for (int i = 0; i < cadena.size(); i++) {

		/*Validacion de simbolos especiales y letras*/
		if ((cadena.at(i) > 32 && cadena.at(i) < 40) || 
			(cadena.at(i) == 44) || 
			(cadena.at(i) > 57 && cadena.at(i) < 94) ||
			(cadena.at(i) > 94 && cadena.at(i) < 255))
			return false;
	}
	
	return true;
}

