#include "Pares.h" 

class NodoPar
{
public:
	NodoPar* getSiguiente(void);
	void setSiguiente(NodoPar* newSiguiente);
	Pares getPar(void);
	void setPar(Pares newPar);

private:
	NodoPar* siguiente;
	Pares par;
};

