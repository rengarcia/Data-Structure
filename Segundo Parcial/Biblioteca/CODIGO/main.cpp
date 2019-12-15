/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 2967                                                       *
******************************************************************/

#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <fstream>

#include "Ingreso.h"
#include "ListaDobleCircular.h"
#include "Libro.h"
#include "Autor.h"
#include "Persona.h"
#include "Pais.h"
#include "Editorial.h"

#define ARRIBA     72
#define ABAJO      80
#define ENTER      13


void gotoxy(short posicionx, short posiciony);
void menu();
void biblioteca(int opcion,ListaDobleCircular *lista,int &idLibro);
Libro ingresarLibro(int &id);
Autor ingresarAutor();
Persona ingresarPersona();
Pais ingresarPais();
Editorial ingresarEditorial();

using namespace std;

int main()
{

    fstream enter;

    ListaDobleCircular *lista=new ListaDobleCircular();
	int posX = 4;
	int posY = 6;
	int posMaxY=12;
	bool bandera = true;
	int idLibro=1;

    enter.open("BIBIOTECA.txt", fstream::out);
	enter << "Lista Dobles" << endl;
	enter << "Lista de libros" << endl;
	

	do{
		system("cls");
		std::cout << "\n\t BIBLIOTECA \n\tLISTAS DOBLES";
		menu();
		gotoxy(posX, posY);
		cout << "=>";
			switch (_getch())
			{
			case ARRIBA:
				posY--;
				if (posY < 6) {
					posY = posMaxY;
				}
				break;
			case ABAJO:
				posY++;
				if (posY > posMaxY) {
					posY = 6;
				}
				break;

			case ENTER:
				if (posY == posMaxY) {
					bandera = false;
				}
				else {
					biblioteca(posY,lista,idLibro);
				}
				break;
			}
	} while (bandera);

	enter.close();
	
	return 0;
}

void gotoxy(short posicionx, short posiciony) {
	COORD coordenadaPosicion = { posicionx, posiciony };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordenadaPosicion);
}


void menu() {
	int posX = 7;
	int posY = 6;
	gotoxy(posX, posY++);cout << "INGRESAR INICIO";
	gotoxy(posX, posY++);cout << "INGRESAR FINAL";
	gotoxy(posX, posY++);cout << "INGRESAR POSICION";
	gotoxy(posX, posY++);cout << "MODIFICAR POR ID";
	gotoxy(posX, posY++);cout << "ELIMINAR POR ID";
	gotoxy(posX, posY++);cout << "IMPRIMIR";
	gotoxy(posX, posY++);cout << "SALIR";

}
void biblioteca(int opcion, ListaDobleCircular* lista, int &idLibro) {

    Ingreso leer;
    bool bandera;
	system("cls");

	int idModificar=0;
	int aux;
	switch (opcion)
	{
	case 6:
	    //INGRESO AL INICIO
	    cout << "\n\tINGRESO AL INICIO\n\n";
	    lista->insertarInicio(ingresarLibro(idLibro));
		break;
	case 7:
	    //INGRESO AL FINAL
	    cout << "\n\tINGRESO AL FINAL\n\n";
	    lista->insertarFinal(ingresarLibro(idLibro));
		break;
    case 8:
	    //INGRESO AL POSICION
	    cout << "\n\tINGRESO POR POSICION\n\n";

	    lista->insertarPosicion(1,ingresarLibro(idLibro));
		break;
    case 9:
	    //MODIFICAR
	    cout << "\n\tMODIFICAR POR ID\n\n";
	    do{
            bandera=false;
            idModificar=atoi(leer.ingresoNumero("  Ingrese el ID:"));
            if(lista->buscarPosicionLibroId(idModificar)==-1){
                cout<<" ID NO ENCOTRADO\n";
                cout<<" ENTER para ingresar o ESC para salir\n";
                switch(getch()){
                case 13:
                        bandera=true;
                        break;
                }
            }
	    }while(bandera);
	    aux=idModificar;
        lista->modificarPorId(aux,ingresarLibro(idModificar));
		break;
    case 10:
	    //ELIMINAR
	    cout << "\n\tELIMINAR POR ID\n\n";
	    do{
            bandera=false;
            idModificar=atoi(leer.ingresoNumero("  Ingrese el ID:"));
            if(lista->buscarPosicionLibroId(idModificar)==-1){
                cout<<"\n ID NO ENCOTRADO\n";
                cout<<" ENTER para ingresar o ESC para salir\n";
                switch(getch()){
                case 13:
                        bandera=true;
                        break;
                }
            }
	    }while(bandera);
        lista->eliminar(idModificar);
	    break;
    case 11:
	    //IMPRIMIR
	    cout << "\n\tIMPRESION DE DATOS DE LA LISTA\n\n";
	    lista->imprimir();
		break;
	default:
		break;
	}

	system("pause");

}

Libro ingresarLibro(int &id){
    Ingreso leer;
    Libro libro;

    cout<<"\nINGRESE LOS DATOS\n";
    cout<<"  ID del Libro: "<<id<<endl;
    libro.setIdLibro(id);
    libro.setNombreLibro(leer.ingresoCadena("  Nombre del Libro:"));cout<<endl;

    Autor autor=ingresarAutor();
    Editorial editorial=ingresarEditorial();
    Pais pais=ingresarPais();

    libro.setAutor(autor);
    libro.setEditorial(editorial);
    libro.setPais(pais);
    id++;
    return libro;
}

Autor ingresarAutor(){
    Autor autor;
    Ingreso leer;
    cout<<"\nDATOS AUTOR\n";
    Persona persona=ingresarPersona();
    autor.setPersona(persona);
    autor.setNumPublicacion(atoi(leer.ingresoNumero("  Num Publicacion:")));cout<<endl;

    return autor;
}

Persona ingresarPersona(){
    Persona persona;
    Ingreso leer;
    persona.setId(leer.ingresoNumero("  Cedula:"));cout<<endl;
    persona.setNombre(leer.ingresoCadena("  Nombre:"));cout<<endl;
    persona.setApellido(leer.ingresoCadena("  Apellido:"));cout<<endl;
    persona.setCorreo(leer.ingresoCorreo("  Correo:"));cout<<endl;

    return persona;
}

Pais ingresarPais(){
    Pais pais;
    Ingreso leer;
    cout<<"\nDATOS DEL PAIS\n";
    pais.setIdPais(atoi(leer.ingresoNumero("  Id del Pais:")));cout<<endl;
    pais.setNombrePais(leer.ingresoCadena("  Nombre del Pais:"));cout<<endl;
    pais.setNacionalidad(leer.ingresoCadena("  Nacionalidad: "));cout<<endl;

    return pais;
}

Editorial ingresarEditorial(){
    Editorial editorial;
    Ingreso leer;
    cout<<"\nDATOS DE LA EDITORIAL\n";
    editorial.setIdEditorial(atoi(leer.ingresoNumero("  ID Iditorial")));cout<<endl;
    editorial.setNombreEditorial(leer.ingresoCadena("  Nombre:"));cout<<endl;
    editorial.setContactoEditorial(leer.ingresoNumero("  Telefono:"));cout<<endl;

    return editorial;
}

