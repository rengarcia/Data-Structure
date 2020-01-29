/***********************************************************************
 * Module:  Marquesina.h
 * Author:  Kevin Duy, Carlos Puco
 * Modified: sabado, 26 de noviembre de 2019 17:21:23
 * Purpose: Declaration of the class Marquesina
 ***********************************************************************/

#include "metrics.cpp"
#include "pdf.cpp"
#include <windows.h> 

typedef void (*DemoFunction)(PDF &);

class Marquesina {
	public:
		void hacerMarquesina();
		void borrar();
};
