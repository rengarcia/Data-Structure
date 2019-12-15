#include <iostream>
#include <stdio.h>

class Jugador{
	private:
		string nombre_jugador;
		int puntaje_jugador;
	public:
		Jugador(string, int);
		Jugador();
		string getNombre();
		void setNombre(string);
		int getPuntaje();
		void setPuntaje(int);
};

Jugador::Jugador(string name, int points){
	nombre_jugador=name;
	puntaje_jugador=points;
}

Jugador::Jugador(){
}

string Jugador::getNombre(){
	return nombre_jugador;
}

void Jugador::setNombre(string name){
	nombre_jugador=name;
}

int Jugador::getPuntaje(){
	return puntaje_jugador;
}

void Jugador::setPuntaje(int points){
	puntaje_jugador=points;
}


