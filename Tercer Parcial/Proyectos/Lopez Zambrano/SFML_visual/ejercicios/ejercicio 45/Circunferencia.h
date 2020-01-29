#pragma once
class Circunferencia {
private:
	double radio;
	double perimetro;
	double area;
public:
	void setRadio(double newRadio);
	double getRadio();
	void calcularPerimetro(double radio);
	double getPerimetro();
	void calcularArea(double radio);
	double getArea();
protected:
};