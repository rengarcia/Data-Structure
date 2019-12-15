/***********************************************************************
 * Module:  Libro.h
 * Author:  ALEX
 * Modified: Saturday, December 14, 2019 8:55:50 PM
 * Purpose: Declaration of the class Libro
 ***********************************************************************/

#if !defined(__BIBLIOTECA_LISTA_DOBLE2_Libro_h)
#define __BIBLIOTECA_LISTA_DOBLE2_Libro_h

#include "Autor.h"
#include "Pais.h"
#include "Editorial.h"

class Libro
{
public:
   Libro();
   ~Libro();
   int getIdLibro(void);
   void setIdLibro(int newIdLibro);
   std::string getNombreLibro(void);
   void setNombreLibro(std::string newNombreLibro);
   Autor getAutor(void);
   void setAutor(Autor newAutor);
   Pais getPais(void);
   void setPais(Pais newPais);
   Editorial getEditorial(void);
   void setEditorial(Editorial newEditorial);

protected:
private:
   int idLibro;
   std::string nombreLibro;
   Autor autor;
   Pais pais;
   Editorial editorial;


};

#endif
