/***********************************************************************
 * Module:  Tablero.cpp
 * Author:  fleia
 * Modified: Monday, January 20, 2020 ‏‎8:49:14 AM
 * Purpose: Implementation of the class Tablero
 ***********************************************************************/

#include "Tablero.h"
#include "Validacion.h"
#include <string>
using namespace std;

Validacion validacion;

////////////////////////////////////////////////////////////////////////
// Name:       Tablero::moverRey(Cuadricula* rey, Cuadricula* nuevaPosicion)
// Purpose:    Implementation of Tablero::moverRey()
// Parameters:
// - rey
// - nuevaPosicion
// Return:     bool
////////////////////////////////////////////////////////////////////////

bool Tablero::moverRey(Cuadricula* rey, Cuadricula* posicion) {
	if (abs(posicion->getX() - rey->getX()) == 1)
		if (abs(posicion->getY() - rey->getY()) == 1)
		{
			posicion->setEspacio(rey);
			rey->setVacio();
			return true;
		}
		else return false;
	else return false;
}

////////////////////////////////////////////////////////////////////////
// Name:       Tablero::moverReina(Cuadricula* reina, Cuadricula* nuevaPosicion)
// Purpose:    Implementation of Tablero::moverReina()
// Parameters:
// - reina
// - nuevaPosicion
// Return:     bool
////////////////////////////////////////////////////////////////////////

bool Tablero::moverReina(Cuadricula* reina, Cuadricula* posicion) {

	int reinaX = reina->getX();
	int reinaY = reina->getY();
	int posicionX = posicion->getX();
	int posicionY = posicion->getY();
	int yIncremento;
	int xIncremento;

	bool invalido = false;
	if (reinaX != posicionX || reinaY != posicionY)
	{

		if (reinaX == posicionX)
		{
			yIncremento = (posicionY - reinaY) / (abs(posicionY - reinaY));
			for (int i = reinaY + yIncremento; i != posicionY; i += yIncremento)
			{
				if ((*(*(cuadricula + posicionX) + i)).getColor() != NINGUNO)
					return false;

			}
		}
		else
			if (reinaY == posicionY)
			{

				xIncremento = (posicionX - reinaX) / (abs(posicionX - reinaX));
				for (int i = reinaX + xIncremento; i != posicionX; i += xIncremento)
				{
					if ((*(*(cuadricula + i) + posicionY)).getColor() != NINGUNO)
						return false;
				}
			}
			else
				if (abs(reinaX - posicionX) == abs(reinaY - posicionY))
				{
					xIncremento = (posicionX - reinaX) / (abs(posicionX - reinaX));
					yIncremento = (posicionY - reinaY) / (abs(posicionY - reinaY));

					for (int i = 1; i < abs(reinaX - posicionX); i++)
					{
						if ((*(*(cuadricula + reinaX + xIncremento * i) + reinaY + yIncremento * i)).getColor() != NINGUNO)
							return false;

					}
				}
				else
					return false;
	}

	if (invalido == false)
	{
		posicion->setEspacio(reina);
		reina->setVacio();
		return true;
	}
	else
	{
		return false;
	}
}

////////////////////////////////////////////////////////////////////////
// Name:       Tablero::moverAlfil(Cuadricula* alfil, Cuadricula* nuevaPosicion)
// Purpose:    Implementation of Tablero::moverAlfil()
// Parameters:
// - alfil
// - nuevaPosicion
// Return:     bool
////////////////////////////////////////////////////////////////////////

bool Tablero::moverAlfil(Cuadricula* alfil, Cuadricula* posicion) {
	int alfilX = alfil->getX();
	int alfilY = alfil->getY();
	int posicionX = posicion->getX();
	int posicionY = posicion->getY();
	bool invalido = false;
	Cuadricula* s;
	if (abs(alfilX - posicionX) == abs(alfilY - posicionY))
	{
		int xIncrement = (posicionX - alfilX) / (abs(posicionX - alfilX));
		int yIncrement = (posicionY - alfilY) / (abs(posicionY - alfilY));

		for (int i = 1; i < abs(alfilX - posicionX); i++)
		{
			if ((*(*(cuadricula + alfilX + xIncrement * i) + alfilY + yIncrement * i)).getColor() != NINGUNO)
				return false;
		}
	}
	else
		return false;

	if (invalido == false)
	{
		posicion->setEspacio(alfil);
		alfil->setVacio();
		return true;
	}
	else
	{
		return false;
	}
}

