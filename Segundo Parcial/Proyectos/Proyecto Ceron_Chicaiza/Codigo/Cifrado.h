#pragma once
#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include<string>


using namespace std;

class Cifrado
{
public:
	void encriptado();
	void desencriptado();
private:
	FILE* archivo, * nuevo;

};

