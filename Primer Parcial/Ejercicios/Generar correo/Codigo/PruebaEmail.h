/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 2967                                                       *
******************************************************************/
#include <string>
#include <stdio.h>
#include <cstdlib>
#include "GenerarEmail.h"
using namespace std;

class PruebaEmail : public GenerarEmail
{
public:
   string genEmail(string nombre, string apellido);
   PruebaEmail();
};
string PruebaEmail::genEmail(string nombre, string apellido)
{
	string email, min;
	char* alocator;
	alocator=(char*)malloc(1*sizeof(char));
	int x=nombre.find(" ");
	if(x>1){
	sprintf(alocator,"%c%c",nombre.at(0),nombre.at(nombre.find(" ")+1));
	}
	else{
	sprintf(alocator,"%c",nombre.at(0));
	}
	email.append(alocator);
	if(apellido.find(" ")>0){
	email.append(apellido.substr(0,apellido.find(" ")).c_str());
	}
	else{
	email.append(apellido.c_str());
	}
	for(int i = 0; i<email.length();i++){
		int y=(int)email.at(i);
		char c=tolower(y);
		char* minus;
		minus=(char*)malloc(1*sizeof(char));
		sprintf(minus,"%c",c);
		min.append(minus);
		free(minus);
	}
	return min;
}
PruebaEmail::PruebaEmail()
{
}
