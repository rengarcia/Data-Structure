/**
    *@file Operaciones.cpp
    *@version 2.0
    *@author Antoni Toapanta
    *@title Funciones Principales
    *@brief Funciones Utilizadas en el Juego Sudoku
    */
/***********************************************************************
 * Module:  Operaciones.h
 * Author:  RODRIGO
 * Modified: miércoles, 6 de noviembre de 2019 01:54:07
 * Purpose: Declaration of the class Operaciones
 ***********************************************************************/

#if !defined(__Class_Diagram_1_Operaciones_h)
#define __Class_Diagram_1_Operaciones_h

class Operaciones
{
public:
    /**
    @brief Comienza a resolver el sudoku usasando Backtraking
    @param Nada
    @return Un Verdadero si se puede resolver o un falso si es imposible
    */
   virtual bool Sudoku()=0;
   /**
    @brief Comprueba si se encuentra el numero en la fila
    @param fila, numero
    @return Verdadero sis e encuentra o falso si no
    */
   virtual bool UtilizadoEnFila(int fila, int num)=0;
   /**
    @brief Comprueba si se encuentra el numero en la columna
    @param fila, numero
    @return Verdadero si se encuentra o falso si no
    */
   virtual bool UtilizadoEnColumna(int col, int num)=0;
   /**
    @brief Comprueba si se encuentra el numero en la  tanto en fila como en columna
    @param fila, numero
    @return Verdadero si  se encuentra o falso si no
    */
   virtual bool UtilizadoEnSudoku(int inicioFila, int inicioColumna, int num)=0;

protected:
private:

};

#endif
