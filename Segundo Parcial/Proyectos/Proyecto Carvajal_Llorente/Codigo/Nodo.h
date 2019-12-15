/**
	Universidad de las Fuerzas Armadas ESPE
    Nombre: Luis Carvajal, Elian Llorente
    NRC: 2967
    Fecha creacion: 30/11/2019
	Fecha ultima modificacion:	12/12/2019
	Docente: Ing. Fernando Solis
*/
class Nodo
{
	private:
		int numero;
		Nodo* anteriorDireccion;
		Nodo* siguienteDireccion;
	public:
		void setNumero(int);
		int getNumero();
		void setAnteriorDireccion(Nodo*);
		Nodo* getAnteriorDireccion();
		void setSiguienteDireccion(Nodo*);
		Nodo* getSiguienteDireccion();
};

void Nodo::setNumero(int numero_)
{
	numero=numero_;
}

int Nodo::getNumero()
{
	return numero;
}

void Nodo::setAnteriorDireccion(Nodo* anteriorDireccion_)
{
	anteriorDireccion=anteriorDireccion_;
}

Nodo* Nodo::getAnteriorDireccion()
{
	return anteriorDireccion;
}

void Nodo::setSiguienteDireccion(Nodo* siguienteDireccion_)
{
	siguienteDireccion=siguienteDireccion_;
}

Nodo* Nodo::getSiguienteDireccion()
{
	return siguienteDireccion;
}
