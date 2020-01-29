#include "Triangulo.h"
void Triangulo::setBase(double newBase)
{
	this->base = newBase;
}

double Triangulo::getBase()
{
	return base;
}

void Triangulo::setAltura(double newAltura)
{
	this->altura = newAltura;
}

double Triangulo::getAltura()
{
	return altura;
}

void Triangulo::setPuntoA(double newPuntoA)
{
	this->puntoA = newPuntoA;
}

double Triangulo::getPuntoA()
{
	return puntoA;
}

void Triangulo::setPuntoB(double newPuntoB)
{
	this->puntoB = newPuntoB;
}

double Triangulo::getPuntoB()
{
	return puntoB;
}
void Triangulo::setPuntoC(double newPuntoC)
{
	this->puntoC = newPuntoC;
}
double Triangulo::getPuntoC()
{
	return puntoC;
}

void Triangulo::calcularArea(double base, double altura)
{
	double newArea = (base * altura) / 2;
	this->area = newArea;
}

double Triangulo::getArea()
{
	return area;
}