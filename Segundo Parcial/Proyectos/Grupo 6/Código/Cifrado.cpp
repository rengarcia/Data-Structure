/***********************************************************************
 * Module:  Cifrado.cpp
 * Author:  Kevin Duy, Carlos Puco
 * Modified: sabado, 26 de octubre de 2019 17:21:23
 * Purpose: Declaration of the class Cifrado
 ***********************************************************************/

#include "Cifrado.h"
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;

/**
 * @brief abre la direccion del archivo que es pasado por parametro
 * @param  const char* (tipo de numero)
 * @return void
 */
void Cifrado::leer(const char* nombre_archivo) {
	 FILE *ar1;
	 //abre el archivo
	 ar1 = fopen( nombre_archivo,"rb" );
	 if( !ar1 )exit(1); //si no puede sale
	 fseek( ar1,0,2 ); //se posiciona al final
	 tamanio = ftell( ar1 ); //guarda el numero
	 fseek( ar1,0,0 ); //se posiciona al principio
	 //crea un vector del tamaño conseguido
	 cadena = new char[tamanio];
	 //intenta leer los datos, si no puede sale
	 if( !fread(cadena,tamanio,1,ar1) )exit(1);
	 fclose( ar1 ); //cierra el archivo
}
 
/**
 * @brief suma el codigo ASCII de la cadena con una
 * @param  const char* (tipo de numero)
 * @return nada
 */
void Cifrado::cifrar(const char *clave) {
	 int x=0,y=0; //indices de las cadenas
	 //mientras no sea el fin de la cadena
	 while( cadena[x]!=0 ) {
		 cadena[x]+=clave[y]; //suma el codigo ASCII
		 x++; //pasa a la siguiente posicion
		 if( clave[y+1]==0 ) //si se llega al final de la cadena
		 y=0; //comienza de nuevo
		 else //si no
		 y++; //sigue incrementando el indice
	 }
}
 
/**
 * @brief resta el codigo ASCII de la cadena con una
 * @param  const char* (tipo de numero)
 * @return nada
 */
void Cifrado::descifrar(const char *clave) {
	 int x=0,y=0; //indices de las cadenas
	 //mientras no sea el fin de la cadena
	 while( cadena[x]!=0 ) {
		 cadena[x]-=clave[y]; //resta el codigo ASCII
		 x++; //pasa a la siguiente posicion
		 if( clave[y+1]==0 ) //si se llega al final de la cadena
		 y=0; //comienza de nuevo
		 else //si no
		 y++; //sigue incrementando el indice
	 }
}
 
/**
 * @brief abre la direccion que es pasada por parametro
 * @param  const char* (tipo de numero)
 * @return nada
 */
void Cifrado::grabar( const char *nombre_archivo ) {
	 FILE *ar1;
	 //abre el archivo
	 ar1 = fopen( nombre_archivo,"rb+" );
	 if( !ar1 )exit(1); //si no puede sale
	 //intenta escribir los datos, si no puede sale
	 if( !fwrite(cadena,tamanio,1,ar1) )exit(1);
	 fclose( ar1 ); //cierra el archivo
}
 
Cifrado::~Cifrado() {
 	delete[] cadena; //libera la memoria
}
