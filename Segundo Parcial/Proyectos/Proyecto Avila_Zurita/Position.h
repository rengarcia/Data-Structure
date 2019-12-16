#pragma once
class Position
{
private:
	int posX;
	int posY;
	int num;
public:
	Position();
	~Position();
	void setPosXY(int X, int Y,int num);
	int getPosX();
	int getPosY();
	int getNum();
};

