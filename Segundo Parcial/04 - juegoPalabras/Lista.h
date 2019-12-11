#include <iostream>


using namespace std;


class Nodo
{
	private:
		string palabra;
		Nodo *siguiente;
		
		friend class Lista;
	public:
		void setPalabra(string newPalabra){
			palabra=newPalabra;
		}
		string getPalabra(){
			return palabra;
		}
		
};

class Lista
{
	private:
		Nodo *primero;
	public:
		Lista();
		void ingresarDatoFinal(string palabra);
		void borrarPrimerElemento();	
		bool verificarCadena(string palabra);
		string obtenerUltimaPalabra(string frase);
		~Lista();
		Nodo* getPrimero();
		void imprimir();
};
