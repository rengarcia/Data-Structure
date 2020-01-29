#pragma once
#include <iostream>
using namespace std;
class Menor {
private:
	string menor;
public:
	string getMenor();
	void setMenor(string newMenor);
	void calcularMenor(int num_palabras);
protected:
};