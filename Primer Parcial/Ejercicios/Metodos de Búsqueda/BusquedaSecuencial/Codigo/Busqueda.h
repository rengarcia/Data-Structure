/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 2967                                                       *
******************************************************************/

#if !defined(__Class_Diagram_2_Busqueda_h)
#define __Class_Diagram_2_Busqueda_h

class Busqueda {
public:
    Busqueda(int* arrg, int n);
    void busquedaSecuencial(int clave);
    int* getArreglo(void);
    void setArreglo(int* newArreglo);
    int getTamanio(void);
    void setTamanio(int newTamanio);

protected:
private:
    int* arreglo;
    int tamanio;


};

#endif
