class Prototipo
{
public:	
	void insertarCola(Nodo** referencia, int numero);
	bool buscarDato(Nodo* referencia, int numero);
	void eliminarDato(Nodo** referencia, int numero);
	void imprimir(NodoPar* referencia);
	void insertarColaPar(NodoPar** referencia, Pares par);   
};