////////////////////////////////////////////////////////////////////////
// Name:       Tablero::moverCaballo(Cuadricula* caballo, Cuadricula* nuevaPosicion)
// Purpose:    Implementation of Tablero::moverCaballo()
// Parameters:
// - caballo
// - nuevaPosicion
// Return:     bool
////////////////////////////////////////////////////////////////////////


bool Tablero::moverCaballo(Cuadricula* caballo, Cuadricula* posicion)
{
	int caballoX = caballo->getX();
	int caballoY = caballo->getY();
	int posicionX = posicion->getX();
	int posicionY = posicion->getY();

	if ((abs(caballoX - posicionX) == 2 && abs(caballoY - posicionY) == 1) || (abs(caballoX - posicionX) == 1 && abs(caballoY - posicionY) == 2))
	{
		posicion->setEspacio(caballo);
		caballo->setVacio();
		return true;
	}
	else
	{
		return false;
	}
}

////////////////////////////////////////////////////////////////////////
// Name:       Tablero::moverTorre(Cuadricula* torre, Cuadricula* nuevaPosicion)
// Purpose:    Implementation of Tablero::moverTorre()
// Parameters:
// - torre
// - nuevaPosicion
// Return:     bool
////////////////////////////////////////////////////////////////////////

bool Tablero::moverTorre(Cuadricula* torre, Cuadricula* posicion)
{
	int torreX = torre->getX();
	int torreY = torre->getY();
	int posicionX = posicion->getX();
	int posicionY = posicion->getY();
	bool invalido = false;
	if (torreX != posicionX || torreY != posicionY)
	{

		if (torreX == posicionX)
		{
			int yIncrement = (posicionY - torreY) / (abs(posicionY - torreY));
			for (int i = torreY + yIncrement; i != posicionY; i += yIncrement)
			{
				if ((*(*(cuadricula + posicionX) + i)).getColor() != NINGUNO)
					return false;

			}
		}
		else
			if (torreY == posicionY)
			{

				int xIncrement = (posicionX - torreX) / (abs(posicionX - torreX));
				for (int i = torreX + xIncrement; i != posicionX; i += xIncrement)
				{
					if ((*(*(cuadricula + i) + posicionY)).getColor() != NINGUNO)
						return false;
				}
			}
			else
				return false;
	}
	if (invalido == false)
	{
		posicion->setEspacio(torre);
		torre->setVacio();
		return true;
	}
	else
	{
		return false;
	}
}

////////////////////////////////////////////////////////////////////////
// Name:       Tablero::moverPeon(Cuadricula* peon, Cuadricula* nuevaPosicion)
// Purpose:    Implementation of Tablero::moverPeon()
// Parameters:
// - peon
// - nuevaPosicion
// Return:     bool
////////////////////////////////////////////////////////////////////////

bool Tablero::moverPeon(Cuadricula* peon, Cuadricula* posicion) {
	bool invalid = false;
	int peonX = peon->getX();
	int peonY = peon->getY();
	int posicionX = posicion->getX();
	int posicionY = posicion->getY();


	if (peon->getColor() == BLANCO)
	{

		if (peonX == posicionX && posicionY == peonY + 1 && posicion->getColor() == NINGUNO)
		{
			posicion->setEspacio(peon);
			peon->setVacio();
			return true;
		}
		else
			if ((peonX + 1 == posicionX || peonX - 1 == posicionX) && peonY + 1 == posicionY && posicion->getColor() == NEGRO)
			{
				posicion->setEspacio(peon);
				peon->setVacio();
				return true;
			}
			else
				return false;
	}
	else
		if (peon->getColor() == NEGRO)
		{
			if (peonX == posicionX && posicionY == peonY - 1 && posicion->getColor() == NINGUNO)
			{
				posicion->setEspacio(peon);
				peon->setVacio();
				return true;
			}
			else
				if ((peonX + 1 == posicionX || peonX - 1 == posicionX) && peonY - 1 == posicionY && posicion->getColor() == BLANCO)
				{
					posicion->setEspacio(peon);
					peon->setVacio();
					return true;
				}
				else
					return false;
		}
		else
			return false;
}

