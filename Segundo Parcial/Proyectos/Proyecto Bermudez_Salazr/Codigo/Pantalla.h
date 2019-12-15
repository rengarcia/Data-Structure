/***********************************************************************
 * Module:  Pantalla.h
 * Author:  Alan
 * Modified: lunes, 18 de noviembre de 2019 23:20:19
 * Purpose: Declaration of the class Pantalla
 ***********************************************************************/

#if !defined(__Tetris_2_Pantalla_h)
#define __Tetris_2_Pantalla_h
#include <iostream>

using namespace std;

class Pantalla
{
public:
   void gotoxy(int x, int y);
   void dimensionPantalla(void);
   void tablero(string nombre, int numero,int puntuacion);
   void ocultarCursor();
   void borrarLinea();


protected:
    
private:
   int ancho;
   int alto;


};

#endif