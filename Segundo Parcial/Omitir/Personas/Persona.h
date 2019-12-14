#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <fstream>
using namespace std;
/***********************************************************************
 * Module:  Persona.h
 * Author:  Kevin Zurita
 * Modified: Thursday, November 13, 2019 10:38:09 AM
 * Purpose: Declaration of the class Persona
 ***********************************************************************/

#if !defined(__Listas2_Persona_h)
#define __Listas2_Persona_h


class Persona
{
public:
   int getidPersona(void);
   void setidPersona(int newIdPersona);
   string getcedula(void);
   void setcedula(string newCedula);
   string getnombre(void);
   void setnombre(string newNombre);
   string getapellido(void);
   void setapellido(string newApellido);
   string getCorreo(void);
   void setCorreo(string newCorreo);
   void imprimirDatos();
   void imprimirDatosPrimos();
   void setPrimos(int);
   int getPrimos();
   Persona(int, string, string, string, int, string);
   Persona();
//Es la graficacion del estado de se;ales y el  flip flop en el tiempo
protected:
private:
   int idPersona;
   string cedula;
   string nombre;
   string apellido;
   string correo;
   int primos;
};

Persona::Persona(int id, string ced, string nom, string ape, int pri, string email){
	idPersona=id;
	cedula=ced;
	nombre=nom;
	apellido=ape;
	primos=pri;
	correo=email;
}

Persona::Persona(){
	
}

void Persona::imprimirDatos(){
	cout<<"Id: "<<idPersona<<endl;
	cout<<"Cedula: "<<cedula<<endl;
	cout<<"Nombre: "<<nombre<<endl;
	cout<<"Apellido: "<<apellido<<endl;
	cout<<"Correo: "<<correo<<endl;
}

void Persona::imprimirDatosPrimos(){
	cout<<"Id: "<<idPersona<<endl;
	cout<<"Cedula: "<<cedula<<endl;
	cout<<"Nombre: "<<nombre<<endl;
	cout<<"Apellido: "<<apellido<<endl;
	cout<<"Cantidad de numeros primos en cedula: "<<primos<<endl;
}


void Persona::setPrimos(int primo){
	primos=primo;
}

int Persona::getPrimos(){
	return primos;
}

void Persona::setCorreo(string email){
	correo=email;
}

string Persona::getCorreo(){
	return correo;
}

#endif
