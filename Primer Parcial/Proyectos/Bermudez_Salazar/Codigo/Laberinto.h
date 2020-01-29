/***********************************************************************
 * Module:  Laberinto.h
 * Author:  Alan
 * Modified: sábado, 02 de noviembre de 2019 11:21:49
 * Purpose: Declaration of the class Laberinto
 ***********************************************************************/

#if !defined(__Indiana_Croft_Laberinto_h)
#define __Indiana_Croft_Laberinto_h
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;


class Laberinto
{
public:
   Laberinto(int filas, int columnas);
   ~Laberinto();
   int** getLaberinto(void);
   void imprimir(void);

protected:
private:
   int filas;
   int columnas;
   int** laberinto;


};



#endif
