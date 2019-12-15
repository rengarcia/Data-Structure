/***********************************************************************
 * Module:  Cubo.h
 * Author:  fleia
 * Modified: Saturday, November 30, 2019 1:35:25 PM
 * Purpose: Declaration of the class Cubo
 ***********************************************************************/

#if !defined(__proyecto_Cubo_h)
#define __proyecto_Cubo_h

class Cubo
{
public:
   int getFila(void);
   void setFila(int newFila);
   int getColumna(void);
   void setColumna(int newColumna);
   int getValor(void);
   void setValor(int newValor);

protected:
private:
   int fila;
   int columna;
   int valor;

};

#endif