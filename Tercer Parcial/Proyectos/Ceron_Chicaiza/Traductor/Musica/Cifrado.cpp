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
 * Module:  Cifrado.cpp
 * Modified: Sunday, January 24, 2020 3:41:28 PM
 * Purpose: Implementation of the class Cifrado
 ***********************************************************************/

#include "Cifrado.h"

 ////////////////////////////////////////////////////////////////////////
 // Name:       Cifrado::encriptado()
 // Purpose:    Implementation of Cifrado::encriptado()
 // Return:     void
////////////////////////////////////////////////////////////////////////

void Cifrado::encriptado() {
    char car;
    archivo = fopen("solucion.txt", "rb");
    nuevo = fopen("1SolucioEncriptado.txt", "wb");
    if (nuevo == NULL) {
        cout << "Error al abrir el archivo nuevo\n";
    }

    if (archivo == NULL) {
        cout << "Error al abrir el archivo\n";
    }
    while (fread(&car, 1, 1, archivo) != 0) {
        car += 20;
        fwrite(&car, 1, 1, nuevo);
    }
    fclose(nuevo);
    fclose(archivo);
}

////////////////////////////////////////////////////////////////////////
// Name:       Cifrado::desencriptado()
// Purpose:    Implementation of Cifrado::desencriptado()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Cifrado::desencriptado() {
    char car;
	archivo = fopen("1SolucioEncriptado.txt", "rb");
    nuevo = fopen("2SolucionDesncriptar.txt", "wb");
	
    if (nuevo == NULL) {
        cout << "Error al abrir el archivo nuevo\n";
    }

    if (archivo == NULL) {
        cout << "Error al abrir el archivo\n";
    }

    while (fread(&car, 1, 1, archivo) != 0) {
        car -= 20;
        fwrite(&car, 1, 1, nuevo);
    }
    fclose(nuevo);
    fclose(archivo);
}
