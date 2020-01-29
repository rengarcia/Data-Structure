#pragma once
#include "Vector.h"
class Operaciones {
public:
	Vector sumar(Vector v1, Vector v2);
	Vector diferenciar(Vector v1, Vector v2);
	double productoEscalar(Vector v1, Vector v2);
	Vector productoVectorial(Vector v1, Vector v2);
	double angulo(Vector v1, Vector v2);
	double longitud(Vector v1);
};