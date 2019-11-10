/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 2967                                                       *
******************************************************************/

#if !defined(__FormulaGeneralModel_Formula_h)
#define __FormulaGeneralModel_Formula_h

class Raiz;

class Formula
{
public:
   Formula();
   float getNum1(void);
   void setNum1(float newNum1);
   float getNum2(void);
   void setNum2(float newNum2);
   float getNum3(void);
   void setNum3(float newNum3);

   Raiz* raiz;

protected:
private:
   float num1;
   float num2;
   float num3;


};

#endif
