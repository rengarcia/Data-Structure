#include "areaCuadrado.h"
void Cuadrado::setLado(int newLado)
{
	this->lado = newLado;
}

int Cuadrado::getLado()
{
	return lado;
}

int Cuadrado::getArea()
{
	return area;
}

int Cuadrado::getPerimetro()
{
	return perimetro;
}

void Cuadrado::calcularArea(int lado) 
{
	int newArea = lado * lado;
	this->area = newArea;
}

void Cuadrado::calcularPerimetro(int lado)
{
	int newPerimetro = lado * 4;
	this->perimetro = newPerimetro;
}