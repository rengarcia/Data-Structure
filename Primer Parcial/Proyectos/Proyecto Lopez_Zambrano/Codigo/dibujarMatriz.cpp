#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "dibujarMatriz.h"


using namespace sf;
using namespace std;

Texture texturaMeta;
Texture texturaMuro;
Texture texturaCamino;
Texture texturaCaminoMalo;

const int dim_dibujo = 10;

void dibujarMatriz::DibujarNuevoTablero(int** TableroRellenado, int** TableroSolucion) {
	RenderWindow window;
	window.create(VideoMode(800, 800), "Tablero Resuelto");

	window.setKeyRepeatEnabled(false);

	if (!texturaMeta.loadFromFile("Imagenes/meta.png")) {
		cout << "Error could not load player image" << endl;
	}

	if (!texturaCamino.loadFromFile("Imagenes/cesped.png")) {
		cout << "Error could not load player image" << endl;
	}

	if (!texturaMuro.loadFromFile("Imagenes/piedra.png")) {
		cout << "Error could not load player image" << endl;
	}

	if (!texturaCaminoMalo.loadFromFile("Imagenes/malo.png")) {
		cout << "Error could not load player image" << endl;
	}

	Sprite Tablero_Rellenado[dim_dibujo][dim_dibujo];
	Sprite Tablero_Solucion[dim_dibujo][dim_dibujo];

	int h = 0;
	int k = 0;
	for (int i = 0; i < dim_dibujo; i++) {
		for (int j = 0; j < dim_dibujo; j++) {

			if (*(*(TableroRellenado + i) + j) == 0) {
				Tablero_Rellenado[i][j].setTexture(texturaMuro);
			}
			else
			{
				Tablero_Rellenado[i][j].setTexture(texturaCamino);
			}
			Tablero_Rellenado[i][j].setPosition(Vector2f(h, k));
			h = h + 32;
			if (h == 32 * dim_dibujo) {
				h = 0;
			}
		}
		k = k + 32;
	}


	int t = 0;
	int l = 0;
	for (int i = 0; i < dim_dibujo; i++) {
		for (int j = 0; j < dim_dibujo; j++) {

			if ((*(*(TableroSolucion + i) + j)) == 0 && (*(*(TableroRellenado + i) + j)) == 1) {
				Tablero_Solucion[i][j].setTexture(texturaCaminoMalo);
			}
			else if ((*(*(TableroSolucion + i) + j)) == 0 && (*(*(TableroRellenado + i) + j)) == 0) {
				Tablero_Solucion[i][j].setTexture(texturaMuro);
			}
			else
			{
				Tablero_Solucion[i][j].setTexture(texturaCamino);
			}
			Tablero_Solucion[i][j].setPosition(Vector2f(t + 350, l));
			t = t + 32;
			if (t == 32 * dim_dibujo) {
				t = 0;
			}
		}
		l = l + 32;
	}

	Tablero_Rellenado[0][0].setTexture(texturaMeta);
	Tablero_Solucion[0][0].setTexture(texturaMeta);
	Tablero_Rellenado[dim_dibujo - 1][dim_dibujo - 1].setTexture(texturaMeta);
	Tablero_Solucion[dim_dibujo - 1][dim_dibujo - 1].setTexture(texturaMeta);

	while (window.isOpen())
	{

		for (int i = 0; i < dim_dibujo; i++) {
			for (int j = 0; j < dim_dibujo; j++) {
				window.draw(Tablero_Rellenado[i][j]);
				window.draw(Tablero_Solucion[i][j]);
			}
		}

		window.display();
		system("pause");
		window.close();
	}
}
