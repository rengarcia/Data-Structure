/*******************************************************************
 *	Universidad de las Fuerzas Armadas ESPE
 *	Alex Chicaiza
 *	Maria Belen Ceron
 *	NRC: 2967
 *	Fecha creacion: 19/01/2020
 *	Fecha ultima modificacion:	26/01/2020
 *	Docente: Ing. Fernando Solis
******************************************************************/

/***********************************************************************
 * Module:  ABBI.h
 * Modified: Sunday, January 19, 2020 4:00:49 PM
 * Purpose: Declaration of the class ABBI
 ***********************************************************************/

#include<string>
#if !defined(__Traducctor_Arbol_Binario_ABBI_h)
#define __Traducctor_Arbol_Binario_ABBI_h

class ABBI
{
public:
   ABBI(std::string newIngles, std::string newEspanol);
   ~ABBI();
   void insertarNodo(std::string newIngles, std::string newEspanol, ABBI*& arbol);
   void imprimirNodo(void);
   void recorridoIn(ABBI* arbol);
   void recorridoPos(ABBI* arbol);
   void recorridoPre(ABBI* arbol);
   std::string buscar(ABBI* arbol, std::string palabra);
   //void imprimirArbol(ABBI* arbol, int n);

protected:
private:
   std::string ingles;
   std::string espanol;
   ABBI* izquierda;
   ABBI* derecha;

};

#endif