#pragma once
class Vector {
private:
	double x;
	double y;
	double z;
public:
	void setX(double newX);
	double getX();
	void setY(double newY);
	double getY();
	void setZ(double newZ);
	double getZ();
	void imprimir();
};