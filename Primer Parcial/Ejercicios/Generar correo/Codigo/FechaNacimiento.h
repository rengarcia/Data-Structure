/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 2967                                                       *
******************************************************************/
#include <string>
#include <stdlib.h>
using namespace std;

class FechaNacimiento
{
public:
   int getDia(void);
   void setDia(int newDia);
   int getMes(void);
   void setMes(int newMes);
   int getAnio(void);
   void setAnio(int newAnio);
   FechaNacimiento();
   bool fechaPalindroma();

private:
   int dia;
   int mes;
   int anio;


};

int FechaNacimiento::getDia(void)
{
   return dia;
}

void FechaNacimiento::setDia(int newDia)
{
   dia = newDia;
}

int FechaNacimiento::getMes(void)
{
   return mes;
}

void FechaNacimiento::setMes(int newMes)
{
   mes = newMes;
}

int FechaNacimiento::getAnio(void)
{
   return anio;
}

void FechaNacimiento::setAnio(int newAnio)
{
   anio = newAnio;
}
FechaNacimiento::FechaNacimiento()
{
}

bool FechaNacimiento::fechaPalindroma(){
		string palindromo; 
		char* conv;
		conv=(char*)malloc(8*sizeof(char));
		sprintf(conv,"%d%d%d",dia,mes,anio);
		palindromo.append(conv);
		free(conv);
		int x=palindromo.length();
		for(int j=0;j<(palindromo.length()/2);j++){
			if(palindromo.at(j)!=palindromo.at(x-1)){
				return false;
			}
			x--;
		}
		return true;
	}

