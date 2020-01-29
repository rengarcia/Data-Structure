#include "Cuadricula.h"

Cuadricula::Cuadricula()
{
	pieza = VACIO;
	color = NINGUNO;
}

void Cuadricula::setEspacio(Cuadricula* posicion)
{
	color = posicion->getColor();
	pieza = posicion->getPieza();
}

void Cuadricula::setVacio()
{
	color = NINGUNO;
	pieza = VACIO;
}

Pieza Cuadricula::getPieza()
{
	return pieza;
}

Color Cuadricula::getColor()
{
	return color;
}

void Cuadricula::setPiezaYColor(Pieza p, Color c)
{
	pieza = p;
	color = c;

}
