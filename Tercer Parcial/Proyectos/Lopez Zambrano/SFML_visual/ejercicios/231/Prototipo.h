class Prototipo
{
public:
	void insertar(Nodo** referencia, string palabra);
	void eliminarDato(Nodo** referencia, string palabra);
	void imprimir(Nodo* referencia);
   
private:
	void insertarCola(Nodo** referencia, string palabra);
	bool buscarDato(Nodo* referencia, string palabra);
};
