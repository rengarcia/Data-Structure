/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 2967                                                       *
******************************************************************/
#if !defined(__FormulaGeneralModel_Raiz_h)
#define __FormulaGeneralModel_Raiz_h

class Raiz
{
public:
   void calcular(float a, float b, float c);
   float getResult1(void);
   void setResult1(float newResult1);
   float getResult2(void);
   void setResult2(float newResult2);
   Raiz();

protected:
private:
   float result1;
   float result2;


};

#endif
