/**
	Universidad de las Fuerzas Armadas ESPE
    Alex Chicaiza, Maria Belen Ceron
    NRC: 2967
    Fecha creacion: 26/10/2019
	Fecha ultima modificacion:	7/11/2019
	Docente: Ing. Solis
*/
/***********************************************************************
 * Module:  Arreglo.h
 * Author:  Alex Chicaiza, Maria Belen Ceron
 * Modified: Tuesday, November 5, 2019 10:35:18 PM
 * Purpose: Declaration of the class Arreglo
 ***********************************************************************/

#if !defined(__Class_Diagram_1_Arreglo_h)
#define __Class_Diagram_1_Arreglo_h

class Arreglo
{
public:
   Arreglo();
   ~Arreglo();
   int tamanioCadena(char * frase);
   void invertirCadena(char * frase, char* fraseInvertida, int inicio, int fin);

protected:
private:

};

#endif
