#include "Vector.h"
#include <iostream>
using namespace std;
void Vector::setX(double newX)
{
	this->x = newX;
}

double Vector::getX()
{
	return x;
}

void Vector::setY(double newY)
{
	this->y = newY;
}

double Vector::getY()
{
	return y;
}

void Vector::setZ(double newZ)
{
	this->z = newZ;
}

double Vector::getZ()
{
	return z;
}

void Vector::imprimir()
{
	cout << "(" << getX() << ", " << getY() << ", " << getZ() << " )" << endl;
}