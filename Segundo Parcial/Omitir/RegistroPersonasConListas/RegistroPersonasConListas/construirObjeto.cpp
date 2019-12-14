#include "ConstruirObjeto.h"
#include <iostream>
#include "Validacion.h"

Validacion validacion;
Persona persona;
string idPersona;
string cedula;
string nombre;
string apellido;

Persona ConstruirObjeto::construirPersona() {
	cout << "Ingrese su nombre: " << endl;
	cin >> nombre;
	nombre = validacion.soloLetras(nombre);
	persona.setNombre(nombre);

	cout << "Ingrese su apellido: " << endl;
	cin >> apellido;
	apellido = validacion.soloLetras(apellido);
	persona.setApellido(apellido);

	cout << "Ingrese su cedula: " << endl;
	cin >> cedula;
	cedula = validacion.soloNumeros(cedula);
	cedula = validacion.validacionCedula(cedula);
	persona.setCedula(cedula);

	cout << "Ingrese su id: " << endl;
	cin >> idPersona;
	idPersona = validacion.validacionId(idPersona);
	persona.setIdPersona(idPersona);

	return persona;
}