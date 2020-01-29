#pragma once
class Desglosar {
private:
	int doscientos;
	int veinte;
	int diez;
	int dos;
public:
	int getDoscientos();
	void setDoscientos(int newDoscientos);
	int getVeinte();
	void setVeinte(int newVeinte);
	int getDiez();
	void setDiez(int newDiez);
	int getDos();
	void setDos(int newDos);
	void desglosarEuros(int euros);
protected:
};