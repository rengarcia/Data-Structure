#pragma once
class Cuadrado {
public:
	int getLado();
	void setLado(int newLado);
	void calcularPerimetro(int lado);
	void calcularArea(int lado);
	int getArea();
	int getPerimetro();
private:
	int lado;
	int area;
	int perimetro;
protected:
};