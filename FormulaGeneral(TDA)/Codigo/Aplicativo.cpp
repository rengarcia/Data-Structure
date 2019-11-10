#include<iostream>
#include <sstream>
#include"Formula.cpp"
#include"Raiz.cpp"
#include"Ingreso.h"

using namespace std;

int main(){
	
	Formula obj;
	Raiz obj2;
	Ingreso ingreso;
	float a,b,c;
	string dim;
	
	cout<<">Ingrese los datos (ax^2+bx+c)"<<endl;
	
		dim=ingreso.leer("Ingrese el coeficiente a",2);
    	istringstream (dim) >> a;
		obj.setNum1(a);
	

		dim=ingreso.leer("Ingrese el coeficiente b",2);
    	istringstream (dim) >> b;
		obj.setNum2(b);
	

		dim=ingreso.leer("Ingrese el coeficiente c",2);
    	istringstream (dim) >> c;
		obj.setNum3(c);
	
	obj2.calcular(obj.getNum1(),obj.getNum2(),obj.getNum3());
	
	
	return 0;
}
