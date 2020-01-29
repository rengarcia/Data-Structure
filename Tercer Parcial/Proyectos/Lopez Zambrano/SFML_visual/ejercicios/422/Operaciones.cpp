#include "Operaciones.h"

bool Operaciones :: esBisiesto(int anio)
{
	return (((anio % 4 == 0) &&(anio % 100 != 0)) ||(anio % 400 == 0));
}

bool Operaciones:: fecha_valida(int dia, int mes, int anio)
{
	
	if (anio > MaximoAnioValido ||anio < MinimoAnioValido)
		return false;

	if (mes < 1 || mes > 12)
		return false;
	
	if (dia < 1 || dia > 31)
		return false;

	if (mes == 2)
	{
		if (esBisiesto(anio)) {
			return (dia <= 29);
		}
	
		else
			return (dia <= 28);
	}

	 
	if (mes == 4 || mes == 6 ||mes == 9 || mes == 11)
		return (dia <= 30);

	return true;
}