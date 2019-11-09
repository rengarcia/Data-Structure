/***********************************************************************
 * Module:  Tablero.h
 * Author:  kevin
 * Modified: Saturday, November 9, 2019 12:18:37 PM
 * Purpose: Declaration of the class Tablero
 ***********************************************************************/

#if !defined(__PuzleDeslizar2_Tablero_h)
#define __PuzleDeslizar2_Tablero_h

class Tablero
{
public:
   Tablero(int filas, int columnas);
   ~Tablero();
   void inicializar(int filas, int columnas);
   void mover(int filaActual, int columnaActual, int filaNueva, int columnaNueva);
   void llenar(int filas, int columnas);
   void desordenar(int filas, int columnas);
   void imprimir(int filas, int columnas);
   bool verificar(int filas, int columnas);
   int buscarColumna(int filas, int columnas);
   int buscarFila(int filas, int columnas);   
   int** getMatriz(void);
   void setMatriz(int** newMatriz);

protected:
private:
   int** matriz;


};

#endif
