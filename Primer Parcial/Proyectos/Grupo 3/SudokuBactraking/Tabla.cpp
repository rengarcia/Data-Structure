/**
    *@file Tabla.cpp
    *@version 2.0
    *@author Antoni Toapanta
    *@title Funciones de la Clase Tabla
    *@brief Implementacion de los metos de la Clase Tabla
    */
/***********************************************************************
 * Module:  Tabla.cpp
 * Author:  RODRIGO
 * Modified: miércoles, 6 de noviembre de 2019 02:01:52
 * Purpose: Implementation of the class Tabla
 ***********************************************************************/

#include "Tabla.h"
#include "ManejoMemoria.h"
/**
    @brief Busaca la posisicon donde puede hacer el cambio
    @param Fila,Columna
    @return Verdadero si encuentra un 0 donde puede hacer el cambio si no un falso
    */
bool Tabla::buscarLugar(int& fila, int& col)
{
    for (fila = 0; fila < 9; fila++)
        for (col = 0; col < 9; col++)
            if (*(*(tablero+fila)+col) == 0)
                return true;
    return false;
}
/**
    @brief Comprueba si cumple las condiciones de Sudoku
    @param Fila,Columna,num
    @return Verdadero si cumple  si no un falso
    */
bool Tabla::comprobar( int fila, int col, int num)
{
    return !UtilizadoEnFila(fila, num) &&!UtilizadoEnColumna(col, num) &&!UtilizadoEnSudoku(fila - fila % 3 ,col - col % 3, num) &&*(*(tablero+fila)+col)== 0;
}
/**
    @brief Muestra el Sudoku y guarda informacion en el .csv
    */
void Tabla::mostrarT()
{
    mostrar(tablero,9,9);
}
/**
    @brief Obtiene tablero
    */

int** Tabla::getTablero(void)
{
   return tablero;
}
/**
    @brief Camcio de tablero
    */

void Tabla::setTablero(int** newTablero)
{
   tablero = newTablero;
}

/**
    @brief Constructor de la Clase
    */
Tabla::Tabla()
{
    this->tablero=reservar(9,9);
    encerar(this->tablero,9,9);
}

/**
    @brief Destructor de la clase
    */
Tabla::~Tabla()
{
    liberarMemoria(this->tablero,9);
}

bool Tabla::Sudoku()
{
    int fila, col;
    if (!buscarLugar(fila, col))
    return true;

    for (int num = 1; num <= 9; num++)
    {
        if (comprobar(fila, col, num))
        {
            *(*(tablero+fila)+col) = num;
            escribirArchivo(tablero,9);
            cout<<endl;
            if (Sudoku())
                return true;
            *(*(tablero+fila)+col)= 0;
        }
    }
    return false;
}
bool Tabla::UtilizadoEnFila(int fila, int num)
{

    for (int col = 0; col < 9; col++)
        if (*(*(tablero+fila)+col)== num)
            return true;
    return false;
}


bool Tabla::UtilizadoEnColumna(int col, int num)
{
for (int fila = 0; fila < 9; fila++)
        if (*(*(tablero+fila)+col) == num)
            return true;
    return false;
}

bool Tabla::UtilizadoEnSudoku(int inicioFila, int inicioColumna, int num)
{
    for (int fila = 0;  fila< 3; fila++)
        for (int col = 0; col < 3; col++)
            if (*(*(tablero+(fila + inicioFila))+(col + inicioColumna)) == num)
                return true;
    return false;
}
