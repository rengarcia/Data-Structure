#include "Interes.h"
#include <math.h>
void Interes::setCapital(double newCapital)
{
	this->capital = newCapital;
}

double Interes::getCapital()
{
	return capital;
}

void Interes::setPorcentaje(double newPorcentaje)
{
	this->porcentaje = newPorcentaje;
}

double Interes::getPorcentaje()
{
	return porcentaje;
}

void Interes::setAnio(int newAnio)
{
	this->anio = newAnio;
}

int Interes::getAnio()
{
	return anio;
}

double Interes::calcularInteres(double capital, double porcentaje, int anio)
{
	double newInteres;
	newInteres = (1 + porcentaje / 100);
	newInteres = pow(newInteres, anio);
	newInteres = capital * newInteres;
	return newInteres;
}