#include "Operaciones.h"
#include <math.h>
Vector Operaciones::sumar(Vector v1, Vector v2)
{
	Vector resultante;
	resultante.setX((v1.getX() + v2.getX()));
	resultante.setY((v1.getY() + v2.getY()));
	resultante.setZ((v1.getZ() + v2.getZ()));
	return resultante;
}

Vector Operaciones::diferenciar(Vector v1, Vector v2)
{
	Vector resultante;
	resultante.setX((v1.getX() - v2.getX()));
	resultante.setY((v1.getY() - v2.getY()));
	resultante.setZ((v1.getZ() - v2.getZ()));
	return resultante;
}

double Operaciones::productoEscalar(Vector v1, Vector v2)
{
	double resultado = v1.getX() * v2.getX() + v1.getY() * v2.getY() + v1.getZ() * v2.getZ();
	return resultado;
}

Vector Operaciones::productoVectorial(Vector v1, Vector v2)
{
	Vector resultante;
	resultante.setX(((v1.getY() * v2.getZ())  - (v1.getZ() * v2.getY())));
	resultante.setY(((v1.getZ() * v2.getX()) - (v1.getX() * v2.getZ())));
	resultante.setZ(((v1.getX() * v2.getY()) - (v1.getY() * v2.getX())));
	return resultante;
}

double Operaciones::angulo(Vector v1, Vector v2)
{
	double numerador = productoEscalar(v1, v2);
	double denominador = longitud(v1) * longitud(v2);
	double resultado = acos(numerador / denominador);
	return resultado;
}

double Operaciones::longitud(Vector v1)
{
	double resultado = sqrt(v1.getX() * v1.getX() + v1.getY() * v1.getY() + v1.getZ() * v1.getZ());
	return resultado;
}