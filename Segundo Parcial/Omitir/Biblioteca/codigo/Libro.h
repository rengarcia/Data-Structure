/***********************************************************************
 * Module:  Libro.h
 * Author:  NICKOLAS
 * Modified: sábado, 23 de noviembre de 2019 20:20:06
 * Purpose: Declaration of the class Libro
 ***********************************************************************/

#if !defined(__UML_Class_Diagram_2_Libro_h)
#define __UML_Class_Diagram_2_Libro_h

#include <Autor.h>

class Libro
{
public:
   bool Disponibilidad(void);
   int getidLibro(void);
   void setidLibro(int newIdLibro);
   string gettitulo(void);
   void settitulo(string newTitulo);
   Autor getautor(void);
   void setautor(Autor newAutor);
   string getfechaPublicacion(void);
   void setfechaPublicacion(string newFechaPublicacion);
   string getgenero(void);
   void setgenero(string newGenero);
   int getedicion(void);
   void setedicion(int newEdicion);
   string geteditorial(void);
   void seteditorial(string newEditorial);
   int getpaginas(void);
   void setpaginas(int newPaginas);
   string getlugarPublicacion(void);
   void setlugarPublicacion(string newLugarPublicacion);
   Libro();

protected:
private:
   int idLibro;
   string titulo;
   Autor autor;
   string fechaPublicacion;
   string genero;
   int edicion;
   string editorial;
   int paginas;
   string lugarPublicacion;


};

#endif