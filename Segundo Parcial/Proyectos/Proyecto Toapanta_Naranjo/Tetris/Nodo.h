/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS                   *
*                        ESPE                                     *
*TRABAJO EN GRUPO:                                                *
*          NOMBRES:ANTONI TOAPANTA                                *
*                   JONNY NARANJO                                 *
*MATERIA: ESTRUCTURA DE DATOS                                     *
*NRC:2967                                                         *
*Fecha de Creacion:09/12/2019                                     *
******************************************************************/

#if !defined(__Class_Diagram_1_Nodo_h)
#define __Class_Diagram_1_Nodo_h


class Nodo
{
public:
    int getDatos(void);
    void setDatos(int newDatos);
    Nodo *getSiguiente(void);
    void setSiguiente(Nodo* newSiguiente);
    Nodo *getAnterior(void);
    void setAnterior(Nodo* newAnterior);
    Nodo();
protected:
private:
    int datos;
    Nodo *siguiente;
    Nodo *anterior;
};

#endif
