#include <string>
using namespace std;

class Nodo
{
public:
	Nodo* getSiguiente(void);
	void setSiguiente(Nodo* newSiguiente);
	string getPalabra(void);
	void setPalabra(string newPersona);

private:
	Nodo* siguiente;
	string palabra;

};