////////////////////////////////////////////////////////////////////////
// Name:       Tablero::moverPieza(int x1, int y1, int x2, int y2)
// Purpose:    Implementation of Tablero::moverPieza()
// Parameters:
// - x1
// - y1
// - x2
// - y2
// Return:     bool
////////////////////////////////////////////////////////////////////////

bool Tablero::moverPieza(int x1, int y1, int x2, int y2) {

	Cuadricula* origen = *(cuadricula + x1) + y1;
	Cuadricula* destino = *(cuadricula + x2) + y2;

	/*if (origen->getColor() == destino->getColor() && destino->getColor() != NINGUNO)
	{
		cout << "Movimiento invalido, reingrese." << endl;
		return false;
	}*/

	switch (origen->getPieza())
	{
	case REY:
		return moverRey(origen, destino);
		break;
	case REINA:
		return moverReina(origen, destino);
		break;
	case ALFIL:
		return moverAlfil(origen, destino);
		break;
	case CABALLO:
		return moverCaballo(origen, destino);
		break;
	case TORRE:
		return moverTorre(origen, destino);
		break;
	case PEON:
		return moverPeon(origen, destino);
		break;
	case VACIO:
		cout << "No tines una pieza en esa posicion." << endl;  return false;
		break;
	default:
		break;
	}
	return false;
}

////////////////////////////////////////////////////////////////////////
// Name:       Tablero::imprimirTablero()
// Purpose:    Implementation of Tablero::imprimirTablero()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Tablero::imprimirTablero() {
	char cuadrado = 254;
	char peonNegro = 232;
	char peonBlanco = 225;

	cout << "   y: 0  1  2  3  4  5  6  7" << endl << "x:" << endl;
	for (int i = 0; i < 8; i++)
	{
		cout << " " << i << "   ";
		for (int j = 0; j < 8; j++)
		{
			Cuadricula temp = *(*(cuadricula + i) + j);

			Pieza pieza = temp.getPieza();
			Color color = temp.getColor();

			switch (pieza)
			{
			case REY: 
				if (color == BLANCO)
					cout << " R ";
				else 
					cout << " r ";
				break;
			case REINA: 
				if (color == BLANCO)
					cout << " Q ";
				else
					cout << " q ";
				break;
			case ALFIL:
				if (color == BLANCO)
					cout << " A ";
				else 
					cout << " a ";
				break;
			case CABALLO:
				if (color == BLANCO)
					cout << " C ";
				else
					cout << " c ";
				break;
			case TORRE: 
				if (color == BLANCO)
					cout << " T ";
				else
					cout << " t ";
				break;
			case PEON: 
				if (color == BLANCO)
					cout << " " <<peonBlanco<< " ";
				else 
					cout << " " <<peonNegro << " ";
				break;
			case VACIO: cout << " " << cuadrado << " ";
				break;
			default:
				break;
			}

		}
		cout << endl;
	}
}

////////////////////////////////////////////////////////////////////////
// Name:       Tablero::generar(int dim)
// Purpose:    Implementation of Tablero::generar()
// Parameters:
// - dim
// Return:     Cuadricula**
////////////////////////////////////////////////////////////////////////

Cuadricula** Tablero::generar(int dim)
{
	Cuadricula** a = new Cuadricula * [dim];
	for (int i = 0; i < dim; ++i) {
		a[i] = new Cuadricula[dim];
	}
	return a;

}

////////////////////////////////////////////////////////////////////////
// Name:       Tablero::movimiento()
// Purpose:    Implementation of Tablero::movimiento()
// Return:     bool
////////////////////////////////////////////////////////////////////////

