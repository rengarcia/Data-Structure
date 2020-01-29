#include "Desglosar.h"
int Desglosar::getDoscientos()
{
	return doscientos;
}

void Desglosar::setDoscientos(int newDoscientos)
{
	this->doscientos = newDoscientos;
}

int Desglosar::getVeinte()
{
	return veinte;
}

void Desglosar::setVeinte(int newVeinte)
{
	this->veinte = newVeinte;
}

int Desglosar::getDiez()
{
	return diez;
}

void Desglosar::setDiez(int newDiez)
{
	this->diez = newDiez;
}

int Desglosar::getDos()
{
	return dos;
}

void Desglosar::setDos(int newDos)
{
	this->dos = newDos;
}

void Desglosar::desglosarEuros(int euros)
{
	setDoscientos(euros / 200);
	euros = euros % 200;
	setVeinte(euros / 20);
	euros = euros % 20;
	setDiez(euros / 10);
	euros = euros % 10;
	setDos(euros / 2);
	euros = euros % 2;
}