/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS                   *
*                        ESPE                                     *
*TRABAJO EN GRUPO:                                                *
*          NOMBRES:ANTONI TOAPANTA                                *
*                   JHONY NARANJO                                 *
*MATERIA: ESTRUCTURA DE DATOS                                     *
*NRC:2967                                                         *
*Fecha de Creacion:26/01/2020                                     *
******************************************************************/
#pragma once
#if !defined(__Class_Diagram_1_Palabra_h)
#define __Class_Diagram_1_Palabra_h
#include<string>
using namespace std;
class Palabra
{
public:
   string getEspanol(void);
   void setEspanol(string newEspanol);
   string getIngles(void);
   void setIngles(string newIngles);
   int getClave(void);
   void setClave(int newClave);
   int getClaveE(void);
   void setClaveE(int newClave);
   Palabra();
   ~Palabra();

protected:
private:
   string espanol;
   string ingles;
   int clave;
   int claveE;
};

#endif
