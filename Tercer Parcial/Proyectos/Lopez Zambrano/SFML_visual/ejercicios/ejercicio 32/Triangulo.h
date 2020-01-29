#pragma once
class Triangulo {
public:
	void setBase(double newBase);
	double getBase();
	void setAltura(double newAltura);
	double getAltura();
	void setPuntoA(double newPuntoA);
	double getPuntoA();
	void setPuntoB(double newPuntoB);
	double getPuntoB();
	void setPuntoC(double newPuntoC);
	double getPuntoC();
	void calcularArea(double base, double altura);
	double getArea();
private:
	double puntoA;
	double puntoB;
	double puntoC;
	double base;
	double altura;
	double area;
protected:
};