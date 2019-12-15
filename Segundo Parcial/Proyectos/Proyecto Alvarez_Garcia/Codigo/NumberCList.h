#pragma once
#include <iostream>
#include <string>
#include <fstream>

class NumericNode {
private:
	int number;
	NumericNode* incoming;
	NumericNode* previous;

	friend class CircularList;
public:
	NumericNode(int data, NumericNode* nI, NumericNode* nP) 
	{
		incoming = nI; previous = nP; number = data;
	}
};

class CircularList {
private:
	NumericNode* first;
	NumericNode* last;

public:
	CircularList() { first = last = nullptr; }
	void insertNode(int data, bool flag);
	void insertIn(int data, int pos);
	void updateCList();
	void printCList();
	int getNumberOfNodes();
	void saveInTxt();
	void encrypt();
	void decrypt();
};