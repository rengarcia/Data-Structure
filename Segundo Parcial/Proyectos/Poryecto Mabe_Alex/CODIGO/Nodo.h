/**************************************************************
 *	Universidad de las Fuerzas Armadas ESPE
 *	Maria Belen Ceron, Alex Chicaiza
 *	NRC: 2967
 *	Fecha creacion: 08/11/2019
 *	Fecha ultima modificacion:	12/12/2019
 *	Docente: Ing. Fernando Solis
***************************************************************/


#if !defined(__Tetris_Nodo_h)
#define __Tetris_Nodo_h
class Nodo
{
public:
    Nodo();
    ~Nodo();
    void setNumero(int);
    int getNumero();
    void setAnteriorDireccion(Nodo*);
    Nodo* getAnteriorDireccion();
    void setSiguienteDireccion(Nodo*);
    Nodo* getSiguienteDireccion();
private:
    int numero;
    Nodo* anteriorDireccion;
    Nodo* siguienteDireccion;

};
#endif
