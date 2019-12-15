/**
	Universidad de las Fuerzas Armadas ESPE
	Estructura de Datos
	NRC: 2967
	Docente: Ing. Fernando Solis
*/

#if !defined(__NumeroPrimo2_Lista_h)
#define __NumeroPrimo2_Lista_h

#include "Nodo.h"

class Lista
{
public:
   void InsertarInicio(int numero);
   void InsertarFinal(int numero);
   void Imprimir(void);
   int vacio(void);

protected:
private:
   Nodo *siguiente;


};

#endif
