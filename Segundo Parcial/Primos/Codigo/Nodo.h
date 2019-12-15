/**
	Universidad de las Fuerzas Armadas ESPE
	Estructura de Datos
	NRC: 2967
	Docente: Ing. Fernando Solis
*/

#if !defined(__NumeroPrimo2_Nodo_h)
#define __NumeroPrimo2_Nodo_h

class Nodo
{
public:
    Nodo();
    Nodo(int newNumero, Nodo *newSiguiente);
   ~Nodo();
   Nodo *getSiguiente(void);
   void setSiguiente(Nodo *newSiguiente);
   int getNumero(void);
   void setNumero(int newNumero);
protected:
private:
   int numero;
   Nodo *siguiente;
};

#endif
