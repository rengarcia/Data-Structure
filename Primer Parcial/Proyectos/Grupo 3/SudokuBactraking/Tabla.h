/***********************************************************************
 * Module:  Tabla.h
 * Author:  RODRIGO
 * Modified: miércoles, 6 de noviembre de 2019 02:01:52
 * Purpose: Declaration of the class Tabla
 ***********************************************************************/

#if !defined(__Class_Diagram_1_Tabla_h)
#define __Class_Diagram_1_Tabla_h

#include "Operaciones.h"

class Tabla : public Operaciones
{
public:
   bool buscarLugar(int& fila, int& col);
   bool comprobar(int fila, int col, int num);
   void mostrarT();
   int** getTablero(void);
   void setTablero(int** newTablero);
   Tabla();
   ~Tabla();
   bool Sudoku();
   bool UtilizadoEnFila(int fila, int num);
   bool UtilizadoEnColumna(int col, int num);
   bool UtilizadoEnSudoku(int inicioFila, int inicioColumna, int num);

protected:
private:
   int** tablero;
};
#endif
