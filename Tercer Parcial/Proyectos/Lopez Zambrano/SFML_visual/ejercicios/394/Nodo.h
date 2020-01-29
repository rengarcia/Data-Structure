#include <string>
using namespace std;

class Nodo
{
public:
	Nodo* getSiguiente(void);
	void setSiguiente(Nodo* newSiguiente);
	int getNumero(void);
	void setNumero(int newPersona);

private:
	Nodo* siguiente;
	int numero;

};

