/***********************************************************************
 * Module:  Cuadricula.h
 * Author:  fleia
 * Modified: Monday, January 20, 2020 ‏‎8:49:14 AM
 * Purpose: Declaration of the class Cuadricula
 ***********************************************************************/

#if !defined(__Class_Diagram_1_Cuadricula_h)
#define __Class_Diagram_1_Cuadricula_h

#include <iostream>
#include <cmath>


enum Pieza { REY, REINA, ALFIL, CABALLO, TORRE, PEON, VACIO };
enum Color { BLANCO, NEGRO, NINGUNO };

class Cuadricula
{
	Pieza pieza;
	Color color;
	int x, y;
public:
	void setEspacio(Cuadricula* posicion);
	void setVacio();
	void setPiezaYColor(Pieza, Color);
	Pieza getPieza();
	Color getColor();
	void setX(int newX);
	void setY(int newY);
	int getX();
	int getY();
	Cuadricula();
};

#endif