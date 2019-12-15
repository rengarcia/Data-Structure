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

#if !defined(__Class_Diagram_1_Piezas_h)
#define __Class_Diagram_1_Piezas_h

class Piezas
{
public:
   int getX(void);
   void setX(int newX);
   int getY(void);
   void setY(int newY);
   void pieza(int x, int y, int col);
   int unaPieza(int pieza);
   int getNum(void);
   void setNum(int n);
   int cubo1(void);
   int cubo2(void);
   int cubo3(void);
   int cubo4(void);
   int cubo5(void);
   int cubo6(void);
   int cubo7(void);
   int cubo8(void);
   int cubo9(void);
   int vacio(void);
protected:
private:
   int x;
   int y;
   int num;
};

#endif
