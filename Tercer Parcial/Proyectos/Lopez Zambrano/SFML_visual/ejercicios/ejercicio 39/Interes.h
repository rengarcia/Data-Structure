#pragma once
class Interes {
public:
	void setCapital(double newCapital);
	double getCapital();
	void setPorcentaje(double newPorcentaje);
	double getPorcentaje();
	void setAnio(int newAnio);
	int getAnio();
	double calcularInteres(double capital,double porcentaje,int anio);
private:
	double capital;
	double porcentaje;
	int anio;
protected:
};