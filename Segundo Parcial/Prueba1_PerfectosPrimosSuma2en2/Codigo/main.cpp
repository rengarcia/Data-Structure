/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 2967                                                       *
******************************************************************/
#include <iostream>
#include "Persona.cpp"
#include "ingreso.h"
#include "Nodo.cpp"
#include "NodoCedula.cpp"
#include "ListaSimple.cpp"
#include "ListaSimpleCedula.cpp"


using namespace std;

int main(){
    Persona persona;
    Ingreso leer;
    ListaSimple *lista = new ListaSimple();
    ListaSimpleCedula *listacedula = new ListaSimpleCedula();
    string opc,buscar;
    int id = 1;
    do{
    	cout<<"\t\tBienvenido\n";
        persona.setNombre(leer.ingresarString("Ingrese nombre: "));
        persona.setApellido(leer.ingresarString("Ingresar apellido: "));
        persona.setCedula(leer.ingresar10Digitos("Ingresar cedula: "));
        persona.setIdPersona(id);
        lista->ingresoFinal(persona);
        cout<<endl;
        listacedula->guardarDosDigitos(persona.getCedula());
        listacedula->guardarUnDigito(persona.getCedula());
        listacedula->buscarPrimos();
        listacedula->guardarUnDigito(persona.getCedula());
        listacedula->buscarPerfectos();
        id++;
        opc = leer.ingresarString("Desea ingresar otra persona (s/n): ");
        system("cls");
    }while(opc == "s" || opc == "S");
    system("pause");
    //lista->imprimirDatos();
    lista->~ListaSimple();
    return 0;
}
