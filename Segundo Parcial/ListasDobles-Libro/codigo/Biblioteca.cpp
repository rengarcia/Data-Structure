/***********************************************************************
 * Module:  Biblioteca.cpp
 * Author:  NICKOLAS
 * Modified: sábado, 23 de noviembre de 2019 20:20:06
 * Purpose: Implementation of the class Biblioteca
 ***********************************************************************/

#include "Biblioteca.h"

////////////////////////////////////////////////////////////////////////
// Name:       Biblioteca::Reservarlibro()
// Purpose:    Implementation of Biblioteca::Reservarlibro()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Biblioteca::Reservarlibro(void)
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       Biblioteca::insertarInicio(Nodo*& Nodo, Libro libro)
// Purpose:    Implementation of Biblioteca::insertarInicio()
// Parameters:
// - Nodo
// - libro
// Return:     void
////////////////////////////////////////////////////////////////////////

void Biblioteca::insertarInicio(Nodo*& Nodo, Libro libro)
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       Biblioteca::borrarLibro(int idLibro)
// Purpose:    Implementation of Biblioteca::borrarLibro()
// Parameters:
// - idLibro
// Return:     void
////////////////////////////////////////////////////////////////////////

void Biblioteca::borrarLibro(int idLibro, Nodo*& nodo)
{
   Nodo *aux = new Nodo();
   aux = nodo;
   int pos = 0;
   if(aux == NULL) {
      printf("No se puede eliminar --- Lista Vacia");
      return;
   } 

   while(aux!=NULL) {
      pos++;
      
      if(aux->getlibro().getidLibro() == idLibro) {	
      	 aux->getAnterior()->setsiguiente(aux->getSiguiente());
      	 aux->getSiguiente()->setanterior(aux->getAnterior());
      	 delete aux;
      	 return;
      }
      aux = aux->getSiguiente();
   }
   printf("No existe el id", idLibro);
}

////////////////////////////////////////////////////////////////////////
// Name:       Biblioteca::buscarLibro(int idLibro)
// Purpose:    Implementation of Biblioteca::buscarLibro()
// Parameters:
// - idLibro
// Return:     void
////////////////////////////////////////////////////////////////////////

int Biblioteca::buscarLibro(Nodo *&nodo, int idLibro)
{
    Nodo *aux = new Nodo();
    aux = nodo;
    int posicion=1, cont=0;
    while(aux != NULL)
    {
        if(aux->getlibro().getidLibro() == idLibro)
        {
            cout<<"Nombre del libro: "<<aux->getlibro().gettitulo()<<endl;
            cout<<"Encontrado en la posicion: "<<posicion<<endl;
            cont++;
        }
        posicion++;
        aux = aux->getSiguiente();
    }
    if(cont==0){
        cout<<"Nombre no encontrado"<<endl;
        return 0;
    }
        return posicion;
}

////////////////////////////////////////////////////////////////////////
// Name:       Biblioteca::imprimir()
// Purpose:    Implementation of Biblioteca::imprimir()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Biblioteca::imprimir(void)
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       Biblioteca::modificarLibro(int idLibro)
// Purpose:    Implementation of Biblioteca::modificarLibro()
// Parameters:
// - idLibro
// Return:     void
////////////////////////////////////////////////////////////////////////

void Biblioteca::modificarLibro(int idLibro, Nodo*& nodo)
{
   string newTitulo;
   Autor newAutor;
   string nombreAutor;
   string newFechaPublicacion;
   string newGenero;
   int newEdicion;
   string newEditorial;
   int newPaginas;
   string newLugarPublicacion;	
	Nodo *aux = new Nodo();
    aux = nodo;
    int pos = 0;
   if(aux == NULL) {
      printf("Lista Vacia");
      return;
   } 

   while(aux!=NULL) {
      pos++;
      
      if(aux->getlibro().getidLibro() == idLibro) {
      	
      	cout << "Ingrese titulo del nuevo libro" <<endl;
      	cin >> newTitulo;
      	aux->getlibro().settitulo(newTitulo);
      	cout << "Ingrese fecha de publicacion del nuevo libro" <<endl;
      	cin >> newFechaPublicacion;
      	aux->getlibro().setfechaPublicacion(newFechaPublicacion);
      	cout << "Ingrese edicion del nuevo libro" <<endl;
      	cin >> newEdicion;
      	aux->getlibro().setedicion(newEdicion);
      	cout << "Ingrese editorial del nuevo libro" <<endl;
      	cin >> newEditorial;
      	aux->getlibro().seteditorial(newEditorial);
      	cout << "Ingrese paginas del nuevo libro" <<endl;
      	cin >> newPaginas;
      	aux->getlibro().setpaginas(newPaginas);
      	cout << "Ingrese lugar de publicacion del nuevo libro" <<endl;
      	cin >> newLugarPublicacion;
      	aux->getlibro().setlugarPublicacion(newLugarPublicacion);
      	cout << "Ingrese genero del nuevo libro" <<endl;
      	cin >> newGenero;
      	aux->getlibro().setgenero(newGenero);
    /*  	cout << "Ingrese el autor del nuevo libro" <<endl;
      	cin >> nombreAutor;
      	aux->getlibro().getautor().getautor().getautor().*/
      //   return;
      }
     aux = aux->getSiguiente();
   }
   printf("No existe el id", idLibro);
}

////////////////////////////////////////////////////////////////////////
// Name:       Biblioteca::insertarEntre(Nodo*& Nodo, Libro libro)
// Purpose:    Implementation of Biblioteca::insertarEntre()
// Parameters:
// - Nodo
// - libro
// Return:     void
////////////////////////////////////////////////////////////////////////

void Biblioteca::insertarEntre(Nodo*& Nodo, Libro libro)
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       Biblioteca::insertarFinal(Nodo*& Nodo, Libro libro)
// Purpose:    Implementation of Biblioteca::insertarFinal()
// Parameters:
// - Nodo
// - libro
// Return:     void
////////////////////////////////////////////////////////////////////////

void Biblioteca::insertarFinal(Nodo*& nodo, Libro libro)
{
  Nodo *newNodo = new Nodo();
  newNodo->setlibro(libro);
  Nodo *aux=nodo;
  Nodo *aux2;
  while(aux!=NULL)
  {
      aux2=aux;
      aux=aux->getsiguiente();
  }
  if(aux==nodo)
   {
       nodo=newNodo;
       nodo->setsiguiente(NULL);
       nodo->setanterior(NULL);
   }
   else{
        aux2->setsiguiente(newNodo);
        newNodo->setanterior(aux2);
   }
   newNodo->setsiguiente(NULL);
}
