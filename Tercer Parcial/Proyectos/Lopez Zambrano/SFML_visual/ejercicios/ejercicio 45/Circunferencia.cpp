#include "Circunferencia.h"
#define PI 3.14159265
void Circunferencia::setRadio(double newRadio)
{
	this->radio = newRadio;
}

double Circunferencia::getRadio()
{
	return radio;
}

void Circunferencia::calcularPerimetro(double radio)
{
	this->perimetro = 2 * PI * radio;
}

double Circunferencia::getPerimetro()
{
	return perimetro;
}

void Circunferencia::calcularArea(double radio)
{
	this->area = PI * radio * radio;
}

double Circunferencia::getArea()
{
	return area;
}