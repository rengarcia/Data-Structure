#include "NodoPar.h"

NodoPar* NodoPar::getSiguiente(void)
{
	return siguiente;
}

void NodoPar::setSiguiente(NodoPar* newSiguiente)
{
	siguiente = newSiguiente;
}

Pares NodoPar::getPar(void)
{
	return par;
}

void NodoPar::setPar(Pares newPar)
{
	par = newPar;
}
