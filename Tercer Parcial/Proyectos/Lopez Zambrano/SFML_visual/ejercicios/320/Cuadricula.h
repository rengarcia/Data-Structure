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
	void setX(int ex) { x = ex; }
	void setY(int why) { y = why; }
	int getX() { return x; }
	int getY() { return y; }
	Cuadricula();
};

