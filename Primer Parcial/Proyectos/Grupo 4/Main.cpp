/**
 *
 *                                      UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
 *                                          CARRERA DE INGENIERIA DE SOFTWARE
 *                                                  TERCER SEMESTRE
 *
 * PROYECTO DEL PRIMER PARCIAL
 * AUTORES: Sebastian Alvarez
 *          Renan Garcia
 * NRC:
 * FECHA DE MODIFICACION: 5/NOV/2019
 * FECHA DE ENTREGA: 7/NOV/2019
 *
 * STATUS: Finalizado
 */
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Ingreso.h"
#include "SolveHorseMoves.h"
#include <windows.h>
//#include <pthread.h>

using namespace std;

void* menuBacktracking(void*);
void* marquee(void*);
void gotoxy(int, int);

/* Driver program to test above functions */
int main()
{
	/*void* controll = NULL;
	pthread_t thread_1, thread_2;
	pthread_create(&thread_1, NULL, marquee, (void*) & thread_2);
	pthread_create(&thread_2, NULL, menuBacktracking, (void*) & thread_1);

	pthread_join(thread_1, &controll);
	pthread_join(thread_2, &controll);*/
	menuBacktracking(NULL);

	
	system("pause");
	return 0;
}

void* menuBacktracking(void* data) {
	sf::RenderWindow backtrackingWindow(sf::VideoMode(600, 600), "Backtracking solution");
	backtrackingWindow.setVisible(false);

	sf::Texture textChess;
	sf::Texture textSolution;
	sf::Sprite chess;
	sf::Sprite solution;

	SolveHorseMoves solver;
	Ingreso ingreso;
	int option;
	cout << "\n\n\n";
	cout << "**************************************************" << endl;
	cout << "      THE HORSE MOVEMENTS PROJECT           " << endl;
	cout << "**************************************************\n\n" << endl;
	cout << "    1. Iniciar                                    " << endl;
	cout << "    2. Informacion                                " << endl;
	cout << "    3. Salir                                     \n" << endl;
	cout << "**************************************************\n" << endl;
	cout << "Para continuar, ingrese su opcion:   "; 
	//int option = atoi(ingreso.ingresar("Ingrese valor entero: ").c_str());
	cin >> option;
	int N;
	switch (option) {
	case 1:
		/*Init the backtracking function and show*/
		//N = atoi(ingreso.ingresar("Ingrese valor entero para N: ").c_str());
		cout << "Ingrese el valor para N: "; cin >> N;

		switch (N) {
		case 1:
		case 2:
		case 3:
		case 4:
			cout << "The backtracking project has no solution" << endl;
			break;
		case 5:
			textChess.loadFromFile("Resourses/5x5.png");
			textSolution.loadFromFile("Resourses/sol5x5.png");
			break;
		case 6:
			textChess.loadFromFile("Resourses/6x6.png");
			textSolution.loadFromFile("Resourses/sol6x6.png");
			break;
		case 7:
			textChess.loadFromFile("Resourses/7x7.png");
			textSolution.loadFromFile("Resourses/sol7x7.png");
			break;
		case 8:
			textChess.loadFromFile("Resourses/8x8.png");
			textSolution.loadFromFile("Resourses/sol8x8.png");
			break;
		default:
			/*The value N is bigger or lower than the requiered*/
			cout << "The value N is bigger or lower than the requiered" << endl;
		}
		chess.setTexture(textChess);
		backtrackingWindow.setVisible(true);
		backtrackingWindow.draw(chess);
		backtrackingWindow.display();

		/*BACKTRACKING SOLUTION TO CONSOLE N' GRAPHICMODE*/
		solver.setMAX_DIM(N);
		solver.solveKT();

		Sleep(2000);
		solution.setTexture(textSolution);
		backtrackingWindow.draw(solution);
		backtrackingWindow.display();

		/*PDF creation*/
		system("java -jar dist/textToPdf.jar");
		system("pause");
		break;
	case 2:
		/*Shows the HELP window*/
		system("HELP.chm");
		break;
	case 3:
		/*The program will close*/
		cout << "Thanks for using :)" << endl;
		exit(0);
	default:
		/*The entered value is not the correct*/
		cout << "The entered value is not the correct" << endl;
		break;
	}
}

/*
void* marquee(void* data) {

	int a, b, c, n = 0, letra = 39, pos = 1, cont = 39, aux, cont1 = 39, auxg;
	char t[50] = "BACKTRACKING PROJECT, WELCOME!", auxt[39] = " ";

	for(;;){
		for (a = 0; a < 42; a++) {
			aux = pos;
			for (b = 39; b > cont; b--) {
				gotoxy(pos, 1);
				cout << t[b];
				pos--;
			}
			aux++;
			pos = aux;
			cont--;
			Sleep(75);
			if (a == 40) {
				break;
			}
		}
		for (a = 3; a < 70; a++) {
			gotoxy(a - 1, 1);
			cout << " ";
			gotoxy(a, 1);
			cout << t;
			Sleep(75);

		}

		pos = 70;
		auxg = 69;
		for (a = 0; a < 41; a++) {
			gotoxy(auxg, 1);
			cout << " ";
			aux = pos;
			for (b = 0; b <= cont1; b++) {
				gotoxy(pos, 1);
				cout << t[b];
				pos++;
			}
			cont1--;
			aux++;
			pos = aux;
			auxg++;
			Sleep(75);
		}
		cont1 = 39;
		letra = 39;
		pos = 1;
		cont = 39;
		c = 0;
	} 

	return NULL;
}

void gotoxy(int x, int y) {
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}
*/