bool Tablero::movimiento() {

	string movimiento;
	int x1, x2, y1, y2;
	bool bandera = false;
	while (!bandera)
	{
		if (turno == BLANCO)
			cout << endl << "Turno del jugador blanco" << endl;
		else 
			cout << endl << "Turno del jugador negro" << endl;


		cout << "Escriba su movimiento como una cadena de 4 caracteres. Escriba la coordenada de x primero. Ej: \"0102\"" << endl;
		cin >> movimiento;
		movimiento = validacion.soloNumeros(movimiento);
		movimiento = validacion.dentroDeLimites(movimiento);

		x1 = movimiento.at(0) - 48;
		y1 = movimiento.at(1) - 48;
		x2 = movimiento.at(2) - 48;
		y2 = movimiento.at(3) - 48;

		if ((*(cuadricula + x1) + y1)->getColor() == turno)
		{


			if (moverPieza(x1, y1, x2, y2) == false)
			{
				cout << "Movimiento invalido, reingrese." << endl;
			}
			else
				bandera = true;
		}
		else
			cout << "Esa no es tu pieza, reingrese." << endl;
	}

	if ((*(cuadricula + x2) + y2)->getPieza() == REY)
		if ((*(cuadricula + x1) + y1)->getColor() == BLANCO)
		{
			cout << "BLANCO GANA" << endl;
			return false;
		}
		else

		{
			cout << "NEGRO GANA" << endl;
			return false;
		}


	if (turno == NEGRO)
		turno = BLANCO;
	else
		turno = NEGRO;

	return true;

}

////////////////////////////////////////////////////////////////////////
// Name:       Tablero::inicializarTablero()
// Purpose:    Implementation of Tablero::inicializarTablero()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Tablero::inicializarTablero()
{
	(*(*(cuadricula))).setPiezaYColor(TORRE, BLANCO);
	(*(*(cuadricula + 1))).setPiezaYColor(CABALLO, BLANCO);
	(*(*(cuadricula + 2))).setPiezaYColor(ALFIL, BLANCO);
	(*(*(cuadricula + 3))).setPiezaYColor(REINA, BLANCO);
	(*(*(cuadricula + 4))).setPiezaYColor(REY, BLANCO);
	(*(*(cuadricula + 5))).setPiezaYColor(ALFIL, BLANCO);
	(*(*(cuadricula + 6))).setPiezaYColor(CABALLO, BLANCO);
	(*(*(cuadricula + 7))).setPiezaYColor(TORRE, BLANCO);

	(*(*(cuadricula)+7)).setPiezaYColor(TORRE, NEGRO);
	(*(*(cuadricula + 1) + 7)).setPiezaYColor(CABALLO, NEGRO);
	(*(*(cuadricula + 2) + 7)).setPiezaYColor(ALFIL, NEGRO);
	(*(*(cuadricula + 3) + 7)).setPiezaYColor(REINA, NEGRO);
	(*(*(cuadricula + 4) + 7)).setPiezaYColor(REY, NEGRO);
	(*(*(cuadricula + 5) + 7)).setPiezaYColor(ALFIL, NEGRO);
	(*(*(cuadricula + 6) + 7)).setPiezaYColor(CABALLO, NEGRO);
	(*(*(cuadricula + 7) + 7)).setPiezaYColor(TORRE, NEGRO);

	for (int i = 0; i < 8; i++)
	{
		(*(*(cuadricula + i) + 1)).setPiezaYColor(PEON, BLANCO);
		(*(*(cuadricula + i) + 6)).setPiezaYColor(PEON, NEGRO);

	}
	for (int i = 2; i < 6; i++)
	{
		for (int j = 0; j < 8; j++)
			(*(*(cuadricula + j) + i)).setPiezaYColor(VACIO, NINGUNO);
	}
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
		{
			(*(*(cuadricula + i) + j)).setX(i);
			(*(*(cuadricula + i) + j)).setY(j);
		}

}

////////////////////////////////////////////////////////////////////////
// Name:       Tablero::jugar()
// Purpose:    Implementation of Tablero::jugar()
// Return:     bool
////////////////////////////////////////////////////////////////////////

bool Tablero::jugar()
{
	system("cls");
	imprimirTablero();
	return movimiento();
}


