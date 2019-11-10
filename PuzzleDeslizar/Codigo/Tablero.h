/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 2967                                                       *
******************************************************************/
#if !defined(__PuzleDeslizar2_Tablero_h)
#define __PuzleDeslizar2_Tablero_h

class Tablero {
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
