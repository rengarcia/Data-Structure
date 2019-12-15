#include "NumberCList.h"
#include <string>
#include <fstream>

void CircularList::insertNode(int data, bool flag) {
	NumericNode* primal;
	primal = first;

	if (first == nullptr) {
		first = new NumericNode(data, first, nullptr);
	}
	else if (flag) {
		while (primal->incoming != nullptr) {
			primal = primal->incoming;
		}
		primal->incoming = new NumericNode(data, nullptr, primal);
	}
	else {
		primal = new NumericNode(data, first, nullptr);
		first = primal;;
	}
}

void CircularList::insertIn(int data, int pos) {
	NumericNode* newNode = new NumericNode(data, nullptr, nullptr);
	NumericNode* current;
	current = first;

	for (int i = 1; i < pos; ++i) current = current->incoming;
	newNode->incoming = current->incoming;
	newNode->previous = current;

	if (current->incoming == nullptr) last = newNode;
	else current->incoming->previous = newNode;
	current->incoming = newNode;
}

void CircularList::updateCList() {
	NumericNode* current;
	current = first;

	if (first != nullptr) {
		while (current) {
			if (current->number == (current->incoming)->number) {
				(current->previous)->incoming = (current->incoming)->incoming;
				((current->incoming)->incoming)->previous = current->previous;
			}
			current = current->incoming;
		} 
	}
}

void CircularList::printCList() {
	NumericNode* current;
	current = first;

	if (first != nullptr) {
		while (current) {
			std::cout << current->number;
			current = current->incoming;
		} 
	}
}

int CircularList::getNumberOfNodes() {
	NumericNode* current;
	current = first;
	int auxCont = 0;
	if (first != nullptr) {
		while (current) {
			auxCont++;
			current = current->incoming;
		} 
	}

	return auxCont;
}

void CircularList::saveInTxt() {
	std::fstream _txtArchive;
	_txtArchive.open("Solution.txt", std::fstream::out);
	_txtArchive << "SOLUTION" << std::endl;
	for (int i = 0; i < 7; i++) {
		for (int k = 0; k < getNumberOfNodes(); k++) {
			_txtArchive << "0 ";
		}
		_txtArchive << std::endl;
	}
	
	NumericNode* current;
	current = first;
	if (first != nullptr) {
		while (current) {
			_txtArchive << current->number << " ";
			current = current->incoming;
		}
	}
}

void CircularList::encrypt() {
	std::fstream _txtArchive;
	_txtArchive.open("Solution.txt", std::fstream::app);

}

void CircularList::decrypt() {

}