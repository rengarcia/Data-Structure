#include "Tetris.h"
#include <SFML/Graphics.hpp>
#include "SFML/Audio.hpp"
#include <time.h>
#include <iostream>
#include "OperacionesNodo.h"
#include "Cubo.h"
#include "Nodo.h"
using namespace sf;
using namespace std;

const int limiteAlto = 20;
const int limiteAncho = 10;

struct Point
{
	int x, y;
};

Point* encerarEstruct() {
	Point* temporal = new Point[4];
	for (int i = 0; i < 4; i++) {
		(temporal + i)->x = 0;
		(temporal + i)->y = 0;
	}
	return temporal;
}

Point* figuraBase = encerarEstruct();
Point* figuraPivot = encerarEstruct();

sf::SoundBuffer buffer;



int** encerarField() {
	int** temporal = new int* [limiteAlto];
	for (int i = 0; i < limiteAlto; ++i) {
		*(temporal + i) = new int[limiteAncho];
	}

	for (int i = 0; i < limiteAlto; i++) {
		for (int j = 0; j < limiteAncho; j++) {
			*(*(temporal + i) + j) = 0;
		}
	}

	return temporal;
}

int** field = encerarField();

bool check()
{
	for (int i = 0; i < 4; i++)
		if ((figuraBase + i)->x < 0 || (figuraBase + i)->x >= limiteAncho || (figuraBase + i)->y >= limiteAlto) return 0;

		else if (*(*(field + (figuraBase + i)->y) + (figuraBase + i)->x)) return 0;

	return 1;
};


int* numeros = new int[20];

int posicionColumna;
int posicionFila;
int auxiliarColorNum;
bool revisar;
bool seguirEnJuego = true;


