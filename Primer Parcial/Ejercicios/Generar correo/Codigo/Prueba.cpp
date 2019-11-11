/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* CARRERA: Ingenieria de Software                                 *
* SEMESTRE: Tercer semestre                                       *
* MATERIA: Estructura de Datos                                    *
* NRC: 2967                                                       *
******************************************************************/
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include "Alumno.h"
#include "PruebaEmail.h"
#include "Ingreso.h"

int main(){
	Ingreso ex;
	string idPa,idPr,idCa, idAlumno, nombre,apellido;
	Alumno alum = Alumno();
	PruebaEmail pru = PruebaEmail();
	cout<<"Ingrese su nombre"<<endl;
	getline(cin,nombre);
	alum.setNombre(nombre);
	cout<<"Ingrese su apellido"<<endl;
	getline(cin,apellido);
	alum.setApellido(apellido);
	alum.setCedula(ex.ingresarStringN("Ingrese su cedula"));
	alum.setEstCivil(ex.ingresarString("Ingrese su estado civil"));
	alum.setGenero(ex.ingresarString("Ingrese su genero"));
	alum.setTelf(ex.ingresarStringN("Ingrese su telefono"));
	alum.setNacionalidad(ex.ingresarString("Ingrese su nacionalidad"));
	alum.setAnio(ex.ingresar("Ingrese su anio de nacimiento"));
	alum.setMes(ex.ingresar("Ingrese su mes de nacimiento"));
	while(alum.getMes()>12){
		alum.setMes(ex.ingresar("Ingrese su mes de nacimiento"));
	}
	alum.setDia(ex.ingresar("Ingrese su dia de nacimiento"));
	while(alum.getDia()>28&&alum.getMes()==2){
		alum.setDia(ex.ingresar("Ingrese su dia de nacimiento"));
	}
	while(alum.getDia()>31){
		alum.setDia(ex.ingresar("Ingrese su dia de nacimiento"));
	}
	cout<<"Ingrese el id de su provincia"<<endl;
	cin>>idPr;
	alum.setIdProvincia(idPr);
	alum.setNombreProvincia(ex.ingresarString("Ingrese el nombre de su provincia de residencia"));
	cout<<"Ingrese el id de su canton"<<endl;
	cin>>idCa;
	alum.setIdCanton(idCa);
	alum.setNombreCanton(ex.ingresarString("Ingrese el nombre de su canton de residencia"));
	cout<<"Ingrese el id de su parroquia"<<endl;
	cin>>idPa;
	alum.setIdParroq(idPa);
	alum.setNombreParroq(ex.ingresarString("Ingrese el nombre de su parroquia de residencia"));
	cout<<"Ingrese su id de alumno"<<endl;
	cin>>idAlumno;
	alum.setIdAlumno(idAlumno);
	alum.setEmail(pru.genEmail(alum.getNombre(),alum.getApellido()));
	string line;
	fstream out;
	out.open("example.txt",fstream::app);
	int i=0;
	ifstream myfile ("example.txt");
	if (myfile.is_open())
  	{    	
	  while ( getline (myfile,line) )
    	{
    	if(pru.genEmail(alum.getNombre(),alum.getApellido()).compare(line.substr(0,pru.genEmail(alum.getNombre(),alum.getApellido()).length()))==0){
    		i++;
			}
    	}
    	myfile.close();
    	line=pru.genEmail(alum.getNombre(),alum.getApellido());
	if(i!=0){
		char* num;
		num=(char*)malloc(1*sizeof(char));
		sprintf(num,"%d",i);
		line.append(num);
	}
	out<<line<<endl;
	out.close();
    	
  	}
	else{
	}
	if(alum.fechaPalindroma()){
		cout<<"es palindromo"<<endl;
	}else{
		cout<<"Nel prro"<<endl;
	}
	
	return 0;
}
