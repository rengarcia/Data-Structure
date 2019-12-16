#include "Position.h"

Position::Position()
{
	this->posX = 0;
	this->posY = 0;
	this->num = 0;
}


Position::~Position()
{
}

void Position::setPosXY(int X, int Y,int num)
{
	this->posX = X;
	this->posY = Y;
	this->num = num;
}

int Position::getPosX()
{
	return this->posX;
}

int Position::getPosY()
{
	return this->posY;
}

int Position::getNum() {
	return this->num;
}