void Tetris::juego()
{
	buffer.loadFromFile("Tetris.wav");

	Sound sound;
	sound.setBuffer(buffer);
	sound.play();
	sound.setLoop(10);
	sound.setVolume(10);
	sound.setAttenuation(10);

	int dimFila = 200;
	OperacionesNodo operaciones;

	Nodo* listaBase = NULL;
	Nodo* listaSuperior = NULL;

	operaciones.inicializarFila(&listaBase, dimFila);
	operaciones.inicializarFila(&listaSuperior, dimFila);

	srand(time(0));

	RenderWindow window(VideoMode(320, 480), "Tetris ");

	Texture textCubo, textFondo, textMarco, textGameOver;
	textCubo.loadFromFile("images/tiles.png");
	textFondo.loadFromFile("images/background.png");
	textGameOver.loadFromFile("images/gameOver.png");

	Sprite s(textCubo), background(textFondo), lose(textGameOver);

	int dx = 0;
	int colorNum = 1;
	float timer = 0;

	float auxDelay = 0;
	float delay = 0.2 - auxDelay;
	int contadorDificultad = 0;

	Clock clock;


	int x = 20;
	for (int i = 0; i < 20; i++) {
		*(numeros + i) = x;
		x--;
	}


	while (window.isOpen() && seguirEnJuego)
	{

		revisar = false;
		float time = clock.getElapsedTime().asSeconds();
		clock.restart();
		timer += time;

		Event e;
		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
				window.close();

			if (e.type == Event::KeyPressed)
				if (e.key.code == Keyboard::Left) dx = -1;
				else if (e.key.code == Keyboard::Right) dx = 1;
		}

		if (Keyboard::isKeyPressed(Keyboard::Down)) delay = 0.05;

		//// <- Move -> ///

		for (int i = 0; i < 4; i++) {
			*(figuraPivot + i) = *(figuraBase + i);
			(figuraBase + i)->x += dx;
		}

		if (!check()) {
			for (int i = 0; i < 4; i++) {
				*(figuraBase + i) = *(figuraPivot + i);
			}
		}


		///////Tick//////
		if (timer > delay)
		{
			for (int i = 0; i < 4; i++) {
				*(figuraPivot + i) = *(figuraBase + i);

				(figuraBase + i)->y += 1;
			}

			if (!check())
			{
				for (int i = 0; i < 4; i++) {
					*(*(field + (figuraPivot + i)->y) + (figuraPivot + i)->x) = colorNum;
				}

				colorNum = 1 + rand() % 7;
				//coloNum=1;

				for (int i = 0; i < 4; i++)
				{
					(figuraBase + i)->x = 4;
					(figuraBase + i)->y = 1;
				}

				posicionColumna = (posicionColumna + 18) / 18;
				posicionFila = (posicionFila + 18) / 18;
				posicionFila = *(numeros + posicionFila - 1);

				cout << "Fila: " << posicionFila << endl;
				cout << "Columna: " << posicionColumna << endl;
				cout << auxiliarColorNum;

				operaciones.insertarDatoPorPosicion(listaBase, posicionFila, posicionColumna, auxiliarColorNum);
				revisar = true;

				cout << endl;

				//aqui reviso las filas
				operaciones.verificacionHorizontal(listaBase);
				operaciones.verificacionVertical(listaBase);
				operaciones.imprimir(listaBase);
				operaciones.imprimirTxt(listaBase);
				contadorDificultad++;

				bool banderaDificultad = false;

				if (auxDelay <= 0.15) {
					banderaDificultad = true;
				}

				if (contadorDificultad == 2 && banderaDificultad) {
					auxDelay += 0.01;
					contadorDificultad = 0;
				}
			}
			timer = 0;
		}

		///////check lines//////////
		Cubo cuboBase;
		Cubo cuboPivot;
		class Nodo* temporalBase = listaBase;
		class Nodo* temporalPivot = listaBase;
		int i_posision, j_posicion;

		if (revisar) {

			int i = 0;
			while (i < 10) {
				temporalPivot = temporalPivot->getSiguiente();
				i++;
			}

			while (temporalBase->getSiguiente() != listaBase)
			{
				cuboPivot = temporalPivot->getCubo();
				cuboBase = temporalBase->getCubo();
				i_posision = *(numeros + cuboBase.getFila());

				j_posicion = cuboBase.getColumna() - 1;

				if (cuboBase.getValor() != cuboPivot.getValor() && cuboBase.getValor() == -1) {

					int auxFila = i_posision;
					int auxVector;
					for (auxFila; auxFila > 0; auxFila--) {
						*(*(field + auxFila) + j_posicion) = *(*(field + auxFila - 1) + j_posicion);
						auxVector = *(numeros + auxFila);
						operaciones.insertarDatoPorPosicion(listaBase, auxVector, cuboBase.getColumna(), *(*(field + auxFila - 1) + j_posicion));
					}
				}

				if (cuboBase.getValor() == cuboPivot.getValor() && cuboBase.getValor() != 0) {
					int auxFila = i_posision;
					int auxVector;
					for (auxFila; auxFila > 2; auxFila--) {
						*(*(field + auxFila) + j_posicion) = *(*(field + auxFila - 2) + j_posicion);
						auxVector = *(numeros + auxFila);
						operaciones.insertarDatoPorPosicion(listaBase, auxVector, cuboBase.getColumna(), *(*(field + auxFila - 2) + j_posicion));
					}
				}
				temporalBase = temporalBase->getSiguiente();
				temporalPivot = temporalPivot->getSiguiente();
			}


		}

		dx = 0; delay = 0.2 - auxDelay;

		/////////draw//////////
		window.clear(Color::White);
		window.draw(background);

		for (int i = 0; i < limiteAlto; i++)
			for (int j = 0; j < limiteAncho; j++)
			{
				if (*(*(field + i) + j) == 0) continue;
				s.setTextureRect(IntRect(*(*(field + i) + j) * 18, 0, 18, 18));

				s.setPosition(j * 18, i * 18);
				s.move(28, 31); //offset
				window.draw(s);
			}

		for (int i = 0; i < 4; i++)
		{
			posicionColumna = (figuraBase + i)->x * 18;
			posicionFila = (figuraBase + i)->y * 18;

			s.setTextureRect(IntRect(colorNum * 18, 0, 18, 18));
			s.setPosition((figuraBase + i)->x * 18, (figuraBase + i)->y * 18);

			s.move(28, 31); //offset
			window.draw(s);
		}

		auxiliarColorNum = colorNum;
		window.display();

		seguirEnJuego = operaciones.seguirEnJuego(listaBase);

		if (seguirEnJuego == false) {
			lose.move(0, 100);
			window.draw(lose);
			window.display();
			sound.pause();
			system("pause");
		}
	}

	if (seguirEnJuego == false) {
		cout << "Perdiste Perro";
	}
}
