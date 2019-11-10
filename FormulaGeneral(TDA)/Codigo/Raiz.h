/***********************************************************************
 * Module:  Raiz.h
 * Author:  Edison Baez
 * Modified: sábado, 9 de noviembre de 2019 12:15:09
 * Purpose: Declaration of the class Raiz
 ***********************************************************************/

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
