/***********************************************************************
 * Module:  Busqueda.h
 * Author:  Sashael
 * Modified: sábado, 9 de noviembre de 2019 17:34:53
 * Purpose: Declaration of the class Busqueda
 ***********************************************************************/
/***********************************************************************
 * Module:  Busqueda.java
 * Author:  Sashael
 * Purpose: Defines the Class Busqueda
 ***********************************************************************/

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
